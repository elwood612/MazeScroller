using System;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    [SerializeField] private GM_Settings _settings;
    [SerializeField] private GameObject _runnerPrefab;
    [SerializeField] private int _startingInstability;

    private AnimationCurve _tileSpeedCurve;
    private AnimationCurve _runnerSpeedCurve;
    private AnimationCurve _tileSpawnerWidthCurve;
    private static Vector3 _tileSpeed = Vector3.zero;
    private static Vector3 _boardLength;
    private float _defaultSpeed = 1f;
    private float _minSpeed = 0.5f;
    private static float _maxSpeed = 50f;
    
    private static float _tileLength;
    private static float _speedMultiplier = 1f;
    private static int _instability;
    private static int _maxInstability = 1000;

    public static GameState CurrentState;
    public static event Action<GameState> OnStateChanged;
    public static event Action<int> OnInstabilityChanged;
    public static GameManager Instance;
    public static float HighestDrawnRowHeight;
    
    public static int NumberOfRows;
    public static float TileLength => _tileLength;
    public static Vector3 BoardLength => _boardLength;
    public static float TileSpeed => Mathf.Abs(_tileSpeed.z);
    public AnimationCurve RunnerSpeedCurve => _runnerSpeedCurve;
    public AnimationCurve TileSpawnerWidthCurve => _tileSpawnerWidthCurve;
    public static int MaxInstability => _maxInstability;
    public static float MaxSpeed => _maxSpeed;
    public static int Instability
    {
        get => _instability;
        set 
        { 
            _instability = value; 
            OnInstabilityChanged?.Invoke(value); 
        }
    }


    private void Awake()
    {
        if (Instance == null) { Instance = this; }
        else { Destroy(this); }

        Instability = _startingInstability;
        _tileSpeedCurve = _settings.TileSpeedCurve;
        _runnerSpeedCurve = _settings.RunnerSpeedCurve;
        _tileSpawnerWidthCurve = _settings.TileSpawnerWidthCurve;
        _tileLength = GameObject.FindGameObjectWithTag("Tile").GetComponent<BoxCollider>().bounds.size.x;

        //Time.timeScale = 0.25f; // DEBUG
    }

    private void Start()
    {
        UpdateGameState(GameState.Setup);
    }

    private void Update()
    {
        if (CurrentState == GameState.Idle || CurrentState == GameState.Running) 
        { 
            CalculateBoardSpeed(_speedMultiplier);
        }
    }

    private void CalculateBoardSpeed(float multiplier)
    {
        float heightCurve = Mathf.Clamp(_tileSpeedCurve.Evaluate(HighestDrawnRowHeight), _minSpeed, _maxSpeed);
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
            case GameState.Idle:
                break;
            case GameState.Running:
                break;
            case GameState.Lose:
                CalculateBoardSpeed(0);
                break;
        }
        OnStateChanged?.Invoke(newState);
    }

    public void SpawnPlayer(Transform tile)
    {
        Instantiate(_runnerPrefab, tile.position, Quaternion.identity);
    }

    public static void AddBoardMotion(Transform t)
    {
        t.Translate(_tileSpeed * Time.deltaTime);
    }
}