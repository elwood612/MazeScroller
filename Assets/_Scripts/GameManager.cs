using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    #region Variables
    [SerializeField] private GM_Settings _settings;
    [SerializeField] private GameObject _runnerPrefab;
    [SerializeField] private bool _debugMode;
    public List<StageParameters> Parameters;

    private AnimationCurve _tileSpeedCurve;
    private AnimationCurve _runnerSpeedCurve;
    private AnimationCurve _tileSpawnerWidthCurve;
    private float _defaultSpeed = 1f;
    private float _averageSpeed;
    private int _counterAverageSpeed = 0;
    private int _counterTransitionBonusIncrease = 0;
    private int _triggerCounters = 30;
    private WaitForSeconds _bonusShortDelay = new WaitForSeconds(2f);
    private WaitForSeconds _bonusLongDelay = new WaitForSeconds(10f);
    private bool _startOfGame = true;
    private Queue<float> _rollingSpeedAverage = new Queue<float>();
    private int _rollingSpeedAverageMaxCount = 40;
    private static float _maxSpeed = 50f;
    private static float _tileLength;
    private static float _speedMultiplier = 1f;
    private static int _currentStage = -1; // so that we start off by incrementing to 0
    private static int _stageProgress;
    private static int _stageLength = 100;
    private static int _transitionProgress;
    private static int _transitionLength = 20;
    private static int _score = 0;
    private static int _loseCounter = 0;
    private static int _tileBonus = 100;
    private static int _speedBonus = 100;
    private static Vector3 _tileSpeed = Vector3.zero;
    private static Vector3 _boardLength;
    private static bool _canIncreaseTileBonus = false;
    private static bool _canIncreaseSpeedBonus = false;

    public static GameState CurrentState;
    public static event Action<GameState> OnStateChanged;
    public static event Action<int> OnSetupNextStage;
    public static event Action<int> OnScoreChanged;
    public static event Action<int> OnStageChanged;
    public static event Action<int> OnTileBonusChanged;
    public static event Action<int> OnSpeedBonusChanged;
    public static event Action<int> OnLoseCounterChanged;

    public static GameManager Instance;
    public static float HighestDrawnRowHeight;
    public static float RunnerHeight;
    public static int NumberOfRows;

    public static float TileLength => _tileLength;
    public static Vector3 BoardLength => _boardLength;
    public static float TileSpeed => Mathf.Abs(_tileSpeed.z);
    public AnimationCurve RunnerSpeedCurve => _runnerSpeedCurve;
    public AnimationCurve TileSpawnerWidthCurve => _tileSpawnerWidthCurve;
    public static int StageLength => _stageLength;
    public static float MaxSpeed => _maxSpeed;
    public static int CurrentStage => _currentStage;
    public static int StageProgress => _stageProgress;
    public static int TransitionProgress => _transitionProgress;
    public static int TileBonus => _tileBonus;
    public static int SpeedBonus => _speedBonus;
    public static int LoseCounter => _loseCounter;
    public static int Score
    {
        get => _score;
        set
        {
            _score = value + _tileBonus / 5 + _speedBonus / 5;
            OnScoreChanged?.Invoke(value);
        }
    }
    private float _minSpeed => Parameters[_currentStage].MinSpeed;
    #endregion

    #region Initialization
    private void Awake()
    {
        if (Instance == null) { Instance = this; }
        else { Destroy(this); }

        _tileSpeedCurve = _settings.TileSpeedCurve;
        _runnerSpeedCurve = _settings.RunnerSpeedCurve;
        _tileSpawnerWidthCurve = _settings.TileSpawnerWidthCurve;
        _tileLength = GameObject.FindGameObjectWithTag("Tile").GetComponent<BoxCollider>().bounds.size.x;

        if (_debugMode)
        {
            Camera.main.GetComponent<AudioSource>().Stop();
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

        if (CurrentState == GameState.Transition)
        {
            if (++_counterTransitionBonusIncrease > _triggerCounters)
            {
                _counterTransitionBonusIncrease = 0;
                IncreaseSpeedBonus(5);
                IncreaseTileBonus(5);
            }
        }

        if (CurrentState == GameState.Progressing) 
        {
            if (_debugMode) { return; }

            if (++_counterAverageSpeed > _triggerCounters)
            {
                _counterAverageSpeed = 0;
                CalculateSpeedAverage();

                if (_loseCounter > 100) 
                { 
                    Debug.Log("You lose!"); 
                }

                if (_speedBonus < 100 && _tileBonus < 100)
                {
                    _loseCounter++;
                    OnLoseCounterChanged?.Invoke(_loseCounter);
                }
                else if (_speedBonus < 10 || _tileBonus < 10)
                {
                    _loseCounter++;
                    OnLoseCounterChanged?.Invoke(_loseCounter);
                }
                else
                {
                    _loseCounter = 0;
                    OnLoseCounterChanged?.Invoke(_loseCounter);
                }
            }
        }
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

    private void CalculateSpeedAverage()
    {
        _rollingSpeedAverage.Enqueue(TileSpeed);
        if (_rollingSpeedAverage.Count > _rollingSpeedAverageMaxCount) { _rollingSpeedAverage.Dequeue(); }
        _averageSpeed = _rollingSpeedAverage.Average();

        if (_averageSpeed > _minSpeed) 
        { 
            IncreaseSpeedBonus(Mathf.CeilToInt((_averageSpeed - _minSpeed) / 4f)); 
        }
        else
        {
            DecreaseSpeedBonus(1, Mathf.FloorToInt(_averageSpeed * 100 / _minSpeed));
        }

        //Debug.Log("Average speed = " + _averageSpeed);
    }

    private void CalculateBoardLength()
    {
        _boardLength = new Vector3(0, 0, _tileLength * NumberOfRows);
    }

    private void OnDestroy()
    {
        if (Instance == this) { Instance = null; }
    }

    private IEnumerator BonusRecovery(WaitForSeconds delay, int x)
    {
        yield return delay;
        if (x == 0) { _canIncreaseTileBonus = true; }
        else if (x == 1) { _canIncreaseSpeedBonus = true; }
    }

    private void SetupNextStage()
    {
        _currentStage++;
        OnSetupNextStage?.Invoke(_currentStage);
        if (_currentStage >= Parameters.Count)
        {
            StageParameters newStage = ScriptableObject.CreateInstance<StageParameters>();
            Parameters.Add(newStage);
        }
        _bonusShortDelay = new WaitForSeconds(Parameters[_currentStage].BonusRecoveryTime);
        _bonusLongDelay = new WaitForSeconds(Parameters[_currentStage].BonusRecoveryTime * 4);
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
                OnLoseCounterChanged?.Invoke(0);
                break;
            case GameState.Progressing:
                //OnStageChanged?.Invoke(_currentStage);
                break;
            case GameState.Lose:
                CalculateBoardSpeed(0);
                break;
        }
        OnStateChanged?.Invoke(newState);
    }

    public void IncreaseTileBonus(int value)
    {
        if (_canIncreaseTileBonus)
        {
            _tileBonus = Mathf.Min(_tileBonus + value, 100);
            OnTileBonusChanged?.Invoke(_tileBonus);
        }
    }

    public void DecreaseTileBonus(int value)
    {
        if (value == 100)
        {
            StopCoroutine(BonusRecovery(_bonusLongDelay, 0));
            StartCoroutine(BonusRecovery(_bonusLongDelay, 0));
        }
        else
        {
            StopCoroutine(BonusRecovery(_bonusShortDelay, 0));
            StartCoroutine(BonusRecovery(_bonusShortDelay, 0));
        }

        _canIncreaseTileBonus = false;
        _tileBonus = Mathf.Max(_tileBonus - value, 0);
        OnTileBonusChanged?.Invoke(_tileBonus);
    }

    public void IncreaseSpeedBonus(int value)
    {
        if (_canIncreaseSpeedBonus)
        {
            _speedBonus = Mathf.Min(_speedBonus + value, 100);
            OnSpeedBonusChanged?.Invoke(_speedBonus);
        }
    }

    public void DecreaseSpeedBonus(int value, int floor = 0)
    {
        if (value == 100)
        {
            StopCoroutine(BonusRecovery(_bonusLongDelay, 1));
            StartCoroutine(BonusRecovery(_bonusLongDelay, 1));
            _rollingSpeedAverage.Clear(); // reset averages
        }
        else
        {
            StopCoroutine(BonusRecovery(_bonusShortDelay, 1));
            StartCoroutine(BonusRecovery(_bonusShortDelay, 1));
        }

        _canIncreaseSpeedBonus = false;
        _speedBonus = Mathf.Max(_speedBonus - value, Mathf.Min(_speedBonus, floor)); // this logic prevents accidentally increasing the bonus from here
        OnSpeedBonusChanged?.Invoke(_speedBonus);
    }

    public static void Progress()
    {
        if (CurrentState == GameState.Transition)
        {
            if (_transitionProgress < _transitionLength)
            {
                _transitionProgress++;
            }
            else
            {
                _transitionProgress = 0;
                Debug.Log("Transition phase ending");
                Instance.UpdateGameState(GameState.Progressing);
            }
        }
        else if (CurrentState == GameState.Progressing)
        {
            if (_stageProgress < Instance.Parameters[_currentStage].StageLength)
            {
                _stageProgress++;
                //OnProgressChanged?.Invoke(_stageProgress);
            }
            else
            {
                _stageProgress = 0;
                Instance.UpdateGameState(GameState.Transition);
            }
        }
    }

    public void SpawnPlayer(Transform tile)
    {
        Instantiate(_runnerPrefab, tile.position, Quaternion.identity);
        _startOfGame = false;
    }

    public static void AddBoardMotion(Transform t)
    {
        t.Translate(_tileSpeed * Time.deltaTime);
    }

    public static bool CompareVectors(Vector3 v1, Vector3 v2)
    {
        return Vector3Int.RoundToInt(v1) == Vector3Int.RoundToInt(v2);
    }
}