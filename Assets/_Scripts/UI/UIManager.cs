using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class UIManager : MonoBehaviour
{
    [SerializeField] private Slider _slider;
    [SerializeField] private TextMeshProUGUI _scoreText;

    private void Awake()
    {
        UpdateInstability(GameManager.Instability);
        _slider.maxValue = GameManager.MaxInstability;
        UpdateScore(0);
    }

    private void OnEnable()
    {
        GameManager.OnInstabilityChanged += UpdateInstability;
        GameManager.OnScoreChanged += UpdateScore;
    }

    private void OnDisable()
    {
        GameManager.OnInstabilityChanged -= UpdateInstability;
        GameManager.OnScoreChanged -= UpdateScore;
    }

    private void UpdateInstability(int amount)
    {
        _slider.value = amount;
    }

    private void UpdateScore(int score)
    {
        _scoreText.text = score.ToString(); // add "D2" for 2 leading digits
    }
}
