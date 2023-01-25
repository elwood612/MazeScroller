using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GenerateBoard : MonoBehaviour
{
    [SerializeField] private GameObject _rowPrefab;

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
        Queue<GameObject> boardQueue = new Queue<GameObject>();
        for (int i = 0; i < GameManager.NumberOfRows; i++)
        {
            GameObject newRow = GenerateRow();
            newRow.name = "Row" + i;
            newRow.transform.position += new Vector3(0, 0, i * GameManager.TileLength);

            // THIS IS VERY VERY TEMPORARY PLEASE OK THANK YOU
            if (i == GameManager.Instance.DebugStartTilePosition - 1)
            {
                newRow.transform.GetChild(0).GetChild(0).GetComponent<Tile>().SetStartingTile();
            }

            boardQueue.Enqueue(newRow);
        }
        GameManager.Instance.BoardQueue = boardQueue;
        yield return null; // important! don't want two gameState updates in the same frame
        GameManager.Instance.UpdateGameState(GameState.Idle);
    }

    private GameObject GenerateRow()
    {
        GameObject row = Instantiate(_rowPrefab, transform);
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
            tile.SetTileAsDestroyed();
        }
    }
}
