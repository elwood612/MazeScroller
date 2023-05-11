using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using Object = UnityEngine.Object;
using Random = UnityEngine.Random;

public class GameManager : MonoBehaviour
{
    #region Variables
    [SerializeField] private GM_Settings _settings;
    [SerializeField] private GameObject _runnerPrefab;
    [SerializeField] private bool _debugMode;
    public Transform SampleTileTransform;

    private static Object[] _allStageDialogueObjects;
    private static Object[] _earlyStageDialogueObjects;
    private static Object[] _midStageDialogueObjects;
    private static Object[] _lateStageDialogueObjects;
    private static Object[] _specialStageDialogueObjects;
    private static List<StageDialogue> _allStageDialogue = new List<StageDialogue>();
    private static Queue<StageDialogue> _stageDialogue_early = new Queue<StageDialogue>();
    private static Queue<StageDialogue> _stageDialogue_mid = new Queue<StageDialogue>();
    private static Queue<StageDialogue> _stageDialogue_late = new Queue<StageDialogue>();
    private static Queue<StageDialogue> _stageDialogue_special = new Queue<StageDialogue>();
    private static StageDialogue _currentStageDialogue;
    private AnimationCurve _tileSpeedCurve;
    private AnimationCurve _runnerSpeedCurve;
    private AnimationCurve _runnerTransitionCurve;
    private AnimationCurve _tileSpawnerWidthCurve;
    private GameObject _currentRunner;
    private float _defaultSpeed = 1f;    
    private int _speedBonus = 0;
    private int _compassionateBonus = 0;
    private WaitForSeconds _bonusDelay = new WaitForSeconds(1f);
    private WaitForSeconds _bonusStep = new WaitForSeconds(0.4f);
    private bool _startOfGame = true;
    private bool _decreaseSpeedBonus = true;
    private bool _triggerBonusStep = true;
    private static float _maxSpeed = 50f;
    private static float _tileLength;
    private static float _speedMultiplier = 1f;
    private static float _tileAlpha = 1f;
    //private static int _currentStage = 0; // so that we start off by incrementing to 0
    private static int _stageProgress;
    private static int _stageLength = 80;
    private static int _transitionProgress;
    private static int _acquiredStars = 0;
    private static int _requiredStars = 1;
    private static int _lifetimeStars = 0;
    private static int _loseCounter = 0;
    private static int _bonusStarLevel = 0;
    private static int _spawnChargedTileChance = 6;
    private static int _specialDialogueCounter = 0;
    private static float _tileColorHue = 0;
    private static bool _firstStarGained = true;
    private static bool _resetStoryMode = false;
    private static bool _isAudioEnabled = false;
    private static bool _isMusicEnabled = false;
    private static bool _needDialogueBoxHint = true;
    private static bool _spawnPurpleCrystal = false;
    private static bool _spawnGoldCrystal = false;
    private static bool _spawnGreenCrystal = false;
    private static Vector3 _tileSpeed = Vector3.zero;
    private static Vector3 _transitionSpeed = new Vector3(0, 0, -40);
    private static Vector3 _boardLength;
    private static Answer _stageAnswer = Answer.Poor;

    public static GameState CurrentState;
    public static event Action<GameState> OnStateChanged;
    public static event Action OnSetupNextStage;
    public static event Action<int> OnSpeedBonusChanged;
    public static event Action<int> OnCompassionateBonusChanged;
    public static event Action OnCompassionateVictory;
    public static event Action OnStageEnd;
    public static event Action<GameObject> OnRunnerSpawned;
    public static event Action<int> OnStarGained;
    public static event Action OnMainMenuOpen;
    public static event Action OnMainMenuClose;

    public static GameManager Instance;
    public static GameObject LastCrystal;
    public static float HighestDrawnRowHeight;
    public static float RunnerHeight;
    public static int NumberOfRows;
    public static bool IsRunnerInTransition = false;
    public static bool DoTutorial = true;
    public static bool IsStageOver = false;

