using System;
using System.Collections.Generic;
using UnityEngine;

public class Row : MonoBehaviour
{
    private bool _isHighestDrawnRow;
    private bool _hasSetupBeenRun = false;
    private List<Tile> _enabledTiles = new List<Tile>();

    public event Action OnRowReset;
    public event Action OnRowSetup;

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
            if (_hasSetupBeenRun) { GameManager.Progress(); }
        }
        //else if (other.CompareTag("TileSpawner") && _hasSetupBeenRun) { GameManager.Progress(); }
    }

    private float CalculateHeight()
    {
        Vector3 screenPos = Camera.main.WorldToScreenPoint(transform.position);
        return screenPos.y / Screen.height;
    }

    private void ResetRow()
    {
        transform.position += GameManager.BoardLength;
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
            //if (t.IsColored && t.GetNeighborTile(Vector3.right).NeighborPaths.Count == 1) { t.SetAsColored(false); }
            //if (t.IsColored && t.GetNeighborTile(Vector3.left).NeighborPaths.Count == 1) { t.SetAsColored(false); }
        }
    }
}
