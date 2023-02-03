using UnityEngine;

public class TileSpawner : MonoBehaviour
{
    private float _width;
    private float _xPos;
    private float _speed;
    private Vector3 _target;

    private void Awake()
    {
        _width = GameManager.TileLength;
    }

    private void Update()
    {
        CalculateWidth();
        CalculateTarget();
        UpdateSizeAndPosition();
    }

    private void CalculateWidth()
    {
        // set _width
    }

    private void CalculateTarget()
    {
        // set _xPos;
        _target = new Vector3(_xPos, 0, 0);
    }

    private void UpdateSizeAndPosition()
    {
        transform.localScale = new Vector3(_width, 1, 1);
        transform.position = Vector3.Lerp(transform.position, _target, Time.deltaTime * _speed);
    }
}
