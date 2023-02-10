using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;

public class Row : MonoBehaviour
{
    private bool _isHighestDrawnRow;
    private bool _hasSetupBeenRun = false;
    private bool _shouldDisableRandomTiles = false;
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
}
