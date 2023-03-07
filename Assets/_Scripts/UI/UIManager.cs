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
    [SerializeField] private Slider _speedSlider;
    [SerializeField] private GameObject _starParent;
    [SerializeField] private GameObject _stageStarParent;
    [SerializeField] private Slider _tileSlider;
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
    private List<GameObject> _allStars = new List<GameObject>();

    private void Awake()
    {
        UpdateScore(0);
        _tileSlider.value = GameManager.TileBonus;
        _speedSlider.value = GameManager.SpeedBonus;
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
        GameManager.OnTileBonusChanged += UpdateTileBonus;
        GameManager.OnLoseCounterChanged += Losing;
        GameManager.OnRunnerSpawned += AssignDialogueBox;
        GameManager.OnStageEnd += EndStage;
        GameManager.OnStateChanged += BeginStage;
        GameManager.OnStarLost += LoseStar;
        DialogueManager.OnNextSentence += UpdateDialogueBox;
        DialogueManager.OnDialogueEnd += HideDialogueBox;
    }

    private void OnDisable()
    {
        GameManager.OnScoreChanged -= UpdateScore;
        GameManager.OnSpeedBonusChanged -= UpdateSpeedBonus;
        GameManager.OnTileBonusChanged -= UpdateTileBonus;
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

    private void UpdateTileBonus(int value)
    {
        _tileSlider.value = value;
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
            ResetStars();
        }
    }

    private void EndStage()
    {
        _topCanvas.enabled = false;
        _stageCanvas.enabled = true;

        _stageScore.text = "Score: " + (GameManager.Score + GameManager.Stars * 1000); // This is what we need but needs to be fixed

        // Start Coroutine for stars
    }

    private void LoseStar(int star)
    {
        _starParent.transform.GetChild(star).GetChild(0).gameObject.SetActive(false);
        _stageStarParent.transform.GetChild(star).GetChild(0).gameObject.SetActive(false);
    }

    private void ResetStars()
    {
        foreach (var star in _allStars)
        {
            Destroy(star.gameObject); // ok yes this needs to be better
        }
        _allStars.Clear();
        for (int i = 0; i < GameManager.Instance.Parameters[GameManager.CurrentStage].Stars; i++)
        {
            GameObject newStar = Instantiate(_starPrefab, _starParent.transform);
            GameObject newStageStar = Instantiate(_starPrefab, _stageStarParent.transform);
            _allStars.Add(newStar);
            _allStars.Add(newStageStar);
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
