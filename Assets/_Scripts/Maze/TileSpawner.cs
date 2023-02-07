using System.Collections;
using UnityEngine;

public class TileSpawner : MonoBehaviour
{
    private int _disableTileCounter = 0;
    private int _randomDisableTile = 5;
    private int _crystalSpawnCounter = 0;
    private int _randomCrystalSpawn = 5;
    private float _width;
    private float _xPos;
    public float _smooth = 3f; // the larger this is, the slower you move
    private float _delta = 0.1f;
    private bool _toggle = false;
    private float _middleOfScreen, _edgeOfScreen;
    private Vector3 _target;
    private Vector3 _velocity = Vector3.zero;
    private AnimationCurve _widthCurve;
    private WaitForSeconds _crystalDelay = new WaitForSeconds(0.1f);

    private void Awake()
    {
        Initialize();
    }

    private void Initialize()
    {
        _widthCurve = GameManager.Instance.TileSpawnerWidthCurve;
        _target = transform.position;
        _middleOfScreen = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width / 2, Screen.height, 100)).x;
        _edgeOfScreen = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width, Screen.height, 100)).x;
        CalculateWidth(GameManager.Instability); // we subscribe too late to catch the first state update, need to call it manually
    }

    private void OnEnable()
    {
        GameManager.OnInstabilityChanged += CalculateWidth;
    }

    private void OnDisable()
    {
        GameManager.OnInstabilityChanged -= CalculateWidth;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Row"))
        {
            if (++_disableTileCounter > _randomDisableTile && _width > 1.1f)
            {
                _disableTileCounter = 0;
                _randomDisableTile = Random.Range(3, 10);
                int tilesToDisable = Mathf.Max(1, Random.Range(0, GameManager.Instability * 4 / GameManager.MaxInstability));
                StartCoroutine(DisableRandomTile(other.GetComponent<Row>(), tilesToDisable));
            }

            if (++_crystalSpawnCounter > _randomCrystalSpawn && _width > 1.1f)
            {
                _crystalSpawnCounter = 0;
                _randomCrystalSpawn = Random.Range(2, 16);
                int level = 1;
                StartCoroutine(SpawnRandomCrystal(other.GetComponent<Row>(), level));
            }
        }
    }

    private void Update()
    {
        if (Vector3.Magnitude(transform.position - _target) < _delta && GameManager.Instability > 0) 
        { 
            SetNewTarget();
        }
        UpdateSizeAndPosition();
    }

    private void UpdateSizeAndPosition()
    {
        _smooth = Mathf.Clamp(GameManager.MaxSpeed / GameManager.TileSpeed, 3f, 50f);
        transform.localScale = new Vector3(_width * GameManager.TileLength, 1, 1);
        transform.position = Vector3.SmoothDamp(transform.position, _target, ref _velocity, _smooth);
    }

    private void CalculateWidth(int instability)
    {
        // !! DO NOT DELETE THE CASTS !! V.S. IS WRONG !!
        _width = _widthCurve.Evaluate((float)instability / (float)GameManager.MaxInstability);
    }

    private void SetNewTarget()
    {
        int sign = _toggle ? 1 : -1;
        _toggle = _toggle ? false : true;

        _xPos = Random.Range(_middleOfScreen, _edgeOfScreen - _width * GameManager.TileLength / 2);
        _target = new Vector3(_xPos * sign, transform.position.y, transform.position.z);
    }

    private IEnumerator DisableRandomTile(Row row, int amount)
    {
        yield return null;
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
        if (tile.IsEnabled) { tile.SpawnCrystal(level); }
    }
}
