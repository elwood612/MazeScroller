using System.Collections;
using UnityEngine;
using UnityEngine.Pool;

public class Crystal : MonoBehaviour
{
    [SerializeField] private GameObject _wireframe;
    [SerializeField] private ParticleSystem _particlesNormal;
    [SerializeField] private ParticleSystem _particlesExplosion;
    [SerializeField] private ParticleSystem _particlesExplosionMissile;
    [SerializeField] private OrbitMissile _missilePrefab;

    private ParticleSystem.MainModule _particlesExplosionModule;
    private ObjectPool<Crystal> _crystalPool;
    private int _level = 0;
    private int _initialLevel;
    private bool _destroyed = false;
    private WaitForSeconds _destroyDelay = new WaitForSeconds(1f);
    private OrbitMissile[] _orbitMissiles = new OrbitMissile[6];

    private void Awake()
    {
        for (int i = 0; i < _orbitMissiles.Length; i++)
        {
            _orbitMissiles[i] = Instantiate(_missilePrefab, transform);
            _orbitMissiles[i].gameObject.SetActive(false);
        }
        _particlesExplosionModule = _particlesExplosion.main;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Runner") && !_destroyed)
        {
            if (_level == 0)
            {
                //if (other.GetComponent<IRunner>()) { } // this should fucking work but it's not
                PlayerContact();
            }
            else
            {
                DestroyOrbitMissile(_orbitMissiles[_level - 1]);
                _level--;
            }
        }
        else if (other.CompareTag("TileDestroyer") && !_destroyed)
        {
            EndOfBoardContact();
        }
    }

    private void SpawnOrbitMissiles()
    {
        for (int i = 0; i < _level; i++)
        {
            _orbitMissiles[i].Spawn(i, _level);
        }
    }

    private void PlayerContact()
    {
        StartCoroutine(Explode());
        //GameManager.Score += (int)Mathf.Pow(10, _initialLevel);
    }

    private void EndOfBoardContact()
    {
        StartCoroutine(Explode());
        GameManager.Instance.DecreaseSpeedBonus(100);
        for (int i = 0; i < _level; i++)
        {
            DestroyOrbitMissile(_orbitMissiles[_level - 1]);
        }
    }

    private IEnumerator Explode()
    {
        _destroyed = true;
        _wireframe.SetActive(false);
        _particlesExplosion.Play();
        _particlesNormal.Stop();
        yield return _destroyDelay;
        _crystalPool.Release(this);
    }

    private void DestroyOrbitMissile(OrbitMissile missile)
    {
        StartCoroutine(missile.DestroyMissile());
        _particlesExplosionMissile.Play();
    }

    public void Initialize(int level, ObjectPool<Crystal> crystalPool)
    {
        _destroyed = false;
        _wireframe.SetActive(true);
        _level = level;
        _initialLevel = _level;
        _crystalPool = crystalPool;
        SpawnOrbitMissiles();
    }
}
