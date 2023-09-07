using System;
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

    public static event Action<Tile> OnTileAdded;

    private void Awake()
    {
        _renderer = GetComponentInChildren<Renderer>();
        _cam = Camera.main;
        DisableRenderer();
    }

    private void Start()
    {
#if UNITY_ANDROID
        Taptic.tapticOn = true;
#endif
    }

    private void Update()
    {
        HandleRaycast();
    }

    private void HandleRaycast()
    {
        if (GameManager.CurrentState != GameState.Transition && GameManager.CurrentState != GameState.Progressing) { return; }

        if (InputHandler.IsPressingScreen)
        {
            _ray = _cam.ScreenPointToRay(InputHandler.PressPosition);
            _hits = Physics.RaycastAll(_ray);
        }

        if (!InputHandler.IsPressingScreen || _hits.Length == 0 || DialogueManager.Instance.IsDialogueActive)
        {
            DisallowDraw();
            return;
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
        SetHighestDrawnRow(tileToAdd);

        if (_lastTile != null && _lastTile != _currentTile)
        {
            Wall toDeactivate = tileToCheck.GetWallBetween(_lastTile);
            if (toDeactivate != null)
            {
                toDeactivate.SetWallAsPath();
            }
        }

        foreach (Wall wall in tileToAdd.NeighborWalls)
        {
            if (!wall.IsBorder && !wall.IsPath)
            {
                wall.SetWallAsBorder();
            }
        }

#if UNITY_ANDROID
        if (GameManager.IsHapticEnabled) { Taptic.Vibrate(); }
#endif

        OnTileAdded?.Invoke(tileToAdd);
    }

    private void DisallowDraw()
    {
        if (_renderer.enabled) { DisableRenderer(); }
        _currentTile = null;
        _lastTile = null;
    }

    private bool DrawConditionsNotMet(Tile tile)
    {
        return
            tile == null ||
            _lastTile == null ||
            (!_lastTile.IsPartOfMaze && !tile.IsPartOfMaze) ||
            (_lastTile.IsPartOfMaze && tile.IsPartOfMaze) ||
            !AreTilesContiguous(tile, _lastTile) ||
            (_lastTile.IsPartOfMaze && _lastTile.IsTransitionTile) ||
            (tile.IsPartOfMaze && tile.IsTransitionTile);
            //_lastTile.IsTransitionTile || // should be able to delete? 
            //_lastTile.IsPreTransitionTile;
    }
    private bool AreTilesContiguous(Tile t1, Tile t2)
    {
        if (t1 == null || t2 == null) return false;
        return (t1.transform.position - t2.transform.position).magnitude < GameManager.TileLength + 0.5f;
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

    private static void SetHighestDrawnRow(Tile tile, bool decrease = false)
    {
        // If we're supposed to be increasing height: bail if it turns out we're not
        // Reversed if we're supposed to be decreasing
        if (!decrease &&
            (tile.transform.position.z <= BoardManager.HighestDrawnRow.transform.position.z || tile.ParentRow.IsHighestDrawnRow))
        {
            return;
        }
        else if (decrease &&
            (tile.transform.position.z >= BoardManager.HighestDrawnRow.transform.position.z || tile.ParentRow.IsHighestDrawnRow))
        {
            return;
        }

        BoardManager.SetHighestRow(tile.ParentRow);
    }

    public static void TileAddingItselfToMaze(Tile tile)
    {
        if (!tile.IsTransitionTile)
        {
            SetHighestDrawnRow(tile);
        }
        OnTileAdded?.Invoke(tile);
    }
}
