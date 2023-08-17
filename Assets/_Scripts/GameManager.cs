using System;
using System.Collections;
using UnityEngine;
using Random = UnityEngine.Random;

public class GameManager : MonoBehaviour
{
    #region Variables
    [SerializeField] private bool _debugMode;
    [Range(0, 8)] [SerializeField] private int _debugStartStage;
    [SerializeField] private GM_Settings _settings;
    [SerializeField] private GameObject _runnerPrefab;
    [SerializeField] private int _firstPurpleStage;
    [SerializeField] private int _firstGoldStage;
    public Transform SampleTileTransform;

    [SerializeField] private Dialogue[] _allTutorialDialogue;
    [SerializeField] private StageDialogue[] _globalStageDialogue;


    private static StageDialogue _currentStageDialogue;
    private AnimationCurve _tileSpeedCurve;
    private AnimationCurve _runnerSpeedCurve;
    private AnimationCurve _runnerTransitionCurve;
    private AnimationCurve _tileSpawnerWidthCurve;
    private GameObject _currentRunner;
    private float _defaultSpeed = 1f;    
    private int _starBonus = 0;
    private int _compassionateStars = 0;
    private int _compassionateProgress = 0;
    private WaitForSeconds _bonusDelay = new WaitForSeconds(1f);
    private WaitForSeconds _bonusStep = new WaitForSeconds(0.4f);
    private WaitForSeconds _runnerTeleportDelay = new WaitForSeconds(0.5f);
    private bool _startOfGame = true;
    private bool _decreaseSpeedBonus = true;
    private bool _triggerBonusStep = true;
    private static float _maxSpeed = 50f;
    private static float _tileLength;
    private static float _speedMultiplier = 1f;
    private static float _tileAlpha = 1f;
    private static int _stageProgress;
    private static int _stageLength = 80;
    private static int _transitionProgress;
    private static int _acquiredStars = 0;
    private static int _requiredStars = 1;
    private static int _currentScore = 0;
    private static int _loseCounter = 0;
    private static int _bonusStarLevel = 0;
    private static int _chargedTileCounter = 6;
    private static float _tileColorHue = 0;
    private static bool _firstStarGained = true;
    private static bool _secondStarGained = false;
    private static bool _thirdStarGained = false;
    private static bool _isAudioEnabled = true;
    private static bool _isMusicEnabled = true;
    private static bool _isStageMenuOpen = false;
    private static bool _isInMainMenu = false;
    private static bool _needDialogueBoxHint = true;
    private static bool _spawnPurpleCrystal = false;
    private static bool _spawnGoldCrystal = false;
    private static bool _spawnGreenCrystal = false;
    private static bool _isGameOver = false;
    private static bool _repeatingStage = false;
    private static bool _compassionateVictoryAchieved = false;
    private static Vector3 _tileSpeed = Vector3.zero;
    private static Vector3 _transitionSpeed = new Vector3(0, 0, -40);
    private static Vector3 _boardLength;
    private static Answer _stageAnswerQuality = Answer.Poor;

    public static event Action<GameState> OnStateChanged;
    public static event Action OnSetupNextStage;
    public static event Action<int> OnStarBonusChanged;
    public static event Action<int> OnCompassionateStarAdded;
    public static event Action OnCompassionateStarsReset;
    public static event Action OnCompassionateVictory;
    public static event Action OnStageEnd;
    public static event Action<GameObject> OnRunnerSpawned;
    public static event Action<int> OnStarGained;
    public static event Action OnMainMenuOpen;
    public static event Action OnMainMenuClose;
    public static event Action OnGameOver;
    public static event Action OnQuitToMenu;
    public static event Action<int> OnCompassionateChargeUp;
    public static Action<bool> OnCompassionateStarsToggle;
    public static Action<int> OnNextTutorial;
    public static Action OnShowEmptySlots;

    public static GameState CurrentState;
    public static GameManager Instance;
    public static GameObject LastCrystal;
    public static float HighestDrawnRowHeight;
    public static float RunnerHeight;
    public static int NumberOfRows;
    public static bool IsRunnerInTransition = false;
    public static bool IsStageCompleted = false;
    public static bool[] DoTutorial;
    public static bool GameUnderway = false;
    public static int GlobalDialogueCounter = 0;
    public static int HighScore = 0;

