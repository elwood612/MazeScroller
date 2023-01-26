using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GenerateBoard : MonoBehaviour
{
    [SerializeField] private GameObject _rowPrefab;
    private Row _firstRow;

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
        else { StartCoroutine(GenerateBoardQueue()); }
    }

    public IEnumerator GenerateBoardQueue()
    {
        for (int i = 0; i < GameManager.NumberOfRows; i++)
        {
            Row newRow = GenerateRow();
            newRow.gameObject.name = "Row" + i;
            newRow.transform.position += new Vector3(0, 0, i * GameManager.TileLength);

            if (i == 0)
            {
                _firstRow = newRow;
            }
            // THIS IS VERY VERY TEMPORARY PLEASE OK THANK YOU
            if (i == GameManager.Instance.DebugStartTilePosition - 1)
            {
                newRow.transform.GetChild(0).GetChild(0).GetComponent<Tile>().IsStartingTile = true;
            }
            if (i == GameManager.NumberOfRows - 1)
            {
                foreach (Tile tile in newRow.GetComponentsInChildren<Tile>())
                {
                    tile.IsOnLastRow = true;
                    tile.FirstRow = _firstRow;
                    _firstRow.OnRowReset += tile.DelayedSetupWrapper;
                }
            }
        }
        yield return null; // keep this, important! don't want two gameState updates in the same frame
        GameManager.Instance.UpdateGameState(GameState.Idle);
    }

    private Row GenerateRow()
    {
        Row row = Instantiate(_rowPrefab, transform).GetComponent<Row>();
        Tile[] tiles = row.GetComponentsInChildren<Tile>();
        foreach (Tile tile in tiles)
        {
            GenerateTile(tile);
        }
        return row;
    }

    private void GenerateTile(Tile tile)
    {
        if (Random.Range(0, 100) <= GameManager.TileDestroyedChance)
        {
            tile.DestroyTile();
        }
    }
}
