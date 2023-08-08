using System;
using System.Collections.Generic;
using UnityEngine;

public class Row : MonoBehaviour
{
    public bool _isHighestDrawnRow;
    private bool _hasSetupBeenRun = false;
    private static bool _firstEnabledRow = true;
    private List<Tile> _enabledTiles = new List<Tile>();

    public event Action OnRowReset;
    public event Action OnRowSetup;
    public event Action<float> OnRowTransition;
    public static event Action OnFirstRowsReady;

    public bool HasSetupBeenRun => _hasSetupBeenRun;
    public List<Tile> EnabledTiles
    {
        get => _enabledTiles;
        set => _enabledTiles = value;
    }
    public bool IsHighestDrawnRow
    {
        get => _isHighestDrawnRow;
        set => _isHighestDrawnRow = value;
    }

    private void Update()
    {
        GameManager.AddBoardMotion(transform);
        if (_isHighestDrawnRow) { GameManager.HighestDrawnRowHeight = CalculateHeight(); }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("RowReset")) { ResetRow(); }
        else if (other.CompareTag("RowSetup")) { SetupRow(); }
        else if (other.CompareTag("RowQA")) 
        { 
            CheckRow();
            if (_hasSetupBeenRun && !GameManager.IsTutorialOngoing)
            {
                GameManager.StageProgress++;
            }
        }
    }

    private float CalculateHeight()
    {
        Vector3 screenPos = Camera.main.WorldToScreenPoint(transform.position);
        return screenPos.y / Screen.height;
    }

    private void ResetRow()
    {
        transform.position += GameManager.BoardLength;
        if (_firstEnabledRow && _hasSetupBeenRun)
        {
            _firstEnabledRow = false;
            OnFirstRowsReady?.Invoke();
        }
        _isHighestDrawnRow = false;
        _enabledTiles.Clear();
        OnRowReset?.Invoke();
    }

    private void SetupRow()
    {
        if (!_hasSetupBeenRun) 
        {
            OnRowSetup?.Invoke();
            _hasSetupBeenRun = true;
        }
        if (GameManager.CurrentState == GameState.Transition)
        {
            OnRowTransition?.Invoke(1f);
        }
    }

    private void CheckRow()
    {
        foreach (Tile t in _enabledTiles)
        {
            Tile tMinus = t.GetNeighborTile(Vector3.back);
            if (tMinus != null && !tMinus.IsEnabled && t.IsMiddleTile && !t.IsStartingTile)
            {
                Debug.Log("Fixing a hole!");
                tMinus.SpawnTile();
                if (tMinus.IsCharged && GameManager.CurrentState == GameState.Transition)
                {
                    Debug.Log("Removing rogue charge!");
                    tMinus.SetAsCharged(false);
                }
            }
            if (t.IsPreTransitionTile) { t.SetAlpha(0.1f); }
        }        
    }
}