    public GameObject CurrentRunner => _currentRunner;
    public GM_Settings GameSettings => _settings;
    public static float TileLength => _tileLength;
    public static Vector3 BoardLength => _boardLength;
    public static float TileSpeed => Mathf.Abs(_tileSpeed.z);
    public AnimationCurve RunnerSpeedCurve => _runnerSpeedCurve;
    public AnimationCurve RunnerTransitionCurve => _runnerTransitionCurve;
    public AnimationCurve TileSpawnerWidthCurve => _tileSpawnerWidthCurve;
    public static int StageLength => _stageLength;
    public static float MaxSpeed => _maxSpeed;
    public static float TileAlpha => _tileAlpha;
    public static int TransitionProgress => _transitionProgress;
    public static int LoseCounter => _loseCounter;
    public static int RequiredStars => _requiredStars;
    public static float TileColorHue => _tileColorHue;
    public static StageDialogue CurrentStageDialogue => _currentStageDialogue;
    public static int SpawnChargedTileChance => _spawnChargedTileChance;
    public static bool SpawnPurpleCrystal => _spawnPurpleCrystal;
    public static bool SpawnGoldCrystal => _spawnGoldCrystal;
    public static bool SpawnGreenCrystal => _spawnGreenCrystal;
    public static Answer StageAnswer => _stageAnswer;
    public static bool IsAudioEnabled
    {
        get => _isAudioEnabled;
        set
        {
            _isAudioEnabled = value;
            PlayerPrefs.SetInt("IsAudioEnabled", _isAudioEnabled ? 1 : 0);
            PlayerPrefs.Save();
        }
    }
    public static bool IsMusicEnabled
    {
        get => _isMusicEnabled;
        set
        {
            _isMusicEnabled = value;
            PlayerPrefs.SetInt("IsMusicEnabled", _isMusicEnabled ? 1 : 0);
            PlayerPrefs.Save();
        }
    }
    public static bool NeedDialogueBoxHint
    {
        get => _needDialogueBoxHint;
        set
        {
            _needDialogueBoxHint = value;
            PlayerPrefs.SetInt("NeedDialogueBoxHint", _needDialogueBoxHint ? 1 : 0);
            PlayerPrefs.Save();
        }
    }
    public static bool ResetStoryMode
    {
        get => _resetStoryMode;
        set
        {
            _resetStoryMode = value;
        }
    }
    public static int StageProgress
    {
        get => _stageProgress;
        set
        {
            if (CurrentState == GameState.Progressing)
            {
                if (_stageProgress < _stageLength)
                {
                    _stageProgress = value;
                    if (_stageProgress > _stageLength / 2)
                    {
                        _tileAlpha = Mathf.Max(_tileAlpha - 2f / _stageLength, 0);
                    }
                }
                else
                {
                    _stageProgress = 0;
                    IsStageOver = true;
                    if (DoTutorial)
                    { 
                        DoTutorial = false;
                        PlayerPrefs.SetInt("DoTutorial", 0);
                        PlayerPrefs.Save();
                    }
                    Instance.UpdateGameState(GameState.Transition);
                }
            }
        }
    }
    public int SpeedBonus
    {
        get => _speedBonus;
        set
        {
            if (value > _speedBonus)
            {
                ResetCoroutines();
                StartCoroutine(BonusDelay());
            }
            _speedBonus = value;
            OnSpeedBonusChanged?.Invoke(value);
            if (_speedBonus > 100 * (_acquiredStars + 1))
            {
                AcquiredStars++;
                LifetimeStars++;
            }
        }
    }
    public int CompassionateBonus
    {
        get => _compassionateBonus;
        set
        {
            if (value <= 3 && value >= 0)
            {
                _compassionateBonus = value;
                OnCompassionateBonusChanged?.Invoke(value);
                if (value == 3)
                {
                    CompassionateVictory();
                }
            }
        }
    }
    public static int AcquiredStars
    {
        get => _acquiredStars;
        set
        {
            _acquiredStars = value;
            AudioManager.Instance.StarGain.Play();
            if (_firstStarGained && DoTutorial)
            {
                _firstStarGained = false;
                DialogueManager.Instance.NextTutorialDialogue(6);
            }
            if (_acquiredStars % _requiredStars == 0)
            {
                _bonusStarLevel++;
            }
            OnStarGained?.Invoke(_bonusStarLevel);
        }
    }
    public static int LifetimeStars
    {
        get => _lifetimeStars;
        set
        {
            _lifetimeStars = value;
            PlayerPrefs.SetInt("LifetimeStars", value);
        }
    }
    public static int SpecialDialogueCounter
    {
        get => _specialDialogueCounter;
        set
        {
            _specialDialogueCounter = value;
            PlayerPrefs.SetInt("SpecialDialogueCounter", value);
        }
    }
    #endregion

    #region Initialization
    private void Awake()
    {
        if (Instance == null) { Instance = this; }
        else { Destroy(this); }

        LoadSettings();
        LoadPlayerPrefs();
        LoadStageDialogue();

        QualitySettings.vSyncCount = 0;
        Application.targetFrameRate = 60;

        if (_debugMode)
        {
            _isMusicEnabled = false;
            DoTutorial = false; 
        }
    }

    private void Start()
    {
        UpdateGameState(GameState.Setup);
    }
    #endregion

