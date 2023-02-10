using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class UIManager : MonoBehaviour
{
    [SerializeField] private Slider _slider;
    [SerializeField] private TextMeshProUGUI _scoreText;
    [SerializeField] private TextMeshProUGUI _livesText;

    private void Awake()
    {
        UpdateInstability(GameManager.Progress);
        _slider.maxValue = GameManager.MaxProgress;
        UpdateScore(0);
        UpdateLives(GameManager.Lives);
    }

    private void OnEnable()
    {
        GameManager.OnProgressChanged += UpdateInstability;
        GameManager.OnScoreChanged += UpdateScore;
        GameManager.OnLivesChanged += UpdateLives;
    }

    private void OnDisable()
    {
        GameManager.OnProgressChanged -= UpdateInstability;
        GameManager.OnScoreChanged -= UpdateScore;
        GameManager.OnLivesChanged -= UpdateLives;
    }

    private void UpdateInstability(int amount)
    {
        _slider.value = amount;
    }

    private void UpdateScore(int score)
    {
        _scoreText.text = "Score: " + score.ToString(); // can add "D2" for 2 leading digits
        // Need to add flash effect
    }

    private void UpdateLives(int lives)
    {
        _livesText.text = "Lives: " + lives.ToString();
    }
}
