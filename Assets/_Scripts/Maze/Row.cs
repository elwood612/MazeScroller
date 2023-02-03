using System;
using UnityEngine;

public class Row : MonoBehaviour
{
    private bool _isHighestDrawnRow;
    private bool _hasSetupBeenRun = false;

    public event Action OnRowReset;
    public event Action OnRowSetup;

    public bool HasSetupBeenRun => _hasSetupBeenRun;
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
        if (other.CompareTag("RowReset")) { ResetRow(); }
        else if (other.CompareTag("RowSetup")) { SetupRow(); }
    }

    private float CalculateHeight()
    {
        Vector3 screenPos = Camera.main.WorldToScreenPoint(transform.position);
        return screenPos.y / Screen.height;
    }

    private void ResetRow()
    {
        transform.position += GameManager.BoardLength;
        OnRowReset?.Invoke();
    }

    private void SetupRow()
    {
        if (_hasSetupBeenRun) { return; }
        OnRowSetup?.Invoke();
        _hasSetupBeenRun = true;
    }
}
