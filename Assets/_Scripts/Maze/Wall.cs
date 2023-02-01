using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class Wall : MonoBehaviour
{
    [SerializeField] LayerMask _tileLayer;
    private Renderer[] _renderers;
    private bool _isOnFirstRow = false;
    private bool _isBorder;
    private bool _isPath;
    private bool _isPathfindingPath;
    private bool _isHidden = false;
    private int _crossings = 0;
    private float _timeCrossed;
    private float _timeDrawn;
    private Row _firstRow;
    private List<Tile> _neighborTiles = new List<Tile>();

    public bool IsBorder => _isBorder;
    public bool IsPath => _isPath;
    public bool IsDestroyed => _isHidden;
    public int Crossings => _crossings;
    public float TimeDrawn => _timeDrawn;
    public float TimeCrossed => _timeCrossed;
    public bool IsPathfindingPath
    {
        get => _isPathfindingPath;
        set => _isPathfindingPath = value;
    }
    public bool IsOnFirstRow
    {
        get => _isOnFirstRow;
        set => _isOnFirstRow = value;
    }
    public Row FirstRow
    {
        get => _firstRow;
        set => _firstRow = value;
    }

    private void OnEnable()
    {
        //if (!_isOnFirstRow) { GenerateBoard.OnWallsSetup += Setup; }
    }

    private void OnDisable()
    {
        //if (!_isOnFirstRow) { GenerateBoard.OnWallsSetup -= Setup; }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player"))
        {
            PlayerCrossing();
        }
    }

    private void PlayerCrossing()
    {
        _crossings++;
        _timeCrossed = Time.timeSinceLevelLoad;
        if (_isPathfindingPath) { _isPathfindingPath = false; }
    }

    private void UpdateNeighborTiles()
    {
        foreach (Tile tile in _neighborTiles)
        {
            if (_isPath)
            {
                tile.NeighborPaths.Add(this);
            }
            else
            {
                if (tile.NeighborPaths.Contains(this)) { tile.NeighborPaths.Remove(this); }
            }
        }
    }

    public void SetWallAsBorder(bool startingTile = false)
    {
        _renderers[0].enabled = true;
        _isBorder = true;
        _isPath = false;
        if (!startingTile) { UpdateNeighborTiles(); }
    }

    public void SetWallAsPath()
    {
        _timeDrawn = Time.timeSinceLevelLoad;
        _renderers[0].enabled = false;
        _isBorder = false;
        _isPath = true;
        UpdateNeighborTiles();
    }

    public void ResetWall()
    {
        HideWall();
        _isBorder = false;
        _isPath = false;
        _isPathfindingPath = false;
        _isHidden = false;
        _crossings = 0;
    }

    public bool GoodToHide()
    {
        int destroy = _neighborTiles.Count;
        foreach (Tile tile in _neighborTiles)
        {
            if (tile.IsHidden) { destroy--; }
        }
        return destroy == 0;
    }

    // Good but need to account for first row edge case.
    // Also find a good time to call it as tiles get destroyed, because OnRowReset will NOT work
    public void HideWall() 
    {
        _renderers[0].enabled = false;
        _renderers[1].enabled = false;
        _isHidden = true;
    }

    public void UnhideWall()
    {
        _renderers[1].enabled = true;
        _isHidden = false;
    }

    public void Setup()
    {
        //ResetWall();
        _neighborTiles.Clear();
        foreach (Tile tile in GenerateBoard.AllTiles)
        {
            if (Vector3.Distance(tile.transform.position, transform.position) < (GameManager.TileLength / 2) + 0.5f)
            {
                _neighborTiles.Add(tile);
                if (tile.IsStartingTile) { SetWallAsBorder(true); }
            }
        }
        //HideWall();
    }

    public void Initialize()
    {
        _renderers = GetComponentsInChildren<Renderer>();
        HideWall();
    }

    private void Awake()
    {
        Initialize();
    }
}
