using System;
using System.Collections;
using UnityEngine;
using UnityEngine.Pool;

public class Crystal : MonoBehaviour
{
    [SerializeField] private Renderer _renderer;
    [SerializeField] private ParticleSystem _particlesNormal;
    [SerializeField] private ParticleSystem _particlesExplosion;
    [SerializeField] private ParticleSystem _particlesExplosionMissile;
    [SerializeField] private OrbitMissile _missilePrefab;

    //private ParticleSystem.MainModule _particlesNormalModule;
    //private ParticleSystem.MainModule _particlesExplosionModule;
    private ObjectPool<Crystal> _crystalPool;
    private int _crystalLevel = 0;
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
        //_particlesNormalModule = _particlesNormal.main;
        //_particlesExplosionModule = _particlesExplosion.main;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player") && !_destroyed)
        {
            if (_crystalLevel == 0)
            {
                GameManager.Score++;
                StartCoroutine(PlayerContact());
            }
            else
            {
                DestroyOrbitMissile(_orbitMissiles[_crystalLevel - 1]);
                _crystalLevel--;
            }
        }
        else if (other.CompareTag("TileDestroyer") && !_destroyed)
        {
            EndOfBoardContact();
        }
    }

    //private void SetColor(Material color)
    //{
    //    _renderer.material = color;
    //    _particlesNormalModule.startColor = color.color;
    //    _particlesExplosionModule.startColor = color.color;
    //}

    private void SpawnOrbitMissiles()
    {
        for (int i = 0; i < _crystalLevel; i++)
        {
            _orbitMissiles[i].gameObject.SetActive(true);
            _orbitMissiles[i].transform.localPosition = new Vector3(3.5f, 2, 0);
            _orbitMissiles[i].transform.RotateAround(transform.position, transform.up, i * (360 / _crystalLevel));
        }
    }

    private IEnumerator PlayerContact()
    {
        _destroyed = true;
        _renderer.enabled = false;
        _particlesExplosion.Play();
        _particlesNormal.Stop();
        yield return _destroyDelay;
        _crystalPool.Release(this);
    }

    private void EndOfBoardContact()
    {
        GameManager.Instability += 100;
        for (int i = 0; i < _crystalLevel; i++)
        {
            // Spawn actual missile here
            DestroyOrbitMissile(_orbitMissiles[_crystalLevel - 1]);
        }
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
        _renderer.enabled = true;
        _crystalLevel = level;
        _crystalPool = crystalPool;
        SpawnOrbitMissiles();
    }
}
