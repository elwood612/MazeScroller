using UnityEngine;

public class AudioManager : MonoBehaviour
{
    [SerializeField]
    private float
        _beepVol,
        _zapVol,
        _negativeVol,
        _UIClickVol,
        _UIZapVol,
        _musicVol;

    public AudioSource Beep;
    public AudioSource Zap;
    public AudioSource Negative;
    public AudioSource UIClick;
    public AudioSource UIZap;
    public AudioSource Music;

    public static AudioManager Instance;

    private void Awake()
    {
        if (Instance == null) { Instance = this; }
        else { Destroy(this); }
    }

    public void MuteAudio(bool mute)
    {
        Beep.volume = mute ? 0 : _beepVol;
        Zap.volume = mute ? 0 : _zapVol;
        Negative.volume = mute ? 0 : _negativeVol;
        UIClick.volume = mute ? 0 : _UIClickVol;
        UIZap.volume = mute ? 0 : _UIZapVol;
    }

    public void MuteMusic(bool mute)
    {
        Music.volume = mute ? 0 : _musicVol;
    }
}
