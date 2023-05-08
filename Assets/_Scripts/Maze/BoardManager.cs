using System.Collections.Generic;
using UnityEngine;

public class BoardManager : MonoBehaviour
{
    [SerializeField] private GameObject _rowPrefab;
    [SerializeField] private GameObject _tileSpawnerPrefab;
    [SerializeField] private GameObject _tileDestroyCollider;
    [SerializeField] private GameObject _rowResetCollider;
    [SerializeField] private GameObject _rowSetupCollider;
    [SerializeField] private GameObject _rowQACollider;
    [SerializeField] private float _safetyMargin;

    private static List<Tile> _allTiles = new List<Tile>();
    private static List<Wall> _allWalls = new List<Wall>();
    private Vector3 _rowResetPos;
    private Vector3 _rowSetupPos;
    private Vector3 _rowQAPos;
    private Vector3 _tileSpawnerPos;
    private Vector3 _tileDestroyPos;
    private float _destroyMargin = 1f;

    public static List<Tile> AllTiles => _allTiles;
    public static List<Wall> AllWalls => _allWalls;

    private void Awake()
    {
        Initialize();
    }

    private void Initialize()
    {
        Vector3 bottomOfScreen = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width / 2, 0, 100));
        Vector3 topOfScreen = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width / 2, Screen.height, 100));
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
        GameManager.OnCompassionateVictory += ClearAllCrystals;
    }

    private void OnDisable()
    {
        GameManager.OnStateChanged -= GenerateBoard;
        GameManager.OnCompassionateVictory -= ClearAllCrystals;
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

    private void ClearAllCrystals()
    {
        foreach (Tile tile in _allTiles)
        {
            if (tile.AttachedCrystal != null && tile.AttachedCrystal.isActiveAndEnabled)
            {
                tile.RemoveCrystal();
            }
        }
    }
}
