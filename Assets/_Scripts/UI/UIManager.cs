using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;
using System.Collections.Generic;

public class UIManager : MonoBehaviour
{
    [SerializeField] private TextMeshProUGUI _topTotalStarAmount;
    [SerializeField] private TextMeshProUGUI _stageCurrentScore;
    [SerializeField] private TextMeshProUGUI _stageAssessment;
    [SerializeField] private TextMeshProUGUI _lifetimeStarsAmountMenu;
    [SerializeField] private TextMeshProUGUI _newHighScore;
    [SerializeField] private Slider[] _speedSliders;
    [SerializeField] private GameObject _requiredStars;
    [SerializeField] private GameObject _starParent;
    [SerializeField] private GameObject _compassionateStars;
    [SerializeField] private Slider[] _compassionateSliders;
    [SerializeField] private Canvas _stageCanvas;
    [SerializeField] private Canvas _topCanvas;
    [SerializeField] private Canvas _mainMenuCanvas;
    [SerializeField] private Canvas _menuSettingsCanvas;
    [SerializeField] private GameObject _starPrefab;
    [SerializeField] private GameObject _mainMenuButtons;
    [SerializeField] private GameObject _endStageButtons;
    [SerializeField] private GameObject _mainPage;
    [SerializeField] private GameObject _backPage;
    [SerializeField] private Button _storyModeButton;
    [SerializeField] private Button _challengeModeButton;
    [SerializeField] private Button _quitButton;
    [SerializeField] private Button _quitToMenuButton;
    [SerializeField] private Button _resetButton;
    [SerializeField] private TextMeshProUGUI _loadingText;
    [SerializeField] private Image _blackScreenStart;
    [SerializeField] private Image _blackScreenEnd;
    [SerializeField] private GameObject _endCreditsObj;
    [SerializeField] private Animation _blackScreenFadeOut;
    [SerializeField] private Animation _blackScreenFadeIn;
    [SerializeField] private Animation _endCreditsAnimation;
    [SerializeField] private TMP_FontAsset _liberationFont;
    [SerializeField] private TMP_FontAsset _VCRFont;
    [SerializeField] private TextMeshProUGUI _debugMessage;

    private WaitForSecondsRealtime _sentenceDelay = new WaitForSecondsRealtime(1f);
    private WaitForSecondsRealtime _starGainDelay = new WaitForSecondsRealtime(0.35f);
    private bool _typeOutSentence = true;
    private bool _isDialogueBoxOpen = false;
    private TextMeshProUGUI _dialogueBox;
    private Image _runnerFace;
    private int _newStarIndex = 0;
    private int _bonusStarIndex = 0;
    private List<GameObject> _allStars = new List<GameObject>();
    private Slider _activeSlider;
    private WaitForSecondsRealtime _hintDelay = new WaitForSecondsRealtime(3f);
    private WaitForSeconds _menuResetDelay = new WaitForSeconds(5f);
    private Color _runnerDialogueColor = new Color(0.478f, 1f, 1f, 1f);
    private Color _incomingQueryColor = new Color(0f, 0.764f, 0f, 1f);
    private string _currentSentence;

    public bool _blackScreenEndDeactivated = false;

    private void Awake()
    {
        _activeSlider = _speedSliders[0];
        _compassionateStars.SetActive(false);
        _lifetimeStarsAmountMenu.text = GameManager.HighScore.ToString();
        _topCanvas.enabled = false;
        _stageCanvas.enabled = false;
        _menuSettingsCanvas.enabled = false;
        _blackScreenStart.enabled = true;
        _blackScreenEnd.enabled = false;
        _loadingText.enabled = true;
        _mainPage.SetActive(true);
        _backPage.SetActive(false);
        _endCreditsObj.SetActive(false);
        _newHighScore.enabled = false;
        _debugMessage.enabled = false;
    }

    private void OnEnable()
    {
        GameManager.OnStarBonusChanged += UpdateSpeedBonus;
        GameManager.OnCompassionateChargeUp += UpdateCompassionateSlider;
        GameManager.OnCompassionateStarsToggle += ToggleCompassionateStars;
        GameManager.OnCompassionateStarsReset += ResetCompassionateStars;
        GameManager.OnRunnerSpawned += AssignDialogueBox;
        GameManager.OnStageEnd += EndStage;
        GameManager.OnStateChanged += BeginStage;
        GameManager.OnMainMenuOpen += MainMenu;
        GameManager.OnStarGained += GainStar;
        GameManager.OnGameOver += BlackScreenFadeIn;
        DialogueManager.OnNextSentence += UpdateDialogueBox;
        DialogueManager.OnDialogueEnd += HideDialogueBox;
        Row.OnFirstRowsReady += BlackScreenFadeOut;
        GameManager.OnErrorMessage += DisplayErrorMessage;
    }

