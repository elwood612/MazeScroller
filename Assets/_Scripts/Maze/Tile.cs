using System.Collections;
using UnityEngine;

public class Tile : MonoBehaviour
{
    public bool tempCheckMark = false;
    [SerializeField] private Material _tileBase, _tileDrawn;
    [SerializeField] private LayerMask _wallLayer;

    private Renderer _renderer;
    private Row _parentRow;
    private Row _firstRow;
    public Wall[] _neighborWalls = new Wall[4];
    private bool _isStartingTile = false;
    private bool _isOnLastRow = false;
    private bool _isPartOfMaze = false;
    private bool _isDestroyed = false;
    private bool _hasCrystal = false;
    private bool _initialSetup = true;

    public Wall[] NeighborWalls => _neighborWalls;
    public bool IsPartOfMaze => _isPartOfMaze;
    public bool IsDestroyed => _isDestroyed;
    public bool HasCrystal => _hasCrystal;

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

    public Row FirstRow
    {
        get => _firstRow;
        set => _firstRow = value;
    }
    public Row ParentRow => _parentRow;

    private void Awake()
    {
        _renderer = GetComponentInChildren<Renderer>();
        _parentRow = transform.GetComponentInParent<Row>();
    }

    private void OnEnable()
    {
        GameManager.OnStateChanged += RegularSetup;
        if (_parentRow != null) { _parentRow.OnRowReset += ResetTile; }
    }

    private void OnDisable()
    {
        if (_parentRow != null) { _parentRow.OnRowReset -= ResetTile; }
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
        Collider[] colliders = Physics.OverlapSphere(transform.position, (GameManager.TileLength / 2) + 0.5f, _wallLayer);
        Debug.Log("Getting neighboring walls, found: " + colliders.Length);
        Wall[] walls = new Wall[colliders.Length];
        for (int i = 0; i < colliders.Length; i++)
        {
            walls[i] = colliders[i].GetComponent<Wall>();
        }
        return walls;
    }

    public void RegularSetup(GameState state)
    {
        if (state == GameState.Setup || !_initialSetup) { return; }
        
        Collider[] colliders = Physics.OverlapSphere(transform.position, (GameManager.TileLength / 2) + 0.5f, _wallLayer);
        if (colliders.Length != 4) { return; }

        for (int i = 0; i < colliders.Length; i++)
        {
            _neighborWalls[i] = colliders[i].GetComponent<Wall>();
        }

        if (_isStartingTile) { SetStartingTile(); }
        GameManager.OnStateChanged -= RegularSetup;
        if (_isOnLastRow) { _firstRow.OnRowReset -= DelayedSetupWrapper; }
        _initialSetup = false;
    }

    public void DestroyTile()
    {
        if (_renderer != null) { _renderer.enabled = false; }
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
        _parentRow.IsHighestDrawnRow = true;
        DrawMaze.HighestDrawnRow = _parentRow;
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
        foreach (Wall wall in _neighborWalls)
        {
            wall.HideWall();
        }
        RemoveTileFromMaze();
    }

    public void DelayedSetupWrapper()
    {
        StartCoroutine(DelayedSetup());
    }

    private IEnumerator DelayedSetup()
    {
        yield return new WaitForSeconds(1f);
        RegularSetup(GameState.Idle);
    }

    //private void OnDrawGizmos()
    //{
    //    Gizmos.DrawSphere(transform.position, (GameManager.TileLength / 2) + 0.5f);
    //}
}
