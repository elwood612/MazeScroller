using System;
using System.Collections.Generic;
using UnityEngine;

public class Row : MonoBehaviour
{
    private bool _isHighestDrawnRow;
    private bool _hasSetupBeenRun = false;
    private static bool _endTutorial = false;
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

    private void OnEnable()
    {
        GameManager.OnStarGained += EndTutorial;
        GameManager.OnSetupNextStage += ResetTutorial;
    }

    private void OnDisable()
    {
        GameManager.OnStarGained -= EndTutorial;
        GameManager.OnSetupNextStage -= ResetTutorial;
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
            if (_hasSetupBeenRun && _endTutorial)
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
        if (GameManager.CurrentState == GameState.Transition) { return; }

        bool canPathThrough = false;
        bool canPathAroundColor = false;
        bool isBoxedInByColor = true;
        bool isAColor = false;

        foreach (Tile t in _enabledTiles)
        {
            if (t.IsColored) { isAColor = true; }
            if (t.GetNeighborTile(Vector3.forward).IsEnabled && t.GetNeighborTile(Vector3.back).IsEnabled)
            {
                canPathThrough = true;
                if (!t.IsColored) { canPathAroundColor = true; }
            }
            if (t.DisallowCrystal() && t.AttachedCrystal != null) { t.RemoveCrystal(); }

            int paths = 0;
            int blockedPaths = 0;
            foreach (Tile neighbor in t.NeighborTiles)
            {
                if (!t.IsEnabled) { continue; }
                paths++;
                if (neighbor.IsColored)
                {
                    blockedPaths++;
                }
            }
            if (paths > blockedPaths) { isBoxedInByColor = false; }
        }

        foreach (Tile t in GetComponentsInChildren<Tile>())
        {
            if (!canPathThrough && !t.IsEnabled) { t.SpawnTile(); } // this is currently overkill
            if (!canPathAroundColor && isAColor && t.IsEnabled) { t.SetAsColored(false); }
            if (isBoxedInByColor && isAColor && t.IsEnabled) { t.SetAsColored(false); }
        }
    }

    private void EndTutorial(int unused) 
    {
        if (!_endTutorial)
        {
            _endTutorial = true;
        }
    }

    private void ResetTutorial()
    {
        _endTutorial = !GameManager.DoTutorial;
    }
}
