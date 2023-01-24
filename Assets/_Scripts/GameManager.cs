using System;
using System.Collections;
using UnityEngine;

public class GameManager : Singleton<GameManager>
{
    [SerializeField] private GameObject _environment;
    private Vector3 _speed = new Vector3(0, 0, -2);

    public GameState CurrentState;
    public static event Action<GameState> OnStateChanged;

    private void Start()
    {
        UpdateGameState(CurrentState);
    }

    private void Update()
    {
        _environment.transform.Translate(_speed * Time.deltaTime);
    }

    public void UpdateGameState(GameState newState)
    {
        CurrentState = newState;

        switch (newState)
        {
            case GameState.Setup:
                break;
            case GameState.Idle:
                break;
            case GameState.Running:
                break;
            case GameState.Lose:
                break;
            default:
                break;
        }

        OnStateChanged?.Invoke(newState);
    }
}

public enum GameState
{
    Setup,
    Idle,
    Running,
    Lose
}