    public static bool IsTutorialOngoing => DoTutorial[6];
    public GameObject CurrentRunner => _currentRunner;
    public GM_Settings GameSettings => _settings;
    public static float TileLength => _tileLength;
    public static Vector3 BoardLength => _boardLength;
    public static float TileSpeed => Mathf.Abs(_tileSpeed.z);
    public AnimationCurve RunnerSpeedCurve => _runnerSpeedCurve;
    public AnimationCurve RunnerTransitionCurve => _runnerTransitionCurve;
    public AnimationCurve TileSpawnerWidthCurve => _tileSpawnerWidthCurve;
    public static int StageLength => _stageLength;
    public static float MaxSpeed => _maxSpeed;
    public static float TileAlpha => _tileAlpha;
    public static int TransitionProgress => _transitionProgress;
    public static int LoseCounter => _loseCounter;
    public static int RequiredStars => _requiredStars;
    public static float TileColorHue => _tileColorHue;
    public static StageDialogue CurrentStageDialogue => _currentStageDialogue;
    public static int ChargedTileCounter => _chargedTileCounter;
    public static bool SpawnPurpleCrystal => _spawnPurpleCrystal;
    public static bool SpawnGoldCrystal => _spawnGoldCrystal;
    public static bool SpawnGreenCrystal => _spawnGreenCrystal;
    public static bool IsGameOver => _isGameOver;
    public static bool IsInMainMenu => _isInMainMenu;
    public static bool CompassionateVictoryAchieved => _compassionateVictoryAchieved;
    public static Answer StageAnswerQuality => _stageAnswerQuality;
    public static bool RepeatingStage => _repeatingStage;
    public Dialogue[] AllTutorialDialogue => _allTutorialDialogue;
    public static bool IsAudioEnabled
    {
        get => _isAudioEnabled;
        set => _isAudioEnabled = value;
    }
    public static bool IsMusicEnabled
    {
        get => _isMusicEnabled;
        set => _isMusicEnabled = value;
    }
    public static bool IsStageMenuOpen
    {
        get => _isStageMenuOpen;
        set => _isStageMenuOpen = value;
    }
    public static bool NeedDialogueBoxHint
    {
        get => _needDialogueBoxHint;
        set => _needDialogueBoxHint = value;
    }
    public static int StageProgress
    {
        get => _stageProgress;
        set
        {
            if (CurrentState == GameState.Progressing)
            {
                if (_stageProgress < _stageLength)
                {
                    _stageProgress = value;
                    if (_stageProgress > _stageLength / 2)
                    {
                        _tileAlpha = Mathf.Max(_tileAlpha - 2f / _stageLength, 0);
                    }
                }
                else
                {
                    _stageProgress = 0;
                    if (!_isInMainMenu) { IsStageCompleted = true; }
                    Instance.UpdateGameState(GameState.Transition);
                }
            }
        }
    }
    public int StarProgress
    {
        get => _starBonus;
        set
        {
            if (value > _starBonus)
            {
                ResetCoroutines();
                StartCoroutine(BonusDelay());
            }
            _starBonus = value;
            OnStarBonusChanged?.Invoke(value);
            if (_starBonus > 100 * (_acquiredStars + 1))
            {
                AcquiredStars++;
                CurrentScore++;
            }
        }
    }
    public int CompassionateStars
    {
        get => _compassionateStars;
        set
        {
            _compassionateStars = value;
            if (value <= 3 && value > 0)
            {
                OnCompassionateStarAdded?.Invoke(value);
                if (value == 3)
                {
                    CompassionateVictory();
                }
            }
            else if (value == 0)
            {
                OnCompassionateStarsReset?.Invoke();
            }
        }
    }
    public int CompassionateProgress
    {
        get => _compassionateProgress;
        set
        {
            if (value < 100)
            {
                _compassionateProgress = value;
                OnCompassionateChargeUp?.Invoke(value);
            }
            if (value == 100)
            {
                CompassionateStars++;
                _compassionateProgress = 0;
            }
        }
    }
    public static int AcquiredStars
    {
        get => _acquiredStars;
        set
        {
            _acquiredStars = value;
            if (_acquiredStars == _requiredStars) { AudioManager.Instance.CompassionateVictory.Play(); }
            else { AudioManager.Instance.StarGain.Play(); }
            if (_acquiredStars % _requiredStars == 0)
            {
                _bonusStarLevel++;
            }
            OnStarGained?.Invoke(_bonusStarLevel);

            if (_firstStarGained)
            {
                _firstStarGained = false;
                _secondStarGained = true;
                OnNextTutorial?.Invoke(6);
                return;
            }
            if (_secondStarGained && IsTutorialOngoing)
            {
                _secondStarGained = false;
                _thirdStarGained = true;
                OnNextTutorial?.Invoke(19);
                return;
            }
            if (_thirdStarGained && IsTutorialOngoing)
            {
                _thirdStarGained = false;
                OnNextTutorial?.Invoke(20);
            }
        }
    }
    public static int CurrentScore
    {
        get => _currentScore;
        set => _currentScore = value;
    }
    #endregion

