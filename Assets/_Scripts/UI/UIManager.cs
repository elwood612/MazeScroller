using UnityEngine;
using UnityEngine.UI;

public class UIManager : MonoBehaviour
{
    [SerializeField] private Slider _slider;

    private void Awake()
    {
        UpdateInstability(GameManager.Instability);
        _slider.maxValue = GameManager.MaxInstability;
    }

    private void OnEnable()
    {
        GameManager.OnInstabilityChanged += UpdateInstability;
    }

    private void OnDisable()
    {
        GameManager.OnInstabilityChanged -= UpdateInstability;
    }

    private void UpdateInstability(int amount)
    {
        _slider.value = amount;
    }
}
