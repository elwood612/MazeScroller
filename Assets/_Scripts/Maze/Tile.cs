using System.Collections;
using UnityEngine;

public class Tile : MonoBehaviour
{
    
    [SerializeField] private Material _tileBase, _tileDrawn;
    [SerializeField] private LayerMask _wallLayer;

    private Renderer _renderer;
    private Row _parentRow;
    private Row _firstRow;
    public Wall[] _neighborWalls = new Wall[4];
    private bool _isSetup = true;
    private bool _isStartingTile = false;
    private bool _isEndOfBoard = false;
    private bool _isPartOfMaze = false;
    private bool _isDestroyed = false;
    private bool _hasCrystal = false;

    public Wall[] NeighborWalls => _neighborWalls;
    public bool IsPartOfMaze => _isPartOfMaze;
    public bool IsDestroyed => _isDestroyed;
    public bool HasCrystal => _hasCrystal;

    public bool IsStartingTile
    {
        get => _isStartingTile;
        set => _isStartingTile = value;
    }

    public bool IsEndOfBoard
    {
        get => _isEndOfBoard;
        set => _isEndOfBoard = value;
    }

    public Row FirstRow
    {
        get => _firstRow;
        set => _firstRow = value;
    }

    private void Awake()
    {
        _renderer = GetComponentInChildren<Renderer>();
        _parentRow = transform.GetComponentInParent<Row>();
    }

    private void OnEnable()
    {
        if (_parentRow != null) { _parentRow.OnRowReset += ResetTile; }
        GameManager.OnStateChanged += SetNeighborWalls;
    }

    private void OnDisable()
    {
        if (_parentRow != null) { _parentRow.OnRowReset -= ResetTile; }
    }

    private void Start()
    {
        //_neighborWalls = GetNeighborWalls();
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

    public Wall[] GetNeighborWallsLegacy()
    {
        //GameObject sphere = Instantiate(GameObject.CreatePrimitive(PrimitiveType.Sphere), transform);
        //sphere.transform.localScale *= (GameManager.TileLength) + 0.5f;
        //sphere.transform.GetComponent<Renderer>().material.color = Color.yellow;
        Collider[] colliders = Physics.OverlapSphere(transform.position, (GameManager.TileLength / 2) + 0.5f, _wallLayer);
        Debug.Log("Getting neighboring walls, found: " + colliders.Length);
        Wall[] walls = new Wall[colliders.Length];
        for (int i = 0; i < colliders.Length; i++)
        {
            walls[i] = colliders[i].GetComponent<Wall>();
        }
        return walls;
    }

    public void SetNeighborWalls(GameState state)
    {
        if (_isEndOfBoard)
        {
            _firstRow.OnRowReset += EndOfRowDelay;
        }
        if (state != GameState.Idle || !_isSetup)
        {
            _isSetup = false;
            return;
        }

        Collider[] colliders = Physics.OverlapSphere(transform.position, (GameManager.TileLength / 2) + 0.5f, _wallLayer);
        if (colliders.Length != 4) { return; }

        for (int i = 0; i < colliders.Length; i++)
        {
            _neighborWalls[i] = colliders[i].GetComponent<Wall>();
        }

        if (_isStartingTile) { SetStartingTile(); }
        if (_firstRow != null) { _firstRow.OnRowReset -= EndOfRowDelay; }
    }

    public void SetTileAsDestroyed()
    {
        if (_renderer != null)
            _renderer.enabled = false;
        _isDestroyed = true;
        _isPartOfMaze = false;
    }

    public void SetStartingTile()
    {
        _isStartingTile = true;
        if (_isDestroyed) { UndoDestroyed(); }
        AddTileToMaze();
        foreach (Wall wall in _neighborWalls)
        {
            wall.WallIsBorder();
        }
    }

    private void UndoDestroyed()
    {
        _renderer.enabled = true;
        _isDestroyed = false;
    }

    private void SetMaterial(Material material)
    {
        _renderer.material = material;
    }

    private void ResetTile()
    {
        //foreach (Wall wall in GetNeighborWallsLegacy())
        foreach (Wall wall in _neighborWalls)
        {
            wall.DeactivateWall();
        }
        RemoveTileFromMaze();
    }

    private void EndOfRowDelay()
    {
        Debug.Log("End of row delay");
        _isEndOfBoard = false;
        SetNeighborWalls(GameState.Idle);
        //_firstRow.OnRowReset -= EndOfRowDelay;
    }

    //private void OnDrawGizmos()
    //{
    //    Gizmos.DrawSphere(transform.position, (GameManager.TileLength / 2) + 0.5f);
    //}
}
