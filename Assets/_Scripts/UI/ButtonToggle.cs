using UnityEngine;
using UnityEngine.UI;

public class ButtonToggle : MonoBehaviour
{
    private enum ButtonType
    {
        AudioFX,
        Music,
        Haptic
    }
    [SerializeField] private ButtonType _buttonType;
    [SerializeField] private Image _enabledImage;
    [SerializeField] private Image _disabledImage;

    private bool _isEnabled = true;

    private void Awake()
    {
        // Syncing the toggle with PlayerPrefs
        if (_buttonType == ButtonType.AudioFX) 
        { 
            _isEnabled = GameManager.IsAudioEnabled;
        }
        else if (_buttonType == ButtonType.Music)
        {
            _isEnabled = GameManager.IsMusicEnabled;
        }
        else if (_buttonType == ButtonType.Haptic)
        {
            _isEnabled = GameManager.IsHapticEnabled;
        }

        UpdateImage();
    }

    private void Toggle()
    {
        _isEnabled = _isEnabled? false : true;
    }

    private void UpdateImage()
    {
        _enabledImage.enabled = _isEnabled;
        _disabledImage.enabled = !_isEnabled;
    }

    public void OnAudioMute()
    {
        Toggle();
        UpdateImage();
        AudioManager.Instance.MuteAudio(_isEnabled);
        GameManager.IsAudioEnabled = _isEnabled;
    }

    public void OnMusicMute()
    {
        Toggle();
        UpdateImage();
        AudioManager.Instance.MuteMusic(_isEnabled);
        GameManager.IsMusicEnabled = _isEnabled;
    }

    public void OnHapticDisable()
    {
        Toggle();
        UpdateImage();
        GameManager.IsHapticEnabled = _isEnabled;
    }
}
