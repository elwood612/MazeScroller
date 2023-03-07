using System;
using System.Collections.Generic;
using UnityEngine;

public class Tile : MonoBehaviour
{
    [SerializeField] private Crystal _crystalPrefab;
    [SerializeField] private Renderer _tileRenderer;
    [SerializeField] private Renderer _colorRenderer;
    [SerializeField] private Renderer _flashRenderer;
    [SerializeField] private ParticleSystem _colorParticles;
    [SerializeField] private ParticleSystem _deadEndSuccessParticles;
    [SerializeField] private Material _tileBase;
    [SerializeField] private Material _tileDrawn;
    [SerializeField] private Material _tileDead;
    [SerializeField] private Material _tileFlash;
    [SerializeField] private Material _tileCrossed;
    [SerializeField] private GameObject _tileDeadEnd;
    [SerializeField] private LayerMask _wallLayer;
    [SerializeField] private AudioSource _audioNegative;
    [SerializeField] private AudioSource _audioTada;

    private Row _parentRow;
    private List<Wall> _neighborWalls = new List<Wall>();
    private List<Tile> _neighborTiles = new List<Tile>();
    private bool _isPartOfMaze = false;
    private bool _isEnabled = false;
    private bool _isColored = false;
    private bool _deadEndPrimed = false;
    private int _crossings = 0;
    private Tile _pathfindingParent;
    private static bool _firstTile = true;

    public static event Action<Tile> OnTileDestroy;
    public static event Action<Tile> OnTileDeactivate;
    public static event Action<Crystal> OnCrystalRemoval;
    public bool IsStartingTile = false;
    public bool IsTransitionTile = false;
    public bool IsPreTransitionTile = false;
    public Crystal AttachedCrystal;
    public List<Wall> NeighborPaths = new List<Wall>();
    public List<Wall> NeighborWalls => _neighborWalls;
    public List<Tile> NeighborTiles => _neighborTiles;
    public bool IsPartOfMaze => _isPartOfMaze;
    public bool IsEnabled => _isEnabled;
    public bool IsColored => _isColored;
    public int Crossings => _crossings;
    public Row ParentRow => _parentRow;
    public Tile PathfindingParent
    {
        get => _pathfindingParent;
        set => _pathfindingParent = value;
    }

    private void Awake()
    {
        _parentRow = transform.GetComponentInParent<Row>();
        _colorRenderer.enabled = false;
        _tileDeadEnd.SetActive(false);
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

    private void PlayerCrossing(IRunner runner)
    {
        SetMaterial(_tileCrossed);
        _crossings++;
        _pathfindingParent = null;
        runner.PreviousTile = runner.CurrentTile;
        runner.CurrentTile = this;
        runner.CalculateNextTargetWrapper(this);
        if ((IsTransitionTile || IsPreTransitionTile) && !runner.IsInTransition) { runner.BeginTransition(); }
        if (!IsTransitionTile && runner.IsInTransition) { runner.BeginStage(); }
        if (!IsTransitionTile) { GameManager.Score++; }

        if (_isColored)
        {
            if (NeighborPaths.Count == 1)
            {
                _audioTada.Play();
                _colorParticles.Stop();
                _deadEndSuccessParticles.Play();
                _colorRenderer.enabled = false;
            }
            else if (NeighborPaths.Count > 1)
            {
                _audioNegative.Play();
                SetAsColored(false);
                GameManager.Stars--;
            }
        }
    }

    private void DestroyTile()
    {
        if (!_parentRow.HasSetupBeenRun || !_isEnabled) { return; }
        if (_crossings == 0) 
        { 
            GetComponent<ParticleSystem>().Play();
            GameManager.Instance.DecreaseTileBonus(30);
        }
        else
        {
            GameManager.Instance.IncreaseTileBonus(1);
        }
        OnTileDestroy?.Invoke(this);
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

    private void ResetDeadEnd()
    {
        _tileDeadEnd.SetActive(false);
        _deadEndPrimed = false;
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
        
        if (GameManager.CurrentState == GameState.Transition)
        {
            IsTransitionTile = true;
            Tile t = GetNeighborTile(Vector3.back);
            if (!t.IsTransitionTile && !t.IsPreTransitionTile && !t.IsStartingTile && !IsStartingTile)
            {
                IsTransitionTile = false;
                IsPreTransitionTile = true;
                return;
            }

            AddTileToMaze();
            if (!IsStartingTile) { DrawMaze.TileAddingItselfToMaze(this); }
            foreach (Wall wall in _neighborWalls)
            {
                if (wall == GetWallBetween(t) && !IsStartingTile) { wall.SetWallAsPath(); }
                else { wall.SetWallAsBorder(); }
            }
        }
        else if (GameManager.CurrentState == GameState.Progressing)
        {
            Tile t = GetNeighborTile(Vector3.back);
            if (t.IsTransitionTile) 
            { 
                t.IsTransitionTile = false;
                DrawMaze.TileAddingItselfToMaze(t);
            }
        }
}

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

    public void SetTileAsDeadEnd(Transform wall)
    {
        _tileDeadEnd.SetActive(true);
        _tileDeadEnd.transform.LookAt(wall);
        _deadEndPrimed = true;
    }

    public void UndoDeadEnd()
    {
        if (_deadEndPrimed) { _tileDeadEnd.SetActive(false); }
    }

    public Tile GetNeighborTile(Vector3 direction)
    {
        foreach (Tile tile in _neighborTiles)
        {
            if (GameManager.CompareVectorsAsInts(tile.transform.position, transform.position + direction.normalized * GameManager.TileLength))
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
            if (GameManager.CompareVectorsAsInts(wall.transform.position, (transform.position + other.transform.position) / 2))
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

    public void SetAsColored(bool input)
    {
        _isColored = input;
        _colorRenderer.enabled = input;
        _colorParticles.Play();
    }

    public void SetStartingTile()
    {
        AddTileToMaze();
        _parentRow.IsHighestDrawnRow = true;
        IsStartingTile = true;
        foreach (Wall wall in _neighborWalls)
        {
            wall.SetWallAsBorder();
        }

        DrawMaze.HighestDrawnRow = _parentRow;
        GameManager.Instance.SpawnPlayer(transform);
        GameManager.Instance.CurrentRunner.GetComponent<IRunner>().SetCurrentTile(this);
    }

    public void ResetTile()
    {
        _crossings = 0;
        IsStartingTile = false;
        IsTransitionTile = false;
        IsPreTransitionTile = false;
        RemoveTileFromMaze();
        SetMaterial(_tileBase);
        DisableTile();
        SetAsColored(false);
        ResetDeadEnd();
        NeighborPaths.Clear();
    }
}
