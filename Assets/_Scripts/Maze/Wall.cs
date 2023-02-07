using System.Collections.Generic;
using UnityEngine;

public class Wall : MonoBehaviour
{
    [SerializeField] LayerMask _tileLayer;
    private Renderer[] _renderers;
    private Rigidbody _rb;
    private bool _isBorder;
    private bool _isPath;
    public bool _isPathfindingPath;
    private bool _isHidden = false;
    public int _crossings = 0;
    private float _timeCrossed;
    private float _timeDrawn;
    private Row _parentRow;
    private List<Tile> _neighborTiles = new List<Tile>();

    public bool IsBorder => _isBorder;
    public bool IsPath => _isPath;
    public bool IsDestroyed => _isHidden;
    public int Crossings => _crossings;
    public float TimeDrawn => _timeDrawn;
    public float TimeCrossed => _timeCrossed;
    public bool IsPathfindingPath
    {
        get => _isPathfindingPath;
        set => _isPathfindingPath = value;
    }

    private void OnEnable()
    {
        _parentRow.OnRowReset += ResetWall;
        _parentRow.OnRowSetup += GetNeighbors;
    }

    private void OnDisable()
    {
        _parentRow.OnRowReset -= ResetWall;
        _parentRow.OnRowSetup -= GetNeighbors;
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
        foreach (Tile tile in _neighborTiles)
        {
            if (_isPath)
            {
                tile.NeighborPaths.Add(this);
            }
            else
            {
                if (tile.NeighborPaths.Contains(this)) { tile.NeighborPaths.Remove(this); }
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

    public void UndoWallAsBorder()
    {
        _renderers[0].enabled = false;
        _isBorder = false;
        _isPath = false;
        UpdateNeighborTiles();
    }

    private void ResetWall()
    {
        _crossings = 0;
        _isBorder = false;
        _isPath = false;
        _isPathfindingPath = false;
        _isHidden = false;
        //_rb.isKinematic = true;
        //_rb.transform.SetLocalPositionAndRotation(new Vector3(0, 1, 0), Quaternion.identity);
        DisableWall();
    }

    private void DisableWall() 
    {
        _renderers[0].enabled = false;
        _renderers[1].enabled = false;
        _isHidden = true;
    }

    public void EnableWall()
    {
        _renderers[1].enabled = true;
        _isHidden = false;
    }

    public void TryDisable()
    {
        foreach (Tile tile in _neighborTiles)
        {
            if (tile.IsEnabled) { return; }
        }
        DisableWall();
    }

    public void DestroyWall()
    {
        //_rb.isKinematic = false;
        //Vector3 impulse = new Vector3(Random.Range(-50f, 50f), Random.Range(-50f, 0), Random.Range(-50f, 50f));
        //_rb.AddForce(impulse, ForceMode.Impulse);
        DisableWall();
    }

    public void GetNeighbors()
    {
        foreach (Tile tile in BoardManager.AllTiles)
        {
            if (Vector3.Distance(tile.transform.position, transform.position) < (GameManager.TileLength / 2) + 0.5f)
            {
                _neighborTiles.Add(tile);
            }
        }
    }

    public void Initialize()
    {
        _renderers = GetComponentsInChildren<Renderer>();
        _parentRow = GetComponentInParent<Row>();
        _rb = GetComponentInChildren<Rigidbody>();
        DisableWall();
    }

    private void Awake()
    {
        Initialize();
    }
}
