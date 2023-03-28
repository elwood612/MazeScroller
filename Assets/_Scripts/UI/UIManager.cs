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
    [SerializeField] private GameObject _starPrefab;
    [SerializeField] private Button _continueButton;
    [SerializeField] private Image _blackScreen;
    [SerializeField] private Animation _blackScreenFadeOut;

    private WaitForSecondsRealtime _flashDelay = new WaitForSecondsRealtime(0.25f);
    private WaitForSecondsRealtime _sentenceDelay = new WaitForSecondsRealtime(1f);
    private bool _flashing = true;
    private bool _flashRunning = false;
    private bool _typeOutSentence = true;
    private bool _firstStage = true;
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
        _mainMenuCanvas.enabled = true;
        _blackScreen.enabled = true;
    }

    private void OnEnable()
    {
        GameManager.OnSpeedBonusChanged += UpdateSpeedBonus;
        GameManager.OnRunnerSpawned += AssignDialogueBox;
        GameManager.OnStageEnd += EndStage;
        GameManager.OnStateChanged += BeginStage;
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

        if (_firstStage)
        {
            _firstStage = false;
            return;
        }

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

    private void BlackScreenFade()
    {
        _blackScreenFadeOut.Play();
        //OnContinueButtonClick(); // temp, this should be called from main menu
    }

    public void OnSettingsButtonClick()
    {
        // Open pause menu
    }

    public void OnContinueButtonClick()
    {
        GameManager.Instance.SetupNextStage();
        DialogueManager.Instance.NextQuery(GameManager.CurrentStageDialogue);
        _stageCanvas.enabled = false;
    }

    public void OnStartButtonClick()
    {
        _mainMenuCanvas.enabled = false;
        OnContinueButtonClick();
    }
}
