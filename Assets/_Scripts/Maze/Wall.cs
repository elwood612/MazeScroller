using System.Collections.Generic;
using UnityEngine;

public class Wall : MonoBehaviour
{
    [SerializeField] LayerMask _tileLayer;
    [SerializeField] private Renderer _wallRenderer;
    [SerializeField] private Renderer _lineRenderer;
    [SerializeField] private Renderer _glowRendererLeft;
    [SerializeField] private Renderer _glowRendererRight;
    [SerializeField] private Material _lineBase;

    private bool _isBorder;
    public bool _isPath;
    public bool _isPathfindingPath;
    private bool _isHidden = false;
    private bool _firstSpawnInStage = true;
    private int _crossings = 0;
    private float _timeCrossed = Mathf.Infinity;
    private float _timeDrawn = Mathf.Infinity;
    private float _emissionColorIntensity = 3.5f;
    private Row _parentRow;
    private List<Tile> _neighborTiles = new List<Tile>();
    private Tile _leftTile, _rightTile;
    private Material _baseMaterial;

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

    private void Awake()
    {
        _baseMaterial = new Material(_lineBase);
        _lineRenderer.material = _baseMaterial;
        _parentRow = GetComponentInParent<Row>();
        DisableWall();
    }

    private void OnEnable()
    {
        _parentRow.OnRowReset += ResetWall;
        _parentRow.OnRowSetup += GetNeighbors;
        _parentRow.OnRowTransition += ResetColor;
    }

    private void OnDisable()
    {
        _parentRow.OnRowReset -= ResetWall;
        _parentRow.OnRowSetup -= GetNeighbors;
        _parentRow.OnRowTransition -= ResetColor;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Runner"))
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
                if (tile.IsColored)
                {
                    if (tile.NeighborPaths.Count == 1) { tile.SetTileAsDeadEnd(transform); }
                    else { tile.UndoDeadEnd(); }
                }
            }
            else
            {
                if (tile.NeighborPaths.Contains(this)) { tile.NeighborPaths.Remove(this); }
            }
        }
    }

    private void ResetColor(float unused)
    {
        _baseMaterial = new Material(_lineBase);
        _firstSpawnInStage = true;
    }

    public void SetWallAsBorder()
    {
        _wallRenderer.enabled = true;
        if (_leftTile != null && _leftTile.IsPartOfMaze) { _glowRendererLeft.enabled = true; }
        if (_rightTile != null && _rightTile.IsPartOfMaze) { _glowRendererRight.enabled = true; }
        _isBorder = true;
        _isPath = false;
        UpdateNeighborTiles();
    }

    public void SetWallAsHiddenBorder()
    {
        _isBorder = true;
        _isPath = false;
        UpdateNeighborTiles();
    }

    public void SetWallAsPath()
    {
        _timeDrawn = Time.timeSinceLevelLoad;
        _wallRenderer.enabled = false;
        _glowRendererLeft.enabled = false;
        _glowRendererRight.enabled = false;
        _isBorder = false;
        _isPath = true;
        UpdateNeighborTiles();
    }

    public void UndoWallAsBorder()
    {
        _wallRenderer.enabled = false;
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
        _timeCrossed = Mathf.Infinity;
        _timeDrawn = Mathf.Infinity;
        DisableWall();
    }

    private void DisableWall() 
    {
        _wallRenderer.enabled = false;
        _lineRenderer.enabled = false;
        _glowRendererLeft.enabled = false;
        _glowRendererRight.enabled = false;
        _isHidden = true;
    }

    public void EnableWall()
    {
        _lineRenderer.enabled = true;
        _isHidden = false;

        if (_firstSpawnInStage && GameManager.CurrentState == GameState.Progressing)
        {
            _baseMaterial.color = GameManager.Instance.Parameters[GameManager.CurrentStage].TileColor;
            _baseMaterial.SetColor("_EmissionColor", _baseMaterial.color * _emissionColorIntensity);
            _lineRenderer.material = _baseMaterial;
            _firstSpawnInStage = false;
        }
    }

    public void TryDisable()
    {
        foreach (Tile tile in _neighborTiles)
        {
            if (tile.IsEnabled) { return; }
        }
        DisableWall();
    }

    public void HideWall()
    {
        DisableWall();
        _lineRenderer.enabled = true;
    }

    public void GetNeighbors()
    {
        foreach (Tile tile in BoardManager.AllTiles)
        {
            if (Vector3.Distance(tile.transform.position, transform.position) < (GameManager.TileLength / 2) + 0.5f)
            {
                _neighborTiles.Add(tile);
                // Let's prettify this maybe?
                if (GameManager.CompareVectorsAsInts(transform.position + Vector3.right * GameManager.TileLength / 2, tile.transform.position) ||
                    GameManager.CompareVectorsAsInts(transform.position + Vector3.back * GameManager.TileLength / 2, tile.transform.position))
                {
                    _rightTile = tile;
                }
                else if (GameManager.CompareVectorsAsInts(transform.position + Vector3.left * GameManager.TileLength / 2, tile.transform.position) ||
                    GameManager.CompareVectorsAsInts(transform.position + Vector3.forward * GameManager.TileLength / 2, tile.transform.position))
                {
                    _leftTile = tile;
                }
            }
        }
    }
}
