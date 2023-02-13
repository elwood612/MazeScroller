using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;

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
        else if (other.CompareTag("RowQA")) { CheckRow(); }
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
        GameManager.Progress++;
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
        bool isColor = false;

        foreach (Tile t in _enabledTiles)
        {
            if (t.IsColored) { isColor = true; }
            if (t.GetNeighborTile(Vector3.forward).IsEnabled && t.GetNeighborTile(Vector3.back).IsEnabled)
            {
                canPathThrough = true;
                if (!t.IsColored) { canPathAroundColor = true; }
            }
            if (t.DisallowCrystal() && t.AttachedCrystal != null) { t.RemoveCrystal(); }
        }

        // temporary
        foreach (Tile t in GetComponentsInChildren<Tile>())
        {
            if (!canPathThrough && !_enabledTiles.Contains(t)) { t.SpawnTile(); }
            if (!canPathAroundColor && isColor && _enabledTiles.Contains(t)) { t.SetAsColored(false); }
        }
    }
}
