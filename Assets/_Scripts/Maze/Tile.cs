using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tile : MonoBehaviour
{
    public bool tempCheckMark = false;
    [SerializeField] private Material _tileBase;
    [SerializeField] private Material _tileDrawn;
    [SerializeField] private Material[] _tileCrossing;
    [SerializeField] private LayerMask _wallLayer;

    private Renderer _renderer;
    private Row _parentRow;
    private Row _firstRow;
    private List<Wall> _neighborWalls = new List<Wall>();
    private List<Wall> _neighborPaths = new List<Wall>();
    private List<Tile> _neighborTiles = new List<Tile>();
    private bool _isStartingTile = false;
    private bool _isOnLastRow = false;
    private bool _isPartOfMaze = false;
    private bool _isHidden = false;
    private bool _hasCrystal = false;
    private int _crossings = 0;
    public Tile _pathfindingParent;

    public List<Wall> NeighborWalls => _neighborWalls;
    public bool IsPartOfMaze => _isPartOfMaze;
    public bool IsHidden => _isHidden;
    public bool HasCrystal => _hasCrystal;
    public int Crossings => _crossings;
    public Row ParentRow => _parentRow;
    public Row FirstRow
    {
        get => _firstRow;
        set => _firstRow = value;
    }
    public bool IsStartingTile
    {
        get => _isStartingTile;
        set => _isStartingTile = value;
    }
    public bool IsOnLastRow
    {
        get => _isOnLastRow;
        set => _isOnLastRow = value;
    }
    public List<Wall> NeighborPaths
    {
        get => _neighborPaths;
        set => _neighborPaths = value;
    }
    public Tile PathfindingParent
    {
        get => _pathfindingParent;
        set => _pathfindingParent = value;
    }

    private void OnEnable()
    {
        //if (!_isOnLastRow) { GenerateBoard.OnTilesSetup += Setup; }
        if (_parentRow != null) { _parentRow.OnRowReset += ResetTile; }
    }

    private void OnDisable()
    {
        //if (!_isOnLastRow) { GenerateBoard.OnTilesSetup -= Setup; }
        if (_parentRow != null) { _parentRow.OnRowReset -= ResetTile; }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player"))
        {
            PlayerCrossing(other.GetComponent<IRunner>());
        }
    }

    private void PlayerCrossing(IRunner runner)
    {
        if (_crossings < _tileCrossing.Length && !_isStartingTile)
        {
            SetMaterial(_tileCrossing[_crossings]);
        }
        _crossings++;
        
        runner.PreviousTile = runner.CurrentTile;
        runner.CurrentTile = this;
        runner.CalculateNextTargetWrapper(this);
    }

    private void Unhide()
    {
        _renderer.enabled = true;
        _isHidden = false;
    }

    private void SetMaterial(Material material)
    {
        _renderer.material = material;
    }   

    // Used for the last row, can't set it up until the first row gets reset
    private IEnumerator DelayedSetup()
    {
        yield return new WaitForSeconds(1f);
        Setup();
    }

    public void DelayedSetupWrapper()
    {
        StartCoroutine(DelayedSetup());
    }

    public void AddTileToMaze()
    {
        if (!_isPartOfMaze)
        {
            _isPartOfMaze = true;
            SetMaterial(_tileDrawn);
        }
    }

    public void RemoveTileFromMaze()
    {
        if (_isPartOfMaze)
        {
            _isPartOfMaze = false;
            SetMaterial(_tileBase);
        }
    }

    // To make these new versions work:
    // Need to delay setup at least until the row behind has been reset
    // Can do a new setup everytime the row gets reset
    // Probably time to implement those trigger areas for spawning
    public Tile GetNeighborTile(Vector3 direction)
    {
        foreach (Collider collider in Physics.OverlapSphere(transform.position + direction.normalized * GameManager.TileLength, 1f))
        {
            if (collider.CompareTag("Tile"))
            {
                return collider.GetComponent<Tile>();
            }
        }

        return null;
    }

    public Wall GetWallBetween(Tile other)
    {
        foreach (Collider collider in Physics.OverlapSphere((transform.position + other.transform.position) / 2, 1f, _wallLayer))
        {
            if (collider.CompareTag("Wall"))
            {
                return collider.GetComponent<Wall>();
            }
        }
        return null;
    }

    public void HideTile()
    {
        _renderer.enabled = false;
        _isHidden = true;
    }

    public void UnhideTile()
    {
        if (_renderer != null) { _renderer.enabled = true; }
        _isHidden = false;
    }

    public void SetStartingTile()
    {
        _isStartingTile = true;
        if (_isHidden) { Unhide(); }
        AddTileToMaze();
        _parentRow.IsHighestDrawnRow = true;
        DrawMaze.HighestDrawnRow = _parentRow;
    }

    public void ResetTile()
    {
        _crossings = 0;
        RemoveTileFromMaze();
        HideTile();
    }

    public void Setup()
    {
        _neighborWalls.Clear();
        _neighborTiles.Clear();
        foreach (Wall wall in GenerateBoard.AllWalls)
        {
            if (Vector3.Distance(wall.transform.position, transform.position) < (GameManager.TileLength / 2) + 0.5f)
            {
                _neighborWalls.Add(wall);
            }
        }
        foreach (Tile tile in GenerateBoard.AllTiles)
        {
            if (Vector3.Distance(tile.transform.position, transform.position) < GameManager.TileLength + 0.5f)
            {
                _neighborTiles.Add(tile);
            }
        }
        //if (_neighborWalls.Count != 4 || _neighborTiles.Count != 4) { return; }
        if (_isStartingTile) { SetStartingTile(); }
        //if (_isOnLastRow) { _firstRow.OnRowReset -= DelayedSetupWrapper; }
    }

    private void Initialize()
    {
        _renderer = GetComponentInChildren<Renderer>();
        _parentRow = transform.GetComponentInParent<Row>();
        HideTile();
    }

    private void Awake()
    {
        Initialize();
    }
}
