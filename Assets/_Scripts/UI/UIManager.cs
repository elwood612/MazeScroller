using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class UIManager : MonoBehaviour
{
    [SerializeField] private TextMeshProUGUI _scoreText;
    [SerializeField] private Slider _speedSlider;
    [SerializeField] private Slider _tileSlider;

    private void Awake()
    {
        UpdateScore(0);
        _tileSlider.value = 20;
        _speedSlider.value = 20;
    }

    private void OnEnable()
    {
        GameManager.OnScoreChanged += UpdateScore;
        GameManager.OnSpeedBonusChanged += UpdateSpeedBonus;
        GameManager.OnTileBonusChanged += UpdateTileBonus;
    }

    private void OnDisable()
    {
        GameManager.OnScoreChanged -= UpdateScore;
        GameManager.OnSpeedBonusChanged -= UpdateSpeedBonus;
        GameManager.OnTileBonusChanged -= UpdateTileBonus;
    }

    private void UpdateScore(int score)
    {
        _scoreText.text = "Score: " + score.ToString(); // can add "D2" for 2 leading digits
        // Need to add flash effect
    }

    private void UpdateSpeedBonus(int amount)
    {
        _speedSlider.value = amount;
    }

    private void UpdateTileBonus(int amount)
    {
        _tileSlider.value = amount;
    }

    public void Settings()
    {
        //_audioSource.PlayOneShot(_audioSource.clip);
    }
}
