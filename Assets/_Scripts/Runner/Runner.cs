using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Runner : MonoBehaviour, IRunner
{
    [SerializeField] private Renderer[] _renderers;

    public Tile _currentTile;
    private Tile _currentTarget;
    private Tile _nextTarget;
    private Tile _previousTile;
    private List<Tile> _uncrossedTiles = new List<Tile>();
    private List<Tile> _uncrossedTransitionTiles = new List<Tile>();
    private float _currentSpeed;
    private int _colliderCheck = 0;
    public bool _runnerStopped = true;
    private bool _runnerOffScreen = false;
    private bool _approachingDeadEnd = false;
    public bool _isInTransition = false;
    private AnimationCurve _speedCurve;
    private AnimationCurve _transitionCurve;

    public static event Action OnTransitionReached;
    public bool IsInTransition
    {
        get => _isInTransition;
        set => _isInTransition = value;
    }
    public Tile CurrentTile
    {
        get => _currentTile;
        set => _currentTile = value;
    }
    public Tile PreviousTile
    {
        get => _previousTile;
        set => _previousTile = value;
    }

    private void Awake()
    {
        _speedCurve = GameManager.Instance.RunnerSpeedCurve;
        _transitionCurve = GameManager.Instance.RunnerTransitionCurve;
    }

    private void OnEnable()
    {
        DrawMaze.OnTileAdded += AddTileToPath;
        DrawMaze.OnTileRemoved += RemoveTileFromPath;
        Tile.OnTileDestroy += RemoveTileFromPath;
    }

    private void OnDisable()
    {
        DrawMaze.OnTileAdded -= AddTileToPath;
        DrawMaze.OnTileRemoved -= RemoveTileFromPath;
        Tile.OnTileDestroy -= RemoveTileFromPath;
    }

    private void Update()
    {
        GameManager.AddBoardMotion(transform);
        CalculateSpeed();
        if (_uncrossedTiles.Count > 0 && !_isInTransition) { Move(); }
        if (_uncrossedTiles.Count == 0 && _currentTile.IsPreTransitionTile) { Move(); }
        if (_uncrossedTransitionTiles.Count > 0 && _isInTransition) { Move(); }

        GameManager.RunnerHeight = Camera.main.WorldToScreenPoint(transform.position).y / Screen.height;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("TileCenter") && _colliderCheck == 0)
        {
            _colliderCheck++;
            SetTarget(other.GetComponentInParent<Tile>());
        }
        else if (other.CompareTag("TileDestroyer"))
        {
            _runnerOffScreen = true;
            CalculateNextTargetWrapper(_currentTile);
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.CompareTag("TileCenter")) { _colliderCheck = 0; }
    }

    private void CalculateSpeed() // this needs to change
    {
        Vector3 screenPos = Camera.main.WorldToScreenPoint(transform.position);
        float height = screenPos.y / Screen.height;

        if (_isInTransition)
        {
            _currentSpeed = _transitionCurve.Evaluate(height);
        }
        else if (!_isInTransition)
        {
            _currentSpeed = _speedCurve.Evaluate(height) + GameManager.TileSpeed;
        }
    }

    private void Move()
    {
        if (_currentTarget == null) { return; }
        //Debug.Log("Moving!");
        transform.position = Vector3.MoveTowards(transform.position, _currentTarget.transform.position, Time.deltaTime * _currentSpeed);
    }

    private void SetTarget(Tile tile) // On tile center
    {
        RemoveTileFromPath(_currentTile);

        if ((_uncrossedTiles.Count == 0 && !_isInTransition && !_currentTile.IsPreTransitionTile) ||
            (_uncrossedTransitionTiles.Count == 0 && _isInTransition))
        {
            DrawMaze.OnTileAdded += SetTarget;
            _nextTarget = null;
            return;
        }
        else
        {
            if (_runnerStopped)
            {
                //if (!_isInTransition && !_currentTile.IsStartingTile)
                //{
                //    foreach (Tile t in _currentTile.NeighborTiles)
                //    {
                //        if (t.IsTransitionTile)
                //        {
                //            _nextTarget = t;
                //            goto skipAhead;
                //        }
                //    }
                //}
                CalculateNextTargetWrapper(_currentTile);
                //_runnerStopped = false;
            }
            //DrawMaze.OnTileAdded -= SetTarget;
        }

    //skipAhead:
        if (_nextTarget != null)
        {
            _currentTarget = _nextTarget;
            _runnerStopped = false;
            DrawMaze.OnTileAdded -= SetTarget;
        }
        
        if (_currentTarget != null) { transform.GetChild(0).LookAt(_currentTarget.transform); }
    }

    private IEnumerator CalculateNextTarget(Tile tile) // On tile edge
    {
        _approachingDeadEnd = _currentTile.NeighborPaths.Count == 1;

        if (_currentTile.NeighborPaths.Count == 0) { yield break; }

        //if (_runnerStopped && !_currentTile.IsStartingTile) // should get you out of a jam if you get stuck
        //{
        //    yield return new WaitUntil(() => ExecutePathfinding(_currentTile, tile)); // possibly pathfind to most recent uncrossed tile??
        //    _nextTarget = GetPathfindingPath(_currentTile);
        //    _currentTarget = _nextTarget;
        //    _runnerStopped = false;
        //    yield break;
        //}

        Tile pathfindingTarget = tile;
        if (_uncrossedTiles.Count > 0) { pathfindingTarget = _uncrossedTiles[0]; }
        else if (_uncrossedTransitionTiles.Count > 0) { pathfindingTarget = _uncrossedTransitionTiles[0]; }

        if (_runnerOffScreen)
        {
            yield return new WaitUntil(() => ExecutePathfinding(_currentTile, pathfindingTarget));
            _nextTarget = GetPathfindingPath(_currentTile);
            _runnerOffScreen = false;
            yield break;
        }

        if (GetPathfindingPath(_currentTile) != _currentTile)
        {
            _nextTarget = GetPathfindingPath(_currentTile);
            yield break;
        }

        switch (tile.NeighborPaths.Count)
        {
            case 1:
            case 2:
                if (GetOldestCrossedPath(_currentTile) != _currentTile)
                {
                    _nextTarget = GetOldestCrossedPath(_currentTile);
                }
                else
                {
                    yield return new WaitUntil(() => ExecutePathfinding(_currentTile, pathfindingTarget));
                    _nextTarget = GetPathfindingPath(_currentTile);
                }
                break;
            case 3:
            case 4:
                if (GetFirstUncrossedPath(_currentTile) != _currentTile)
                {
                    _nextTarget = GetFirstUncrossedPath(_currentTile);
                }
                else
                {
                    yield return new WaitUntil(() => ExecutePathfinding(_currentTile, pathfindingTarget));
                    _nextTarget = GetPathfindingPath(_currentTile);
                }
                break;
            default:
                _nextTarget = tile;
                break;
        }
    }

    private Tile GetFirstUncrossedPath(Tile tile)
    {
        float firstDrawn = Mathf.Infinity;
        Tile toReturn = tile;

        foreach (Wall wall in tile.NeighborPaths)
        {
            if (wall.Crossings > 0) { continue; }
            Vector3 direction = wall.transform.position - tile.transform.position;
            if (wall.TimeDrawn < firstDrawn)
            {
                firstDrawn = wall.TimeDrawn;
                toReturn = tile.GetNeighborTile(direction);
            }
        }
        return toReturn;
    }

    private Tile GetOldestCrossedPath(Tile tile)
    {
        float firstCrossed = Mathf.Infinity;
        Tile toReturn = tile;
        foreach (Wall wall in tile.NeighborPaths)
        {
            Vector3 direction = wall.transform.position - tile.transform.position;
            if (wall.Crossings == 0) { return tile.GetNeighborTile(direction); }
            if (wall.TimeCrossed < firstCrossed)
            {
                firstCrossed = wall.TimeCrossed;
                toReturn = tile.GetNeighborTile(direction);
            }
        }
        return toReturn;
    }

    private Tile GetPathfindingPath(Tile tile)
    {
        Tile toReturn = tile;
        foreach (Wall wall in tile.NeighborPaths)
        {
            if (!wall.IsPathfindingPath) { continue; }
            else
            {
                toReturn = tile.GetNeighborTile(wall.transform.position - tile.transform.position);
            }
        }
        return toReturn;
    }

    private bool ExecutePathfinding(Tile startTile, Tile endTile)
    {
        ClearPathfinding(); // should help with bugs

        Queue<Tile> openSet = new Queue<Tile>();
        HashSet<Tile> closedSet = new HashSet<Tile>();
        openSet.Enqueue(startTile);

        while (openSet.Count > 0)
        {
            Tile currentTile = openSet.Dequeue();
            closedSet.Add(currentTile);

            if (currentTile == endTile)
            {
                RetracePathfindingPath(startTile, endTile);
                return true;
            }

            foreach (Wall wall in currentTile.NeighborPaths)
            {
                Tile neighborTile = currentTile.GetNeighborTile(wall.transform.position - currentTile.transform.position);
                if (closedSet.Contains(neighborTile)) { continue; }
                if (!openSet.Contains(neighborTile)) 
                { 
                    openSet.Enqueue(neighborTile);
                    neighborTile.PathfindingParent = currentTile;
                }
            }
        }
        Debug.Log("Whelp, something went wrong, teleporting to safety.");
        Teleport(endTile);
        return true;
    }

    // Not quite working
    // There shouldn't be pathfinding happening AFTER the teleport (OnTileDrawn), yet there is
    private void Teleport(Tile endTile)
    {
        ClearPathfinding();
        
        _runnerStopped = true;
        _runnerOffScreen = false;
        _currentTile = endTile;
        _currentTarget = endTile;
        
        ResetUncrossedTiles();

        transform.position = endTile.transform.position;
    }

    private void ClearPathfinding()
    {
        foreach (Tile tile in BoardManager.AllTiles) { tile.PathfindingParent = null; }
        foreach (Wall wall in BoardManager.AllWalls) { wall.IsPathfindingPath = false; }
    }

    private void ResetUncrossedTiles()
    {
        _uncrossedTiles.Clear();
        foreach (Tile tile in BoardManager.AllTiles)
        {
            if (tile.IsPartOfMaze && tile.Crossings == 0) { _uncrossedTiles.Add(tile); }
        }
    }

    private void RetracePathfindingPath(Tile startTile, Tile finishTile)
    {
        Tile currentTile = finishTile;
        while (currentTile != startTile)
        {
            currentTile.GetWallBetween(currentTile.PathfindingParent).IsPathfindingPath = true;
            currentTile = currentTile.PathfindingParent;
        }
    }

    protected void AddTileToPath(Tile tile)
    {
        //if (!tile.IsStartingTile) { _uncrossedTiles.Add(tile); }
        if (!tile.IsStartingTile && !tile.IsTransitionTile) { _uncrossedTiles.Add(tile); }
        if (!tile.IsStartingTile && tile.IsTransitionTile) { _uncrossedTransitionTiles.Add(tile); }
        if (_approachingDeadEnd) { CalculateNextTargetWrapper(_currentTile); }
    }

    protected void RemoveTileFromPath(Tile tile)
    {
        if (_uncrossedTiles.Contains(tile)) { _uncrossedTiles.Remove(tile); }
        if (_uncrossedTransitionTiles.Contains(tile)) { _uncrossedTransitionTiles.Remove(tile); }

        if (_uncrossedTiles.Count == 0 && !_isInTransition) { _runnerStopped = true; }
        if (_uncrossedTransitionTiles.Count == 0 && _isInTransition) { _runnerStopped = true; }
    }

    public void CalculateNextTargetWrapper(Tile tile)
    {
        StartCoroutine(CalculateNextTarget(tile));
    }

    public void BeginTransition()
    {
        _isInTransition = true;
        GameManager.IsRunnerInTransition = true;
        OnTransitionReached?.Invoke();
    }

    public void BeginStage()
    {
        _isInTransition = false;
        GameManager.IsRunnerInTransition = false;
    }

    public void SetCurrentTile(Tile tile)
    {
        _currentTile = tile;
    }
}
