using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Runner : MonoBehaviour, IRunner
{
    [SerializeField] private Renderer[] _renderers;
    [SerializeField] private ParticleSystem _particles;
    private ParticleSystem.MainModule _particlesMainModule;

    private Tile _currentTile;
    private Tile _currentTarget;
    private Tile _nextTarget;
    private Tile _previousTile;
    private List<Tile> _uncrossedTilesInMaze = new List<Tile>();
    private float _currentSpeed;
    private bool _runnerStopped = true;
    private bool _approachingDeadEnd = false;
    private bool _particlesStart = true;
    private AnimationCurve _speedCurve;
    protected Rigidbody _rb;

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
        _rb = GetComponent<Rigidbody>();
        _particlesMainModule = _particles.main;
        ChangeColor(Color.white);
    }

    private void Update()
    {
        GameManager.AddBoardMotion(transform);
        CalculateSpeed();
        if (_uncrossedTilesInMaze.Count > 0) { Move(); }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("TileCenter"))
        {
            SetTarget(other.GetComponentInParent<Tile>());
            //if (_particlesStart)
            //{
            //    _particlesMainModule.customSimulationSpace = other.transform;
            //    _particlesStart = false;
            //}
        }
        else if (other.CompareTag("TileDestroyer"))
        {
            SelfDestruct();
        }
        else if (other.CompareTag("Crystal"))
        {
            ChangeColor(Color.white);
        }
    }

    private void CalculateSpeed() // this needs to change
    {
        Vector3 screenPos = Camera.main.WorldToScreenPoint(transform.position);
        float height = screenPos.y / Screen.height;
        _currentSpeed = _speedCurve.Evaluate(height) + GameManager.TileSpeed;
    }

    private void Move()
    {
        transform.position = Vector3.MoveTowards(transform.position, _currentTarget.transform.position, Time.deltaTime * _currentSpeed);
    }

    private void SetTarget(Tile tile) // On tile center
    {
        RemoveTileFromPath(_currentTile);

        if (_uncrossedTilesInMaze.Count == 0)
        {
            _runnerStopped = true;
            DrawMaze.OnTileAdded += SetTarget;
            return;
        }
        else
        {
            if (_runnerStopped)
            {
                _runnerStopped = false;
                CalculateNextTargetWrapper(_currentTile);
            }
            DrawMaze.OnTileAdded -= SetTarget;
        }

        _currentTarget = _nextTarget;
        if (_currentTarget != null) { transform.GetChild(0).LookAt(_currentTarget.transform); }
    }

    private IEnumerator CalculateNextTarget(Tile tile) // On tile edge
    {
        _approachingDeadEnd = tile.NeighborPaths.Count == 1;

        if (_currentTile.NeighborPaths.Count == 0) { yield break; }

        if (GetPathfindingPath(_currentTile) != _currentTile)
        {
            _nextTarget = GetPathfindingPath(_currentTile);
            yield break;
        }

        switch (tile.NeighborPaths.Count)
        {
            case 1:
            case 2:
                _nextTarget = GetOldestCrossedPath(_currentTile);
                break;
            case 3:
            case 4:
                if (GetFirstUncrossedPath(_currentTile) != _currentTile)
                {
                    _nextTarget = GetFirstUncrossedPath(_currentTile);
                }
                else
                {
                    yield return new WaitUntil(() => ExecutePathfinding(_currentTile, _uncrossedTilesInMaze[0]));
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
        Debug.Log("Whelp. Something went wrong");
        return false; // should never happen inshallah
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
        if (_approachingDeadEnd) { CalculateNextTargetWrapper(_currentTile); }
        _uncrossedTilesInMaze.Add(tile);
    }

    protected void RemoveTileFromPath(Tile tile)
    {
        if (_uncrossedTilesInMaze.Contains(tile)) { _uncrossedTilesInMaze.Remove(tile); }
    }

    protected virtual void SelfDestruct()
    {
        // override in inheriting classes
    }

    public void CalculateNextTargetWrapper(Tile tile)
    {
        StartCoroutine(CalculateNextTarget(tile));
    }

    public void ChangeColor(Color color)
    {
        foreach (var renderer in _renderers)
        {
            renderer.material.color = color;
        }
        // also set trail
    }
}
