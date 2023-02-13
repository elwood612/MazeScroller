using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;

public class Tile : MonoBehaviour
{
    [SerializeField] private Crystal _crystalPrefab;
    [SerializeField] private Renderer _tileRenderer;
    [SerializeField] private Renderer _colorRenderer;
    [SerializeField] private Renderer _deadEndRenderer;
    [SerializeField] private Renderer _flashRenderer;
    [SerializeField] private Renderer _colorBorderRenderer;
    [SerializeField] private ParticleSystem _colorParticles;
    [SerializeField] private Material _tileBase;
    [SerializeField] private Material _tileDrawn;
    [SerializeField] private Material _tileDead;
    [SerializeField] private Material _tileFlash;
    [SerializeField] private Material _tileCrossed;
    [SerializeField] private LayerMask _wallLayer;

    private ParticleSystem.MainModule _colorParticlesMainModule;
    private Row _parentRow;
    private List<Wall> _neighborWalls = new List<Wall>();
    private List<Wall> _neighborPaths = new List<Wall>();
    private List<Tile> _neighborTiles = new List<Tile>();
    private bool _isPartOfMaze = false;
    private bool _isEnabled = false;
    private bool _isColored = false;
    private int _crossings = 0;
    public Tile _pathfindingParent;
    private static bool _firstTile = true;
    private WaitForSecondsRealtime _flashDelay = new WaitForSecondsRealtime(0.1f);
    private float _flashAlpha = 1f;
    private float _colorShift = 50;
    private Material _tileBaseColored;

    public static event Action<Tile> OnTileDestroy;
    public static event Action<Tile> OnTileDeactivate;
    public static event Action<Crystal> OnCrystalRemoval;
    public bool IsStartingTile = false;
    public Crystal AttachedCrystal;
    public List<Wall> NeighborWalls => _neighborWalls;
    public List<Tile> NeighborTiles => _neighborTiles;
    public bool IsPartOfMaze => _isPartOfMaze;
    public bool IsEnabled => _isEnabled;
    public bool IsColored => _isColored;
    public int Crossings => _crossings;
    public Row ParentRow => _parentRow;
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

    private void Awake()
    {
        _parentRow = transform.GetComponentInParent<Row>();
        _colorRenderer.enabled = false;
        _deadEndRenderer.enabled = false;
        DisableTile();
    }

    private void OnEnable()
    {
        _parentRow.OnRowReset += ResetTile;
        _parentRow.OnRowSetup += GetNeighbors;
    }

    private void OnDisable()
    {
        _parentRow.OnRowReset -= ResetTile;
        _parentRow.OnRowSetup -= GetNeighbors;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Runner"))
        {
            PlayerCrossing(other.GetComponent<IRunner>());
        }
        else if (other.CompareTag("TileSpawner"))
        {
            SpawnTile();
        }
        else if (other.CompareTag("TileDestroyer"))
        {
            DestroyTile();
        }
        else if (other.CompareTag("TileDeactivator"))
        {
            OnTileDeactivate?.Invoke(this);
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.CompareTag("Runner"))
        {
            if (_isColored && _neighborPaths.Count > 1)
            {
                Debug.Log("You messed up the dead end!");
            }
        }
    }

    //private void TileOffscreen()
    //{
    //    foreach (Tile tile in _neighborTiles)
    //    {
    //        GetWallBetween(tile).SetWallAsPath();
    //    }
    //}

    private void PlayerCrossing(IRunner runner)
    {
        SetMaterial(_tileCrossed);
        if (IsDeadEnd() && _isColored) { PrimeDeadEnd(); }
        _crossings++;
        _pathfindingParent = null;
        runner.PreviousTile = runner.CurrentTile;
        runner.CurrentTile = this;
        runner.CalculateNextTargetWrapper(this);
        GameManager.Score++;
    }

    public void SpawnTile()
    {
        if (!_parentRow.HasSetupBeenRun) { return; }

        EnableTile();
        foreach (Wall wall in _neighborWalls)
        {
            wall.EnableWall();  
        }
        if (_firstTile) { SetStartingTile(); }
        _firstTile = false;
    }

    private void DestroyTile()
    {
        if (!_parentRow.HasSetupBeenRun || !_isEnabled) { return; }

        if (_isPartOfMaze) 
        { 
            RemoveTileFromMaze();
        }
        if (_crossings > 0)
        {
            SetMaterial(_tileCrossed);
        }

        OnTileDestroy?.Invoke(this);
    }

