using System;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Tilemaps;
using UnityEngine.Windows;

public class GameManager : MonoBehaviour
{
    [SerializeField][Range(0, 100)] private int _debugSetTileDestroyChance;
    public int DebugStartTilePosition;

    private int _setNumberOfRows;
    private AnimationCurve _speedCurve;
    [SerializeField] private GM_Settings _settings;

    private static Vector3 _tileSpeed = Vector3.zero;
    private static Vector3 _boardLength;
    private float _defaultSpeed = 1f;
    private static float _speedMultiplier = 1f;
    private static float _highestRowPercentage;
    private static float _tileLength;
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
    public static float HighestDrawnRowHeight
    {
        get => _highestRowPercentage;
        set => _highestRowPercentage = value;
    }

    public static float SpeedMultiplier
    {
        get => _speedMultiplier;
        set => _speedMultiplier = value;
    }

    private void Awake()
    {
        if (Instance == null) { Instance = this; }
        else { Destroy(this); }

        _numberOfRows = _settings.NumberOfRows;
        _speedCurve = _settings.SpeedCurve;
        _tileDestroyedChance = _debugSetTileDestroyChance;
    }

    private void Start()
    {
        UpdateGameState(GameState.Setup);
    }

    private void Update()
    {
        if (CurrentState == GameState.Idle || CurrentState == GameState.Running) { CalculateSpeed(_speedMultiplier); }
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
                //CalculateSpeed(1);
                break;
            case GameState.Running:
                //CalculateSpeed(1);
                break;
            case GameState.Lose:
                CalculateSpeed(0);
                break;
            
            default:
                break;
        }
        OnStateChanged?.Invoke(newState);
    }

    private void SetSpeed(float input)
    {
        _tileSpeed = new Vector3(0, 0, -input * _defaultSpeed);
    }

    private void CalculateSpeed(float multiplier)
    {
        float heightCurve = _speedCurve.Evaluate(_highestRowPercentage);
        _tileSpeed = new Vector3(0, 0, -heightCurve * _defaultSpeed * multiplier);
        //SetSpeed(_defaultSpeed * mult);
        //Debug.Log("Mult = " + mult);
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