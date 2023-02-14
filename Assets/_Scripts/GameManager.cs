using System;
using System.Collections;
using Unity.VisualScripting.YamlDotNet.Core.Tokens;
using UnityEngine;
using UnityEngine.Pool;

public class GameManager : MonoBehaviour
{
    [SerializeField] private GM_Settings _settings;
    [SerializeField] private GameObject _runnerPrefab;
    [SerializeField] private bool _debugMode;

    private AnimationCurve _tileSpeedCurve;
    private AnimationCurve _runnerSpeedCurve;
    private AnimationCurve _tileSpawnerWidthCurve;
    private float _defaultSpeed = 1f;
    private float _minSpeed = 0.5f;
    private WaitForSeconds _bonusLongDelay = new WaitForSeconds(10f);
    private WaitForSeconds _bonusShortDelay = new WaitForSeconds(2f);
    private bool _startOfGame = true;
    private static int _transitionCounter = 0;
    private static float _maxSpeed = 50f;
    private static float _tileLength;
    private static float _speedMultiplier = 1f;
    private static int _progress;
    private static int _maxProgress = 400;
    private static int _score = 0;
    private static int _stage = 1;
    private static int _prevStage = 1;
    private static int _tileBonus = 20;
    private static int _speedBonus = 20;
    private static Vector3 _tileSpeed = Vector3.zero;
    private static Vector3 _boardLength;
    private static bool _isTileBonusDeactivated = false;
    private static bool _isSpeedBonusDeactivated = false;

    public static GameState CurrentState;
    public static event Action<GameState> OnStateChanged;
    public static event Action<int> OnProgressChanged;
    public static event Action<int> OnScoreChanged;
    public static event Action<int> OnStageChanged;
    public static event Action<int> OnTileBonusChanged;
    public static event Action<int> OnSpeedBonusChanged;

    public static GameManager Instance;
    public static float HighestDrawnRowHeight;
    public static float RunnerHeight;
    public static int NumberOfRows;
    
    public static float TileLength => _tileLength;
    public static Vector3 BoardLength => _boardLength;
    public static float TileSpeed => Mathf.Abs(_tileSpeed.z);
    public AnimationCurve RunnerSpeedCurve => _runnerSpeedCurve;
    public AnimationCurve TileSpawnerWidthCurve => _tileSpawnerWidthCurve;
    public static int MaxProgress => _maxProgress;
    public static float MaxSpeed => _maxSpeed;
    public static int Stage => _stage;
    public static int SpeedBonus => _speedBonus;
    public static int TileBonus => _tileBonus;
    public static int Progress
    {
        get => _progress;
        set 
        { 
            if (_progress < _maxProgress)
            {
                if (CurrentState == GameState.Transition) 
                { 
                    _transitionCounter++;
                    if (_transitionCounter > 10)
                    {
                        Instance.UpdateGameState(GameState.Progressing);
                        _transitionCounter = 0;
                    }
                }
                else
                {
                    _progress = value;
                    OnProgressChanged?.Invoke(value);
                }

                _stage = Mathf.CeilToInt(_progress * 4f / _maxProgress);
                if (_stage > _prevStage)
                {
                    _prevStage = _stage;
                    Instance.UpdateGameState(GameState.Transition);
                    OnStageChanged?.Invoke(_stage);
                }
            }
        }
    }
    public static int Score
    {
        get => _score;
        set
        {
            _score = value + _tileBonus / 5 + _speedBonus / 5;
            OnScoreChanged?.Invoke(value);
        }
    }

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

    private void Update()
    {
        if (CurrentState == GameState.Transition || CurrentState == GameState.Progressing) 
        { 
            CalculateBoardSpeed(_speedMultiplier);
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

    private void CalculateBoardLength()
    {
        _boardLength = new Vector3(0, 0, _tileLength * NumberOfRows);
    }

    private void OnDestroy()
    {
        if (Instance == this) { Instance = null; }
    }

    private IEnumerator ReduceTileBonus(WaitForSeconds delay)
    {
        Debug.Log("Can't increase tile bonus yet");
        yield return delay;
        _isTileBonusDeactivated = false;
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
                //Debug.Log("Transition");
                break;
            case GameState.Progressing:
                //Debug.Log("Progressing");
                break;
            case GameState.Lose:
                CalculateBoardSpeed(0);
                break;
        }
        OnStateChanged?.Invoke(newState);
    }

    // How this should work:
    // Spend too long on EITHER bonus at < 10, fail the stage
    // Spend too long on BOTH bonuses at < 100, fail the stage
    public void UpdateTileBonus(int amount)
    {
        if (amount < 0)
        {
            if (amount == 100)
            {
                StopCoroutine(ReduceTileBonus(_bonusLongDelay));
                StartCoroutine(ReduceTileBonus(_bonusLongDelay));
            }
            else
            {
                StopCoroutine(ReduceTileBonus(_bonusShortDelay));
                StartCoroutine(ReduceTileBonus(_bonusShortDelay));
            }
            
            _isTileBonusDeactivated = true;
            _tileBonus = amount >= _tileBonus ? 0 : _tileBonus - amount;
            OnTileBonusChanged?.Invoke(_tileBonus);
        }
        else
        {
            if (!_isTileBonusDeactivated)
            {
                _tileBonus += amount;
                OnTileBonusChanged?.Invoke(_tileBonus);
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