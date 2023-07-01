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
    [SerializeField] private Dialogue[] _allTutorialDialogue;
    [SerializeField] private StageDialogue[] _earlyStageDialogue;
    [SerializeField] private StageDialogue[] _midStageDialogue;
    [SerializeField] private StageDialogue[] _lateStageDialogue;
    [SerializeField] private StageDialogue[] _specialStageDialogue;

    [SerializeField] private GM_Settings _settings;
    [SerializeField] private GameObject _runnerPrefab;
    [SerializeField] private bool _debugMode;
    public Transform SampleTileTransform;

    private static StageDialogue _currentStageDialogue;
    private static StageDialogue[] _allStageDialogue;
    private AnimationCurve _tileSpeedCurve;
    private AnimationCurve _runnerSpeedCurve;
    private AnimationCurve _runnerTransitionCurve;
    private AnimationCurve _tileSpawnerWidthCurve;
    private GameObject _currentRunner;
    private float _defaultSpeed = 1f;    
    private int _speedBonus = 0;
    private int _compassionateBonus = 0;
    private WaitForSeconds _bonusDelay = new WaitForSeconds(1f);
    private WaitForSeconds _bonusStep = new WaitForSeconds(0.4f);
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
    private static int _lifetimeStars = 0;
    private static int _loseCounter = 0;
    private static int _bonusStarLevel = 0;
    private static int _spawnChargedTileChance = 6;
    //private static int _earlyDialogueCounter = 0;
    //private static int _midDialogueCounter = 0;
    //private static int _lateDialogueCounter = 0;
    //private static int _specialDialogueCounter = 0;
    private static float _tileColorHue = 0;
    private static bool _firstStarGained = true;
    private static bool _resetStoryMode = false;
    private static bool _isAudioEnabled = true;
    private static bool _isMusicEnabled = true;
    private static bool _needDialogueBoxHint = true;
    private static bool _spawnPurpleCrystal = false;
    private static bool _spawnGoldCrystal = false;
    private static bool _spawnGreenCrystal = false;
    private static bool _isGameOver = false;
    private static Vector3 _tileSpeed = Vector3.zero;
    private static Vector3 _transitionSpeed = new Vector3(0, 0, -40);
    private static Vector3 _boardLength;
    private static Answer _stageAnswer = Answer.Poor;
    private static StageDialogueTypes _currentStageDialogueType = StageDialogueTypes.Start;

    public static event Action<GameState> OnStateChanged;
    public static event Action OnSetupNextStage;
    public static event Action<int> OnSpeedBonusChanged;
    public static event Action<int> OnCompassionateBonusChanged;
    public static event Action OnCompassionateVictory;
    public static event Action OnStageEnd;
    public static event Action<GameObject> OnRunnerSpawned;
    public static event Action<int> OnStarGained;
    public static event Action OnMainMenuOpen;
    public static event Action OnMainMenuClose;
    public static event Action OnGameOver;

    public delegate void NextDialogue(int index);
    public static NextDialogue OnNextTutorial;

    public static GameState CurrentState;
    public static GameManager Instance;
    public static GameObject LastCrystal;
    public static float HighestDrawnRowHeight;
    public static float RunnerHeight;
    public static int NumberOfRows;
    public static bool IsRunnerInTransition = false;
    public static bool IsStageOver = false;
    public static bool[] DoTutorial;
    public static bool[] DoStageDialogue;
    public static int SpecialDialogueCounter = 0;
    public static int EarlyDialogueCounter = 0;
    public static int MidDialogueCounter = 0;
    public static int LateDialogueCounter = 0;

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
    public static Answer StageAnswer => _stageAnswer;
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
                    IsStageOver = true;
                    Instance.UpdateGameState(GameState.Transition);
                }
            }
        }
    }
    public int SpeedBonus
    {
        get => _speedBonus;
        set
        {
            if (value > _speedBonus)
            {
                ResetCoroutines();
                StartCoroutine(BonusDelay());
            }
            _speedBonus = value;
            OnSpeedBonusChanged?.Invoke(value);
            if (_speedBonus > 100 * (_acquiredStars + 1))
            {
                AcquiredStars++;
                LifetimeStars++;
            }
        }
    }
    public int CompassionateBonus
    {
        get => _compassionateBonus;
        set
        {
            if (value <= 3 && value >= 0)
            {
                _compassionateBonus = value;
                OnCompassionateBonusChanged?.Invoke(value);
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
    public static int LifetimeStars
    {
        get => _lifetimeStars;
        set => _lifetimeStars = value;
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
        NextStageDialogueType();
        LoadStageDialogue();

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

        if (_decreaseSpeedBonus && _triggerBonusStep && !DialogueManager.Instance.IsDialogueActive) { StartCoroutine(BonusDecrease()); }
    }

    private void LoadDefaultSettings()
    {
        _tileSpeedCurve = _settings.TileSpeedCurve;
        _runnerSpeedCurve = _settings.RunnerSpeedCurve;
        _runnerTransitionCurve = _settings.RunnerTransitionCurve;
        _tileSpawnerWidthCurve = _settings.TileSpawnerWidthCurve;
        _tileLength = SampleTileTransform.GetComponent<BoxCollider>().bounds.size.x;
        DoTutorial = new bool[_allTutorialDialogue.Length];
        for (int i = 0; i < _allTutorialDialogue.Length; i++)
        {
            DoTutorial[i] = true;
        }
    }

    private void LoadStageDialogue()
    {
        _allStageDialogue = _earlyStageDialogue.Concat(_midStageDialogue).Concat(_lateStageDialogue).ToArray();
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
        SpeedBonus = SpeedBonus > _acquiredStars * 100 ? SpeedBonus - 1 : _acquiredStars * 100;
        _triggerBonusStep = true;
    }

    private void ResetCoroutines()
    {
        StopAllCoroutines();
        _triggerBonusStep = true;
    }

    private void ResetStats()
    {
        _speedBonus = 0;
        _compassionateBonus = 0;
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

    private void IncrementStageDialogueCounters()
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

    private void NextStageDialogueType() // On end stage
    {
        if ((_lifetimeStars <= 8 && SpecialDialogueCounter == 0) ||
            (_lifetimeStars > 8 && SpecialDialogueCounter == 1) ||
            (_lifetimeStars > 12 && SpecialDialogueCounter == 2))
        {
            _currentStageDialogueType = StageDialogueTypes.Special;
        }
        else if (_lifetimeStars <= 5)
        {
            _currentStageDialogueType = StageDialogueTypes.Early;
        }
        else if (_lifetimeStars > 5 && _lifetimeStars <= 10)
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
                Debug.Log("Selecting special dialogue");
                dialogueToReturn = _specialStageDialogue[SpecialDialogueCounter];
                break;
            case StageDialogueTypes.Early:
                Debug.Log("Selecting early dialogue");
                CheckStageDialogueCounter(0, 0, _earlyStageDialogue.Length, ref EarlyDialogueCounter);
                dialogueToReturn = _earlyStageDialogue[EarlyDialogueCounter];
                break;
            case StageDialogueTypes.Mid:
                Debug.Log("Selecting mid dialogue");
                CheckStageDialogueCounter(0, _earlyStageDialogue.Length, _midStageDialogue.Length, ref MidDialogueCounter);
                dialogueToReturn = _midStageDialogue[MidDialogueCounter];
                break;
            case StageDialogueTypes.Late:
                Debug.Log("Selecting late dialogue");
                CheckStageDialogueCounter(_earlyStageDialogue.Length, _midStageDialogue.Length, _lateStageDialogue.Length, ref LateDialogueCounter);
                dialogueToReturn = _lateStageDialogue[LateDialogueCounter];
                break;
        }

        return dialogueToReturn;
    }

    private void CheckStageDialogueCounter(int previousMin, int newMin, int max, ref int counter)
    {
        if (counter < max)
        {
            DoStageDialogue[counter + previousMin + newMin] = false;
        }
        else
        {
            for (int i = newMin; i < max; i++) { DoStageDialogue[i] = true; }
            counter = 0;
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

    public void SpawnPlayer(Transform tile)
    {
        _currentRunner = Instantiate(_runnerPrefab, tile.position, Quaternion.identity);
        _startOfGame = false;
        OnRunnerSpawned?.Invoke(_currentRunner);
    }

    public static void AddBoardMotion(Transform t)
    {
        if (DialogueManager.Instance.IsTutorialDialogueActive) { return; }

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

    public void SetupNextStage()
    {
        _currentStageDialogue = AssignNextStageDialogue();

        if (_lifetimeStars > 10 && _acquiredStars >= _requiredStars)
        {
            _spawnGoldCrystal = true;
            _spawnPurpleCrystal = true;
            _spawnChargedTileChance = 4;
        }
        else if (_lifetimeStars > 3)
        {
            _spawnGoldCrystal = false;
            _spawnPurpleCrystal = true;
            _spawnChargedTileChance = 5;
        }
        else 
        { 
            _spawnPurpleCrystal = false;
            _spawnGoldCrystal = false;
            _spawnChargedTileChance = 6;
        }

        //_spawnGreenCrystal = _currentStageDialogue.CompassionateAnswer != ""; // Keep this!
        _spawnGreenCrystal = true;

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
            _stageLength = _requiredStars * 80;
        }
        
        OnSetupNextStage?.Invoke();
    }

    public void EndStage()
    {
        IsStageOver = false;

        if (_acquiredStars < _requiredStars)
        {
            _stageAnswer = Answer.Poor;
        }
        else if (_acquiredStars == _requiredStars)
        {
            _stageAnswer = Answer.Acceptable;
            IncrementStageDialogueCounters();
            NextStageDialogueType();
        }
        else if (_acquiredStars > _requiredStars)
        {
            _stageAnswer = Answer.Excellent;
            IncrementStageDialogueCounters();
            NextStageDialogueType();
        }

        if (_compassionateBonus == 3)
        {
            _stageAnswer = Answer.Compassionate;
        }

        SaveData.SavePlayerSettings();
        OnStageEnd?.Invoke();
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
        OnMainMenuOpen?.Invoke();
    }

    public void CloseMainMenu()
    {
        OnMainMenuClose?.Invoke();
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