using System;
using UnityEngine;

public class Row : MonoBehaviour
{
    private bool _isHighestDrawnRow;

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
        if (other.CompareTag("BottomOfBoard")) { SendBackToTop(); }
    }

    private float CalculateHeight()
    {
        Vector3 screenPos = Camera.main.WorldToScreenPoint(transform.position);
        return screenPos.y / Screen.height;
    }

    private void SendBackToTop()
    {
        transform.position += GameManager.BoardLength;
        OnRowReset?.Invoke();
    }
}
