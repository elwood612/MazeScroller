//using System;
using System.Collections;
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
    private int _triggerDisableTile = 2;
    private int _triggerColorSpawn = 1000;
    private int _triggerCrystalSpawn = 1000;
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
    private ObjectPool<Crystal> _crystalPool;
    //private System.Random _randomSystem = new System.Random(0);

    private float _colorMinRowsToSpawn => GameManager.Instance.Parameters[GameManager.CurrentStage].ColorMinRows
        .Evaluate(Random.Range(0f, (float)GameManager.StageProgress / (float)GameManager.Instance.Parameters[GameManager.CurrentStage].StageLength));
    private float _colorMaxRowsToSpawn => GameManager.Instance.Parameters[GameManager.CurrentStage].ColorMaxRows
        .Evaluate(Random.Range(0f, (float)GameManager.StageProgress / (float)GameManager.Instance.Parameters[GameManager.CurrentStage].StageLength));
    private float _crystalMinRowsToSpawn => GameManager.Instance.Parameters[GameManager.CurrentStage].CrystalMinRows
        .Evaluate(Random.Range(0f, (float)GameManager.StageProgress / (float)GameManager.Instance.Parameters[GameManager.CurrentStage].StageLength));
    private float _crystalMaxRowsToSpawn => GameManager.Instance.Parameters[GameManager.CurrentStage].CrystalMaxRows
        .Evaluate(Random.Range(0f, (float)GameManager.StageProgress / (float)GameManager.Instance.Parameters[GameManager.CurrentStage].StageLength));
    //private int _crystalLevel => (int)GameManager.Instance.Parameters[GameManager.CurrentStage].CrystalMaxLevel
    //    .Evaluate(Random.Range(0f, (float)GameManager.StageProgress / (float)GameManager.Instance.Parameters[GameManager.CurrentStage].StageLength));
    private int _crystalLevel => GameManager.Instance.Parameters[GameManager.CurrentStage].CrystalLevel;
    private float _widthMin => GameManager.Instance.Parameters[GameManager.CurrentStage].TileSpawnerWidthMin;
    private float _widthMax => GameManager.Instance.Parameters[GameManager.CurrentStage].TileSpawnerWidthMax;
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
    }

    private void OnDisable()
    {
        Tile.OnCrystalRemoval -= RemoveCrystal;
        GameManager.OnStateChanged -= SetNewScale;
        GameManager.OnSetupNextStage -= SetupNewStage;
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

            if (++_counterColorSpawn > _triggerColorSpawn)
            {
                _counterColorSpawn = 0;
                StartCoroutine(SpawnColor(other.GetComponent<Row>()));
            }

            if (++_counterSpawnCrystal > _triggerCrystalSpawn)
            {
                _counterSpawnCrystal = 0;
                StartCoroutine(SpawnCrystal(other.GetComponent<Row>()));
            }
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

    private IEnumerator DisableRandomTile(Row row) // no longer disabling tiles???
    {
        yield return null;
        Tile tile = row.EnabledTiles[Random.Range(0, row.EnabledTiles.Count)];
        if (row.EnabledTiles.Count <= 1) { yield break; }

        _triggerDisableTile = GameManager.Instance.Parameters[GameManager.CurrentStage].TileDestroyMinRows * 
            Mathf.RoundToInt(Random.Range(2f * 2f / row.EnabledTiles.Count, 5f * 2f / row.EnabledTiles.Count));
        tile.DisableTile(true);
    }

    private IEnumerator SpawnColor(Row row)
    {
        yield return _colorDelay;
        Tile tile = row.EnabledTiles[Random.Range(0, row.EnabledTiles.Count)];
        if (!tile.IsEnabled || row.EnabledTiles.Count <= 2) { yield break; }

        //tile.SetAsColored(true);
        tile.SetAsCharged(true);
        _triggerColorSpawn = Mathf.RoundToInt(Random.Range(_colorMinRowsToSpawn, _colorMaxRowsToSpawn));
    }

    private IEnumerator SpawnCrystal(Row row)
    {
        yield return _crystalDelay;
        Tile tile = row.EnabledTiles[Random.Range(0, row.EnabledTiles.Count)];
        if (!tile.IsEnabled || tile.IsCharged || row.EnabledTiles.Count <= 2) { yield break; }

        Crystal newCrystal = _crystalPool.Get();
        newCrystal.transform.SetParent(tile.transform, false);
        newCrystal.Initialize(_crystalLevel, _crystalPool);
        tile.AttachedCrystal = newCrystal;
        _triggerCrystalSpawn = Mathf.RoundToInt(Random.Range(_crystalMinRowsToSpawn, _crystalMaxRowsToSpawn));
    }

    private void SetupNewStage()
    {
        _triggerDisableTile = GameManager.Instance.Parameters[GameManager.CurrentStage].TileDestroyMinRows * Mathf.RoundToInt(Random.Range(2f, 5f));
        _triggerColorSpawn = Mathf.RoundToInt(Random.Range(_colorMinRowsToSpawn, _colorMaxRowsToSpawn));
        _triggerCrystalSpawn = Mathf.RoundToInt(Random.Range(_crystalMinRowsToSpawn, _crystalMaxRowsToSpawn));
    }

    public void RemoveCrystal(Crystal crystal)
    {
        _crystalPool.Release(crystal);
    }
}
