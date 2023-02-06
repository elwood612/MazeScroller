using System;
using System.Collections.Generic;
using UnityEngine;

public class DrawMaze : MonoBehaviour
{
    [SerializeField] private LayerMask _wallLayer;

    private Ray _ray;
    private static Row _highestDrawnRow;
    private RaycastHit[] _hits;
    private Camera _cam;
    private Renderer _renderer;
    private Tile _currentTile, _lastTile;
    private Stack<Dictionary<Tile, bool>> _tileHistory = new Stack<Dictionary<Tile, bool>>();
    private Stack<Dictionary<Wall, bool>> _wallHistory = new Stack<Dictionary<Wall, bool>>();
    private bool _firstTileDrawn = true;

    public static event Action<Tile> OnTileAdded;
    public static event Action<Tile> OnTileRemoved;

    public static Row HighestDrawnRow
    {
        get => _highestDrawnRow;
        set => _highestDrawnRow = value;
    }

    private void Awake()
    {
        _renderer = GetComponentInChildren<Renderer>();
        _cam = Camera.main;
        DisableRenderer();
    }

    private void Update()
    {
        HandleRaycast();
    }

    private void HandleRaycast()
    {
        if (GameManager.CurrentState != GameState.Idle && GameManager.CurrentState != GameState.Running) { return; }

        if (InputHandler.IsPressingScreen)
        {
            _ray = _cam.ScreenPointToRay(InputHandler.PressPosition);
            _hits = Physics.RaycastAll(_ray);
        }

        if (!InputHandler.IsPressingScreen || _hits.Length == 0)
        {
            DisallowDraw();
            return;
        }
        else // i.e., if pressingScreen && hitting something
        {
            GameManager.Instance.UpdateGameState(GameState.Running); // temp
        }

        foreach (RaycastHit hit in _hits)
        {
            if (hit.collider.CompareTag("Tile"))
            {
                if (_currentTile != null) { _lastTile = _currentTile; }
                _currentTile = hit.collider.GetComponent<Tile>();
                if (!_currentTile.IsEnabled)
                {
                    DisallowDraw();
                    continue;
                }
                UpdateTransformAndRenderer(_currentTile.transform.position);
                Draw(_currentTile);
            }
        }
    }

    private void Draw(Tile tileToCheck)
    {
        if (DrawConditionsNotMet(tileToCheck)) { return; }

        Dictionary<Tile, bool> tileActions = new Dictionary<Tile, bool>();
        Dictionary<Wall, bool> wallActions = new Dictionary<Wall, bool>();
        Tile tileToAdd;

        if (_lastTile.IsPartOfMaze) { tileToAdd = tileToCheck; }
        else { tileToAdd = _lastTile; }
        tileToAdd.AddTileToMaze();
        tileActions.Add(tileToAdd, true);
        SetHighestDrawnRow(tileToAdd);

        if (_lastTile != null && _lastTile != _currentTile)
        {
            Wall toDeactivate = GetWallToDeactivate(tileToCheck, _lastTile);
            if (toDeactivate != null)
            {
                toDeactivate.SetWallAsPath();
                wallActions.Add(toDeactivate, false);
            }
        }

        foreach (Wall wall in tileToAdd.NeighborWalls)
        {
            if (!wall.IsBorder && !wall.IsPath)
            {
                wall.SetWallAsBorder();
                wallActions.Add(wall, true);
            }
        }

        if (_firstTileDrawn)
        {
            GameManager.Instability += 10;
            _firstTileDrawn = false;
        }
        OnTileAdded?.Invoke(tileToAdd);
        _tileHistory.Push(tileActions);
        _wallHistory.Push(wallActions);
    }

    private void DisallowDraw()
    {
        if (_renderer.enabled) { DisableRenderer(); }
        _currentTile = null;
        _lastTile = null;
        GameManager.Instance.UpdateGameState(GameState.Idle);
    }

    private bool DrawConditionsNotMet(Tile tile)
    {
        return
            tile == null ||
            _lastTile == null ||
            (!_lastTile.IsPartOfMaze && !tile.IsPartOfMaze) ||
            (_lastTile.IsPartOfMaze && tile.IsPartOfMaze) ||
            !AreTilesContiguous(tile, _lastTile);
    }

    public void Undo()
    {
        if (_tileHistory.Count == 0) { return; }

        foreach (KeyValuePair<Tile, bool> action in _tileHistory.Peek())
        {
            if (action.Key.Crossings > 0) { return; } // Can't undo if runner has already been here

            if (action.Value) // if tile is in maze
            {
                OnTileRemoved?.Invoke(action.Key);
                action.Key.RemoveTileFromMaze();
            }
            else // unused for now
            {
                Debug.Log("ray what are you doing");
                action.Key.AddTileToMaze();
            }

            _tileHistory.Pop();
        }

        foreach (KeyValuePair<Wall, bool> action in _wallHistory.Pop())
        {
            if (action.Value) // if wall is a border
            { 
                action.Key.UndoWallAsBorder();
            }
            else // if wall is a path
            { 
                action.Key.SetWallAsBorder();
            }
        }

        if (_tileHistory.Count == 0) { return; }
        foreach (KeyValuePair<Tile, bool> previousTile in _tileHistory.Peek())
        {
            SetHighestDrawnRow(previousTile.Key, true); // update highestDrawnRow with next tile
            break;
        }
    }