    private void OnDisable()
    {
        GameManager.OnStarBonusChanged -= UpdateSpeedBonus;
        GameManager.OnCompassionateChargeUp -= UpdateCompassionateSlider;
        GameManager.OnCompassionateStarsToggle -= ToggleCompassionateStars;
        GameManager.OnCompassionateStarsReset -= ResetCompassionateStars;
        GameManager.OnRunnerSpawned -= AssignDialogueBox;
        GameManager.OnStageEnd -= EndStage;
        GameManager.OnStateChanged -= BeginStage;
        GameManager.OnMainMenuOpen -= MainMenu;
        GameManager.OnStarGained -= GainStar;
        GameManager.OnGameOver -= BlackScreenFadeIn;
        DialogueManager.OnNextSentence -= UpdateDialogueBox;
        DialogueManager.OnDialogueEnd -= HideDialogueBox;
        Row.OnFirstRowsReady -= BlackScreenFadeOut;
        GameManager.OnErrorMessage -= DisplayErrorMessage;
    }

    private void DisplayErrorMessage(string s)
    {
        _debugMessage.text = s;
        _debugMessage.enabled = true;
    }

    private void UpdateSpeedBonus(int value)
    {
        _activeSlider.value = value % (GameManager.RequiredStars * 100);
    }

    private void ToggleCompassionateStars(bool toggle)
    {
        _compassionateStars.SetActive(toggle);
        _requiredStars.SetActive(!toggle);
    }

    private void ResetCompassionateStars()
    {
        for (int i = 0; i < 3; i++)
        {
            _compassionateSliders[i].value = 0;
        }
    }

    private void UpdateCompassionateSlider(int value)
    {
        _compassionateSliders[GameManager.Instance.CompassionateStars].value = value;
    }

    private void UpdateDialogueBox(string newSentence)
    {
        if (DialogueManager.Instance.IsQuery)
        {
            _dialogueBox.font = _VCRFont;
            _dialogueBox.color = _incomingQueryColor;
            _dialogueBox.transform.GetComponentInParent<Image>().color = _incomingQueryColor;
            _runnerFace.enabled = false;
        }
        else
        {
            _dialogueBox.font = _liberationFont;
            _dialogueBox.color = _runnerDialogueColor;
            _dialogueBox.transform.GetComponentInParent<Image>().color = _runnerDialogueColor;
            _runnerFace.enabled = true;
        }
        _isDialogueBoxOpen = true;
        _dialogueBox.transform.GetComponentInParent<Canvas>().enabled = true;
        StopCoroutine(TypeSentence(_currentSentence));
        StopCoroutine(FinishSentence());
        _currentSentence = newSentence;
        _typeOutSentence = true;
        StartCoroutine(TypeSentence(newSentence));
        StartCoroutine(FinishSentence());
        if (GameManager.NeedDialogueBoxHint) { StartCoroutine(HintDialogue()); }
    }

    private IEnumerator TypeSentence(string sentence)
    {
        _dialogueBox.text = "";
        foreach (char letter in sentence.ToCharArray())
        {
            if (_typeOutSentence)
            {
                _dialogueBox.text += letter;
                yield return null;
            }
            else
            {
                break;
            }
        }
    }

    private IEnumerator FinishSentence() // ensures dialogue doesn't take too long to appear
    {
        yield return _sentenceDelay;
        _typeOutSentence = false;
        _dialogueBox.text = _currentSentence;
    }

    private void AssignDialogueBox(GameObject runner)
    {
        IRunner r = runner.GetComponent<IRunner>();
        if (r == null) { Debug.Log("Error! No runner found!"); return; }

        _dialogueBox = r.DialogueBox;
        _runnerFace = r.RunnerFace;
    }

    private void HideDialogueBox()
    {
        _dialogueBox.text = "";
        _dialogueBox.transform.GetChild(0).gameObject.SetActive(false);
        _dialogueBox.transform.GetComponentInParent<Canvas>().enabled = false;
        _isDialogueBoxOpen = false;
    }

