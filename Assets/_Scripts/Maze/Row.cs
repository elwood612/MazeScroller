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
    public bool IsHighestDrawnRow
    {
        get => _isHighestDrawnRow;
        set => _isHighestDrawnRow = value;
    }
    public bool ShouldDisableRandomTiles
    {
        get => _shouldDisableRandomTiles;
        set => _shouldDisableRandomTiles = value;
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
        else if (other.CompareTag("TileSpawner")) { StartCoroutine(DisableRandomTiles()); }
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
        if (_hasSetupBeenRun) { return; }
        OnRowSetup?.Invoke();
        _hasSetupBeenRun = true;
    }

    private IEnumerator DisableRandomTiles()
    {
        yield return null;
        if (!_shouldDisableRandomTiles) { yield break; }

        foreach (Tile tile in GetComponentsInChildren<Tile>())
        {
            if (!tile.IsEnabled) { continue; }
            _enabledTiles.Add(tile);
        }
        int index = Random.Range(0, _enabledTiles.Count);
        _enabledTiles[index].DisableTile(true);
    }
}
