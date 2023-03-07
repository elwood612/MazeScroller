using System.Collections;
using System.Threading;
using UnityEngine;
using UnityEngine.Pool;

public class Crystal : MonoBehaviour
{
    [SerializeField] private GameObject _wireframe;
    [SerializeField] private MeshRenderer _shadow;
    [SerializeField] private ParticleSystem _particlesNormal;
    [SerializeField] private ParticleSystem _particlesExplosion;
    [SerializeField] private ParticleSystem _particlesExplosionMissile;
    [SerializeField] private OrbitMissile _missilePrefab;
    [SerializeField] private AudioSource _audioBeep;
    [SerializeField] private AudioSource _audioZap;
    [SerializeField] private AudioSource _audioNegative;
    [SerializeField] private Material[] _wireframeMaterials;
    [SerializeField] private Material[] _shadowMaterials;

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
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Runner") && !_destroyed)
        {
            _audioBeep.Play();
            if (_level == 0)
            {
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

    private void ResetOrbitMissiles()
    {
        for (int i = 0; i < _orbitMissiles.Length; i++)
        {
            _orbitMissiles[i].gameObject.SetActive(false);
        }
    }

    private void PlayerContact()
    {
        StartCoroutine(Explode());
        GameManager.Score += (int)Mathf.Pow(10, _initialLevel);
    }

    private void EndOfBoardContact()
    {
        StartCoroutine(Explode());
        _audioNegative.Play();
        GameManager.Stars--;
        for (int i = 0; i < _level; i++)
        {
            DestroyOrbitMissile(_orbitMissiles[_level - 1]);
        }
    }

    private IEnumerator Explode()
    {
        _destroyed = true;
        _wireframe.SetActive(false);
        _shadow.enabled = false;
        _particlesExplosion.Play();
        _particlesNormal.Stop();
        _audioZap.Play();
        yield return _destroyDelay;
        _crystalPool.Release(this);
    }

    private void DestroyOrbitMissile(OrbitMissile missile)
    {
        StartCoroutine(missile.DestroyMissile());
        _particlesExplosionMissile.Play();
    }

    private void SetMaterials(Material wireframe, Material shadow)
    {
        for (int i = 0; i < _wireframe.transform.childCount; i++)
        {
            _wireframe.transform.GetChild(i).GetComponent<MeshRenderer>().material = wireframe;
        }
        _shadow.material = shadow;
    }

    public void Initialize(int level, ObjectPool<Crystal> crystalPool)
    {
        _destroyed = false;
        _wireframe.SetActive(true);
        _shadow.enabled = true;
        _level = level;
        _initialLevel = level;
        _crystalPool = crystalPool;
        SetMaterials(_wireframeMaterials[_level], _shadowMaterials[_level]);
        ResetOrbitMissiles();
        SpawnOrbitMissiles();
    }
}
