using System;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Tilemaps;

public class GameManager : MonoBehaviour
{
    [SerializeField] private int _debugSetNumberOfRows;
    [SerializeField][Range(0, 100)] private int _debugSetTileDestroyChance;
    [SerializeField] private GameObject _environment;

    private static Vector3 _tileSpeed = Vector3.zero;
    private static Vector3 _boardLength;
    private static float _tileLength;
    private static int _numberOfRows;
    private static int _tileDestroyedChance;
    private Queue<GameObject> _boardQueue = new Queue<GameObject>();

    public int DebugStartTilePosition;
    public GameState CurrentState;
    public static event Action<GameState> OnStateChanged;
    public static GameManager Instance;

    public static float TileLength => _tileLength;
    public static Vector3 BoardLength => _boardLength;
    public static int NumberOfRows => _numberOfRows;
    public static int TileDestroyedChance => _tileDestroyedChance;
    public static Vector3 TileSpeed => _tileSpeed;
    public Queue<GameObject> BoardQueue
    {
        get => _boardQueue;
        set => _boardQueue = value;
    }

    private void Awake()
    {
        if (Instance == null) { Instance = this; }
        else { Destroy(this); }

        _numberOfRows = _debugSetNumberOfRows;
        _tileDestroyedChance = _debugSetTileDestroyChance;
    }

    private void Start()
    {
        UpdateGameState(GameState.Setup);
    }

    private void Update()
    {
        //_environment.transform.Translate(_tileSpeed * Time.deltaTime);
    }

    public void UpdateGameState(GameState newState)
    {
        if (CurrentState == newState && newState != GameState.Setup) { return; } // avoids spamming events for no reason
        CurrentState = newState;

        switch (newState)
        {
            case GameState.Setup:
                SetSpeed(0);
                CalculateBoardLength();
                break;
            case GameState.Idle:
                SetSpeed(1);
                break;
            case GameState.Running:
                SetSpeed(3);
                break;
            case GameState.Lose:
                SetSpeed(0);
                break;
            
            default:
                break;
        }
        OnStateChanged?.Invoke(newState);
    }

    private void SetSpeed(float input)
    {
        _tileSpeed = new Vector3(0, 0, -input);
    }

    private void CalculateBoardLength()
    {
        _tileLength = GameObject.FindGameObjectWithTag("Tile").GetComponent<BoxCollider>().bounds.size.x;
        _boardLength = new Vector3(0, 0, _tileLength * _numberOfRows);
        //Debug.Log("Tile length = " + _tileLength + ", board length = " + _boardLength);
    }

    private void OnDestroy()
    {
        if (Instance == this) { Instance = null; }
    }
}