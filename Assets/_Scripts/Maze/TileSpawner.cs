using System.Collections;
using UnityEngine;
using UnityEngine.Pool;

public class TileSpawner : MonoBehaviour
{
    #region Variables
    [SerializeField] private Crystal _crystalPrefab;
    [SerializeField] private OrbitMissile _missilePrefab;
    [SerializeField] private Color[] _colors; 

    private int _counterDisableTile = 0;
    private int _counterColorSpawn = 0;
    private int _counterSpawnCrystal = 0;
    private int _triggerDisableTile = 1000;
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

    private int _colorSpawnChanceMin => GameManager.Instance.Parameters[GameManager.CurrentStage].ColorSpawnChanceMin;
    private int _colorSpawnChanceMax => GameManager.Instance.Parameters[GameManager.CurrentStage].ColorSpawnChanceMax;
    private int _crystalSpawnChanceMin => GameManager.Instance.Parameters[GameManager.CurrentStage].CrystalSpawnChanceMin;
    private int _crystalSpawnChanceMax => GameManager.Instance.Parameters[GameManager.CurrentStage].CrystalSpawnChanceMax;
    private int _crystalLevel =>
        GameManager.StageProgress < GameManager.Instance.Parameters[GameManager.CurrentStage].EasyIntro ?
        (int)GameManager.Instance.Parameters[GameManager.CurrentStage].CrystalLevelDistribution.Evaluate(0) :
        (int)GameManager.Instance.Parameters[GameManager.CurrentStage].CrystalLevelDistribution.Evaluate(Random.Range(0f, 1f));
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
    }

    private void OnEnable()
    {
        Tile.OnCrystalRemoval += RemoveCrystal;
        GameManager.OnStateChanged += SetNewScale;
        GameManager.OnSetupNextStage += SetTriggerCounters;
    }

    private void OnDisable()
    {
        Tile.OnCrystalRemoval -= RemoveCrystal;
        GameManager.OnStateChanged -= SetNewScale;
        GameManager.OnSetupNextStage -= SetTriggerCounters;
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
                StartCoroutine(SpawnRandomCrystal(other.GetComponent<Row>()));
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
            transform.localScale = Vector3.SmoothDamp(transform.localScale, _targetScale, ref _scaleVelocity, _smooth / 4);
            transform.position = Vector3.SmoothDamp(transform.position, _targetPosition, ref _positionVelocity, _smooth);
        }

        //if (GameManager.CurrentState == GameState.Transition) { _smooth = 0.5f; }
        //else { _smooth = Mathf.Clamp(GameManager.MaxSpeed / GameManager.TileSpeed, 3f, 80f); }

        //transform.localScale = Vector3.SmoothDamp(transform.localScale, _targetScale, ref _scaleVelocity, _smooth / 4);
        //transform.position = Vector3.SmoothDamp(transform.position, _targetPosition, ref _positionVelocity, _smooth);
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
        }
        _targetScale = new Vector3(_width * GameManager.TileLength, 1, 1);
    }

    private IEnumerator DisableRandomTile(Row row) // no longer disabling tiles???
    {
        yield return null;
        Tile tile = row.EnabledTiles[Random.Range(0, row.EnabledTiles.Count)];
        if (row.EnabledTiles.Count <= 1) { yield break; }

        _triggerDisableTile = Mathf.RoundToInt(Random.Range(2f * 3 / row.EnabledTiles.Count, 5f * 3 / row.EnabledTiles.Count));
        tile.DisableTile(true);
    }

    private IEnumerator SpawnColor(Row row)
    {
        yield return _colorDelay;
        Tile tile = row.EnabledTiles[Random.Range(0, row.EnabledTiles.Count)];
        if (!tile.IsEnabled || row.EnabledTiles.Count <= 2) { yield break; }

        tile.SetAsColored(true);
        _triggerColorSpawn = Random.Range(_colorSpawnChanceMin, _colorSpawnChanceMax);
    }

    private IEnumerator SpawnRandomCrystal(Row row)
    {
        yield return _crystalDelay;
        Tile tile = row.EnabledTiles[Random.Range(0, row.EnabledTiles.Count)];
        if (!tile.IsEnabled || tile.IsColored || row.EnabledTiles.Count <= 2) { yield break; }

        Crystal newCrystal = _crystalPool.Get();
        newCrystal.transform.SetParent(tile.transform, false);
        newCrystal.Initialize(_crystalLevel, _crystalPool);
        tile.AttachedCrystal = newCrystal;
        _triggerCrystalSpawn = Random.Range(_crystalSpawnChanceMin, _crystalSpawnChanceMax);
    }

    private void SetTriggerCounters(int stage)
    {
        _triggerColorSpawn = Random.Range(_colorSpawnChanceMin, _colorSpawnChanceMax);
        _triggerCrystalSpawn = Random.Range(_crystalSpawnChanceMin, _crystalSpawnChanceMax);
    }

    public void RemoveCrystal(Crystal crystal)
    {
        _crystalPool.Release(crystal);
    }
}
