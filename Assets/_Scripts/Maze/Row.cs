using System;
using System.Collections;
using UnityEngine;

public class Row : MonoBehaviour
{
    private bool _isHighestDrawnRow;
    private int _tilesToDraw = 5;

    public event Action OnRowReset;
    public bool IsHighestDrawnRow
    {
        get => _isHighestDrawnRow;
        set => _isHighestDrawnRow = value;
    }

    private void Update()
    {
        GameManager.AddBoardMotion(transform);
        if (_isHighestDrawnRow) { GameManager.HighestDrawnRowHeight = CalculateHeight(); }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("BottomOfBoard")) { ResetRow(); }
        else if (other.CompareTag("TopOfBoard")) { SetupRow(); }
    }

    private float CalculateHeight()
    {
        Vector3 screenPos = Camera.main.WorldToScreenPoint(transform.position);
        return screenPos.y / Screen.height;
    }

    private void ResetRow()
    {
        transform.position += GameManager.BoardLength;
        foreach (Tile tile in GetComponentsInChildren<Tile>())
        {
            tile.ResetTile();
        }
        foreach (Wall wall in GetComponentsInChildren<Wall>())
        {
            wall.ResetWall();
        }
        OnRowReset?.Invoke();
    }

    private void SetupRow()
    {
        foreach (Tile tile in GetComponentsInChildren<Tile>())
        {
            tile.Setup();
        }
        foreach (Wall wall in GetComponentsInChildren<Wall>())
        {
            wall.Setup();
        }
        for (int i = 0; i < _tilesToDraw; i++)
        {
            transform.GetChild(0).GetChild(i).GetComponent<Tile>().UnhideTile();
        }
    }
}
