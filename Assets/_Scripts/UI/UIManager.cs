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
    [SerializeField] private Slider[] _speedSliders;
    [SerializeField] private GameObject _starParent;
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
    [SerializeField] private Toggle _resetToggle;
    [SerializeField] private Image _blackScreen;
    [SerializeField] private Image _loadingScreen;
    [SerializeField] private Animation _blackScreenFadeOut;

    private WaitForSecondsRealtime _flashDelay = new WaitForSecondsRealtime(0.25f);
    private WaitForSecondsRealtime _sentenceDelay = new WaitForSecondsRealtime(1f);
    private bool _flashing = true;
    private bool _flashRunning = false;
    private bool _typeOutSentence = true;
    private TextMeshProUGUI _dialogueBox;
    private int _dialogueIndex = 0;
    private int _newStarIndex = 0;
    private int _bonusStarIndex = 0;
    private List<GameObject> _allStars = new List<GameObject>();
    private Slider _activeSlider;

    private void Awake()
    {
        _activeSlider = _speedSliders[0];
        _topCanvas.enabled = false;
        _stageCanvas.enabled = false;
        _menuSettingsCanvas.enabled = false;
        _blackScreen.enabled = true;
        _loadingScreen.enabled = true;
        //_resetToggle.isOn = false;

        _mainPage.SetActive(true);
        _backPage.SetActive(false);

        ChallengeModeCheck();
    }

    private void OnEnable()
    {
        GameManager.OnSpeedBonusChanged += UpdateSpeedBonus;
        GameManager.OnRunnerSpawned += AssignDialogueBox;
        GameManager.OnStageEnd += EndStage;
        GameManager.OnStateChanged += BeginStage;
        GameManager.OnMainMenuOpen += MainMenu;
        GameManager.OnStarGained += GainStar;
        DialogueManager.OnNextSentence += UpdateDialogueBox;
        DialogueManager.OnDialogueEnd += HideDialogueBox;
        Row.OnFirstRowsReady += BlackScreenFade;
    }

    private void OnDisable()
    {
        GameManager.OnSpeedBonusChanged -= UpdateSpeedBonus;
        GameManager.OnRunnerSpawned -= AssignDialogueBox;
        GameManager.OnStageEnd -= EndStage;
        GameManager.OnStateChanged -= BeginStage;
        GameManager.OnMainMenuOpen -= MainMenu;
        GameManager.OnStarGained -= GainStar;
        DialogueManager.OnNextSentence -= UpdateDialogueBox;
        DialogueManager.OnDialogueEnd -= HideDialogueBox;
        Row.OnFirstRowsReady -= BlackScreenFade;
    }

    private void UpdateSpeedBonus(int value)
    {
        _activeSlider.value = value % (GameManager.RequiredStars * 100);
    }

    private void UpdateDialogueBox(string sentence)
    {
        _dialogueBox.transform.parent.gameObject.SetActive(true);
        StopAllCoroutines();
        _typeOutSentence = true;
        StartCoroutine(TypeSentence(sentence));
        StartCoroutine(FinishSentence(sentence));
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
        _dialogueBox = runner.GetComponent<IRunner>().DialogueBox;
    }

    private void HideDialogueBox()
    {
        _dialogueBox.text = "";
        _dialogueBox.transform.parent.gameObject.SetActive(false);
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
            _activeSlider = _speedSliders[0];
            _topTotalStarAmount.text = GameManager.AcquiredStars.ToString();
            _stageTotalStarAmount.text = GameManager.AcquiredStars.ToString();
            ResetSliders();
            ResetStars();
        }
    }

    private void EndStage()
    {
        _topCanvas.enabled = false;
        _stageCanvas.enabled = true;

        _stageTotalStarAmount.text = GameManager.AcquiredStars.ToString() + " ("
            + GameManager.RequiredStars.ToString()
            + " req.)";
        if (GameManager.AcquiredStars < GameManager.RequiredStars)
        {
            _stageAssessment.text = "You gave a suboptimal answer.";
        }
        else if (GameManager.AcquiredStars == GameManager.RequiredStars)
        {
            _stageAssessment.text = "You gave an adequate answer.";
        }
        else
        {
            _stageAssessment.text = "You gave an excellent answer!";
        }

        ChallengeModeCheck();
        // more conditions pls
    }

    private void GainStar(int level)
    {
        _topTotalStarAmount.text = GameManager.AcquiredStars.ToString();
        _starParent.transform.GetChild(_newStarIndex % GameManager.RequiredStars)
            .GetChild(2 + _bonusStarIndex).gameObject.SetActive(true);
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
            Destroy(star.gameObject); // ok yes this needs to be better
        }
        _allStars.Clear();
        _newStarIndex = 0;
        _bonusStarIndex = 0;
        for (int i = 0; i < GameManager.RequiredStars; i++)
        {
            GameObject newStar = Instantiate(_starPrefab, _starParent.transform);
            _allStars.Add(newStar);
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
        //_challengeModeButton.interactable = GameManager.LifetimeStars > 20;

        _challengeModeButton.interactable = false; // temp until, you know, there IS a challenge mode
    }

    private void BlackScreenFade()
    {
        _blackScreenFadeOut.Play();
        GameManager.Instance.OpenMainMenu();
    }

    public void OnChallengeModeButtonClick()
    {
        // Open pause menu
    }

    public void OnContinueButtonClick()
    {
        GameManager.Instance.SetupNextStage();
        DialogueManager.Instance.NextQuery(GameManager.CurrentStageDialogue);
        _stageCanvas.enabled = false;
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
        _menuSettingsCanvas.enabled = true;
        _storyModeButton.enabled = false;
        _challengeModeButton.enabled = false;
        _quitButton.enabled = false;
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
            _menuSettingsCanvas.enabled = false;
        }
    }
}
