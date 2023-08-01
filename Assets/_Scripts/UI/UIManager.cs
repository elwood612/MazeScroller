using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;
using System;
using System.Collections.Generic;

public class UIManager : MonoBehaviour
{
    [SerializeField] private TextMeshProUGUI _topTotalStarAmount;
    [SerializeField] private TextMeshProUGUI _stageTotalStarAmount;
    [SerializeField] private TextMeshProUGUI _stageAssessment;
    [SerializeField] private TextMeshProUGUI _lifetimeStarsAmountMenu;
    [SerializeField] private Slider[] _speedSliders;
    [SerializeField] private GameObject _requiredStars;
    [SerializeField] private GameObject _starParent;
    [SerializeField] private GameObject _compassionateStars;
    [SerializeField] private GameObject _emptySlots;
    [SerializeField] private Canvas _stageCanvas;
    [SerializeField] private Canvas _topCanvas;
    [SerializeField] private Canvas _mainMenuCanvas;
    [SerializeField] private Canvas _menuSettingsCanvas;
    [SerializeField] private GameObject _starPrefab;
    [SerializeField] private GameObject _buttons;
    [SerializeField] private GameObject _mainPage;
    [SerializeField] private GameObject _backPage;
    [SerializeField] private Button _storyModeButton;
    [SerializeField] private Button _challengeModeButton;
    [SerializeField] private Button _quitButton;
    [SerializeField] private Button _quitToMenuButton;
    [SerializeField] private Toggle _resetToggle;
    [SerializeField] private Image _loadingScreen;
    [SerializeField] private Image _blackScreenStart;
    [SerializeField] private Image _blackScreenEnd;
    [SerializeField] private GameObject _endCreditsObj;
    [SerializeField] private Animation _blackScreenFadeOut;
    [SerializeField] private Animation _blackScreenFadeIn;
    [SerializeField] private Animation _endCreditsAnimation;
    [SerializeField] private TMP_FontAsset _liberationFont;
    [SerializeField] private TMP_FontAsset _VCRFont;

    private WaitForSecondsRealtime _sentenceDelay = new WaitForSecondsRealtime(1f);
    private WaitForSecondsRealtime _starGainDelay = new WaitForSecondsRealtime(0.4f);
    private bool _typeOutSentence = true;
    private bool _isDialogueBoxOpen = false;
    private TextMeshProUGUI _dialogueBox;
    //private TextMeshProUGUI _answerBox;
    private Image _runnerFace;
    private int _newStarIndex = 0;
    private int _bonusStarIndex = 0;
    private List<GameObject> _allStars = new List<GameObject>();
    private Slider _activeSlider;
    private WaitForSecondsRealtime _hintDelay = new WaitForSecondsRealtime(3f);
    private WaitForSeconds _menuResetDelay = new WaitForSeconds(5f);
    private Color _runnerDialogueColor = new Color(0.478f, 1f, 1f, 1f);
    private Color _incomingQueryColor = new Color(0f, 0.764f, 0f, 1f);

    private void Awake()
    {
        _activeSlider = _speedSliders[0];
        _lifetimeStarsAmountMenu.text = GameManager.LifetimeStars.ToString();
        _topCanvas.enabled = false;
        _stageCanvas.enabled = false;
        _menuSettingsCanvas.enabled = false;
        _blackScreenStart.enabled = true;
        _blackScreenEnd.enabled = false;
        _loadingScreen.enabled = true;
        _mainPage.SetActive(true);
        _backPage.SetActive(false);
        ChallengeModeCheck();
    }

    private void OnEnable()
    {
        GameManager.OnSpeedBonusChanged += UpdateSpeedBonus;
        GameManager.OnCompassionateBonusChanged += UpdateCompassionateBonus;
        GameManager.OnRunnerSpawned += AssignDialogueBox;
        GameManager.OnStageEnd += EndStage;
        GameManager.OnStateChanged += BeginStage;
        GameManager.OnMainMenuOpen += MainMenu;
        GameManager.OnStarGained += GainStar;
        GameManager.OnGameOver += BlackScreenFadeIn;
        GameManager.OnShowEmptySlots += ShowEmptySlots;
        DialogueManager.OnNextSentence += UpdateDialogueBox;
        DialogueManager.OnNextAnswer += UpdateAnswerBox;
        DialogueManager.OnDialogueEnd += HideDialogueBox;
        Row.OnFirstRowsReady += BlackScreenFadeOut;
    }

