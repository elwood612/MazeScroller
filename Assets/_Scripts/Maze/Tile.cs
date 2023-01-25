using UnityEngine;

public class Tile : MonoBehaviour
{
    [SerializeField] private bool _isStartingTile = false;
    [SerializeField] private Material _tileBase, _tileDrawn;
    [SerializeField] private LayerMask _wallLayer;

    private Renderer _renderer;
    private Row _parentRow;
    private bool _isPartOfMaze = false;
    private bool _isDestroyed = false;
    private bool _hasCrystal = false;

    public bool IsPartOfMaze => _isPartOfMaze;
    public bool IsDestroyed => _isDestroyed;
    public bool HasCrystal => _hasCrystal;

    public bool IsStartingTile
    {
        get => _isStartingTile;
        set => _isStartingTile = value;
    }

    private void Awake()
    {
        _renderer = GetComponentInChildren<Renderer>();
        _parentRow = transform.GetComponentInParent<Row>();
    }

    private void OnEnable()
    {
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

    public Wall[] GetNeighborWalls()
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
        foreach (Wall wall in GetNeighborWalls())
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
        foreach (Wall wall in GetNeighborWalls())
        {
            wall.DeactivateWall();
        }
        RemoveTileFromMaze();
    }

    //private void OnDrawGizmos()
    //{
    //    Gizmos.DrawSphere(transform.position, (GameManager.TileLength / 2) + 0.5f);
    //}
}
