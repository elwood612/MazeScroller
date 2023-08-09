using UnityEngine;

public class AudioManager : MonoBehaviour
{
    [SerializeField]
    private float
        _beepVol,
        _zapVol,
        _negativeVol,
        _starGainVol,
        _UIClickVol,
        _UIZapVol,
        _UIstarVol,
        _UIlevelDoneVol,
        _musicVol,
        _powerUpVol;

    public AudioSource Beep;
    public AudioSource Zap;
    public AudioSource Negative;
    public AudioSource StarGain;
    public AudioSource UIClick;
    public AudioSource UIZap;
    public AudioSource UIStar;
    public AudioSource UILevelDone;
    public AudioSource Music;
    public AudioSource PowerUp;

    public AudioSource[] CrystalPop;

    public static AudioManager Instance;

    private void Awake()
    {
        if (Instance == null) { Instance = this; }
        else { Destroy(this); }

        MuteAudio(GameManager.IsAudioEnabled);
        MuteMusic(GameManager.IsMusicEnabled);
    }

    public void MuteAudio(bool enabled)
    {
        Beep.volume = enabled ? _beepVol : 0;
        Zap.volume = enabled ? _zapVol : 0;
        Negative.volume = enabled ? _negativeVol : 0;
        StarGain.volume = enabled ? _starGainVol : 0;
        UIClick.volume = enabled ? _UIClickVol : 0;
        UIZap.volume = enabled ? _UIZapVol : 0;
        UIStar.volume = enabled ? _UIstarVol : 0;
        UILevelDone.volume = enabled ? _UIlevelDoneVol : 0;
        PowerUp.volume = enabled ? _powerUpVol : 0;
        foreach (AudioSource source in CrystalPop)
        {
            source.volume = enabled ? _beepVol : 0;
        }
    }

    public void MuteMusic(bool enabled)
    {
        Music.volume = enabled ? _musicVol : 0;
    }
}
