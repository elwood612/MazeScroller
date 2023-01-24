using System.Collections.Generic;
using UnityEngine;

public class DrawMaze : MonoBehaviour
{
    [SerializeField] private LayerMask _wallLayer;
    private Ray _ray;
    private RaycastHit[] _hits;
    private Camera _cam;
    private Renderer _renderer;
    private Tile _currentTile, _lastTile;
    private static float _tileLength;
    private Stack<Dictionary<Tile, bool>> _tileHistory = new Stack<Dictionary<Tile, bool>>();
    private Stack<Dictionary<Wall, bool>> _wallHistory = new Stack<Dictionary<Wall, bool>>();

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
            _currentTile = null;
            _lastTile = null;
            return;
        }
      
        foreach (RaycastHit hit in _hits)
        {
            if (hit.collider.CompareTag("Tile"))
            {
                _currentTile = hit.collider.GetComponent<Tile>();
                UpdateTransformAndRenderer(_currentTile.transform.position);
                Draw(_currentTile);
                _lastTile = _currentTile;
            }
        }
    }

    private void Draw(Tile tile)
    {
        if (DrawConditionsNotMet(tile)) { return; }

        Dictionary<Tile, bool> tileActions = new Dictionary<Tile, bool>();
        Dictionary<Wall, bool> wallActions = new Dictionary<Wall, bool>();

        tile.AddTileToMaze();
        tileActions.Add(tile, true);
        
        if (_lastTile != null && _lastTile != _currentTile)
        {
            Wall toDeactivate = GetWallToDeactivate(tile, _lastTile);
            if (toDeactivate != null)
            {
                toDeactivate.WallIsPath();
                wallActions.Add(toDeactivate, false);
            }
        }

        Wall[] neighborWalls = tile.GetNeighborWalls();
        foreach (Wall wall in neighborWalls)
        {
            if (!wall.MazeBorder && !wall.MazePath) 
            { 
                wall.WallIsBorder();
                wallActions.Add(wall, true);
            }
        }

        _tileHistory.Push(tileActions);
        _wallHistory.Push(wallActions);
    }

    private bool DrawConditionsNotMet(Tile tile)
    {
        return
            tile == null ||
            _lastTile == null ||
            !_lastTile.IsPartOfMaze ||
            tile.IsPartOfMaze ||
            !AreTilesContiguous(tile, _lastTile);
    }

    public void Undo()
    {
        if (_tileHistory.Count == 0) { return; }

        foreach (KeyValuePair<Tile, bool> action in _tileHistory.Pop())
        {
            if (action.Value) { action.Key.RemoveTileFromMaze(); }
            else { action.Key.AddTileToMaze(); }
        }

        foreach (KeyValuePair<Wall, bool> action in _wallHistory.Pop())
        {
            if (action.Value) { action.Key.DeactivateWall(); }
            else { action.Key.WallIsBorder(); }
        }
    }

    private bool AreTilesContiguous(Tile t1, Tile t2)
    {
        if (t1 == null || t2 == null) return false;
        return (t1.transform.position - t2.transform.position).magnitude < _tileLength + 0.5f;
    }

    private void UpdateTransformAndRenderer(Vector3 pos)
    {
        if (!_renderer.enabled) { _renderer.enabled = true; }
        transform.position = pos;
    }

    private void DisableRenderer()
    {
        _renderer.enabled = false;
    }

    private Wall GetWallToDeactivate(Tile t1, Tile t2)
    {
        Vector3 pos1 = t1.transform.position;
        Vector3 pos2 = t2.transform.position;
        if ((pos2 - pos1).magnitude > _tileLength + 0.5f) { Debug.Log("Non contiguous tiles"); return null; }

        Collider[] colliders = Physics.OverlapSphere((pos1 + pos2) / 2, 0.5f, _wallLayer);
        if (colliders.Length == 0 || colliders == null)
        {
            Debug.Log("Error! No intermediate wall found");
            return null;
        }

        foreach (Collider collider in colliders)
        {
            if (collider.TryGetComponent(out Wall wall))
            {
                return wall;
            }
        }

        Debug.Log("Unknown error, colliders:" + colliders.Length);
        return null;
    }

    //private void OnDrawGizmos()
    //{
    //    Gizmos.color = Color.red;
    //    Gizmos.DrawSphere(tempDeactivatePosition, 0.5f);
    //}
}
