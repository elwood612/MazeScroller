using UnityEngine;

public class Tile : MonoBehaviour
{
    [SerializeField] private bool _isStartingTile = false;
    [SerializeField] private Material _tileBase, _tileDrawn;
    [SerializeField] private LayerMask _wallLayer;
    private bool _isPartOfMaze = false;
    private float _tileLength, _neighborRadius;

    public bool IsPartOfMaze => _isPartOfMaze;
    public bool IsStartingTile => _isStartingTile;

    private void Start()
    {
        if (_isStartingTile) 
        { 
            DrawMaze.TileLength = GetComponent<BoxCollider>().bounds.size.x;
            AddTileToMaze();
            foreach (Wall wall in GetNeighborWalls())
            {
                wall.WallIsBorder();
            }
        }
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
        
        Collider[] colliders = Physics.OverlapSphere(transform.position, (DrawMaze.TileLength / 2) + 0.5f, _wallLayer);
        Wall[] walls = new Wall[colliders.Length];
        for (int i = 0; i < colliders.Length; i++)
        {
            walls[i] = colliders[i].GetComponent<Wall>();
        }
        return walls;
    }

    private void SetMaterial(Material material)
    {
        GetComponentInChildren<Renderer>().material = material;
    }
}
