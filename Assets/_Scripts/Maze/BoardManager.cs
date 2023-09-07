using System.Collections.Generic;
using UnityEngine;

public class BoardManager : MonoBehaviour
{
    [SerializeField] private Camera _cam;
    [SerializeField] private GameObject _rowPrefab;
    [SerializeField] private GameObject _tileSpawnerPrefab;
    [SerializeField] private GameObject _tileDestroyCollider;
    [SerializeField] private GameObject _rowResetCollider;
    [SerializeField] private GameObject _rowSetupCollider;
    [SerializeField] private GameObject _rowQACollider;


    private static List<Tile> _allTiles = new List<Tile>();
    private static List<Wall> _allWalls = new List<Wall>();
    private static List<Row> _allRows = new List<Row>();
    private static Tile _currentPreTransitionTile;
    private static Row _highestDrawnRow;
    private Vector3 _rowResetPos;
    private Vector3 _rowSetupPos;
    private Vector3 _rowQAPos;
    private Vector3 _tileSpawnerPos;
    private Vector3 _tileDestroyPos;
    private float _safetyMargin = 50f;
    private float _destroyMargin = 10f;

    public static List<Tile> AllTiles => _allTiles;
    public static List<Wall> AllWalls => _allWalls;
    public static Tile CurrentPreTransitionTile => _currentPreTransitionTile;
    public static Row HighestDrawnRow => _highestDrawnRow;

    private void Awake()
    {
        Vector3 bottomOfScreen = _cam.ScreenToWorldPoint(new Vector3(Screen.width / 2, 0, 100));
        Vector3 topOfScreen = _cam.ScreenToWorldPoint(new Vector3(Screen.width / 2, Screen.height, 100));
        _safetyMargin = GameManager.TileLength * 5f; // testing!!
        _destroyMargin = GameManager.TileLength; // testing!!
        _rowResetPos = new Vector3(transform.position.x, transform.position.y, bottomOfScreen.z - _safetyMargin);
        _rowSetupPos = new Vector3(transform.position.x, transform.position.y, topOfScreen.z + _safetyMargin);
        _rowQAPos = new Vector3(transform.position.x, transform.position.y, topOfScreen.z + _destroyMargin);
        _tileSpawnerPos = new Vector3(transform.position.x, transform.position.y, topOfScreen.z + _safetyMargin - 1.1f * GameManager.TileLength);
        _tileDestroyPos = new Vector3(transform.position.x, transform.position.y, bottomOfScreen.z - _destroyMargin);

        transform.position = _rowResetPos;
        GameManager.NumberOfRows = Mathf.CeilToInt((_rowSetupPos.z - _rowResetPos.z) / GameManager.TileLength) + 2;
    }

    private void OnEnable()
    {
        GameManager.OnStateChanged += GenerateBoard;
        GameManager.OnCompassionateVictory += ClearAllCrystalsAndChargedTiles;
        GameManager.OnQuitToMenu += ForceReset;
    }

    private void OnDisable()
    {
        GameManager.OnStateChanged -= GenerateBoard;
        GameManager.OnCompassionateVictory -= ClearAllCrystalsAndChargedTiles;
        GameManager.OnQuitToMenu -= ForceReset;
    }

    private void GenerateBoard(GameState state)
    {
        if (state != GameState.Setup) { return; }

        for (int i = 0; i < GameManager.NumberOfRows; i++)
        {
            Row newRow = GenerateRow();
            newRow.gameObject.name = "Row" + i;
            newRow.transform.position += new Vector3(0, 0, i * GameManager.TileLength);
        }

        InstantiateColliders();
        GameManager.Instance.UpdateGameState(GameState.Transition);
        GameManager.OnStateChanged -= GenerateBoard;
    }

    private Row GenerateRow()
    {
        Row row = Instantiate(_rowPrefab, transform).GetComponent<Row>();
        _allRows.Add(row);
        foreach (Tile tile in row.GetComponentsInChildren<Tile>())
        {
            _allTiles.Add(tile);
        }
        foreach (Wall wall in row.GetComponentsInChildren<Wall>())
        {
            _allWalls.Add(wall);
        }
        return row;
    }

    private void InstantiateColliders()
    {
        Instantiate(_rowResetCollider, transform);
        Instantiate(_rowSetupCollider, _rowSetupPos, Quaternion.identity, transform);
        Instantiate(_rowQACollider, _rowQAPos, Quaternion.identity, transform);
        Instantiate(_tileSpawnerPrefab, _tileSpawnerPos, Quaternion.identity, transform);
        Instantiate(_tileDestroyCollider, _tileDestroyPos, Quaternion.identity, transform);
    }

    private void ClearAllCrystalsAndChargedTiles()
    {
        foreach (Tile tile in _allTiles)
        {
            if (tile.AttachedCrystal != null && tile.AttachedCrystal.isActiveAndEnabled)
            {
                tile.RemoveCrystal();
            }
            if (tile.IsCharged)
            {
                tile.SetAsCharged(false);
            }
        }
    }

    private void ForceReset()
    {
        Debug.Log("Forcing a reset");
        Tile refTile = null;
        foreach (Tile tile in _allTiles)
        {
            if (!refTile || 
                (tile.transform.position.z > refTile.transform.position.z && tile.IsMiddleTile))
            {
                refTile = tile;
            }
        }
        refTile.SpawnTile();
        refTile.SetStartingTile(true);
        ClearAllCrystalsAndChargedTiles();
    }

    public static void SetHighestRow(Row inputRow)
    {
        foreach (Row row in _allRows)
        {
            if (row == inputRow)
            {
                row.IsHighestDrawnRow = true;
                _highestDrawnRow = row;
            }
            else
            {
                row.IsHighestDrawnRow = false;
            }
        }
    }
}