    private void MainMenu()
    {
        _mainMenuCanvas.enabled = true;
        _loadingText.enabled = false;
        _lifetimeStarsAmountMenu.text = "High Score: " + GameManager.HighScore.ToString();
        _storyModeButton.GetComponentInChildren<TextMeshProUGUI>().text = GameManager.GameUnderway ? "Continue Game" : "Start New Game";
    }

    private void BeginStage(GameState state)
    {
        if (state == GameState.Progressing)
        {
            _topCanvas.enabled = true;
            _newHighScore.enabled = false;
            _activeSlider = _speedSliders[0];
            _topTotalStarAmount.text = GameManager.AcquiredStars.ToString() + " ("
            + GameManager.RequiredStars.ToString()
            + " req.)";

            _stageCurrentScore.text = "Current score: " + GameManager.CurrentScore.ToString();
            ResetSliders();
            ResetStars();
        }
    }

    private void EndStage() // this is helpful
    {
        _requiredStars.SetActive(false);
        if (GameManager.GlobalDialogueCounter >= GameManager.MaxStages)
        {
            _endStageButtons.SetActive(false);
            if (GameManager.CurrentScore > GameManager.PreviousHighScore) // This is wrong!
            {
                _newHighScore.enabled = true;
            }
        }
        else
        {
            _endStageButtons.SetActive(true);
        }
        _stageCanvas.enabled = true;
        _stageCurrentScore.text = "Current score: " + (GameManager.CurrentScore - GameManager.AcquiredStars).ToString();

        Assessment(GameManager.StageAnswerQuality);
        StartCoroutine(BankStars(GameManager.AcquiredStars));
        DialogueManager.Instance.NextAnswer(GameManager.CurrentStageDialogue);
    }

    private IEnumerator BankStars(int stars)
    {
        for (int i = 1; i <= stars; i++)
        {
            yield return _starGainDelay;
            _stageCurrentScore.text = "Current score: " + (GameManager.CurrentScore - GameManager.AcquiredStars + i).ToString();
            _topTotalStarAmount.text = (GameManager.AcquiredStars - i).ToString() 
                + " ("
                + GameManager.RequiredStars.ToString()
                + " req.)";
            AudioManager.Instance.UIStar.Play();
        }
        _stageAssessment.enabled = true;
        AudioManager.Instance.UILevelDone.Play(); // Change this depending on answer quality
    }

    private void Assessment(Answer answer)
    {
        if (answer == Answer.Poor)
        {
            _stageAssessment.text = "Incomplete answer, try again.";
        }
        else if (answer == Answer.Acceptable)
        {
            _stageAssessment.text = "Acceptable answer.";
        }
        else if (answer == Answer.Excellent)
        {
            _stageAssessment.text = "Excellent answer!";
        }
        else if (answer == Answer.Compassionate)
        {
            _stageAssessment.text = "Error: Answer outside AI limits.";
        }
    }

    private void GainStar(int level)
    {
        _topTotalStarAmount.text = GameManager.AcquiredStars.ToString() + " ("
            + GameManager.RequiredStars.ToString()
            + " req.)";
        _starParent.transform.GetChild(_newStarIndex % GameManager.RequiredStars)
            .GetChild(Mathf.Min(2 + _bonusStarIndex, 5)).gameObject.SetActive(true);
        _newStarIndex++;
        if (level > _bonusStarIndex)
        {
            _bonusStarIndex = level;
            if (_bonusStarIndex < _speedSliders.Length) 
            {
                _activeSlider = _speedSliders[_bonusStarIndex];
            }
            _activeSlider.gameObject.SetActive(true);
        }
    }

    private void ResetStars() 
    {
        foreach (var star in _allStars)
        {
            Destroy(star.gameObject);
        }
        _allStars.Clear();
        _newStarIndex = 0;
        _bonusStarIndex = 0;
        
        for (int i = 0; i < GameManager.RequiredStars; i++)
        {
            GameObject newStar = Instantiate(_starPrefab, _starParent.transform);
            _allStars.Add(newStar);
        }
        ToggleCompassionateStars(false);
        ResetCompassionateStars();
    }

    private void ResetSliders()
    {
        foreach (Slider slider in _speedSliders)
        {
            slider.maxValue = GameManager.RequiredStars * 100;
            slider.value = 0;
            if (slider != _speedSliders[0]) { slider.gameObject.SetActive(false); }
        }
    }