    #region Initialization
    private void Awake()
    {
        if (Instance == null) { Instance = this; }
        else { Destroy(this); }

        LoadDefaultSettings();
        SaveData.LoadPlayerSettings();

        QualitySettings.vSyncCount = 0;
        Application.targetFrameRate = 60;

        if (_debugMode)
        {
            _isMusicEnabled = false;
            GlobalDialogueCounter = _debugStartStage;
            //for (int i = 0; i < DoTutorial.Length; i++) { DoTutorial[i] = false; }
        }
    }

    private void Start()
    {
        UpdateGameState(GameState.Setup);
    }
    #endregion

    private void Update()
    {
        if (CurrentState == GameState.Setup) { return; }
        CalculateBoardSpeed(_speedMultiplier);

        if (_decreaseSpeedBonus && _triggerBonusStep && !DialogueManager.Instance.IsDialogueActive && !_isStageMenuOpen) { StartCoroutine(BonusDecrease()); }
    }

    private void CalculateBoardSpeed(float multiplier)
    {
        float heightCurve;
        if (RunnerHeight < 0.2f)
        {
            heightCurve = _tileSpeedCurve.Evaluate(RunnerHeight);
        }
        else
        {
            heightCurve = _tileSpeedCurve.Evaluate(HighestDrawnRowHeight);
        }
        if (_startOfGame) { heightCurve = 0.5f; } // just used for first few frames
        _tileSpeed = new Vector3(0, 0, -heightCurve * _defaultSpeed * multiplier);
    }

    private void CalculateBoardLength()
    {
        _boardLength = new Vector3(0, 0, _tileLength * NumberOfRows);
    }

    private void OnDestroy()
    {
        if (Instance == this) { Instance = null; }
    }

    private IEnumerator BonusDelay()
    {
        _decreaseSpeedBonus = false;
        yield return _bonusDelay;
        _decreaseSpeedBonus = true;
    }

    private IEnumerator BonusDecrease()
    {
        _triggerBonusStep = false;
        yield return _bonusStep;
        StarProgress = StarProgress > _acquiredStars * 100 ? StarProgress - 1 : _acquiredStars * 100;
        _triggerBonusStep = true;
    }

    private void ResetCoroutines()
    {
        StopAllCoroutines();
        _triggerBonusStep = true;
    }

    private void ResetStats()
    {
        _starBonus = 0;
        _compassionateStars = 0;
        _compassionateProgress = 0;
        _compassionateVictoryAchieved = false;
        _acquiredStars = 0;
        _bonusStarLevel = 0;
        _tileAlpha = 1f;
    }

    private void CompassionateVictory()
    {
        if (CurrentState == GameState.Progressing) { StageProgress = _stageLength; }
        AudioManager.Instance.CompassionateVictory.Play();
        AcquiredStars += 10;
        CurrentScore += 10;
        if (GlobalDialogueCounter >= _globalStageDialogue.Length - 1)
        {
            //_isGameOver = true;
            OnNextTutorial?.Invoke(13);
        }
        else { OnNextTutorial?.Invoke(12); }
        _compassionateVictoryAchieved = true;
        OnCompassionateVictory?.Invoke();
    }

    private StageDialogue NextStageDialogue()
    {
        return _globalStageDialogue[Mathf.Min(GlobalDialogueCounter, _globalStageDialogue.Length - 1)];
    }

    public void ResetDefaultSettings()
    {
        _isGameOver = false;
        _currentScore = 0;
        GameUnderway = false;
        GlobalDialogueCounter = 0;
        for (int i = 0; i < _allTutorialDialogue.Length; i++)
        {
            DoTutorial[i] = false;
        }
    }

    public void LoadDefaultSettings()
    {
        _tileSpeedCurve = _settings.TileSpeedCurve;
        _runnerSpeedCurve = _settings.RunnerSpeedCurve;
        _runnerTransitionCurve = _settings.RunnerTransitionCurve;
        _tileSpawnerWidthCurve = _settings.TileSpawnerWidthCurve;
        _tileLength = SampleTileTransform.GetComponent<BoxCollider>().bounds.size.x;
        _currentScore = 0;
        GameUnderway = false;
        GlobalDialogueCounter = 0;
        DoTutorial = new bool[_allTutorialDialogue.Length];
        for (int i = 0; i < _allTutorialDialogue.Length; i++)
        {
            DoTutorial[i] = true;
        }
    }

    public void UpdateGameState(GameState newState)
    {
        if (CurrentState == newState && newState != GameState.Setup) { return; } // avoids spamming events for no reason
        CurrentState = newState;

        switch (newState)
        {
            case GameState.Setup:
                CalculateBoardSpeed(0);
                CalculateBoardLength();
                break;
            case GameState.Transition:
                break;
            case GameState.Progressing:
                ResetStats();
                break;
        }
        OnStateChanged?.Invoke(newState);
    }

