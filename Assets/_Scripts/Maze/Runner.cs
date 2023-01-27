using UnityEngine;

public class Runner : MonoBehaviour
{
    private Vector3 _targetTile;
    private Vector3 _previousTile;
    private float _currentSpeed;
    private int _tilesRemaining = 0;

    private void OnEnable()
    {
        DrawMaze.OnTileAdded += AddTile;
        DrawMaze.OnTileRemoved += RemoveTile;
    }

    private void OnDisable()
    {
        DrawMaze.OnTileAdded -= AddTile;
        DrawMaze.OnTileRemoved -= RemoveTile;
    }

    private void Start()
    {
        
    }

    private void Update()
    {
        GameManager.AddBoardMotion(transform);
        if (_tilesRemaining > 0) { Move(); }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("TileCenter"))
        {
            TileDecision(other.gameObject.GetComponentInParent<Tile>());
        }
    }

    private void Move()
    {
        transform.position = Vector3.MoveTowards(transform.position, _targetTile, Time.deltaTime * _currentSpeed);
    }

    private void TileDecision(Tile tile)
    {
        RemoveTile();
    }

    private void AddTile()
    {
        _tilesRemaining++;
        //Debug.Log("Tiles remaining: " + _tilesRemaining);
    }

    private void RemoveTile()
    {
        _tilesRemaining = _tilesRemaining > 0 ? _tilesRemaining - 1 : 0;
        //Debug.Log("Tiles remaining: " + _tilesRemaining);
    }
}
