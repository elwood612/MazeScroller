using System;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    [SerializeField][Range(0, 100)] private int _debugSetTileDestroyChance;
    [SerializeField] private GM_Settings _settings;
    [SerializeField] private GameObject _runnerPrefab;
    public int DebugStartTilePosition;

    private AnimationCurve _tileSpeedCurve;
    private AnimationCurve _runnerSpeedCurve;
    private static Vector3 _tileSpeed = Vector3.zero;
    private static Vector3 _boardLength;
    private float _defaultSpeed = 1f;
    private static float _tileLength;
    private static float _speedMultiplier = 1f;
    private static float _highestDrawnRowHeight;
    private static int _numberOfRows;
    private static int _tileDestroyedChance;

    public static GameState CurrentState;
    public static event Action<GameState> OnStateChanged;
    public static GameManager Instance;
    public static float TileLength => _tileLength;
    public static Vector3 BoardLength => _boardLength;
    public static int NumberOfRows => _numberOfRows;
    public static int TileDestroyedChance => _tileDestroyedChance;
    public static Vector3 TileSpeed => _tileSpeed;
    public GameObject RunnerPrefab => _runnerPrefab;
    public AnimationCurve RunnerSpeedCurve => _runnerSpeedCurve;
    public static float HighestDrawnRowHeight
    {
        get => _highestDrawnRowHeight;
        set => _highestDrawnRowHeight = value;
    }

    private void Awake()
    {
        if (Instance == null) { Instance = this; }
        else { Destroy(this); }

        _numberOfRows = _settings.NumberOfRows;
        _tileSpeedCurve = _settings.TileSpeedCurve;
        _runnerSpeedCurve = _settings.RunnerSpeedCurve;
        _tileDestroyedChance = _debugSetTileDestroyChance;
    }

    private void Start()
    {
        UpdateGameState(GameState.Setup);
    }

    private void Update()
    {
        if (CurrentState == GameState.Idle || CurrentState == GameState.Running) 
        { 
            CalculateSpeed(_speedMultiplier); 
        }
    }

    public void UpdateGameState(GameState newState)
    {
        if (CurrentState == newState && newState != GameState.Setup) { return; } // avoids spamming events for no reason
        CurrentState = newState;

        switch (newState)
        {
            case GameState.Setup:
                CalculateSpeed(0);
                CalculateBoardLength();
                break;
            case GameState.Idle:
                break;
            case GameState.Running:
                break;
            case GameState.Lose:
                CalculateSpeed(0);
                break;
            
            default:
                break;
        }
        OnStateChanged?.Invoke(newState);
    }

    public static void AddBoardMotion(Transform t)
    {
        t.Translate(_tileSpeed * Time.deltaTime);
    }

    private void CalculateSpeed(float multiplier)
    {
        float heightCurve = _tileSpeedCurve.Evaluate(HighestDrawnRowHeight);
        _tileSpeed = new Vector3(0, 0, -heightCurve * _defaultSpeed * multiplier);
    }

    private void CalculateBoardLength()
    {
        _tileLength = GameObject.FindGameObjectWithTag("Tile").GetComponent<BoxCollider>().bounds.size.x;
        _boardLength = new Vector3(0, 0, _tileLength * _numberOfRows);
    }

    private void OnDestroy()
    {
        if (Instance == this) { Instance = null; }
    }
}