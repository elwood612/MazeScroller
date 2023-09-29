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
    private int _counterCrystalLevel = 0;
    private int _counterGreenCrystal = 0;
    private int _counterPurpleCrystal = 0;
    private int _counterGoldCrystal = 0;
    private int _triggerDisableTile = 2;
    private int _triggerCrystalLevel = 4;
    private int _triggerTutorialCrystalSpawn = 2;
    private int _triggerTutorialColorSpawn = 5;
    private int _triggerGreenCrystal = 3;
    private int _triggerPurpleCrystal = 5;
    private int _triggerGoldCrystal = 5;
    private bool _tutorialFirstCrystal = true;
    private bool _tutorialSecondCrystal = false;
    private bool _tutorialThirdCrystal = false;
    private bool _firstGreenCrystalOfStage = true;
    private bool _firstPurpleCrystal = true;
    private bool _firstGoldCrystal = true;
    private bool _firstChargedTile = true;
    private bool _goodToSpawnGreen = true;
    private bool _exitingTransition = true;
    private float _width = 0.5f;
    private float _transitionWidth = 0.5f;
    private float _xPos;
    private float _smooth = 3f; // the larger this is, the slower you move
    private float _delta = 0.1f;
    private bool _toggle = false;
    private float _middleOfScreen, _edgeOfMaze;
    private Vector3 _targetPosition;
    private Vector3 _targetScale;
    private Vector3 _positionVelocity = Vector3.zero;
    private Vector3 _scaleVelocity = Vector3.zero;
    private WaitForSeconds _crystalDelay = new WaitForSeconds(0.8f);
    private WaitForSeconds _colorDelay = new WaitForSeconds(0.4f);
    private WaitForSeconds _goldCrystalDelay = new WaitForSeconds(5f);
    private ObjectPool<Crystal> _crystalPool;
    private int _missingTilesChance = 2;
    private int _minimumTileCounter = 0;
    private int _minimumTileChance = 8;
    private float _widthMin = 2.1f;
    private float _widthMax = 2.9f;
    private float _crystalSpawnModifier = 1f;
    private static int _greenCrystalOnScreenCounter = 0;
    private float _crystalSpawnChance => _crystalSpawnModifier * GameManager.Instance.GameSettings.CrystalSpawnChance
            .Evaluate(Random.Range(0f, (float)GameManager.StageProgress / (float)GameManager.StageLength));
    #endregion

    #region Initialization
    private void Awake()
    {
        _targetPosition = transform.position;
        _targetScale = transform.localScale;
        _middleOfScreen = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width / 2, Screen.height, 100)).x;
        //_edgeOfMaze = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width, Screen.height, 100)).x; // Keep for posterity
        _edgeOfMaze = _middleOfScreen + 2.5f * GameManager.TileLength;
        InitializeCrystalPool();
        SetupNewStage();
    }

    private void OnEnable()
    {
        Tile.OnCrystalRemoval += RemoveCrystal;
        GameManager.OnStateChanged += SetNewScale;
        GameManager.OnSetupNextStage += SetupNewStage;
        Crystal.OnFirstCrystal += EnableSecondCrystal;
        Crystal.OnGreenCrystalPopped += EnableGreenCrystal;
    }

    private void OnDisable()
    {
        Tile.OnCrystalRemoval -= RemoveCrystal;
        GameManager.OnStateChanged -= SetNewScale;
        GameManager.OnSetupNextStage -= SetupNewStage;
        Crystal.OnFirstCrystal -= EnableSecondCrystal;
        Crystal.OnGreenCrystalPopped -= EnableGreenCrystal;
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

            if (GameManager.SpawnGreenCrystal && _goodToSpawnGreen && _firstGreenCrystalOfStage)
            {
                if (++_counterGreenCrystal > _triggerGreenCrystal)
                {
                    _counterGreenCrystal = 0;
                    StartCoroutine(SpawnSpecificCrystal(other.GetComponent<Row>(), 4));
                    _firstGreenCrystalOfStage = false;
                }
            }

            if (!_firstPurpleCrystal)
            {
                if (++_counterPurpleCrystal > _triggerPurpleCrystal)
                {
                    _counterPurpleCrystal = 0;
                    GameManager.OnNextTutorial?.Invoke(7);
                }
            }
            if (!_firstGoldCrystal)
            {
                if (++_counterGoldCrystal > _triggerGoldCrystal)
                {
                    _counterGoldCrystal = 0;
                    GameManager.OnNextTutorial?.Invoke(8);
                }
            }

            if (!GameManager.IsTutorialOngoing || !GameManager.IsTutorialsEnabled)
            {
                if (++_counterColorSpawn > GameManager.ChargedTileCounter)
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
                        _tutorialThirdCrystal = true;
                        if (Random.Range(0f, 1f) < 0.6f) 
                        { 
                            StartCoroutine(SpawnSpecificCrystal(other.GetComponent<Row>(), 1)); 
                        }
                        else { StartCoroutine(SpawnSpecificCrystal(other.GetComponent<Row>(), 0)); }
                        return;
                    }
                    if (_tutorialThirdCrystal)
                    {
                        _counterSpawnCrystal = 0;
                        _tutorialThirdCrystal = false;
                        if (Random.Range(0f, 1f) < 0.4f) { StartCoroutine(SpawnSpecificCrystal(other.GetComponent<Row>(), 1)); }
                        else { StartCoroutine(SpawnSpecificCrystal(other.GetComponent<Row>(), 0)); }
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
            _exitingTransition = true;
        }
        else if (GameManager.CurrentState == GameState.Progressing)
        {
            if (_exitingTransition)
            {
                transform.localScale = _targetScale;
                _exitingTransition = false;
                return;
            }
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
            _xPos = sign * Random.Range(_middleOfScreen, _edgeOfMaze - _width * GameManager.TileLength / 2);
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

    private IEnumerator DisableRandomTile(Row row)
    {
        yield return null;
        Tile tile = row.EnabledTiles[Random.Range(0, row.EnabledTiles.Count)];
        if (tile.IsMiddleTile)
        {
            _triggerDisableTile = 1; // fun little workaround
            yield break;
        }
        if (row.EnabledTiles.Count <= 1) { yield break; }

        _triggerDisableTile = _missingTilesChance * Mathf.RoundToInt(Random.Range(2f * 2f / row.EnabledTiles.Count, 5f * 2f / row.EnabledTiles.Count));
        tile.DisableTile(true);
    }

    private IEnumerator SpawnRandomCharged(Row row)
    {
        yield return _colorDelay;
        if (GameManager.CompassionateVictoryAchieved) { yield break; }
        Tile tile = row.EnabledTiles[Random.Range(0, row.EnabledTiles.Count)];
        if (!tile.IsEnabled || row.EnabledTiles.Count <= 2) { yield break; }
        tile.SetAsCharged(true);
    }

    private IEnumerator SpawnSpecificCharged(Row row)
    {
        yield return _colorDelay;
        Tile tile = row.EnabledTiles[Random.Range(0, row.EnabledTiles.Count)];
        tile.SetAsCharged(true);
    }

    private IEnumerator SpawnCrystal(Row row)
    {
        yield return _crystalDelay;
        if (GameManager.CompassionateVictoryAchieved) { yield break; }
        int level;
        int numCrystalsInOneRow = 0;
        foreach (Tile tile in row.EnabledTiles)
        {
            if (!tile.IsEnabled || 
                tile.IsCharged || 
                tile.AttachedCrystal) 
            { continue; }

            level = 0;

            if (Random.Range(0f, 1f) < _crystalSpawnChance || ++_minimumTileCounter > _minimumTileChance)
            {
                if (++_counterCrystalLevel > _triggerCrystalLevel && numCrystalsInOneRow == 0)
                {
                    _counterCrystalLevel = 0;
                    _triggerCrystalLevel = Random.Range(2, 6);
                    level++;
                    if ((Random.Range(0f, 1f) < 0.35f || _firstPurpleCrystal) && GameManager.SpawnPurpleCrystal && GameManager.StageProgress > 10)
                    {
                        level++;
                        if (_firstPurpleCrystal) { _firstPurpleCrystal = false; }
                        if ((Random.Range(0f, 1f) < 0.5f || _firstGoldCrystal) && GameManager.SpawnGoldCrystal && GameManager.StageProgress > 10)
                        {
                            level++;
                            if (_firstGoldCrystal) { _firstGoldCrystal = false; }
                        }
                    }
                    if (GameManager.SpawnGreenCrystal && _goodToSpawnGreen && GameManager.StageProgress > 10)
                    {
                        level = 4;
                        _goodToSpawnGreen = false;
                    }
                }
                Crystal newCrystal = _crystalPool.Get();
                newCrystal.transform.SetParent(tile.transform, false);
                newCrystal.Initialize(level, _crystalPool);
                tile.AttachedCrystal = newCrystal;
                _minimumTileCounter = 0;
                numCrystalsInOneRow++;
            }
        }
    }

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
        _crystalSpawnModifier = 1;
        _minimumTileChance = 10;
        if (GameManager.GlobalDialogueCounter > 2) { _crystalSpawnModifier += 0.2f; _minimumTileChance--; }
        if (GameManager.GlobalDialogueCounter > 4) { _crystalSpawnModifier += 0.1f; _minimumTileChance--; }
        if (GameManager.GlobalDialogueCounter > 7) { _crystalSpawnModifier += 0.1f; _minimumTileChance--; }
        if (GameManager.GlobalDialogueCounter == 2 || 
            GameManager.GlobalDialogueCounter == 4 ||
            GameManager.GlobalDialogueCounter == 7) 
        { _crystalSpawnModifier += 0.5f; }

        _missingTilesChance = GameManager.GlobalDialogueCounter > 3 ? 1 : 2;
        _goodToSpawnGreen = true;
        _firstGreenCrystalOfStage = true;
        _firstChargedTile = true;
        _minimumTileCounter = 0;
        _counterColorSpawn = 0;

        _tutorialFirstCrystal = true;
        _tutorialSecondCrystal = false;
        _tutorialThirdCrystal = false;
        _triggerTutorialColorSpawn = 6;
        _triggerTutorialCrystalSpawn = 2;
    }

    private void EnableSecondCrystal()
    {
        _tutorialFirstCrystal = false;
        _tutorialSecondCrystal = true;
    }

    private void EnableGreenCrystal()
    {
        _goodToSpawnGreen = true;
    }

    public void RemoveCrystal(Crystal crystal)
    {
        _crystalPool.Release(crystal);
    }
}