    private bool AreTilesContiguous(Tile t1, Tile t2)
    {
        if (t1 == null || t2 == null) return false;
        return (t1.transform.position - t2.transform.position).magnitude < GameManager.TileLength + 0.5f;
    }

    private bool IsTilePartOfOrNextToMaze(Tile t)
    {
        if (t.IsPartOfMaze) { return true; }
        foreach (Tile tile in t.NeighborTiles)
        {
            if (tile.IsPartOfMaze) { return true; }
        }
        return false;
    }

    private void UpdateTransformAndRenderer(Vector3 pos)
    {
        if (!_renderer.enabled) { _renderer.enabled = true; }
        transform.position = pos;
    }

    private void SetHighestDrawnRow(Tile tile, bool decrease = false)
    {
        // If we're supposed to be increasing height: bail if it turns out we're not
        // Reversed if we're supposed to be decreasing
        if (!decrease && 
            (tile.transform.position.z <= _highestDrawnRow.transform.position.z || tile.ParentRow.IsHighestDrawnRow)) 
        { 
            return;
        }
        else if (decrease && 
            (tile.transform.position.z >= _highestDrawnRow.transform.position.z || tile.ParentRow.IsHighestDrawnRow))
        {
            return;
        }

        _highestDrawnRow.IsHighestDrawnRow = false;
        _highestDrawnRow = tile.ParentRow;
        _highestDrawnRow.IsHighestDrawnRow = true;
    }

    private void DisableRenderer()
    {
        _renderer.enabled = false;
    }

    private Wall GetWallToDeactivate(Tile t1, Tile t2)
    {
        Vector3 pos1 = t1.transform.position;
        Vector3 pos2 = t2.transform.position;
        if ((pos2 - pos1).magnitude > GameManager.TileLength + 0.5f) { return null; }

        Collider[] colliders = Physics.OverlapSphere((pos1 + pos2) / 2, 0.5f, _wallLayer);
        if (colliders.Length == 0 || colliders == null) { return null; }

        foreach (Collider collider in colliders)
        {
            if (collider.TryGetComponent(out Wall wall)) { return wall; }
        }

        return null;
    }


    // This was an attempt to be able to draw the maze while simply clicking next to the maze. Needs more work, mysteriously buggy

    //private void Draw(Tile tileToCheck)
    //{
    //    if (DrawConditionsNotMet(tileToCheck)) { return; }

    //    Dictionary<Tile, bool> tileActions = new Dictionary<Tile, bool>();
    //    Dictionary<Wall, bool> wallActions = new Dictionary<Wall, bool>();
    //    Tile tileToAdd = tileToCheck; // temp, don't like

    //    if (_lastTile != null && !IsTilePartOfOrNextToMaze(_lastTile)) { _lastTile = null; }
    //    if (_lastTile == null)
    //    {
    //        foreach (Tile tile in tileToCheck.NeighborTiles)
    //        {
    //            if (tile.IsPartOfMaze)
    //            {
    //                tileToAdd = tileToCheck;
    //                _lastTile = tile;
    //                break;
    //            }
    //        }
    //    }
    //    else if (_lastTile.IsPartOfMaze) { tileToAdd = tileToCheck; }
    //    else { tileToAdd = _lastTile; }

    //    tileToAdd.AddTileToMaze();
    //    tileActions.Add(tileToAdd, true);
    //    SetHighestDrawnRow(tileToAdd);

    //    if (_lastTile != null && _lastTile != _currentTile)
    //    {
    //        Wall toDeactivate = GetWallToDeactivate(tileToCheck, _lastTile);
    //        if (toDeactivate != null)
    //        {
    //            toDeactivate.SetWallAsPath();
    //            wallActions.Add(toDeactivate, false);
    //        }
    //    }

    //    foreach (Wall wall in tileToAdd.NeighborWalls)
    //    {
    //        if (!wall.IsBorder && !wall.IsPath)
    //        {
    //            wall.SetWallAsBorder();
    //            wallActions.Add(wall, true);
    //        }
    //    }

    //    if (_firstTileDrawn)
    //    {
    //        GameManager.Instability += 10;
    //        _firstTileDrawn = false;
    //    }

    //    OnTileAdded?.Invoke(tileToAdd);
    //    _tileHistory.Push(tileActions);
    //    _wallHistory.Push(wallActions);
    //}

    //private void DisallowDraw()
    //{
    //    if (_renderer.enabled) { DisableRenderer(); }
    //    _currentTile = null;
    //    _lastTile = null;
    //    GameManager.Instance.UpdateGameState(GameState.Idle);
    //}

    //private bool DrawConditionsNotMet(Tile tile)
    //{
    //    return
    //        tile == null ||                                                                 // shouldn't happen
    //        !IsTilePartOfOrNextToMaze(tile) ||                                                    // can't join into maze if you're not connected
    //        (_lastTile != null && !_lastTile.IsPartOfMaze && !IsTilePartOfOrNextToMaze(tile)) ||         // can't draw stuff unconnected to maze
    //        (_lastTile != null && _lastTile.IsPartOfMaze && tile.IsPartOfMaze) ||           // can't make "shortcut" in maze
    //        (_lastTile != null && !AreTilesContiguous(tile, _lastTile));                    // should prevent spamming errors
    //}
}
