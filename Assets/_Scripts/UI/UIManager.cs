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
    [SerializeField] private Slider[] _speedSliders;
    [SerializeField] private GameObject _starParent;
    [SerializeField] private Canvas _stageCanvas;
    [SerializeField] private Canvas _topCanvas;
    [SerializeField] private GameObject _starPrefab;
    [SerializeField] private Button _continueButton;
    [SerializeField] private Button _tryAgainButton;

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
        _continueButton.interactable = false;
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
    }

    private void UpdateSpeedBonus(int value)
    {
        _activeSlider.value = value % (GameManager.Instance.Parameters[GameManager.CurrentStage].TotalStars * 100);
    }

    //private IEnumerator PanelRedFlash()
    //{
    //    _flashRunning = true;
    //    while (_flashing)
    //    {
    //        yield return _flashDelay;
    //        _redGlow.enabled = true;
    //        yield return _flashDelay;
    //        _redGlow.enabled = false;
    //    }
    //    _flashRunning = false;
    //}

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
        _stageCanvas.enabled = true;
        _stageTotalStarAmount.text = GameManager.AcquiredStars.ToString() + " ("
            + GameManager.Instance.Parameters[GameManager.CurrentStage].TotalStars.ToString()
            + " req.)";
        if (GameManager.AcquiredStars >= GameManager.Instance.Parameters[GameManager.CurrentStage].TotalStars)
        {
            _continueButton.interactable = true;
            _tryAgainButton.interactable = true;
        }
        else
        {
            _continueButton.interactable = false;
            _tryAgainButton.interactable = true;
        }

        if (GameManager.DoTutorial)
        {
            _tryAgainButton.GetComponentInChildren<TextMeshProUGUI>().text = "Start";
        }
        else
        {
            _tryAgainButton.GetComponentInChildren<TextMeshProUGUI>().text = "Try Again";
            if (GameManager.Instance.Parameters[GameManager.CurrentStage].TutorialStage)
            {
                _tryAgainButton.interactable = false;
            }
        }
        
    }

    private void GainStar(int level)
    {
        _topTotalStarAmount.text = GameManager.AcquiredStars.ToString();
        _starParent.transform.GetChild(_newStarIndex % GameManager.Instance.Parameters[GameManager.CurrentStage].TotalStars)
            .GetChild(2 + _bonusStarIndex).gameObject.SetActive(true);
        _newStarIndex++;
        if (level > _bonusStarIndex)
        {
            _bonusStarIndex = level;
            _activeSlider = _speedSliders[_bonusStarIndex];
            _activeSlider.gameObject.SetActive(true);
        }
    }

    private void ResetStars() // for some reason extra stars appear on random stage parameters??
    {
        foreach (var star in _allStars)
        {
            Destroy(star.gameObject); // ok yes this needs to be better
        }
        _allStars.Clear();
        _newStarIndex = 0;
        _bonusStarIndex = 0;
        for (int i = 0; i < GameManager.Instance.Parameters[GameManager.CurrentStage].TotalStars; i++)
        {
            GameObject newStar = Instantiate(_starPrefab, _starParent.transform);
            _allStars.Add(newStar);
        }
    }

    private void ResetSliders()
    {
        foreach (Slider slider in _speedSliders)
        {
            slider.maxValue = GameManager.Instance.Parameters[GameManager.CurrentStage].TotalStars * 100;
            slider.value = 0;
            if (slider != _speedSliders[0]) { slider.gameObject.SetActive(false); }
        }
    }

    public void OnSettingsButtonClick()
    {
        // Open pause menu
    }

    public void OnContinueButtonClick()
    {
        GameManager.Instance.SetupNextStage();
        GameManager.Instance.GoodToBeginDialogue();
        _stageCanvas.enabled = false;
    }

    public void OnRestartButtonClick()
    {
        GameManager.Instance.GoodToBeginDialogue();
        _stageCanvas.enabled = false;
    }
}
