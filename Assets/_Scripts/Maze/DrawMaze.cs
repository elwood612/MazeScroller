using UnityEngine;

public class DrawMaze : MonoBehaviour
{
    private Ray _ray;
    private RaycastHit[] _hits;
    private Camera _cam;
    private Renderer _renderer;
    private Tile _highlightedTile;
    private static float _tileLength;

    public static float TileLength
    {
        get => _tileLength; 
        set => _tileLength = value; 
    }

    private void Start()
    {
        _cam = Camera.main;
        _renderer = GetComponentInChildren<Renderer>();
    }

    private void Update()
    {
        if (InputHandler.IsPressingScreen)
        {
            _ray = _cam.ScreenPointToRay(InputHandler.PressPosition);
            _hits = Physics.RaycastAll(_ray);
        }

        if (!InputHandler.IsPressingScreen || _hits.Length == 0)
        {
            if (_renderer.enabled) { DisableRenderer(); }
            return;
        }
      
        foreach (RaycastHit hit in _hits)
        {
            if (hit.collider.CompareTag("Tile"))
            {
                UpdateTransformAndRenderer(hit.collider.transform.position);
                Draw(hit.collider.GetComponent<Tile>());
            }
        }
    }

    private void Draw(Tile currentTile)
    {
        if (currentTile == null || currentTile.IsPartOfMaze) { return; }

        currentTile.AddTileToMaze();

        Wall[] neighborWalls = currentTile.GetNeighborWalls();
        foreach (Wall wall in neighborWalls)
        {
            wall.EnableRenderer();
        }
    }

    private void UpdateTransformAndRenderer(Vector3 pos)
    {
        if (!_renderer.enabled) { _renderer.enabled = true; }
        transform.position = pos;
    }

    private void DisableRenderer()
    {
        _renderer.enabled = false;
        _highlightedTile = null;
    }

    //private void OnDrawGizmos()
    //{
    //    Gizmos.color = Color.yellow;
    //    Gizmos.DrawSphere(transform.position, (DrawMaze.TileLength / 2) + 0.5f);
    //}
}
