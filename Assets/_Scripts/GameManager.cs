using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using Object = UnityEngine.Object;
using Random = UnityEngine.Random;

public class GameManager : MonoBehaviour
{
    #region Variables
    [SerializeField] private bool _debugMode;
    [SerializeField] private GM_Settings _settings;
    [SerializeField] private GameObject _runnerPrefab;
    [SerializeField] private int _firstPurpleStage;
    [SerializeField] private int _firstGoldStage;
    public Transform SampleTileTransform;

    [SerializeField] private Dialogue[] _allTutorialDialogue;
    [SerializeField] private StageDialogue[] _earlyStageDialogue;
    [SerializeField] private StageDialogue[] _midStageDialogue;
    [SerializeField] private StageDialogue[] _lateStageDialogue;
    [SerializeField] private StageDialogue[] _specialStageDialogue;
    [SerializeField] private StageDialogue[] _globalStageDialogue;


    private static StageDialogue _currentStageDialogue;
    //private static StageDialogue[] _allStageDialogue;
    private AnimationCurve _tileSpeedCurve;
    private AnimationCurve _runnerSpeedCurve;
    private AnimationCurve _runnerTransitionCurve;
    private AnimationCurve _tileSpawnerWidthCurve;
    private GameObject _currentRunner;
    private float _defaultSpeed = 1f;    
    private int _starBonus = 0;
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
    private static int _highScore = 0;
    private static int _loseCounter = 0;
    private static int _bonusStarLevel = 0;
    private static int _spawnChargedTileChance = 6;
    private static float _tileColorHue = 0;
    private static bool _firstStarGained = true;
    private static bool _resetStoryMode = false;
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
    private static Vector3 _tileSpeed = Vector3.zero;
    private static Vector3 _transitionSpeed = new Vector3(0, 0, -40);
    private static Vector3 _boardLength;
    private static Answer _stageAnswerQuality = Answer.Poor;
    private static StageDialogueTypes _currentStageDialogueType = StageDialogueTypes.Start;

    public static event Action<GameState> OnStateChanged;
    public static event Action OnSetupNextStage;
    public static event Action<int> OnStarBonusChanged;
    public static event Action<int> OnCompassionateProgressChanged;
    public static event Action OnCompassionateVictory;
    public static event Action OnStageEnd;
    public static event Action<GameObject> OnRunnerSpawned;
    public static event Action<int> OnStarGained;
    public static event Action OnMainMenuOpen;
    public static event Action OnMainMenuClose;
    public static event Action OnGameOver;
    public static event Action OnQuitToMenu;

    // Need delegates here because we're invoking them from elsewhere.
    public delegate void NextDialogue(int index);
    public static NextDialogue OnNextTutorial;
    public delegate void ShowEmptySlots();
    public static ShowEmptySlots OnShowEmptySlots;