    public void SpawnRunner(Transform tile)
    {
        _currentRunner = Instantiate(_runnerPrefab, tile.position, Quaternion.identity);
        _startOfGame = false;
        OnRunnerSpawned?.Invoke(_currentRunner);
    }

    public void ResetRunner(Transform tile)
    {
        _currentRunner.transform.SetPositionAndRotation(tile.position, Quaternion.Euler(0, 0, 0));
    }

    public static void AddBoardMotion(Transform t)
    {
        if ((DialogueManager.Instance.IsTutorialDialogueActive && !_isGameOver) || _isStageMenuOpen) { return; }

        if (IsRunnerInTransition)
        {
            t.Translate(_transitionSpeed * Time.deltaTime);
        }
        else if (!IsRunnerInTransition)
        {
            t.Translate(_tileSpeed * Time.deltaTime);
        }
    }

    public static bool CompareVectorsAsInts(Vector3 v1, Vector3 v2)
    {
        return (v2 - v1).sqrMagnitude < _tileLength / 2;
    }

    public void EndStage()
    {
        if (GlobalDialogueCounter >= _globalStageDialogue.Length - 1)
        {
            _isGameOver = true;
        }
        
        IsStageCompleted = false;
        bool answered = false;
        _firstStarGained = false;
        _secondStarGained = false;
        _thirdStarGained = false;

        if (_acquiredStars < _requiredStars)
        {
            _stageAnswerQuality = Answer.Poor;
            answered = false;
        }
        else if (_acquiredStars == _requiredStars)
        {
            _stageAnswerQuality = Answer.Acceptable;
            answered = true;
        }
        else if (_acquiredStars > _requiredStars)
        {
            _stageAnswerQuality = Answer.Excellent;
            answered = true;
        }
        if (_currentStageDialogue.CompassionateAnswer != "")
        {
            if (_compassionateStars == 3)
            {
                _stageAnswerQuality = Answer.Compassionate;
                answered = true;
            }
            else
            {
                _stageAnswerQuality = Answer.Poor;
                answered = false;
            }
        }
        

        if (answered)
        {
            GlobalDialogueCounter++;
            SaveData.SavePlayerSettings();
            if (_currentScore > HighScore)
            {
                HighScore = _currentScore;
            }
        }
        else
        {
            _repeatingStage = true;
        }

        OnStageEnd?.Invoke();
    }

    public void SetupNextStage()
    {
        if (_isGameOver)
        {
            return;
        }

        GameUnderway = true;

        _currentStageDialogue = NextStageDialogue();

        _spawnPurpleCrystal = GlobalDialogueCounter >= _firstPurpleStage;
        _spawnGoldCrystal = GlobalDialogueCounter >= _firstGoldStage;

        _chargedTileCounter = 6;
        _requiredStars = 1;
        _stageLength = (_requiredStars * 20) + 65;
        _tileColorHue = 0.552778f;
        // _tileColorHue = Mathf.Clamp(Random.Range(0f, 1f), 0.1f, 0.9f); // keep for posterity

        if (_spawnPurpleCrystal) { _requiredStars++; }
        if (_spawnGoldCrystal) { _requiredStars++; }
        if (GlobalDialogueCounter >= 2) { _chargedTileCounter--; }
        if (GlobalDialogueCounter >= 4) { _chargedTileCounter--; }
        if (GlobalDialogueCounter >= 6) { _chargedTileCounter--; }
        if (GlobalDialogueCounter >= 7) { _chargedTileCounter--; }
        if (GlobalDialogueCounter == 4) { _chargedTileCounter = 2; }

        _spawnGreenCrystal = _currentStageDialogue.CompassionateAnswer != "";

        if (IsTutorialOngoing)
        {
            _stageLength = 30;
            _chargedTileCounter = 8;
        }

        if (_spawnGreenCrystal)
        {
            _tileColorHue = 0.9f;
        }

        _repeatingStage = false;
        OnSetupNextStage?.Invoke();
    }

    public void GameOver()
    {
        //ResetDefaultSettings();
        OnGameOver?.Invoke();
    }

    public void OpenMainMenu()
    {
        _isInMainMenu = true;
        OnMainMenuOpen?.Invoke();
    }

    public void CloseMainMenu()
    {
        _isInMainMenu = false;
        OnMainMenuClose?.Invoke();
    }

    public void QuitToMenu()
    {
        OpenMainMenu();
        StageProgress = _stageLength;
        OnQuitToMenu?.Invoke();
    }

    public void Quit()
    {
        SaveData.SavePlayerSettings();

#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#else
        Application.Quit();
#endif
    }

    public void OnApplicationQuit()
    {
        SaveData.SavePlayerSettings();
    }
}