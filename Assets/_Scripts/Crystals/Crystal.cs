using System;
using System.Collections;
using TMPro;
using UnityEngine;
using UnityEngine.Pool;
using Random = UnityEngine.Random;

public class Crystal : MonoBehaviour
{
    [SerializeField] private GameObject _wireframe;
    [SerializeField] private GameObject _star;
    [SerializeField] private MeshRenderer _shadow;
    [SerializeField] private ParticleSystem _particlesExplosion;
    [SerializeField] private ParticleSystem _particlesExplosionMissile;
    [SerializeField] private OrbitMissile _missilePrefab;
    [SerializeField] private TextMeshProUGUI _word;
    [SerializeField] private Animation _wordAnimation;
    [SerializeField] private Material[] _wireframeMaterials;
    [SerializeField] private Material[] _shadowMaterials;
    
    private ObjectPool<Crystal> _crystalPool;
    private int _level = 0;
    private int _initialLevel;
    private int _scoreConstant = 12;
    private int _scoreMin = 3;
    private int _compassionateCounter = 0;
    private bool _destroyed = false;
    private bool _compassionateScore = false;
    private bool _firstTimeSeeingCompassionate = true;
    private bool _standingInGreenCrystal = false;
    private bool _greenCrystalControl = true;
    private static bool _firstCrystal = true;
    private static bool _secondCrystal = false;
    private static bool _firstBlueCrystal = false;
    private static bool _firstPurpleCrystal = true;
    private static bool _firstGoldCrystal = true;
    private static bool _thirdCrystal = false;
    private static bool _firstGreenCrystal = true;
    private static bool _firstGreenCrystalPopped = true;
    private static bool _greenCrystalTutorialReset = true;
    private static int _blueCrystalsNotPopped = 0;
    private WaitForSeconds _destroyDelay = new WaitForSeconds(1f);
    private WaitForSecondsRealtime _compassionateDelay = new WaitForSecondsRealtime(2.5f);
    private OrbitMissile[] _orbitMissiles = new OrbitMissile[6];

    public static event Action OnFirstCrystal;
    public static event Action OnSecondCrystal;
    public static event Action OnFirstBlueCrystal;
    public static event Action OnFirstBlueCrystalPopped;
    public static event Action OnGreenCrystalPopped;

    public static int ConsecutiveBonus = 1; // this is public so Runner can reset it

    public int InitialLevel => _initialLevel;
    //public static bool FirstGreenCrystalPopped => _firstGreenCrystalPopped;

    private void Awake()
    {
        for (int i = 0; i < _orbitMissiles.Length; i++)
        {
            _orbitMissiles[i] = Instantiate(_missilePrefab, transform);
            _orbitMissiles[i].gameObject.SetActive(false);
        }
        _word.gameObject.SetActive(false);
        _star.SetActive(false);
    }

    private void OnEnable()
    {
        GameManager.OnSetupNextStage += ResetStage;
        GameManager.OnStarGained += StarGained;
        GameManager.OnCompassionateStarAdded += CompassionateCrystalExplode;
    }

    private void OnDisable()
    {
        GameManager.OnSetupNextStage -= ResetStage;
        GameManager.OnStarGained -= StarGained;
        GameManager.OnCompassionateStarAdded -= CompassionateCrystalExplode;
    }

