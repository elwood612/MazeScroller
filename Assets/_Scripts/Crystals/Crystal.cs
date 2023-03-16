using System;
using System.Collections;
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
    private static bool _firstCrystal = true;
    private static bool _secondCrystal = false;
    private static bool _firstBlueCrystal = false;
    private static bool _thirdCrystal = false;
    private WaitForSeconds _destroyDelay = new WaitForSeconds(1f);
    private OrbitMissile[] _orbitMissiles = new OrbitMissile[6];

    public static event Action OnFirstCrystal;
    public static event Action OnSecondCrystal;
    public static event Action OnFirstBlueCrystal;
    public static event Action OnFirstBlueCrystalPopped;
    public static int ScoreBonus = 1; // this is public so Runner can reset it

    private void Awake()
    {
        for (int i = 0; i < _orbitMissiles.Length; i++)
        {
            _orbitMissiles[i] = Instantiate(_missilePrefab, transform);
            _orbitMissiles[i].gameObject.SetActive(false);
        }
    }

    private void OnEnable()
    {
        GameManager.OnSetupNextStage += ResetTutorial;
    }

    private void OnDisable()
    {
        GameManager.OnSetupNextStage -= ResetTutorial;
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

            #region Tutorial Stuff
            if (_firstCrystal)
            {
                _firstCrystal = false;
                _secondCrystal = true;
                _firstBlueCrystal = true;
                OnFirstCrystal?.Invoke();
                Debug.Log("Good job! Notice the progress bar up top. Break more crystals to get a star.");
                return;
            }
            if (_firstBlueCrystal && _initialLevel == 1)
            {
                _firstBlueCrystal = false;
                _thirdCrystal = true;
                OnFirstBlueCrystal?.Invoke();
                Debug.Log("This crystal was shielded! Try hitting it a second time.");
                return;
            }
            if (_thirdCrystal && _initialLevel == 1 && _destroyed)
            {
                _thirdCrystal = false;
                OnFirstBlueCrystalPopped?.Invoke();
                Debug.Log("Easy enough. Now keep going and get us that star!");
                return;
            }
            if (_secondCrystal)
            {
                Debug.Log("Now you're getting it! Tip: stay away from those charged tiles.");
                _secondCrystal = false;
                OnSecondCrystal?.Invoke();
            }
            #endregion
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
        if (GameManager.Instance.Parameters[GameManager.CurrentStage].TutorialStage) { ScoreBonus = 5; }
        GameManager.Instance.SpeedBonus += 5 * (_initialLevel + 1) * ScoreBonus;
        ScoreBonus = 2;
    }

    private void EndOfBoardContact()
    {
        StartCoroutine(Explode(true));
        for (int i = 0; i < _level; i++)
        {
            DestroyOrbitMissile(_orbitMissiles[_level - 1]);
        }
    }

    private IEnumerator Explode(bool endOfBoard = false)
    {
        _destroyed = true;
        _wireframe.SetActive(false);
        _shadow.enabled = false;
        _particlesNormal.Stop();
        if (!endOfBoard) 
        { 
            _audioZap.Play();
            _particlesExplosion.Play();
        }
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

    private void ResetTutorial()
    {
        _firstCrystal = true;
        _secondCrystal = false;
        _firstBlueCrystal = false;
        _thirdCrystal = false;
    }

    public void ResetScoreBonus(bool stopped)
    {
        if (stopped) { Debug.Log("Reset bonus"); ScoreBonus = 1; }
    }

    public void RemoveCrystal()
    {
        StartCoroutine(Explode(true));
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
