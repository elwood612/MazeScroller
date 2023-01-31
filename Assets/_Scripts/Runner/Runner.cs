using System;
using System.Collections.Generic;
using Unity.VisualScripting.YamlDotNet.Core.Tokens;
using UnityEngine;

public class Runner : MonoBehaviour
{
    private Tile _currentTile;
    private Tile _targetTile;
    private Tile _previousTile;
    private List<Tile> _mazeTiles = new List<Tile>();
    private float _currentSpeed = 10f;

    private void Update()
    {
        GameManager.AddBoardMotion(transform);
        CalculateSpeed();
        if (_mazeTiles.Count > 0) { Move(); }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("TileCenter"))
        {
            _previousTile = _currentTile;
            _currentTile = other.GetComponentInParent<Tile>();
            TileDecision(_currentTile);
        }
        else if (other.CompareTag("Wall"))
        {
            WallCrossing(other.GetComponent<Wall>());
        }
    }

    private void CalculateSpeed()
    {
        _currentSpeed = Mathf.Abs(GameManager.TileSpeed.z) * 2 + 10f;
    }

    private void Move()
    {
        transform.position = Vector3.MoveTowards(transform.position, _targetTile.transform.position, Time.deltaTime * _currentSpeed);
    }

    /* TileDecision needs a tile parameter for AddTileToPath below,
    *  but we obviously don't want to immediately remove that tile.
    *  Therefore, RemoveTileFromPath and SetNextTarget should use _currentTile.
    */
    private void TileDecision(Tile tile)
    {
        RemoveTileFromPath(_currentTile);

        if (_mazeTiles.Count == 0)
        {
            DrawMaze.OnTileAdded += TileDecision;
            return;
        }
        else
        {
            DrawMaze.OnTileAdded -= TileDecision;
        }

        SetNextTarget(_currentTile);
        transform.GetChild(0).LookAt(_targetTile.transform);
    }

    private void SetNextTarget(Tile tile)
    {
        // Of all possible paths:
        //      if there are uncrossed paths:
        //          if there is one with the lowest z direction, pick that
        //          else pick the oldest one
        //      else (if we're full-on backtracking):
        //          if there is one with the highest z direction && we didn't just come from there, pick that
        //          
        // UPDATE (TRY THIS INSTEAD!!)
        // of all possible paths:
        //      if there are uncrossed paths:
        //          pick first drawn path
        //      else (if we're full-on backtracking):
        //          pick oldest crossed path

        if (GetLeastCrossedPath(tile))
        { 
            _targetTile = GetLeastCrossedPath(tile);
            return;
        }
        if (GetLowestPath(tile))
        {
            _targetTile = GetLowestPath(tile);
            return;
        }
        if (GetOldestCrossedPath(tile))
        {
            _targetTile = GetOldestCrossedPath(tile);
            return;
        }
    }

    private void SetNextTargetNEW(Tile tile)
    {
        _targetTile = GetOldestCrossedPath(tile);
    }

    private Tile GetLeastCrossedPath(Tile tile)
    {
        int leastCrossings = 100;
        Tile toReturn = null;
        
        foreach (Wall wall in tile.NeighborPaths)
        {
            Vector3 direction = wall.transform.position - tile.transform.position;
            if (wall.Crossings < leastCrossings)
            {
                leastCrossings = wall.Crossings;
                toReturn = tile.GetNeighborTile(direction);
            }
            else if (wall.Crossings == leastCrossings)
            {
                toReturn = null;
            }
        }
        return toReturn;
    }

    private Tile GetLowestPath(Tile tile)
    {
        float lowestDirection = 100;
        Tile toReturn = null;

        foreach (Wall wall in tile.NeighborPaths)
        {
            Vector3 direction = wall.transform.position - tile.transform.position;
            if (tile.GetNeighborTile(direction) == _previousTile) { continue; }
            if (Mathf.RoundToInt(direction.normalized.z) < Mathf.RoundToInt(lowestDirection))
            {
                lowestDirection = direction.normalized.z;
                toReturn = tile.GetNeighborTile(direction);
            }
            else if (Mathf.RoundToInt(direction.normalized.z) == Mathf.RoundToInt(lowestDirection))
            {
                toReturn = null;
            }
        }

        return toReturn;
    }

    private Tile GetOldestCrossedPath(Tile tile)
    {
        float oldestCrossing = Mathf.Infinity;
        Tile toReturn = tile;

        foreach (Wall wall in tile.NeighborPaths)
        {
            Vector3 direction = wall.transform.position - tile.transform.position;
            if (wall.TimeCrossed < oldestCrossing)
            {
                oldestCrossing = wall.TimeCrossed;
                toReturn = tile.GetNeighborTile(direction);
            }
        }

        return toReturn;
    }

    protected virtual void WallCrossing(Wall wall)
    {
        // override this in Player.cs
    }

    protected void AddTileToPath(Tile tile)
    {
        _mazeTiles.Add(tile);
    }

    protected void RemoveTileFromPath(Tile tile)
    {
        if (_mazeTiles.Contains(tile)) { _mazeTiles.Remove(tile); }
    }
}