    private void OnDisable()
    {
        GameManager.OnSpeedBonusChanged -= UpdateSpeedBonus;
        GameManager.OnCompassionateBonusChanged -= UpdateCompassionateBonus;
        GameManager.OnRunnerSpawned -= AssignDialogueBox;
        GameManager.OnStageEnd -= EndStage;
        GameManager.OnStateChanged -= BeginStage;
        GameManager.OnMainMenuOpen -= MainMenu;
        GameManager.OnStarGained -= GainStar;
        GameManager.OnGameOver -= BlackScreenFadeIn;
        GameManager.OnShowEmptySlots -= ShowEmptySlots;
        DialogueManager.OnNextSentence -= UpdateDialogueBox;
        DialogueManager.OnNextAnswer -= UpdateAnswerBox;
        DialogueManager.OnDialogueEnd -= HideDialogueBox;
        Row.OnFirstRowsReady -= BlackScreenFadeOut;
    }

    private void UpdateSpeedBonus(int value)
    {
        _activeSlider.value = value % (GameManager.RequiredStars * 100);
    }

    private void UpdateCompassionateBonus(int value)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i < value)
            {
                _compassionateStars.transform.GetChild(i + 1).gameObject.SetActive(true);
            }
            else
            {
                _compassionateStars.transform.GetChild(i + 1).gameObject.SetActive(false);
            }
        }

        //_compassionateStars.transform.GetChild(value - 1).gameObject.SetActive(true);
    }

    private void UpdateDialogueBox(string sentence)
    {
        // Still need LCD screen art
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
        StopCoroutine(TypeSentence(sentence));
        StopCoroutine(FinishSentence(sentence));
        _typeOutSentence = true;
        StartCoroutine(TypeSentence(sentence));
        StartCoroutine(FinishSentence(sentence));
        if (GameManager.NeedDialogueBoxHint) { StartCoroutine(HintDialogue()); }
    }

    private void SetRunnerMood()
    {

    }

    private void UpdateAnswerBox(string sentence)
    {
        //_answerBox.transform.parent.gameObject.SetActive(true);
        //_answerBox.text = sentence;
    }

    private void ShowEmptySlots()
    {
        _emptySlots.SetActive(true);
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

    private IEnumerator FinishSentence(string sentence) // ensures dialogue doesn't take too long to appear
    {
        yield return _sentenceDelay;
        _typeOutSentence = false;
        _dialogueBox.text = sentence;
    }

    private void AssignDialogueBox(GameObject runner)
    {
        IRunner r = runner.GetComponent<IRunner>();
        if (r == null) { Debug.Log("Error! No runner found!"); return; }

        _dialogueBox = r.DialogueBox;
        //_answerBox = r.AnswerBox;
        //_glowBox = r.GlowBox;
        _runnerFace = r.RunnerFace;
    }

    private void HideDialogueBox()
    {
        _dialogueBox.text = "";
        _dialogueBox.transform.GetChild(0).gameObject.SetActive(false);
        //_answerBox.transform.parent.gameObject.SetActive(false);
        _dialogueBox.transform.GetComponentInParent<Canvas>().enabled = false;
        _isDialogueBoxOpen = false;
    }

    private void MainMenu()
    {
        _mainMenuCanvas.enabled = true;
        _loadingScreen.enabled = false;
    }

    private void BeginStage(GameState state)
    {
        if (state == GameState.Progressing)
        {
            _topCanvas.enabled = true;
            _requiredStars.SetActive(true);
            _activeSlider = _speedSliders[0];
            _topTotalStarAmount.text = GameManager.AcquiredStars.ToString() + " ("
            + GameManager.RequiredStars.ToString()
            + " req.)";

            _stageTotalStarAmount.text = GameManager.LifetimeStars.ToString();
            ResetSliders();
            ResetStars();
        }
    }

    private void EndStage()
    {
        _requiredStars.SetActive(false);
        _emptySlots.SetActive(false);
        _stageCanvas.enabled = true;
        _stageTotalStarAmount.text = (GameManager.LifetimeStars - GameManager.AcquiredStars).ToString();
        _lifetimeStarsAmountMenu.text = GameManager.LifetimeStars.ToString();

        Assessment(GameManager.StageAnswer);
        StartCoroutine(BankStars(GameManager.AcquiredStars));
        DialogueManager.Instance.NextAnswer(GameManager.CurrentStageDialogue);
    }

    private IEnumerator BankStars(int stars)
    {
        for (int i = 1; i <= stars; i++)
        {
            yield return _starGainDelay;
            _stageTotalStarAmount.text = (GameManager.LifetimeStars - GameManager.AcquiredStars + i).ToString();
            _topTotalStarAmount.text = (GameManager.AcquiredStars - i).ToString() 
                + " ("
                + GameManager.RequiredStars.ToString()
                + " req.)";
            AudioManager.Instance.UIStar.Play();
        }
        _stageAssessment.enabled = true;
        AudioManager.Instance.UILevelDone.Play();
    }

    private void Assessment(Answer answer)
    {
        if (answer == Answer.Poor)
        {
            _stageAssessment.text = "Not enough stars for a complete answer.";
        }
        else if (answer == Answer.Acceptable)
        {
            _stageAssessment.text = "Acceptable answer.";
        }
        else if (answer == Answer.Excellent)
        {
            _stageAssessment.text = "Excellent answer with extra puns!";
        }
        else if (answer == Answer.Compassionate)
        {
            _stageAssessment.text = "Error: answer outside limits of AI language model.";
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
            Destroy(star.gameObject); // ok yes this needs to be better OR DOES IT
        }
        _allStars.Clear();
        _newStarIndex = 0;
        _bonusStarIndex = 0;
        for (int i = 0; i < GameManager.RequiredStars; i++)
        {
            GameObject newStar = Instantiate(_starPrefab, _starParent.transform);
            _allStars.Add(newStar);
        }
        for (int i = 0; i <= 3; i++)
        {
            _compassionateStars.transform.GetChild(i).gameObject.SetActive(false);
        }
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

    private void ChallengeModeCheck()
    {
        _challengeModeButton.interactable = false; // temp until, you know, there IS a challenge mode
    }

    private void BlackScreenFadeOut()
    {
        _blackScreenFadeOut.Play();
        GameManager.Instance.OpenMainMenu();
    }

    private void BlackScreenFadeIn()
    {
        _blackScreenEnd.enabled = true;
        _blackScreenFadeIn.Play();
        EndCreditsRoll();
    }

    private IEnumerator MainMenuReset()
    {
        yield return _menuResetDelay;
        _blackScreenFadeOut.Play();
        _loadingScreen.enabled = false;
    }

    private void EndCreditsRoll()
    {
        _endCreditsObj.SetActive(true);
        _endCreditsAnimation.Play();
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

    

    public void OnChallengeModeButtonClick()
    {
        // Open challenge mode
    }

    public void OnContinueButtonClick()
    {
        _stageCanvas.enabled = false;
        _stageAssessment.enabled = false;

        if (GameManager.IsGameOver)
        {
            GameManager.OnNextTutorial(14);
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
        if (_resetToggle.isOn)
        {
            _resetToggle.isOn = false;
        }
    }

    public void OnMenuSettingsClick()
    {
        if (!_menuSettingsCanvas.enabled)
        {
            _menuSettingsCanvas.enabled = true;
            _buttons.SetActive(false);
        }
        else
        {
            _menuSettingsCanvas.enabled = false;
            _buttons.SetActive(true);
        }
    }

    public void OnStageSettingsClick()
    {
        if (!_menuSettingsCanvas.enabled)
        {
            GameManager.IsStageMenuOpen = true;
            _menuSettingsCanvas.enabled = true;
            _resetToggle.gameObject.SetActive(false);
            _quitToMenuButton.gameObject.SetActive(true);
        }
        else
        {
            GameManager.IsStageMenuOpen = false;
            _menuSettingsCanvas.enabled = false;
            _resetToggle.gameObject.SetActive(true);
            _quitToMenuButton.gameObject.SetActive(false);
        }
    }

    public void OnBackButtonClick()
    {
        if (_resetToggle.isOn)
        {
            _backPage.SetActive(true);
            _mainPage.SetActive(false);
        }
        else
        {
            _buttons.SetActive(true);
            _resetToggle.gameObject.SetActive(true);
            _menuSettingsCanvas.enabled = false;
            _quitToMenuButton.gameObject.SetActive(false);
            GameManager.IsStageMenuOpen = false;
        }
    }

    public void OnQuitToMenu()
    {
        _menuSettingsCanvas.enabled = false;
        _topCanvas.enabled = false;
        _blackScreenStart.color = Color.black;
        _blackScreenStart.enabled = true;
        GameManager.IsStageMenuOpen = false;
        GameManager.Instance.QuitToMenu();
        _loadingScreen.enabled = true;
        StartCoroutine(MainMenuReset());
    }
}
