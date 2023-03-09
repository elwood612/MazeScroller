using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    #region Variables
    [SerializeField] private GM_Settings _settings;
    [SerializeField] private GameObject _runnerPrefab;
    [SerializeField] private bool _debugMode;
    [SerializeField] private bool _demoMode;
    public List<StageParameters> Parameters;

    private AnimationCurve _tileSpeedCurve;
    private AnimationCurve _runnerSpeedCurve;
    private AnimationCurve _runnerTransitionCurve;
    private AnimationCurve _tileSpawnerWidthCurve;
    private GameObject _currentRunner;
    private float _defaultSpeed = 1f;
    private float _averageSpeed;
    private int _counterAverageSpeed = 0;
    private int _counterTransitionBonusIncrease = 0;
    private int _triggerCounters = 30;
    private int _speedBonus = 0;
    private WaitForSeconds _bonusDelay = new WaitForSeconds(1f);
    private WaitForSeconds _bonusStep = new WaitForSeconds(0.5f);
    private bool _startOfGame = true;
    private bool _decreaseSpeedBonus = true;
    private bool _triggerBonusStep = true;
    private Queue<float> _rollingSpeedAverage = new Queue<float>();
    private int _rollingSpeedAverageMaxCount = 40;
    private static float _maxSpeed = 50f;
    private static float _tileLength;
    private static float _speedMultiplier = 1f;
    private static int _currentStage = -1; // so that we start off by incrementing to 0
    private static int _stageProgress;
    private static int _stageLength = 100;
    private static int _transitionProgress;
    private static int _transitionLength = 30;
    private static int _score = 0;
    private static int _stars = 0;
    private static int _loseCounter = 0;
    
    private static Vector3 _tileSpeed = Vector3.zero;
    private static Vector3 _transitionSpeed = new Vector3(0, 0, -40);
    private static Vector3 _boardLength;

    public static GameState CurrentState;
    public static event Action<GameState> OnStateChanged;
    public static event Action<int> OnSetupNextStage;
    public static event Action<int> OnScoreChanged;
    public static event Action<int> OnSpeedBonusChanged;
    public static event Action<int> OnLoseCounterChanged;
    public static event Action OnStageEnd;
    public static event Action<Dialogue> OnDialogueStart;
    public static event Action<GameObject> OnRunnerSpawned;
    public static event Action OnStarGained;

    public static GameManager Instance;
    public static float HighestDrawnRowHeight;
    public static float RunnerHeight;
    public static int NumberOfRows;
    public static bool IsRunnerInTransition = false;
    //private float _minSpeed => Parameters[_currentStage].MinSpeed;

    public GameObject CurrentRunner => _currentRunner;
    public static float TileLength => _tileLength;
    public static Vector3 BoardLength => _boardLength;
    public static float TileSpeed => Mathf.Abs(_tileSpeed.z);
    public AnimationCurve RunnerSpeedCurve => _runnerSpeedCurve;
    public AnimationCurve RunnerTransitionCurve => _runnerTransitionCurve;
    public AnimationCurve TileSpawnerWidthCurve => _tileSpawnerWidthCurve;
    public static int StageLength => _stageLength;
    public static float MaxSpeed => _maxSpeed;
    public static int CurrentStage => _currentStage;
    public static int TransitionProgress => _transitionProgress;
    public static int LoseCounter => _loseCounter;
    public static int StageProgress
    {
        get => _stageProgress;
        set
        {
            if (CurrentState == GameState.Progressing)
            {
                if (_stageProgress < Instance.Parameters[_currentStage].StageLength)
                {
                    _stageProgress = value;
                }
                else
                {
                    _stageProgress = 0;
                    Instance.UpdateGameState(GameState.Transition);
                }
            }
        }
    }
    public static int Score
    {
        get => _score;
        set
        {
            _score = value + Mathf.RoundToInt(Instance._speedBonus / 20);
            OnScoreChanged?.Invoke(value);
        }
    }
    public int SpeedBonus
    {
        get => _speedBonus;
        set
        {
            if (value > _speedBonus)
            {
                //Debug.Log("Bonus = " + _speedBonus);
                ResetCoroutines();
                StartCoroutine(BonusDelay());
            }
            _speedBonus = value;
            OnSpeedBonusChanged?.Invoke(value);
            if (_speedBonus > 100 * (_stars + 1))
            {
                AcquiredStars++;
            }
        }
    }
    public static int AcquiredStars
    {
        get => _stars;
        set
        {
            _stars = value;
            OnStarGained?.Invoke();
        }
    }
    #endregion

    #region Initialization
    private void Awake()
    {
        if (Instance == null) { Instance = this; }
        else { Destroy(this); }

        _tileSpeedCurve = _settings.TileSpeedCurve;
        _runnerSpeedCurve = _settings.RunnerSpeedCurve;
        _runnerTransitionCurve = _settings.RunnerTransitionCurve;
        _tileSpawnerWidthCurve = _settings.TileSpawnerWidthCurve;
        _tileLength = GameObject.FindGameObjectWithTag("Tile").GetComponent<BoxCollider>().bounds.size.x;

        QualitySettings.vSyncCount = 0;
        Application.targetFrameRate = 60;

        if (_debugMode)
        {
            Camera.main.GetComponent<AudioSource>().Stop();
        }
        if (_demoMode)
        {
            _currentStage = 0;
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

        if (_decreaseSpeedBonus && _triggerBonusStep) { StartCoroutine(BonusDecrease()); }
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

    private void SetupNextStage()
    {
        if (!_demoMode) { _currentStage++; }
        OnSetupNextStage?.Invoke(_currentStage);
        if (_currentStage >= Parameters.Count)
        {
            StageParameters newStage = ScriptableObject.CreateInstance<StageParameters>();
            Parameters.Add(newStage);
        }
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
        SpeedBonus = SpeedBonus > _stars * 100 ? SpeedBonus - 1 : _stars * 100;
        _triggerBonusStep = true;
    }

    private void ResetCoroutines()
    {
        StopAllCoroutines();
        _triggerBonusStep = true;
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
                SetupNextStage();
                break;
            case GameState.Progressing:
                Score = 0;
                _stars = 0;
                break;
            case GameState.Lose:
                CalculateBoardSpeed(0);
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

    public void GoodToBeginDialogue()
    {
        if (Parameters[_currentStage].AssociatedDialogue != null)
        {
            OnDialogueStart?.Invoke(Parameters[_currentStage].AssociatedDialogue);
        }
        else
        {
            if (CurrentState == GameState.Transition) { UpdateGameState(GameState.Progressing); }
        }
    }

    public void EndStage()
    {
        if (Parameters[_currentStage].AssociatedDialogue != null)
        {
            OnDialogueStart?.Invoke(Parameters[_currentStage].AssociatedDialogue);
        }
        else
        {
            OnStageEnd?.Invoke();
        }
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