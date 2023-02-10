using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Pool;

public class TileSpawner : MonoBehaviour
{
    [SerializeField] private Crystal _crystalPrefab;
    [SerializeField] private OrbitMissile _missilePrefab;
    [SerializeField] private Color[] _colors; 

    private int _disableTileCounter = 0;
    private int _randomDisableTile = 5;
    private int _crystalSpawnCounter = 0;
    private int _randomCrystalSpawn = 5;
    private int _crystalMaxColors = 0;
    public float _width = 0.5f;
    private float _minWidth = 0.5f;
    private float _xPos;
    private float _smooth = 3f; // the larger this is, the slower you move
    private float _delta = 0.1f;
    private bool _toggle = false;
    private float _middleOfScreen, _edgeOfScreen;
    private Vector3 _positionTarget;
    private Vector3 _scaleTarget;
    private Vector3 _positionVelocity = Vector3.zero;
    private Vector3 _scaleVelocity = Vector3.zero;
    private WaitForSeconds _crystalDelay = new WaitForSeconds(0.5f);
    private ObjectPool<Crystal> _crystalPool;

    private void Awake()
    {
        _positionTarget = transform.position;
        _scaleTarget = transform.localScale;
        _middleOfScreen = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width / 2, Screen.height, 100)).x;
        _edgeOfScreen = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width, Screen.height, 100)).x;
        InitializeCrystalPool();
    }

    private void InitializeCrystalPool()
    {
        _crystalPool = new ObjectPool<Crystal>(() => 
        { 
            return Instantiate(_crystalPrefab);
        }, crystal =>
        {
            crystal.gameObject.SetActive(true);
        }, crystal =>
        {
            crystal.gameObject.SetActive(false);
            crystal.transform.SetParent(transform, false);
        }, crystal =>
        {
            Destroy(crystal.gameObject);
        }, false, 10, 20);
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Row"))
        {
            if (GameManager.CurrentState == GameState.Transition) { return; }

            if (++_disableTileCounter > _randomDisableTile)
            {
                _disableTileCounter = 0;
                _randomDisableTile = Random.Range(2, 5);
                int tilesToDisable = 1;
                StartCoroutine(DisableRandomTile(other.GetComponent<Row>(), tilesToDisable));
            }

            if (++_crystalSpawnCounter > _randomCrystalSpawn && _width > 1.1f)
            {
                _crystalSpawnCounter = 0;
                _randomCrystalSpawn = Random.Range(1, 2);
                int level = Mathf.RoundToInt(Random.Range(0f, GameManager.Progress * 4f / GameManager.MaxProgress));
                StartCoroutine(SpawnRandomCrystal(other.GetComponent<Row>(), level));
            }
        }
    }

    private void Update()
    {
        if (Vector3.Magnitude(transform.position - _positionTarget) < _delta) 
        { 
            SetNewPosition();
        }
        if (Vector3.Magnitude(transform.localScale - _scaleTarget) < _delta && GameManager.Progress > 1)
        {
            SetNewScale();
        }
        UpdateSizeAndPosition();
    }

    private void UpdateSizeAndPosition()
    {
        if (GameManager.CurrentState == GameState.Transition) { _smooth = 3f; }
        else { _smooth = Mathf.Clamp(GameManager.MaxSpeed / GameManager.TileSpeed, 3f, 80f); }
        
        transform.localScale = Vector3.SmoothDamp(transform.localScale, _scaleTarget, ref _scaleVelocity, _smooth / 4);
        transform.position = Vector3.SmoothDamp(transform.position, _positionTarget, ref _positionVelocity, _smooth);
    }

    private void SetNewPosition()
    {
        int sign = _toggle ? 1 : -1;
        _toggle = _toggle ? false : true;

        _xPos = Random.Range(_middleOfScreen, _edgeOfScreen - _width * GameManager.TileLength / 2);
        _positionTarget = new Vector3(_xPos * sign, transform.position.y, transform.position.z);
    }

    private void SetNewScale()
    {
        if (GameManager.CurrentState == GameState.Transition)
        {
            _width = _minWidth;
        }
        else if (GameManager.CurrentState == GameState.Progressing)
        {
            switch (GameManager.Stage)
            {
                case 1:
                    _width = Random.Range(1.2f, 2.8f);
                    break;
                case 2:
                    _width = Random.Range(1.8f, 3.8f);
                    break;
                case 3:
                    _width = Random.Range(2.2f, 4.8f);
                    break;
                case 4:
                    _width = Random.Range(3.2f, 4.8f);
                    break;
            }
        }
        _scaleTarget = new Vector3(_width * GameManager.TileLength, 1, 1);
    }

    private IEnumerator DisableRandomTile(Row row, int amount)
    {
        yield return null;
        if (row.EnabledTiles.Count <= 1) { yield break; }
        Tile tile = row.EnabledTiles[Random.Range(0, row.EnabledTiles.Count)];
        tile.DisableTile(true);

        if (amount == 1) { yield break; }
        for (int i = 0; i < amount; i++)
        {
            tile.NeighborTiles[Random.Range(0, tile.NeighborTiles.Count)].DisableTile();
        }
    }

    private IEnumerator SpawnRandomCrystal(Row row, int level)
    {
        yield return _crystalDelay;
        Tile tile = row.EnabledTiles[Random.Range(0, row.EnabledTiles.Count)];
        if (!tile.IsEnabled || tile.IsColored) { yield break; }

        Crystal newCrystal = _crystalPool.Get();
        Color color = _colors[Random.Range(0, GameManager.Stage)]; // needs to depend on Stage
        if (color != Color.white)
        {
            color = Random.Range(0f, 1f) < 0.5f ? Color.white : color; // Temp, should make colors rarer
        }
        newCrystal.transform.SetParent(tile.transform, false);
        newCrystal.Initialize(level, _crystalPool, color);
        tile.HasCrystal = true;

        if (color == Color.white) { yield break; }
        List<Tile> tiles = new List<Tile>();
        foreach (Tile t in BoardManager.AllTiles)
        {
            if (Vector3.Distance(t.transform.position, tile.transform.position) < GameManager.TileLength * 3 + 0.5f && 
                t.transform.position.z <= tile.transform.position.z &&
                t.IsEnabled &&  
                !t.HasCrystal)
            {
                tiles.Add(t);
            }
        }
        tiles[Random.Range(0, tiles.Count)].SetColor(color);
    }
}
