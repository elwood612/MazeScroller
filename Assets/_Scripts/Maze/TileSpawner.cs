//using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Pool;
//using Random = System.Random;

public class TileSpawner : MonoBehaviour
{
    #region Variables
    [SerializeField] private Crystal _crystalPrefab;
    [SerializeField] private OrbitMissile _missilePrefab;
    [SerializeField] private Color[] _colors; 

    private int _counterDisableTile = 0;
    private int _counterColorSpawn = 0;
    private int _counterSpawnCrystal = 0;
    private int _counterCrystalLevel = 0;
    private int _triggerDisableTile = 2;
    private int _triggerColorSpawn = 8;
    private int _triggerCrystalLevel = 4;
    private int _triggerTutorialCrystalSpawn = 5;
    private int _triggerTutorialColorSpawn = 5;
    private bool _tutorialFirstCrystal = true;
    private bool _tutorialSecondCrystal = false;
    private bool _tutorialThirdCrystal = false;
    private bool _goldCrystalCanBeSpawned = true;
    public float _width = 0.5f;
    private float _transitionWidth = 0.5f;
    private float _xPos;
    private float _smooth = 3f; // the larger this is, the slower you move
    private float _delta = 0.1f;
    private bool _toggle = false;
    private float _middleOfScreen, _edgeOfScreen;
    private Vector3 _targetPosition;
    private Vector3 _targetScale;
    private Vector3 _positionVelocity = Vector3.zero;
    private Vector3 _scaleVelocity = Vector3.zero;
    private WaitForSeconds _crystalDelay = new WaitForSeconds(0.8f);
    private WaitForSeconds _colorDelay = new WaitForSeconds(0.4f);
    private WaitForSeconds _goldCrystalDelay = new WaitForSeconds(5f);
    private ObjectPool<Crystal> _crystalPool;
    private int _missingTilesChance = 2;
    private int _chargedMinRows = 5;
    private int _chargedMaxRows = 8;
    private float _widthMin = 2.1f;
    private float _widthMax = 2.9f;
    private float _crystalSpawnModifier = 1f;
    private float _crystalSpawnChance => _crystalSpawnModifier * GameManager.Instance.GameSettings.CrystalSpawnChance
            .Evaluate(Random.Range(0f, (float)GameManager.StageProgress / (float)GameManager.StageLength));
    #endregion

