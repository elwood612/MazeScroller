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
    [SerializeField] private TextMeshProUGUI _topTotalStarAmount;
    [SerializeField] private TextMeshProUGUI _stageTotalStarAmount;
    [SerializeField] private Slider[] _speedSliders;
    [SerializeField] private GameObject _starParent;
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
    private int _bonusStarIndex = 0;
    private List<GameObject> _allStars = new List<GameObject>();
    private Slider _activeSlider;

    private void Awake()
    {
        UpdateScore(0);
        _activeSlider = _speedSliders[0];
        _redGlow.enabled = false;
        _topCanvas.enabled = false;
        _stageCanvas.enabled = false;
    }

    private void OnEnable()
    {
        GameManager.OnScoreChanged += UpdateScore;
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
        GameManager.OnScoreChanged -= UpdateScore;
        GameManager.OnSpeedBonusChanged -= UpdateSpeedBonus;
        GameManager.OnRunnerSpawned -= AssignDialogueBox;
        GameManager.OnStageEnd -= EndStage;
        GameManager.OnStateChanged -= BeginStage;
        GameManager.OnStarGained -= GainStar;
        DialogueManager.OnNextSentence -= UpdateDialogueBox;
        DialogueManager.OnDialogueEnd -= HideDialogueBox;
    }

    private void UpdateScore(int score)
    {
        _scoreText.text = "Score: " + score.ToString();
    }

    private void UpdateSpeedBonus(int value)
    {
        _activeSlider.value = value % (GameManager.Instance.Parameters[GameManager.CurrentStage].TotalStars * 100);
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
        _stageTotalStarAmount.text = GameManager.AcquiredStars.ToString();
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

    private void ResetSliders()
    {
        foreach (Slider slider in _speedSliders)
        {
            slider.maxValue = GameManager.Instance.Parameters[GameManager.CurrentStage].TotalStars * 100;
            slider.value = 0;
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
