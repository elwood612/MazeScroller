using UnityEngine;
using UnityEngine.UI;

public class ButtonToggle : MonoBehaviour
{
    private enum ButtonType
    {
        AudioFX,
        Music,
        Haptic,
        Tutorials
    }
    [SerializeField] private ButtonType _buttonType;
    [SerializeField] private Image _enabledImage;
    [SerializeField] private Image _disabledImage;

    private bool _isEnabled = true;

    private void Awake()
    {
        // Syncing the toggle with PlayerPrefs
        switch (_buttonType)
        {
            case ButtonType.AudioFX:
                _isEnabled = GameManager.IsAudioEnabled;
                break;
            case ButtonType.Music:
                _isEnabled = GameManager.IsMusicEnabled;
                break;
            case ButtonType.Haptic:
                _isEnabled = GameManager.IsHapticEnabled;
                break;
            case ButtonType.Tutorials:
                _isEnabled = GameManager.IsTutorialsEnabled;
                break;
        }

        UpdateImage();
    }

    private void OnEnable()
    {
        GameManager.OnDisableTutorials += UpdateTutorialToggle;
    }

    private void OnDisable()
    {
        GameManager.OnDisableTutorials -= UpdateTutorialToggle;
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

    private void UpdateTutorialToggle()
    {
        if (_buttonType != ButtonType.Tutorials) { return; }
        _isEnabled = GameManager.IsTutorialsEnabled;
        UpdateImage();
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

    public void OnTutorialsToggle()
    {
        Toggle();
        UpdateImage();
        GameManager.IsTutorialsEnabled = _isEnabled;
        //GameManager.DoTutorial[6] = _isEnabled;
    }
}
