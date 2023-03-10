using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;
using System;
using System.Collections.Generic;

public class UIManager : MonoBehaviour
{
    [SerializeField] private TextMeshProUGUI _scoreText;
    [SerializeField] private TextMeshProUGUI _stageScore;
    [SerializeField] private TextMeshProUGUI _totalStarAmount;
    [SerializeField] private Slider _speedSlider;
    [SerializeField] private GameObject _starParent;
    [SerializeField] private Slider _loseSlider;
    [SerializeField] private Image _redGlow;
    [SerializeField] private Canvas _stageCanvas;
    [SerializeField] private Canvas _topCanvas;
    [SerializeField] private GameObject _starPrefab;

    private WaitForSecondsRealtime _delay = new WaitForSecondsRealtime(0.25f);
    private bool _flashing = true;
    private bool _flashRunning = false;
    private TextMeshProUGUI _dialogueBox;
    private int _dialogueIndex = 0;
    private int _newStarIndex = 0;
    private List<GameObject> _allStars = new List<GameObject>();

    private void Awake()
    {
        UpdateScore(0);
        _speedSlider.value = GameManager.Instance.SpeedBonus;
        _loseSlider.value = 0;
        _loseSlider.gameObject.SetActive(false);
        _redGlow.enabled = false;
        _topCanvas.enabled = false;
        _stageCanvas.enabled = false;
    }

    private void OnEnable()
    {
        GameManager.OnScoreChanged += UpdateScore;
        GameManager.OnSpeedBonusChanged += UpdateSpeedBonus;
        GameManager.OnLoseCounterChanged += Losing;
        GameManager.OnRunnerSpawned += AssignDialogueBox;
        GameManager.OnStageEnd += EndStage;
        GameManager.OnStateChanged += BeginStage;
        GameManager.OnStarGained += GainStar;
        DialogueManager.OnNextSentence += UpdateDialogueBox;
        DialogueManager.OnDialogueEnd += HideDialogueBox;
    }

    private void OnDisable()
    {
        GameManager.OnScoreChanged -= UpdateScore;
        GameManager.OnSpeedBonusChanged -= UpdateSpeedBonus;
        GameManager.OnLoseCounterChanged -= Losing;
        GameManager.OnRunnerSpawned -= AssignDialogueBox;
        GameManager.OnStageEnd -= EndStage;
        GameManager.OnStateChanged -= BeginStage;
        DialogueManager.OnNextSentence -= UpdateDialogueBox;
        DialogueManager.OnDialogueEnd -= HideDialogueBox;
    }

    private void UpdateScore(int score)
    {
        _scoreText.text = "Score: " + score.ToString();
    }

    private void UpdateSpeedBonus(int value)
    {
        _speedSlider.value = value;
    }

    private void UpdateLoseSlider(int value)
    {
        _loseSlider.value = value;
    }

    private void Losing(int value)
    {
        _flashing = value > 0;
        if (_flashing && !_flashRunning) 
        {
            _loseSlider.gameObject.SetActive(true);
            UpdateLoseSlider(value);
            StartCoroutine(PanelRedFlash()); 
        }
        if (!_flashing) 
        {
            UpdateLoseSlider(value);
            _loseSlider.gameObject.SetActive(false);
            StopCoroutine(PanelRedFlash()); 
        }
    }

    private IEnumerator PanelRedFlash()
    {
        _flashRunning = true;
        while (_flashing)
        {
            yield return _delay;
            _redGlow.enabled = true;
            yield return _delay;
            _redGlow.enabled = false;
        }
        _flashRunning = false;
    }

    private void UpdateDialogueBox(string sentence)
    {
        _dialogueBox.transform.parent.gameObject.SetActive(true);
        StopAllCoroutines();
        StartCoroutine(TypeSentence(sentence));
    }

    private IEnumerator TypeSentence(string sentence)
    {
        _dialogueBox.text = "";
        foreach (char letter in sentence.ToCharArray())
        {
            _dialogueBox.text += letter;
            yield return null;
        }
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
            _speedSlider.maxValue = GameManager.Instance.Parameters[GameManager.CurrentStage].TotalStars * 100;
            _speedSlider.value = 0;
            ResetStars();
        }
    }

    private void EndStage()
    {
        _topCanvas.enabled = false;
        _stageCanvas.enabled = true;
        //_stageScore.text = "Score: " + (GameManager.Score + GameManager.AcquiredStars * 1000);
        _totalStarAmount.text = GameManager.AcquiredStars.ToString();
    }

    private void GainStar()
    {
        _starParent.transform.GetChild(_newStarIndex).GetChild(2).gameObject.SetActive(true);
        _newStarIndex++;
    }

    private void ResetStars()
    {
        foreach (var star in _allStars)
        {
            Destroy(star.gameObject); // ok yes this needs to be better
        }
        _allStars.Clear();
        _newStarIndex = 0;
        for (int i = 0; i < GameManager.Instance.Parameters[GameManager.CurrentStage].TotalStars; i++)
        {
            GameObject newStar = Instantiate(_starPrefab, _starParent.transform);
            _allStars.Add(newStar);
        }
    }

    public void OnSettingsButtonClick()
    {
        // Open pause menu
    }

    public void OnContinueButtonClick()
    {
        GameManager.Instance.GoodToBeginDialogue();
        _stageCanvas.enabled = false;
    }

    public void OnQuitButtonClick()
    {
        // Quit to menu
    }
}