    #region Initialization
    private void Awake()
    {
        _targetPosition = transform.position;
        _targetScale = transform.localScale;
        _middleOfScreen = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width / 2, Screen.height, 100)).x;
        _edgeOfScreen = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width, Screen.height, 100)).x;
        InitializeCrystalPool();
        SetupNewStage();
    }

    private void OnEnable()
    {
        Tile.OnCrystalRemoval += RemoveCrystal;
        GameManager.OnStateChanged += SetNewScale;
        GameManager.OnSetupNextStage += SetupNewStage;
        Crystal.OnFirstCrystal += EnableSecondCrystal;
    }

    private void OnDisable()
    {
        Tile.OnCrystalRemoval -= RemoveCrystal;
        GameManager.OnStateChanged -= SetNewScale;
        GameManager.OnSetupNextStage -= SetupNewStage;
        Crystal.OnFirstCrystal -= EnableSecondCrystal;
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
    #endregion

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Row"))
        {
            if (GameManager.CurrentState == GameState.Transition) { return; }

            if (++_counterDisableTile > _triggerDisableTile)
            {
                _counterDisableTile = 0;
                StartCoroutine(DisableRandomTile(other.GetComponent<Row>()));
            }

            if (!GameManager.DoTutorial)
            {
                if (++_counterColorSpawn > _triggerColorSpawn)
                {
                    _counterColorSpawn = 0;
                    StartCoroutine(SpawnRandomCharged(other.GetComponent<Row>()));
                }

                StartCoroutine(SpawnCrystal(other.GetComponent<Row>()));
            }
            #region Tutorial Stuff
            else
            {
                if (++_counterColorSpawn > _triggerTutorialColorSpawn)
                {
                    if (_tutorialSecondCrystal)
                    {
                        _counterColorSpawn = 0;
                        StartCoroutine(SpawnSpecificCharged(other.GetComponent<Row>()));
                    }
                }

                if (++_counterSpawnCrystal > _triggerTutorialCrystalSpawn)
                {
                    if (_tutorialFirstCrystal)
                    {
                        _counterSpawnCrystal = 0;
                        StartCoroutine(SpawnSpecificCrystal(other.GetComponent<Row>(), 0));
                        return;
                    }
                    if (_tutorialSecondCrystal) // after 1st crystal popped
                    {
                        _counterSpawnCrystal = 0;
                        //_tutorialSecondCrystal = false;
                        _tutorialThirdCrystal = true;
                        StartCoroutine(SpawnSpecificCrystal(other.GetComponent<Row>(), 1));
                        return;
                    }
                    if (_tutorialThirdCrystal)
                    {
                        _counterSpawnCrystal = 0;
                        _tutorialThirdCrystal = false;
                        StartCoroutine(SpawnSpecificCrystal(other.GetComponent<Row>(), 1));
                        return;
                    }
                }
            }
            #endregion
        }
    }

    private void Update()
    {
        if (Vector3.Magnitude(transform.position - _targetPosition) < _delta) 
        { 
            SetNewPosition(GameManager.CurrentState);
        }
        if (Vector3.Magnitude(transform.localScale - _targetScale) < _delta)
        {
            SetNewScale(GameManager.CurrentState);
        }
        UpdateSizeAndPosition();
    }

    private void UpdateSizeAndPosition()
    {
        if (GameManager.CurrentState == GameState.Transition)
        {
            transform.localScale = _targetScale;
            transform.position = _targetPosition;
        }
        else if (GameManager.CurrentState == GameState.Progressing)
        {
            _smooth = Mathf.Clamp(GameManager.MaxSpeed / GameManager.TileSpeed, 3f, 80f);
            transform.localScale = Vector3.SmoothDamp(transform.localScale, _targetScale, ref _scaleVelocity, _smooth / 4 * Time.deltaTime * 60);
            transform.position = Vector3.SmoothDamp(transform.position, _targetPosition, ref _positionVelocity, _smooth * Time.deltaTime * 60);
        }
    }

    private void SetNewPosition(GameState state)
    {
        if (state == GameState.Transition)
        {
            _xPos = _middleOfScreen;
        }
        else if (state == GameState.Progressing)
        {
            int sign = _toggle ? 1 : -1;
            _toggle = _toggle ? false : true;
            _xPos = sign * Random.Range(_middleOfScreen, _edgeOfScreen - _width * GameManager.TileLength / 2);
        }
        _targetPosition = new Vector3(_xPos, transform.position.y, transform.position.z);
    }

    private void SetNewScale(GameState state)
    {
        if (state == GameState.Transition)
        {
            _width = _transitionWidth;
        }
        else if (state == GameState.Progressing)
        {
            _width = Random.Range(_widthMin, _widthMax);
            //_width = _randomSystem.Next((int)_widthMin * 10, (int)_widthMax * 10) / 10;
        }
        _targetScale = new Vector3(_width * GameManager.TileLength, 1, 1);
    }

    private IEnumerator DisableRandomTile(Row row)
    {
        yield return null;
        Tile tile = row.EnabledTiles[Random.Range(0, row.EnabledTiles.Count)];
        if (row.EnabledTiles.Count <= 1) { yield break; }

        _triggerDisableTile = _missingTilesChance * Mathf.RoundToInt(Random.Range(2f * 2f / row.EnabledTiles.Count, 5f * 2f / row.EnabledTiles.Count));
        tile.DisableTile(true);
    }

    private IEnumerator SpawnRandomCharged(Row row)
    {
        yield return _colorDelay;
        Tile tile = row.EnabledTiles[Random.Range(0, row.EnabledTiles.Count)];
        if (!tile.IsEnabled || row.EnabledTiles.Count <= 2) { yield break; }

        tile.SetAsCharged(true);
        _triggerColorSpawn = Random.Range(_chargedMinRows, _chargedMaxRows);
    }

    private IEnumerator SpawnSpecificCharged(Row row)
    {
        yield return _colorDelay;
        Tile tile = row.EnabledTiles[Random.Range(0, row.EnabledTiles.Count)];

        tile.SetAsCharged(true);
        _triggerColorSpawn = 6;
    }

    private IEnumerator SpawnCrystal(Row row)
    {
        yield return _crystalDelay;
        int level = 0;
        foreach (Tile tile in row.EnabledTiles)
        {
            if (tile.IsEnabled && !tile.IsCharged && !tile.AttachedCrystal)
            {
                if (Random.Range(0f, 1f) < _crystalSpawnChance)
                {
                    if (++_counterCrystalLevel > _triggerCrystalLevel)
                    {
                        _counterCrystalLevel = 0;
                        _triggerCrystalLevel = Random.Range(3, 6); // this is where we can differentiate between levels
                        level++;
                        if (Random.Range(0f, 1f) < 0.25f) { level++; }
                        if (Random.Range(0f, 1f) < 0.25f) { level++; }
                    }
                    Crystal newCrystal = _crystalPool.Get();
                    newCrystal.transform.SetParent(tile.transform, false);
                    newCrystal.Initialize(level, _crystalPool);
                    tile.AttachedCrystal = newCrystal;
                }
            }
        }
    }

    //private IEnumerator SpawnCrystalGroup(Row row)
    //{
    //    yield return _crystalDelay;
    //    Tile centerTile = row.EnabledTiles[Random.Range(0, row.EnabledTiles.Count)];
    //    List<Tile> availableTiles = new List<Tile>();
    //    if (centerTile.IsEnabled && !centerTile.IsCharged && !centerTile.AttachedCrystal) { availableTiles.Add(centerTile); }
    //    foreach (Tile t1 in centerTile.NeighborTiles)
    //    {
    //        if (t1.IsEnabled && !t1.IsCharged && !t1.AttachedCrystal) { availableTiles.Add(t1); }
    //        foreach (Tile t2 in t1.NeighborTiles)
    //        {
    //            if (t2.IsEnabled && !t2.IsCharged && !t2.AttachedCrystal) { availableTiles.Add(t2); }
    //        }
    //    }

    //    for (int i = 0; i < 3; i++)
    //    {
    //        Tile tile = availableTiles[Random.Range(0, availableTiles.Count)];
    //        availableTiles.Remove(tile);
    //        Crystal newCrystal = _crystalPool.Get();
    //        newCrystal.transform.SetParent(tile.transform, false);
    //        newCrystal.Initialize(_crystalLevel, _crystalPool);
    //        tile.AttachedCrystal = newCrystal;
    //    }
    //    _triggerCrystalSpawn = Mathf.RoundToInt(Random.Range(_crystalMinRowsToSpawn, _crystalMaxRowsToSpawn));
    //}

    //private IEnumerator SpawnRandomCrystal(Row row)
    //{
    //    yield return _crystalDelay;
    //    Tile tile = row.EnabledTiles[Random.Range(0, row.EnabledTiles.Count)];
    //    Tile tile2 = tile.NeighborTiles[Random.Range(0, tile.NeighborTiles.Count)];
    //    if (!tile.IsEnabled || tile.IsCharged || tile.AttachedCrystal) { yield break; }

    //    Crystal newCrystal = _crystalPool.Get();
    //    newCrystal.transform.SetParent(tile.transform, false);
    //    newCrystal.Initialize(_crystalLevel, _crystalPool);
    //    tile.AttachedCrystal = newCrystal;

    //    if (Random.Range(0f, 1f) < 0.2f && tile2.IsEnabled && !tile2.IsCharged && !tile2.AttachedCrystal)
    //    {
    //        Crystal newCrystal2 = _crystalPool.Get();
    //        newCrystal2.transform.SetParent(tile2.transform, false);
    //        newCrystal2.Initialize(_crystalLevel, _crystalPool);
    //        tile2.AttachedCrystal = newCrystal2;
    //    }
    //    _triggerCrystalSpawn = Mathf.RoundToInt(Random.Range(_crystalMinRowsToSpawn, _crystalMaxRowsToSpawn));
    //}

    private IEnumerator SpawnSpecificCrystal(Row row, int level)
    {
        yield return _crystalDelay;
        Tile tile = row.EnabledTiles[Random.Range(0, row.EnabledTiles.Count)];
        if (tile.IsCharged) { yield break; }

        Crystal newCrystal = _crystalPool.Get();
        newCrystal.transform.SetParent(tile.transform, false);
        newCrystal.Initialize(level, _crystalPool);
        tile.AttachedCrystal = newCrystal;
        _triggerTutorialCrystalSpawn = 2;
    }

    private void SetupNewStage()
    {
        _crystalSpawnModifier = Random.Range(0.8f, 1.2f);
        _chargedMinRows = Random.Range(2, 5);
        _chargedMaxRows = Random.Range(4, 8);
        _missingTilesChance = Random.Range(1, 3);

        _tutorialFirstCrystal = true;
        _tutorialSecondCrystal = false;
        _tutorialThirdCrystal = false;
        _triggerTutorialColorSpawn = 6;
        _triggerTutorialCrystalSpawn = 4;
    }

    private void EnableSecondCrystal()
    {
        _tutorialFirstCrystal = false;
        _tutorialSecondCrystal = true;
    }

    public void RemoveCrystal(Crystal crystal)
    {
        _crystalPool.Release(crystal);
    }
}