    private void BlackScreenFadeOut()
    {
        _blackScreenFadeOut.Play();
        GameManager.Instance.OpenMainMenu();
        Invoke("DisableBlackScreenStart", 1.8f);
    }

    private void BlackScreenFadeIn()
    {
        _stageCanvas.enabled = false;
        _blackScreenEnd.enabled = true;
        _blackScreenEnd.color = new Color(0, 0, 0, 0);
        _blackScreenFadeIn.Play();
        StartCoroutine(EndCreditsRoll());
        GameManager.Instance.ResetDefaultSettings();
    }

    private IEnumerator MainMenuReset()
    {
        yield return _menuResetDelay;
        _blackScreenFadeOut.Play();
        Invoke("DisableBlackScreenStart", 1.8f);
        _loadingText.enabled = false;
    }

    private IEnumerator EndCreditsRoll()
    {
        _endCreditsObj.SetActive(true);
        _endCreditsAnimation.Play();

        yield return new WaitForSeconds(_endCreditsAnimation.GetClip("CreditScroll").length);

        if (!_blackScreenEndDeactivated)
        {
            _blackScreenEndDeactivated = true;
            _endCreditsObj.SetActive(false);
            _blackScreenEnd.enabled = false;
            OnQuitToMenu();
        }
    }

    private IEnumerator HintDialogue()
    {
        GameManager.NeedDialogueBoxHint = false;
        yield return _hintDelay;
        if (_isDialogueBoxOpen)
        {
            _dialogueBox.transform.GetChild(0).gameObject.SetActive(true);
        }
    }

    private void DisableBlackScreenStart() // This gets invoked twice in UIManager. Sorry not sorry.
    {
        _blackScreenStart.enabled = false;
    }

    public void DeactivateBlackScreen()
    {
        _blackScreenEndDeactivated = true;
    }

    public void OnContinueButtonClick()
    {
        _stageCanvas.enabled = false;
        _stageAssessment.enabled = false;

        if (GameManager.IsGameOver)
        {
            GameManager.OnNextTutorial?.Invoke(14);
            GameManager.Instance.UpdateGameState(GameState.Transition);
            return;
        }
        else
        {
            GameManager.Instance.SetupNextStage();
            DialogueManager.Instance.EndDialogue();
            DialogueManager.Instance.NextQuery(GameManager.CurrentStageDialogue);
        }
    }

    public void OnStoryModeButtonClick()
    {
        _mainMenuCanvas.enabled = false;
        GameManager.Instance.CloseMainMenu();
        OnContinueButtonClick();
    }

    public void OnMenuSettingsClick()
    {
        if (!_menuSettingsCanvas.enabled)
        {
            _menuSettingsCanvas.enabled = true;
            _mainMenuButtons.SetActive(false);
        }
        else
        {
            _menuSettingsCanvas.enabled = false;
            _mainMenuButtons.SetActive(true);
        }
    }

    public void OnStageSettingsClick()
    {
        if (!_menuSettingsCanvas.enabled)
        {
            GameManager.IsStageMenuOpen = true;
            _menuSettingsCanvas.enabled = true;
            _resetButton.gameObject.SetActive(false);
            _quitToMenuButton.gameObject.SetActive(true);
        }
        else
        {
            GameManager.IsStageMenuOpen = false;
            _menuSettingsCanvas.enabled = false;
            _resetButton.gameObject.SetActive(true);
            _quitToMenuButton.gameObject.SetActive(false);
        }
    }

    public void OnBackButtonClick()
    {
        _mainMenuButtons.SetActive(true);
        _resetButton.gameObject.SetActive(true);
        _menuSettingsCanvas.enabled = false;
        _quitToMenuButton.gameObject.SetActive(false);
        GameManager.IsStageMenuOpen = false;
    }

    public void OnResetGame()
    {
        _backPage.SetActive(true);
        _mainPage.SetActive(false);
    }

    public void OnYesToResetClick()
    {
        SaveData.ClearAllSettings();
        GameManager.Instance.LoadDefaultSettings();
        GameManager.HighScore = 0;
        OnQuitToMenu();
     }

    public void OnQuitToMenu()
    {
        _menuSettingsCanvas.enabled = false;
        _topCanvas.enabled = false;
        _blackScreenStart.color = Color.black;
        _blackScreenStart.enabled = true;
        GameManager.IsStageMenuOpen = false;
        GameManager.Instance.QuitToMenu();
        _loadingText.enabled = true;
        StartCoroutine(MainMenuReset());
    }
}
