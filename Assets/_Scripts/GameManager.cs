using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;

public class GameManager : MonoBehaviour
{
    #region Variables
    [SerializeField] private GM_Settings _settings;
    [SerializeField] private GameObject _runnerPrefab;
    [SerializeField] private bool _debugMode;
    [SerializeField] private int _startingStage;
    public Transform SampleTileTransform;
    //public List<StageParameters> Parameters;
    public List<StageDialogue> StageDialogues;

    

    private AnimationCurve _tileSpeedCurve;
    private AnimationCurve _runnerSpeedCurve;
    private AnimationCurve _runnerTransitionCurve;
    private AnimationCurve _tileSpawnerWidthCurve;
    private GameObject _currentRunner;
    private static StageDialogue _currentStageDialogue;
    private float _defaultSpeed = 1f;
    private float _averageSpeed;
    private int _counterAverageSpeed = 0;
    private int _counterTransitionBonusIncrease = 0;
    private int _triggerCounters = 30;
    
    private int _speedBonus = 0;
    private WaitForSeconds _bonusDelay = new WaitForSeconds(0.5f);
    private WaitForSeconds _bonusStep = new WaitForSeconds(0.2f);
    private bool _startOfGame = true;
    private bool _decreaseSpeedBonus = true;
    private bool _triggerBonusStep = true;
    private Queue<float> _rollingSpeedAverage = new Queue<float>();
    private int _rollingSpeedAverageMaxCount = 40;
    private static float _maxSpeed = 50f;
    private static float _tileLength;
    private static float _speedMultiplier = 1f;
    private static float _tileAlpha = 1f;
    //private static int _currentStage = 0; // so that we start off by incrementing to 0
    private static int _stageProgress;
    private static int _stageLength = 100;
    private static int _transitionProgress;
    private static int _transitionLength = 30;
    private static int _acquiredStars = 0;
    private static int _requiredStars = 1;
    private static int _lifetimeStars = 0;
    private static int _loseCounter = 0;
    private static int _bonusStarLevel = 0;
    private static float _tileColorHue = 0;
    private static bool _firstStarGained = true;
    private static bool _resetStoryMode = false;
    private static bool _isAudioEnabled = false;
    private static bool _isMusicEnabled = false;

    private static Vector3 _tileSpeed = Vector3.zero;
    private static Vector3 _transitionSpeed = new Vector3(0, 0, -40);
    private static Vector3 _boardLength;

    public static GameState CurrentState;
    public static event Action<GameState> OnStateChanged;
    public static event Action OnSetupNextStage;
    public static event Action<int> OnScoreChanged;
    public static event Action<int> OnSpeedBonusChanged;
    public static event Action<int> OnLoseCounterChanged;
    public static event Action OnStageEnd;
    public static event Action<Dialogue> OnNextDialogue;
    public static event Action<StageDialogue> OnNextQuery;
    public static event Action<StageDialogue> OnNextComment;
    public static event Action<StageDialogue> OnNextAnswer;
    public static event Action<GameObject> OnRunnerSpawned;
    public static event Action<int> OnStarGained;
    public static event Action OnMainMenuOpen;
    public static event Action OnMainMenuClose;

    public static GameManager Instance;
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
    //public static int CurrentStage => _currentStage;
    public static int TransitionProgress => _transitionProgress;
    public static int LoseCounter => _loseCounter;
    public static int RequiredStars => _requiredStars;
    public static float TileColorHue => _tileColorHue;
    public static StageDialogue CurrentStageDialogue => _currentStageDialogue;
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
    public static bool ResetStoryMode
    {
        get => _resetStoryMode;
        set
        {
            _resetStoryMode = value;
            //Debug.Log("Reset story mode here");
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
    public static int AcquiredStars
    {
        get => _acquiredStars;
        set
        {
            _acquiredStars = value;
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
            PlayerPrefs.SetInt("LifetimeStars", LifetimeStars);
            //PlayerPrefs.Save();
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

        QualitySettings.vSyncCount = 0;
        Application.targetFrameRate = 60;

        if (_debugMode)
        {
            Camera.main.GetComponent<AudioSource>().Stop();
            DoTutorial = false;
        }

        _currentStageDialogue = StageDialogues[0]; // temp
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
        DoTutorial = PlayerPrefs.GetInt("DoTutorial", 1) == 0 ? false : true;
        _isAudioEnabled = PlayerPrefs.GetInt("IsAudioEnabled", 1) == 0 ? false : true;
        _isMusicEnabled = PlayerPrefs.GetInt("IsMusicEnabled", 1) == 0 ? false : true;
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
        _acquiredStars = 0;
        _bonusStarLevel = 0;
        _tileAlpha = 1f;
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
        _currentStageDialogue = StageDialogues[0]; // temp

        if (DoTutorial)
        {
            _tileColorHue = 0.552778f;
            _requiredStars = 1;
            _stageLength = 30;
        }
        else
        {
            _tileColorHue = Mathf.Clamp(Random.Range(0f, 1f), 0.1f, 0.9f);
            //_requiredStars = Mathf.Clamp(Random.Range(0, _lifetimeStars % 20), 1, 3);
            _requiredStars = 1;
            _stageLength = _requiredStars * 60;
        }
        OnSetupNextStage?.Invoke();
    }

    public void EndStage()
    {
        IsStageOver = false;
        PlayerPrefs.Save();
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