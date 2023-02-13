using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;

public class Tile : MonoBehaviour
{
    [SerializeField] private Crystal _crystalPrefab;
    [SerializeField] private Renderer _renderer;
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
    private Color _color;
    private int _crossings = 0;
    public Tile _pathfindingParent;
    private static bool _firstTile = true;
    private WaitForSecondsRealtime _flashDelay = new WaitForSecondsRealtime(0.1f);
    private float _flashAlpha = 1f;

    public static event Action<Tile> OnTileDestroy;
    public static event Action<Tile> OnTileDeactivate;
    public bool HasCrystal = false;
    public bool IsStartingTile = false;
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

    //private void OnTriggerExit(Collider other)
    //{
    //    if (other.CompareTag("TileDeactivator"))
    //    {
    //        TileOffscreen();
    //    }
    //}

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
        if (_isColored) { runner.ChangeColor(_color); }
        ResetColor();
        _crossings++;
        _pathfindingParent = null;
        runner.PreviousTile = runner.CurrentTile;
        runner.CurrentTile = this;
        runner.CalculateNextTargetWrapper(this);
        GameManager.Score++;
    }

    private void SpawnTile()
    {
        if (!_parentRow.HasSetupBeenRun) { return; }

        //float chance = Mathf.Clamp((GameManager.Progress / GameManager.MaxProgress) / 2, 0.1f, 0.5f);
        //if (GameManager.Progress > 10) 
        //{ 
        //    if (Random.Range(0f, 1f) < chance)
        //    {
        //        _color = Color.yellow;
        //    }
        //}

        EnableTile();
        foreach (Wall wall in _neighborWalls)
        {
            wall.EnableWall();  
        }
        //if (_color != Color.white) { SetColor(_color); }
        if (_firstTile) { SetStartingTile(); }
        _firstTile = false;
    }

    private void DestroyTile()
    {
        if (!_parentRow.HasSetupBeenRun || !_isEnabled) { return; }

        //GameManager.Score += _crossings;

        if (_isPartOfMaze) 
        { 
            RemoveTileFromMaze();
            //SpawnProtectiveWall();
        }
        if (_crossings > 0)
        {
            //_flashRenderer.enabled = true;
            //StartCoroutine(TileFlash());
            SetMaterial(_tileCrossed);
        }

        OnTileDestroy?.Invoke(this);
    }

    private void SpawnProtectiveWall()
    {
        foreach (Wall wall in _neighborWalls)
        {
            if (GameManager.CompareVectors(wall.transform.position, transform.position + Vector3.forward * GameManager.TileLength / 2))
            {
                wall.SetWallAsHiddenBorder();
            }
            //else
            //{
            //    wall.HideWall();
            //}
        }
    }

    private IEnumerator TileFlash()
    {
        yield return _flashDelay;
        while (_flashAlpha > 0)
        {
            _flashAlpha -= 0.05f;
            Color newColor = _flashRenderer.material.color;
            newColor.a = _flashAlpha;
            _flashRenderer.material.color = newColor;
        }
    }

    private void ResetColor()
    {
        _isColored = false;
        _colorBorderRenderer.enabled = false;
        _colorParticles.Stop();
    }

    public void DisableTile(bool onSpawn = false)
    {
        _renderer.enabled = false;
        ResetColor();
        _isEnabled = false;

        if (!onSpawn) { return; }

        foreach (Wall wall in _neighborWalls)
        {
            wall.TryDisable();
        }
    }

    private void EnableTile()
    {
        _renderer.enabled = true;
        _isEnabled = true;
        _parentRow.EnabledTiles.Add(this);
    }

    private void SetMaterial(Material material)
    {
        _renderer.material = material;
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

    private void Initialize()
    {
        _parentRow = transform.GetComponentInParent<Row>();
        _flashRenderer.material = _tileFlash;
        _flashRenderer.enabled = false;
        _colorParticlesMainModule = _colorParticles.main;
        _colorBorderRenderer.enabled = false;
        DisableTile();
    }

    private void Awake()
    {
        Initialize();
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

    public void SetColor(Color color)
    {
        _isColored = true;
        _color = color;
        _colorBorderRenderer.enabled = true;
        _colorBorderRenderer.material.color = color;
        _colorParticlesMainModule.startColor = color;
        _colorParticles.Play();
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
        HasCrystal = false;
        _flashAlpha = 1f;
        _flashRenderer.material = _tileFlash;
        _flashRenderer.enabled = false;
        RemoveTileFromMaze();
        DisableTile();
        ResetColor();
    }
}
