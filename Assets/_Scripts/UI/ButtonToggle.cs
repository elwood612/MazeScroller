using UnityEngine;
using UnityEngine.UI;

public class ButtonToggle : MonoBehaviour
{
    [SerializeField] private Image _enabledImage;
    [SerializeField] private Image _disabledImage;

    private bool _isEnabled = true;

    private void Awake()
    {
        // Need to load from save file here
        // if (gameObject.name == "AudioFX") { _isEnabled = GameManager.EnableAudio; } // or something similar
    }

    public void OnButtonClick()
    {
        _isEnabled = _isEnabled? false : true;

        _enabledImage.enabled = _isEnabled;
        _disabledImage.enabled = !_isEnabled;
    }
}