    private void Update()
    {
        if (CurrentState == GameState.Setup) { return; }
        CalculateBoardSpeed(_speedMultiplier);

        if (_decreaseSpeedBonus && _triggerBonusStep && !DialogueManager.Instance.IsDialogueActive) { StartCoroutine(BonusDecrease()); }
    }

    private void LoadSettings()
    {
        _tileSpeedCurve = _settings.TileSpeedCurve;
        _runnerSpeedCurve = _settings.RunnerSpeedCurve;
        _runnerTransitionCurve = _settings.RunnerTransitionCurve;
        _tileSpawnerWidthCurve = _settings.TileSpawnerWidthCurve;
        _tileLength = SampleTileTransform.GetComponent<BoxCollider>().bounds.size.x;
    }

    private void LoadPlayerPrefs()
    {
        _lifetimeStars = PlayerPrefs.GetInt("LifetimeStars", 0);
        _specialDialogueCounter = PlayerPrefs.GetInt("SpecialDialogueCounter", 0);
        DoTutorial = PlayerPrefs.GetInt("DoTutorial", 1) == 0 ? false : true;
        _isAudioEnabled = PlayerPrefs.GetInt("IsAudioEnabled", 1) == 0 ? false : true;
        _isMusicEnabled = PlayerPrefs.GetInt("IsMusicEnabled", 1) == 0 ? false : true;
        _needDialogueBoxHint = PlayerPrefs.GetInt("NeedDialogueBoxHint", 1) == 0 ? false : true;
    }

    private void LoadStageDialogue()
    {
        _allStageDialogueObjects = Resources.LoadAll("StageDialogue", typeof (StageDialogue));
        _earlyStageDialogueObjects = Resources.LoadAll("StageDialogue/early", typeof (StageDialogue));
        _midStageDialogueObjects = Resources.LoadAll("StageDialogue/mid", typeof (StageDialogue));
        _lateStageDialogueObjects = Resources.LoadAll("StageDialogue/late", typeof (StageDialogue));
        _specialStageDialogueObjects = Resources.LoadAll("StageDialogue/special", typeof (StageDialogue));
        foreach (var dialogue in _allStageDialogueObjects)
        {
            _allStageDialogue.Add((StageDialogue)dialogue);
            if (_earlyStageDialogueObjects.Contains(dialogue)) { _stageDialogue_early.Enqueue((StageDialogue)dialogue); }
            else if (_midStageDialogueObjects.Contains(dialogue)) { _stageDialogue_mid.Enqueue((StageDialogue)dialogue); }
            else if (_lateStageDialogueObjects.Contains(dialogue)) { _stageDialogue_late.Enqueue((StageDialogue)dialogue); }
            else if (_specialStageDialogueObjects.Contains(dialogue)) { _stageDialogue_special.Enqueue((StageDialogue)dialogue); }
        }
        _currentStageDialogue = SelectStageDialogue();
    }

    private void CalculateBoardSpeed(float multiplier)
    {
        float heightCurve;
        if (RunnerHeight < 0.2f)
        {
            heightCurve = _tileSpeedCurve.Evaluate(RunnerHeight);
        }
        else
        {
            heightCurve = _tileSpeedCurve.Evaluate(HighestDrawnRowHeight);
        }
        if (_startOfGame) { heightCurve = 0.5f; } // just used for first few frames
        _tileSpeed = new Vector3(0, 0, -heightCurve * _defaultSpeed * multiplier);
    }

    private void CalculateBoardLength()
    {
        _boardLength = new Vector3(0, 0, _tileLength * NumberOfRows);
    }

    private void OnDestroy()
    {
        if (Instance == this) { Instance = null; }
    }

    private IEnumerator BonusDelay()
    {
        _decreaseSpeedBonus = false;
        yield return _bonusDelay;
        _decreaseSpeedBonus = true;
    }

    private IEnumerator BonusDecrease()
    {
        _triggerBonusStep = false;
        yield return _bonusStep;
        SpeedBonus = SpeedBonus > _acquiredStars * 100 ? SpeedBonus - 1 : _acquiredStars * 100;
        _triggerBonusStep = true;
    }

    private void ResetCoroutines()
    {
        StopAllCoroutines();
        _triggerBonusStep = true;
    }

    private void ResetStats()
    {
        _speedBonus = 0;
        _compassionateBonus = 0;
        _acquiredStars = 0;
        _bonusStarLevel = 0;
        _tileAlpha = 1f;
    }

    private void CompassionateVictory()
    {
        AudioManager.Instance.StarGain.Play(); // should probably be a different sound??
        _stageProgress = _stageLength - 5; 
        OnCompassionateVictory?.Invoke();
    }

