using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class UIManager : MonoBehaviour
{
    [SerializeField] private Slider _slider;
    [SerializeField] private TextMeshProUGUI _scoreText;
    [SerializeField] private TextMeshProUGUI _tempStageText;

    private void Awake()
    {
        UpdateInstability(GameManager.Progress);
        _slider.maxValue = GameManager.MaxProgress;
        UpdateScore(0);
        UpdateStage(GameManager.Stage);
    }

    private void OnEnable()
    {
        GameManager.OnProgressChanged += UpdateInstability;
        GameManager.OnScoreChanged += UpdateScore;
        GameManager.OnStageChanged += UpdateStage;
    }

    private void OnDisable()
    {
        GameManager.OnProgressChanged -= UpdateInstability;
        GameManager.OnScoreChanged -= UpdateScore;
        GameManager.OnStageChanged -= UpdateStage;
    }

    private void UpdateInstability(int amount)
    {
        _slider.value = amount;
    }

    private void UpdateScore(int score)
    {
        _scoreText.text = score.ToString(); // can add "D2" for 2 leading digits
        // Need to add flash effect
    }

    private void UpdateStage(int stage)
    {
        _tempStageText.text = "Stage " + stage.ToString();
    }
}
