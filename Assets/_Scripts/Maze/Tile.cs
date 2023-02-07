using Codice.CM.WorkspaceServer.Tree;
using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;

public class Tile : MonoBehaviour
{
    [SerializeField] private Crystal _crystalPrefab;
    [SerializeField] private Material _tileBase;
    [SerializeField] private Material _tileDrawn;
    [SerializeField] private Material[] _tileCrossing;
    [SerializeField] private LayerMask _wallLayer;

    private Renderer _renderer;
    private Rigidbody _rb;
    private ParticleSystem _particles;
    private Row _parentRow;
    private List<Wall> _neighborWalls = new List<Wall>();
    private List<Wall> _neighborPaths = new List<Wall>();
    private List<Tile> _neighborTiles = new List<Tile>();
    private bool _isPartOfMaze = false;
    private bool _isEnabled = false;
    private bool _hasCrystal = false;
    private int _crossings = 0;
    private Tile _pathfindingParent;
    private static bool _firstTile = true;
    private WaitForSeconds _destuctionDelay;
    private WaitForSeconds _hideDelay;

    public static event Action<Tile> OnTileDestroy;
    public static event Action<Tile> OnTileDeactivate;
    public List<Wall> NeighborWalls => _neighborWalls;
    public List<Tile> NeighborTiles => _neighborTiles;
    public bool IsPartOfMaze => _isPartOfMaze;
    public bool IsEnabled => _isEnabled;
    public bool HasCrystal => _hasCrystal;
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
        if (other.CompareTag("Player"))
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

    private void PlayerCrossing(IRunner runner)
    {
        if (_crossings < _tileCrossing.Length)
        {
            SetMaterial(_tileCrossing[_crossings]);
        }
        _crossings++;
        runner.PreviousTile = runner.CurrentTile;
        runner.CurrentTile = this;
        runner.CalculateNextTargetWrapper(this);
    }

    private void SpawnTile()
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

        if (_crossings == 0) { GameManager.Instability += 10; }
        else if (_crossings == 1) { GameManager.Instability++; }

        OnTileDestroy?.Invoke(this);

        if (_crossings > 0) { return; }

        // For uncrossed tiles only
        foreach (Wall wall in _neighborWalls)
        {
            wall.DestroyWall();
        }

        _particles.Play();
        DisableTile();
        
        //StartCoroutine(HideTileAfterDestruction());
        //StartCoroutine(RigidbodyDestroy());
    }

    private IEnumerator RigidbodyDestroy()
    {
        yield return _destuctionDelay;
        _rb.isKinematic = false;
        Vector3 impulse = new Vector3(Random.Range(-50f, 50f), Random.Range(-50f, 0), Random.Range(-50f, 50f));
        _rb.AddForce(impulse, ForceMode.Impulse);
    }

    private IEnumerator HideTileAfterDestruction()
    {
        yield return _hideDelay;
        if (_isEnabled) { DisableTile(); }
    }

    public void DisableTile(bool onSpawn = false)
    {
        _renderer.enabled = false;
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
        _renderer = GetComponentInChildren<MeshRenderer>();
        _parentRow = transform.GetComponentInParent<Row>();
        _rb = GetComponentInChildren<Rigidbody>();
        _particles = GetComponent<ParticleSystem>();
        DisableTile();
        _destuctionDelay = new WaitForSeconds(Random.Range(0, 0.5f));
        _hideDelay = new WaitForSeconds(1f);
    }

    private void Awake()
    {
        Initialize();
    }

    private bool CompareVectors(Vector3 v1, Vector3 v2)
    {
        return Vector3Int.RoundToInt(v1) == Vector3Int.RoundToInt(v2);
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

    public Tile GetNeighborTile(Vector3 direction)
    {
        foreach (Tile tile in _neighborTiles)
        {
            if (CompareVectors(tile.transform.position, transform.position + direction.normalized * GameManager.TileLength))
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
            if (CompareVectors(wall.transform.position, (transform.position + other.transform.position) / 2))
            {
                return wall;
            }
        }
        Debug.Log("Couldn't find wall between");
        return _neighborWalls[0];
    }

    public void SetStartingTile()
    {
        AddTileToMaze();
        _parentRow.IsHighestDrawnRow = true;
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
        _rb.isKinematic = true;
        _rb.transform.SetLocalPositionAndRotation(Vector3.zero, Quaternion.identity);
    }

    public void SpawnCrystal(int level)
    {
        Instantiate(_crystalPrefab, transform);
    }
}
