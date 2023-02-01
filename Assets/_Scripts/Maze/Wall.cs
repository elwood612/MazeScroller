using System;
using UnityEngine;

public class Wall : MonoBehaviour
{
    [SerializeField] LayerMask _tileLayer;
    private Renderer[] _renderers;
    private bool _isBorder;
    private bool _isPath;
    public bool _isPathfindingPath;
    private bool _isDestroyed = false;
    public int _crossings = 0;
    private float _timeCrossed;
    private float _timeDrawn;

    public bool IsBorder => _isBorder;
    public bool IsPath => _isPath;
    public bool IsDestroyed => _isDestroyed;
    public int Crossings => _crossings;
    public float TimeDrawn => _timeDrawn;
    public float TimeCrossed => _timeCrossed;
    public bool IsPathfindingPath
    {
        get => _isPathfindingPath;
        set => _isPathfindingPath = value;
    }

    private void Awake()
    {
        _renderers = GetComponentsInChildren<Renderer>();
    }

    private void Start()
    {
        HideWall();
        TryDestroyWall();
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player"))
        {
            PlayerCrossing();
        }
    }

    private void PlayerCrossing()
    {
        _crossings++;
        _timeCrossed = Time.timeSinceLevelLoad;
        if (_isPathfindingPath) { _isPathfindingPath = false; }
    }

    private void UpdateNeighborTiles()
    {
        foreach (Collider collider in Physics.OverlapSphere(transform.position, 1f))
        {
            if (collider.CompareTag("Tile"))
            {
                if (_isPath) 
                { 
                    collider.GetComponent<Tile>().NeighborPaths.Add(this); 
                }
                else 
                { 
                    if (collider.GetComponent<Tile>().NeighborPaths.Contains(this))
                    {
                        collider.GetComponent<Tile>().NeighborPaths.Remove(this);
                    }
                }
            }
        }
    }

    public void SetWallAsBorder()
    {
        _renderers[0].enabled = true;
        _isBorder = true;
        _isPath = false;
        UpdateNeighborTiles();
    }

    public void SetWallAsPath()
    {
        _timeDrawn = Time.timeSinceLevelLoad;
        _renderers[0].enabled = false;
        _isBorder = false;
        _isPath = true;
        UpdateNeighborTiles();
    }

    public void HideWall()
    {
        _renderers[0].enabled = false;
        _isBorder = false;
        _isPath = false;
        _crossings = 0;
    }

    public bool DestroyConditions()
    {
        Collider[] colliders = Physics.OverlapSphere(transform.position, 1f, _tileLayer);
        int destroy = colliders.Length;
        foreach (Collider collider in colliders)
        {
            if (collider.GetComponent<Tile>().IsDestroyed) { destroy--; }
        }
        return destroy == 0;
    }

    // Good but need to account for first row edge case.
    // Also find a good time to call it as tiles get destroyed, because OnRowReset will NOT work
    public void TryDestroyWall() 
    {
        if (!DestroyConditions()) { return; }
        HideWall();
        _renderers[1].enabled = false;
        _isDestroyed = true;
    }
}