    private void Update()
    {
        if (_standingInGreenCrystal)
        {
            GameManager.Instance.CompassionateProgress++;
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Runner") && !_destroyed)
        {
            if (_level == 0)
            {
                PlayerContact();
            }
            else
            {
                if (_level == 4)
                {
                    _standingInGreenCrystal = true;
                    CompassionateCrystalChargeUp();
                    if (!_firstGreenCrystalPopped && !GameManager.DoTutorial[11] && _greenCrystalTutorialReset) 
                    { 
                        _firstGreenCrystalPopped = true;
                        _greenCrystalTutorialReset = false;
                    }
                    return;
                }
                else if (_level == 1 && ++_blueCrystalsNotPopped > 3 && GameManager.DoTutorial[5])
                {
                    GameManager.OnNextTutorial?.Invoke(18);
                }
                AudioManager.Instance.MissileBeep.pitch = Random.Range(0.6f, 1.2f);
                AudioManager.Instance.MissileBeep.Play();
                GameManager.Instance.StarProgress++;
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
                GameManager.OnNextTutorial?.Invoke(1);
                return;
            }
            if (_firstBlueCrystal && _initialLevel == 1)
            {
                _firstBlueCrystal = false;
                _thirdCrystal = true;
                OnFirstBlueCrystal?.Invoke();
                GameManager.OnNextTutorial?.Invoke(4);
                return;
            }
            if (_thirdCrystal && _initialLevel == 1 && _destroyed)
            {
                _thirdCrystal = false;
                OnFirstBlueCrystalPopped?.Invoke();
                GameManager.OnNextTutorial?.Invoke(5);
                return;
            }
            if (_secondCrystal)
            {
                GameManager.OnNextTutorial?.Invoke(2);
                _secondCrystal = false;
                OnSecondCrystal?.Invoke();
            }
            if (_firstPurpleCrystal && _initialLevel == 2 && _destroyed)
            {
                _firstPurpleCrystal = false;
                GameManager.OnNextTutorial?.Invoke(15);
                return;
            }
            if (_firstGoldCrystal && _initialLevel == 3 && _destroyed)
            {
                _firstGoldCrystal = false;
                GameManager.OnNextTutorial?.Invoke(16);
            }
            #endregion
        }
        else if (other.CompareTag("TileDestroyer") && !_destroyed)
        {
            EndOfBoardContact();
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.CompareTag("Runner") && _initialLevel == 4)
        {
            if (!_destroyed)
            {
                _compassionateScore = false;
                _standingInGreenCrystal = false;
                AudioManager.Instance.PowerUp.Stop();
                GameManager.OnNextTutorial?.Invoke(9);
            }
        }
    }

    private void SpawnOrbitMissiles()
    {
        if (_level == 4) { return; }

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

    private void SetScale()
    {
        if (_initialLevel == 4)
        {
            transform.localScale = new Vector3(1.5f, 1.5f, 1.5f);
        }
        else
        {
            transform.localScale = Vector3.one;
        }
    }

    private void PlayerContact()
    {
        GameManager.LastCrystal = this.gameObject;
        StartCoroutine(Explode());
        if (_initialLevel == 0) { AudioManager.Instance.CrystalPop[_initialLevel].pitch = Random.Range(0.5f, 1.5f); }
        AudioManager.Instance.CrystalPop[Mathf.Min(_initialLevel, AudioManager.Instance.CrystalPop.Length - 1)].Play();
        _particlesExplosion.Play();
        _word.gameObject.SetActive(true);
        _wordAnimation.Play();
        if (GameManager.IsTutorialOngoing) 
        {
            GameManager.Instance.StarProgress += 10;
        }

        if (_initialLevel < 4)
        {
            if (GameManager.Instance.CompassionateStars > 0)
            {
                GameManager.Instance.CompassionateStars = 0;
                // Play audio cue here for losing compassionate progress
                if (_firstGreenCrystalPopped)
                {
                    _firstGreenCrystalPopped = false;
                    if (GameManager.DoTutorial[11]) { GameManager.OnNextTutorial?.Invoke(11); }
                    else { GameManager.OnNextTutorial?.Invoke(22); }
                }
            }
            GameManager.Instance.StarProgress +=
                (int)Mathf.Clamp((_initialLevel * _initialLevel * ConsecutiveBonus * _scoreConstant) + _scoreMin, 1, 100);
            ConsecutiveBonus = 5;
        }
        else
        {
            AudioManager.Instance.PowerUp.Stop();
            OnGreenCrystalPopped?.Invoke();
        }
    }

    private void ResetFirstGreenCrystalPopped()
    {
        _firstGreenCrystalPopped = true;
    }

    private void EndOfBoardContact()
    {
        StartCoroutine(Explode());
        for (int i = 0; i < _level; i++)
        {
            DestroyOrbitMissile(_orbitMissiles[_level - 1]);
        }
        if (_initialLevel == 4) { OnGreenCrystalPopped?.Invoke(); }
    }

    private IEnumerator Explode()
    {
        _destroyed = true;
        _wireframe.SetActive(false);
        _shadow.enabled = false;

        yield return _destroyDelay;
        _crystalPool.Release(this);
    }

    private void CompassionateCrystalChargeUp()
    {
        AudioManager.Instance.PowerUp.Play();
        GameManager.GreenCrystalTouched = true;
        GameManager.OnCompassionateStarsToggle?.Invoke(true);
        if (_firstTimeSeeingCompassionate)
        {
            GameManager.OnNextTutorial?.Invoke(17);
            _firstTimeSeeingCompassionate = false;
        }
    }

    private void CompassionateCrystalExplode(int value) 
    {
        if (!_standingInGreenCrystal) { return; }
        PlayerContact();
        _standingInGreenCrystal = false;
        if (_firstGreenCrystal)
        {
            _firstGreenCrystal = false;
            GameManager.OnNextTutorial?.Invoke(10);
        }
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

    private void ResetStage()
    {
        _firstGreenCrystal = true;
        _firstTimeSeeingCompassionate = true;
        _standingInGreenCrystal = false;
        if (GameManager.IsTutorialOngoing)
        {
            _firstCrystal = true;
            _secondCrystal = false;
            _firstBlueCrystal = false;
            _thirdCrystal = false;
        }
    }

    private void ResetWord()
    {
        _word.gameObject.SetActive(false);
        _word.text = DialogueManager.Instance.GetRandomWord(GameManager.CurrentStageDialogue);
    }

    private void StarGained(int unused)
    {
        if (GameManager.LastCrystal == this.gameObject)
        {
            _star.SetActive(true);
        }
    }

    public void ResetScoreBonus(bool stopped)
    {
        if (stopped) { Debug.Log("Reset bonus"); ConsecutiveBonus = 1; }
    }

    public void RemoveCrystal()
    {
        if (!isActiveAndEnabled) { return; }
        StartCoroutine(Explode());
    }

    public void Initialize(int level, ObjectPool<Crystal> crystalPool)
    {
        _destroyed = false;
        _wireframe.SetActive(true);
        _star.SetActive(false);
        _shadow.enabled = true;
        _level = level;
        _initialLevel = level;
        _crystalPool = crystalPool;
        _compassionateScore = false;
        SetMaterials(_wireframeMaterials[_level], _shadowMaterials[_level]);
        ResetOrbitMissiles();
        SpawnOrbitMissiles();
        ResetWord();
        SetScale();
    }
}