    public static GameState CurrentState;
    public static GameManager Instance;
    public static GameObject LastCrystal;
    public static float HighestDrawnRowHeight;
    public static float RunnerHeight;
    public static int NumberOfRows;
    public static bool IsRunnerInTransition = false;
    public static bool IsStageCompleted = false;
    public static bool[] DoTutorial;
    public static int SpecialDialogueCounter = 0;
    public static int EarlyDialogueCounter = 0;
    public static int MidDialogueCounter = 0;
    public static int LateDialogueCounter = 0;
    public static int GlobalDialogueCounter = 0;

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
    public static int SpawnChargedTileChance => _spawnChargedTileChance;
    public static bool SpawnPurpleCrystal => _spawnPurpleCrystal;
    public static bool SpawnGoldCrystal => _spawnGoldCrystal;
    public static bool SpawnGreenCrystal => _spawnGreenCrystal;
    public static bool IsGameOver => _isGameOver;
    public static bool IsInMainMenu => _isInMainMenu;
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
    public static bool ResetStoryMode
    {
        get => _resetStoryMode;
        set
        {
            _resetStoryMode = value;
        }
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
    public int CompassionateProgress
    {
        get => _compassionateProgress;
        set
        {
            if (value <= 3 && value >= 0)
            {
                _compassionateProgress = value;
                OnCompassionateProgressChanged?.Invoke(value);
                if (value == 3)
                {
                    CompassionateVictory();
                }
            }
        }
    }
    public static int AcquiredStars
    {
        get => _acquiredStars;
        set
        {
            _acquiredStars = value;
            AudioManager.Instance.StarGain.Play();
            if (_firstStarGained)
            {
                _firstStarGained = false;
                OnNextTutorial?.Invoke(6);
            }
            if (_acquiredStars % _requiredStars == 0)
            {
                _bonusStarLevel++;
            }
            OnStarGained?.Invoke(_bonusStarLevel);
        }
    }
    public static int CurrentScore
    {
        get => _currentScore;
        set => _currentScore = value;
    }
    public static int HighScore
    {
        get => _highScore;
        set => _highScore = value;
    }
    #endregion

    #region Initialization
    private void Awake()
    {
        if (Instance == null) { Instance = this; }
        else { Destroy(this); }

        // order is important here
        LoadDefaultSettings();
        SaveData.LoadPlayerSettings();
        //NextStageDialogueType();

        QualitySettings.vSyncCount = 0;
        Application.targetFrameRate = 60;

        if (_debugMode)
        {
            _isMusicEnabled = false;
            for (int i = 0; i < DoTutorial.Length; i++) { DoTutorial[i] = false; }
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

    private void LoadDefaultSettings()
    {
        _tileSpeedCurve = _settings.TileSpeedCurve;
        _runnerSpeedCurve = _settings.RunnerSpeedCurve;
        _runnerTransitionCurve = _settings.RunnerTransitionCurve;
        _tileSpawnerWidthCurve = _settings.TileSpawnerWidthCurve;
        _tileLength = SampleTileTransform.GetComponent<BoxCollider>().bounds.size.x;
        _currentScore = 0;
        DoTutorial = new bool[_allTutorialDialogue.Length];
        for (int i = 0; i < _allTutorialDialogue.Length; i++)
        {
            DoTutorial[i] = true;
        }
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
        _compassionateProgress = 0;
        _acquiredStars = 0;
        _bonusStarLevel = 0;
        _tileAlpha = 1f;
    }

    private void CompassionateVictory()
    {
        AudioManager.Instance.StarGain.Play(); // should probably be a different sound??
        StageProgress = _stageLength;
        if (SpecialDialogueCounter == 2) 
        {
            _isGameOver = true;
            OnNextTutorial?.Invoke(13); 
        }
        else { OnNextTutorial?.Invoke(12); }
        OnCompassionateVictory?.Invoke();
    }

    private void IncrementStageDialogueCounters() // On end stage, step 1
    {
        switch (_currentStageDialogueType)
        {
            case StageDialogueTypes.Start:
                break;
            case StageDialogueTypes.Special:
                SpecialDialogueCounter++;
                break;
            case StageDialogueTypes.Early:
                EarlyDialogueCounter++;
                break;
            case StageDialogueTypes.Mid:
                MidDialogueCounter++;
                break;
            case StageDialogueTypes.Late:
                LateDialogueCounter++;
                break;
        }
    }

    private void NextStageDialogueType() // On end stage, step 2
    {
        if ((_currentScore <= 8 && SpecialDialogueCounter == 0) ||
            (_currentScore > 8 && SpecialDialogueCounter == 1) ||
            (_currentScore > 12 && SpecialDialogueCounter == 2))
        {
            _currentStageDialogueType = StageDialogueTypes.Special;
        }
        else if (_currentScore <= 5)
        {
            _currentStageDialogueType = StageDialogueTypes.Early;
        }
        else if (_currentScore > 5 && _currentScore <= 10)
        {
            _currentStageDialogueType = StageDialogueTypes.Mid;
        }
        else
        {
            _currentStageDialogueType = StageDialogueTypes.Late;
        }
    }

    private StageDialogue AssignNextStageDialogue() // On new stage setup
    {
        StageDialogue dialogueToReturn = _earlyStageDialogue[0];
        switch (_currentStageDialogueType)
        {
            case StageDialogueTypes.Special:
                dialogueToReturn = _specialStageDialogue[SpecialDialogueCounter];
                break;
            case StageDialogueTypes.Early:
                TryResetDialogueCounter(0, 0, _earlyStageDialogue.Length, ref EarlyDialogueCounter);
                dialogueToReturn = _earlyStageDialogue[EarlyDialogueCounter];
                break;
            case StageDialogueTypes.Mid:
                TryResetDialogueCounter(0, _earlyStageDialogue.Length, _midStageDialogue.Length, ref MidDialogueCounter);
                dialogueToReturn = _midStageDialogue[MidDialogueCounter];
                break;
            case StageDialogueTypes.Late:
                TryResetDialogueCounter(_earlyStageDialogue.Length, _midStageDialogue.Length, _lateStageDialogue.Length, ref LateDialogueCounter);
                dialogueToReturn = _lateStageDialogue[LateDialogueCounter];
                break;
        }

        return dialogueToReturn;
    }

    private void TryResetDialogueCounter(int previousMin, int newMin, int max, ref int counter)
    {
        counter = counter >= max ? 0 : counter;
    }

    private StageDialogue NextStageDialogue()
    {
        return _globalStageDialogue[GlobalDialogueCounter];
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
        return Vector3Int.RoundToInt(v1) == Vector3Int.RoundToInt(v2);
    }

    public void EndStage()
    {
        IsStageCompleted = false;
        bool answered = false;

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
        if (_compassionateProgress == 3)
        {
            _stageAnswerQuality = Answer.Compassionate;
            answered = true;
        }

        if (answered)
        {
            //IncrementStageDialogueCounters();
            //NextStageDialogueType();

            GlobalDialogueCounter++;
            SaveData.SavePlayerSettings();
            if (_currentScore > _highScore)
            {
                _highScore = _currentScore;
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
        //_currentStageDialogue = AssignNextStageDialogue();

        //if (_currentScore > 10 && _acquiredStars >= _requiredStars)
        //{
        //    _spawnGoldCrystal = true;
        //    _spawnPurpleCrystal = true;
        //    _spawnChargedTileChance = 4;
        //}
        //else if (_currentScore > 3)
        //{
        //    _spawnGoldCrystal = false;
        //    _spawnPurpleCrystal = true;
        //    _spawnChargedTileChance = 5;
        //}
        //else 
        //{ 
        //    _spawnPurpleCrystal = false;
        //    _spawnGoldCrystal = false;
        //    _spawnChargedTileChance = 6;
        //}

        _currentStageDialogue = NextStageDialogue();

        _spawnPurpleCrystal = GlobalDialogueCounter >= _firstPurpleStage;
        _spawnGoldCrystal = GlobalDialogueCounter > _firstGoldStage;

        _spawnChargedTileChance = 6;
        if (_spawnPurpleCrystal) { _spawnChargedTileChance--; }
        if (_spawnGoldCrystal) { _spawnChargedTileChance--; }

        _spawnGreenCrystal = _currentStageDialogue.CompassionateAnswer != "";

        if (IsTutorialOngoing)
        {
            _tileColorHue = 0.552778f;
            _requiredStars = 1;
            _stageLength = 30;
        }
        else
        {
            _tileColorHue = Mathf.Clamp(Random.Range(0f, 1f), 0.1f, 0.9f);
            _requiredStars = 1;
            _stageLength = _requiredStars * 90;
        }

        _repeatingStage = false;
        OnSetupNextStage?.Invoke();
    }

    public void GameOver()
    {
        // do end stuff
        //
        // fade to black - DONE
        // credits - DONE
        // back to main menu (restart & fade out)
        // unlock challenge mode
        // reset story mode
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