    //private IEnumerator TileFlash()
    //{
    //    yield return _flashDelay;
    //    while (_flashAlpha > 0)
    //    {
    //        _flashAlpha -= 0.05f;
    //        Color newColor = _flashRenderer.material.color;
    //        newColor.a = _flashAlpha;
    //        _flashRenderer.material.color = newColor;
    //    }
    //}

    //private void SetColoredColor()
    //{
    //    float hue, S, V;
    //    _tileBaseColored = new Material(_tileBase);
    //    Color.RGBToHSV(_tileBaseColored.color, out hue, out S, out V);
    //    hue += _colorShift;
    //    Color newColor = Color.HSVToRGB(hue, S, V);
    //    _tileBaseColored.color = newColor;
    //}

    public void DisableTile(bool onSpawn = false)
    {
        _tileRenderer.enabled = false;
        SetAsColored(false);
        _isEnabled = false;
        if (_parentRow.EnabledTiles.Contains(this))
        {
            _parentRow.EnabledTiles.Remove(this);
        }

        if (!onSpawn) { return; }

        foreach (Wall wall in _neighborWalls)
        {
            wall.TryDisable();
        }
    }

    private void EnableTile()
    {
        _tileRenderer.enabled = true;
        _isEnabled = true;
        _parentRow.EnabledTiles.Add(this);
    }

    private void SetMaterial(Material material)
    {
        _tileRenderer.material = material;
    }   

    private void GetNeighbors()
    {
        foreach (Wall wall in BoardManager.AllWalls)
        {
            if (Vector3.Distance(wall.transform.position, transform.position) < (GameManager.TileLength / 2) + 0.5f)
            {
                _neighborWalls.Add(wall);
            }
        }
        foreach (Tile tile in BoardManager.AllTiles)
        {
            if (tile == this) { continue; }
            if (Vector3.Distance(tile.transform.position, transform.position) < GameManager.TileLength + 0.5f)
            {
                _neighborTiles.Add(tile);
            }
        }
    }

    public void AddTileToMaze()
    {
        _isPartOfMaze = true;
        SetMaterial(_tileDrawn);
    }

    public void RemoveTileFromMaze()
    {
        _isPartOfMaze = false;
        SetMaterial(_tileBase);
    }

    public Tile GetNeighborTile(Vector3 direction)
    {
        foreach (Tile tile in _neighborTiles)
        {
            if (GameManager.CompareVectors(tile.transform.position, transform.position + direction.normalized * GameManager.TileLength))
            {
                return tile;
            }
        }
        Debug.Log("Couldn't find neighbor tile");
        return this;
    }

    public Wall GetWallBetween(Tile other)
    {
        foreach (Wall wall in _neighborWalls)
        {
            if (GameManager.CompareVectors(wall.transform.position, (transform.position + other.transform.position) / 2))
            {
                return wall;
            }
        }
        Debug.Log("Couldn't find wall between");
        return _neighborWalls[0];
    }

    public bool DisallowCrystal()
    {
        int counter = 0;
        foreach (Tile tile in _neighborTiles)
        {
            if (tile.IsEnabled) { counter++; }
        }
        return counter <= 1;
    }

    public void RemoveCrystal()
    {
        OnCrystalRemoval?.Invoke(AttachedCrystal);
        AttachedCrystal = null;
    }

    public bool IsDeadEnd()
    {
        return _neighborPaths.Count == 1;
    }

    public void SetAsColored(bool input)
    {
        _isColored = input;
        _colorRenderer.enabled = input;
    }

    public void PrimeDeadEnd() // not working dude
    {
        _deadEndRenderer.enabled = true;
        _colorRenderer.enabled = false;
        _colorRenderer.transform.LookAt(GetNeighborTile(_neighborPaths[0].transform.position - transform.position).transform, Vector3.up);
    }

    public void SetStartingTile()
    {
        AddTileToMaze();
        _parentRow.IsHighestDrawnRow = true;
        IsStartingTile = true;
        DrawMaze.HighestDrawnRow = _parentRow;
        foreach (Wall wall in _neighborWalls)
        {
            wall.SetWallAsBorder();
        }
        GameManager.Instance.SpawnPlayer(transform);
    }

    public void ResetTile()
    {
        _crossings = 0;
        RemoveTileFromMaze();
        DisableTile();
        SetAsColored(false);
        _deadEndRenderer.enabled = false;
    }
}
