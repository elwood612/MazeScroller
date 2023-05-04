using System;
using System.Collections;
using TMPro;
using UnityEngine;
using UnityEngine.Pool;

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
    private bool _destroyed = false;
    private bool _compassionateScore = false;
    private static bool _firstCrystal = true;
    private static bool _secondCrystal = false;
    private static bool _firstBlueCrystal = false;
    private static bool _thirdCrystal = false;
    private WaitForSeconds _destroyDelay = new WaitForSeconds(1f);
    private WaitForSecondsRealtime _compassionateDelay = new WaitForSecondsRealtime(2.5f);
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
        _word.gameObject.SetActive(false);
        _star.SetActive(false);
    }

    private void OnEnable()
    {
        GameManager.OnSetupNextStage += ResetTutorial;
        GameManager.OnStarGained += StarGained;
    }

    private void OnDisable()
    {
        GameManager.OnSetupNextStage -= ResetTutorial;
        GameManager.OnStarGained -= StarGained;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Runner") && !_destroyed)
        {
            AudioManager.Instance.Beep.Play();
            if (_level == 0)
            {
                PlayerContact();
            }
            else
            {
                if (_level == 4)
                {
                    StartCoroutine(CompassionateCrystalContact());
                    return;
                }
                DestroyOrbitMissile(_orbitMissiles[_level - 1]);
                _level--;
            }

            #region Tutorial Stuff
            if (GameManager.DoTutorial)
            {
                if (_firstCrystal)
                {
                    _firstCrystal = false;
                    _secondCrystal = true;
                    _firstBlueCrystal = true;
                    OnFirstCrystal?.Invoke();
                    DialogueManager.Instance.NextTutorialDialogue(1);
                    return;
                }
                if (_firstBlueCrystal && _initialLevel == 1)
                {
                    _firstBlueCrystal = false;
                    _thirdCrystal = true;
                    OnFirstBlueCrystal?.Invoke();
                    DialogueManager.Instance.NextTutorialDialogue(4);
                    return;
                }
                if (_thirdCrystal && _initialLevel == 1 && _destroyed)
                {
                    _thirdCrystal = false;
                    OnFirstBlueCrystalPopped?.Invoke();
                    DialogueManager.Instance.NextTutorialDialogue(5);
                    return;
                }
                if (_secondCrystal)
                {
                    DialogueManager.Instance.NextTutorialDialogue(2);
                    _secondCrystal = false;
                    OnSecondCrystal?.Invoke();
                }
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
        if (other.CompareTag("Runner") && !_destroyed && _initialLevel == 4)
        {
            //StopCoroutine(CompassionateCrystalContact());
            _compassionateScore = false;
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

    private void PlayerContact()
    {
        GameManager.LastCrystal = this.gameObject;
        StartCoroutine(Explode());
        AudioManager.Instance.Zap.Play();
        _particlesExplosion.Play();
        _word.gameObject.SetActive(true);
        _wordAnimation.Play();
        if (GameManager.DoTutorial) { ScoreBonus = 3; }

        if (_initialLevel < 4)
        {
            GameManager.Instance.SpeedBonus +=
            (int)Mathf.Clamp(_initialLevel * _initialLevel * ScoreBonus * 10, 1, 100);
            ScoreBonus = 2;
        }
        else
        {
            Debug.Log("Increase Compassionate score");
            GameManager.Instance.CompassionateBonus++;
        }
    }

    private void EndOfBoardContact()
    {
        StartCoroutine(Explode());
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

        yield return _destroyDelay;
        _crystalPool.Release(this);
    }

    private IEnumerator CompassionateCrystalContact()
    {
        _compassionateScore = true;
        yield return _compassionateDelay;
        if (_compassionateScore && GameManager.Instance.CompassionateBonus < 3) { PlayerContact(); }
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
        if (stopped) { Debug.Log("Reset bonus"); ScoreBonus = 1; }
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
        SetMaterials(_wireframeMaterials[_level], _shadowMaterials[_level]);
        ResetOrbitMissiles();
        SpawnOrbitMissiles();
        ResetWord();
    }
}
