using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;

public class GenerateBoard : MonoBehaviour
{
    [SerializeField] private GameObject _rowPrefab;
    private Row _firstRow;
    private Tile _startingTile;
    private static List<Tile> _allTiles = new List<Tile>();
    private static List<Wall> _allWalls = new List<Wall>();

    //public static event Action OnTilesSetup;
    //public static event Action OnWallsSetup;
    public static List<Tile> AllTiles => _allTiles;
    public static List<Wall> AllWalls => _allWalls;

    private void OnEnable()
    {
        GameManager.OnStateChanged += GenerateBoardQueueWrapper;
    }

    private void OnDisable()
    {
        GameManager.OnStateChanged -= GenerateBoardQueueWrapper;
    }

    private void GenerateBoardQueueWrapper(GameState state)
    {
        if (state != GameState.Setup) { return; }
        else { SpawnRows(); }
    }

    public void SpawnRows()
    {
        for (int i = 0; i < GameManager.NumberOfRows; i++)
        {
            Row newRow = GenerateRow();
            newRow.gameObject.name = "Row" + i;
            newRow.transform.position += new Vector3(0, 0, i * GameManager.TileLength);

            //if (i == 0)
            //{
            //    _firstRow = newRow;
            //    foreach (Wall wall in newRow.GetComponentsInChildren<Wall>())
            //    {
            //        wall.IsOnFirstRow = true;
            //        wall.FirstRow = _firstRow;
            //        _firstRow.OnRowReset += wall.DelayedSetupWrapper;
            //    }
            //}
            //// THIS IS VERY VERY TEMPORARY PLEASE OK THANK YOU
            //if (i == GameManager.Instance.DebugStartTilePosition - 1)
            //{
            //    _startingTile = newRow.transform.GetChild(0).GetChild(0).GetComponent<Tile>();
            //    _startingTile.IsStartingTile = true;
            //}
            //if (i == GameManager.NumberOfRows - 1)
            //{
            //    foreach (Tile tile in newRow.GetComponentsInChildren<Tile>())
            //    {
            //        tile.IsOnLastRow = true;
            //        tile.FirstRow = _firstRow;
            //        _firstRow.OnRowReset += tile.DelayedSetupWrapper;
            //    }
            //}
        }
        GameManager.Instance.UpdateGameState(GameState.Idle);
        //yield return null;
        //OnTilesSetup?.Invoke();
        //yield return null;
        //OnWallsSetup?.Invoke();
        //yield return null;
        //SpawnRunner();
        //GameManager.Instance.UpdateGameState(GameState.Idle);
    }

    private Row GenerateRow()
    {
        Row row = Instantiate(_rowPrefab, transform).GetComponent<Row>();
        foreach (Tile tile in row.GetComponentsInChildren<Tile>())
        {
            _allTiles.Add(tile);
            //tile.HideTile();
        }
        foreach (Wall wall in row.GetComponentsInChildren<Wall>())
        {
            _allWalls.Add(wall);
            //wall.HideWall();
        }
        return row;
    }

    private void SpawnRunner()
    {
        Instantiate(GameManager.Instance.RunnerPrefab, _startingTile.transform.position, Quaternion.identity, transform);
    }
}
