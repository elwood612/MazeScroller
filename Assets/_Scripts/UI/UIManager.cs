using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;
using Unity.VisualScripting.YamlDotNet.Core.Tokens;

public class UIManager : MonoBehaviour
{
    [SerializeField] private TextMeshProUGUI _scoreText;
    [SerializeField] private Slider _speedSlider;
    [SerializeField] private Slider _tileSlider;
    [SerializeField] private Slider _loseSlider;
    [SerializeField] private Image _redGlow;

    private WaitForSecondsRealtime _delay = new WaitForSecondsRealtime(0.25f);
    private bool _flashing = true;
    private bool _flashRunning = false;

    private void Awake()
    {
        UpdateScore(0);
        _tileSlider.value = GameManager.TileBonus;
        _speedSlider.value = GameManager.SpeedBonus;
        _loseSlider.value = 0;
        _loseSlider.gameObject.SetActive(false);
        _redGlow.enabled = false;
    }

    private void OnEnable()
    {
        GameManager.OnScoreChanged += UpdateScore;
        GameManager.OnSpeedBonusChanged += UpdateSpeedBonus;
        GameManager.OnTileBonusChanged += UpdateTileBonus;
        GameManager.OnLoseCounterChanged += Losing;
    }

    private void OnDisable()
    {
        GameManager.OnScoreChanged -= UpdateScore;
        GameManager.OnSpeedBonusChanged -= UpdateSpeedBonus;
        GameManager.OnTileBonusChanged -= UpdateTileBonus;
        GameManager.OnLoseCounterChanged -= Losing;
    }

    private void UpdateScore(int score)
    {
        _scoreText.text = "Score: " + score.ToString();
        // Need to add flash effect
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

    public void Settings()
    {
        // Open pause menu
    }
}