    private StageDialogue SelectStageDialogue()
    {
        if (_lifetimeStars == 0 && _specialDialogueCounter == 0)
        {
            SpecialDialogueCounter++;
            return _stageDialogue_special.Dequeue();
        }
        else if (_lifetimeStars > 8 && _specialDialogueCounter == 1)
        {
            SpecialDialogueCounter++;
            return _stageDialogue_special.Dequeue();
        }
        else if (_lifetimeStars > 12 && _specialDialogueCounter == 2)
        {
            SpecialDialogueCounter++;
            return _stageDialogue_special.Dequeue();
        }
        else if (_lifetimeStars < 6)
        {
            if (_stageDialogue_early.Count == 0)
            {
                foreach (var dialogue in _earlyStageDialogueObjects) { _stageDialogue_early.Enqueue((StageDialogue)dialogue); }
            }
            return _stageDialogue_early.Dequeue();
        }
        else if (_lifetimeStars >= 6 && _lifetimeStars < 11)
        {
            if (_stageDialogue_mid.Count == 0)
            {
                foreach (var dialogue in _midStageDialogueObjects) { _stageDialogue_mid.Enqueue((StageDialogue)dialogue); }
            }
            return _stageDialogue_mid.Dequeue();
        }
        else
        {
            if (_stageDialogue_late.Count == 0)
            {
                foreach (var dialogue in _lateStageDialogueObjects) { _stageDialogue_late.Enqueue((StageDialogue)dialogue); }
            }
            return _stageDialogue_late.Dequeue();
        }
    } 

    public void UpdateGameState(GameState newState)
    {
        if (CurrentState == newState && newState != GameState.Setup) { return; } // avoids spamming events for no reason
        CurrentState = newState;

        switch (newState)
        {
            case GameState.Setup:
                CalculateBoardSpeed(0);
                CalculateBoardLength();
                break;
            case GameState.Transition:
                break;
            case GameState.Progressing:
                ResetStats();
                break;
        }
        OnStateChanged?.Invoke(newState);
    }

    public void SpawnPlayer(Transform tile)
    {
        _currentRunner = Instantiate(_runnerPrefab, tile.position, Quaternion.identity);
        _startOfGame = false;
        OnRunnerSpawned?.Invoke(_currentRunner);
    }

    public static void AddBoardMotion(Transform t)
    {
        if (DialogueManager.Instance.IsDialogueActive && DoTutorial) { return; }

        if (IsRunnerInTransition)
        {
            t.Translate(_transitionSpeed * Time.deltaTime);
        }
        else if (!IsRunnerInTransition)
        {
            t.Translate(_tileSpeed * Time.deltaTime);
        }
    }

    public static bool CompareVectorsAsInts(Vector3 v1, Vector3 v2)
    {
        return Vector3Int.RoundToInt(v1) == Vector3Int.RoundToInt(v2);
    }

    public void SetupNextStage()
    {
        _currentStageDialogue = SelectStageDialogue();

        if (_lifetimeStars > 10 && _acquiredStars >= _requiredStars)
        {
            _spawnGoldCrystal = true;
            _spawnPurpleCrystal = true;
            _spawnChargedTileChance = 4;
        }
        else if (_lifetimeStars > 3)
        {
            _spawnGoldCrystal = false;
            _spawnPurpleCrystal = true;
            _spawnChargedTileChance = 5;
        }
        else 
        { 
            _spawnPurpleCrystal = false;
            _spawnGoldCrystal = false;
            _spawnChargedTileChance = 6;
        }

        _spawnGreenCrystal = _currentStageDialogue.CompassionateAnswer != "";

        if (DoTutorial)
        {
            _tileColorHue = 0.552778f;
            _requiredStars = 1;
            _stageLength = 30;
        }
        else
        {
            _tileColorHue = Mathf.Clamp(Random.Range(0f, 1f), 0.1f, 0.9f);
            _requiredStars = 1;
            _stageLength = _requiredStars * 80;
        }
        
        OnSetupNextStage?.Invoke();
    }

    public void EndStage()
    {
        IsStageOver = false;
        PlayerPrefs.Save();

        if (_acquiredStars < _requiredStars)
        {
            _stageAnswer = Answer.Poor;
        }
        else if (_acquiredStars == _requiredStars)
        {
            _stageAnswer = Answer.Acceptable;
        }
        else if (_acquiredStars > _requiredStars)
        {
            _stageAnswer = Answer.Excellent;
        }

        if (_compassionateBonus == 3)
        {
            _stageAnswer = Answer.Compassionate;
        }

        OnStageEnd?.Invoke();
    }

    public void OpenMainMenu()
    {
        OnMainMenuOpen?.Invoke();
    }

    public void CloseMainMenu()
    {
        OnMainMenuClose?.Invoke();
    }

    public void Quit()
    {
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#else
        Application.Quit();
#endif
    }
}