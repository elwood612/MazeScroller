using System;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    [SerializeField] private GM_Settings _settings;
    [SerializeField] private GameObject _runnerPrefab;

    private AnimationCurve _tileSpeedCurve;
    private AnimationCurve _runnerSpeedCurve;
    private static Vector3 _tileSpeed = Vector3.zero;
    private static Vector3 _boardLength;
    private float _defaultSpeed = 1f;
    private static float _tileLength;
    private static float _speedMultiplier = 1f;
    private static float _highestDrawnRowHeight;
    private static int _numberOfRows;

    public static GameState CurrentState;
    public static event Action<GameState> OnStateChanged;
    public static GameManager Instance;
    public static float TileLength => _tileLength;
    public static Vector3 BoardLength => _boardLength;
    public AnimationCurve RunnerSpeedCurve => _runnerSpeedCurve;
    public static float HighestDrawnRowHeight
    {
        get => _highestDrawnRowHeight;
        set => _highestDrawnRowHeight = value;
    }
    public static int NumberOfRows
    {
        get => _numberOfRows;
        set => _numberOfRows = value;
    }

    private void Awake()
    {
        if (Instance == null) { Instance = this; }
        else { Destroy(this); }

        _tileSpeedCurve = _settings.TileSpeedCurve;
        _runnerSpeedCurve = _settings.RunnerSpeedCurve;
        _tileLength = GameObject.FindGameObjectWithTag("Tile").GetComponent<BoxCollider>().bounds.size.x;
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
        float heightCurve = _tileSpeedCurve.Evaluate(HighestDrawnRowHeight);
        _tileSpeed = new Vector3(0, 0, -heightCurve * _defaultSpeed * multiplier);
    }

    private void CalculateBoardLength()
    {
        _boardLength = new Vector3(0, 0, _tileLength * _numberOfRows);
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