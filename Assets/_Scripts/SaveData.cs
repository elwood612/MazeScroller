using UnityEngine;
using System.IO;

public class SaveData : MonoBehaviour
{
    public static SaveData Instance;

    public int SavedLifetimeStars;
    public int SavedSpecialDialogueCounter;
    public bool SavedDoTutorialOld;
    public bool SavedIsAudioEnabled;
    public bool SavedIsMusicEnabled;
    public bool SavedNeedDialogueBoxHint;

    public bool[] SavedDoTutorial;

    public static string SaveFilename = "/playerSave.json";

    private void Awake()
    {
        if (Instance == null) { Instance = this; }
        else { Destroy(this); }
    }

    public static void SavePlayerSettings()
    {
        Instance.SavedDoTutorial = GameManager.DoTutorial;
        Instance.SavedLifetimeStars = GameManager.LifetimeStars;
        Instance.SavedSpecialDialogueCounter = GameManager.SpecialDialogueCounter;
        Instance.SavedIsAudioEnabled = GameManager.IsAudioEnabled;
        Instance.SavedIsMusicEnabled = GameManager.IsMusicEnabled;
        Instance.SavedNeedDialogueBoxHint = GameManager.NeedDialogueBoxHint;

        File.WriteAllText(Application.persistentDataPath + SaveFilename, JsonUtility.ToJson(Instance));
    }

    public static void LoadPlayerSettings()
    {
        if (!File.Exists(Application.persistentDataPath + SaveFilename)) { return; }
        JsonUtility.FromJsonOverwrite(File.ReadAllText(Application.persistentDataPath + SaveFilename), Instance);

        GameManager.DoTutorial = Instance.SavedDoTutorial;
        GameManager.LifetimeStars = Instance.SavedLifetimeStars;
        GameManager.SpecialDialogueCounter = Instance.SavedSpecialDialogueCounter;
        GameManager.IsAudioEnabled = Instance.SavedIsAudioEnabled;
        GameManager.IsMusicEnabled = Instance.SavedIsMusicEnabled;
        GameManager.NeedDialogueBoxHint = Instance.SavedNeedDialogueBoxHint;
    }

    public static void ClearAllSettings()
    {
        if (!File.Exists(Application.persistentDataPath + SaveFilename)) { return; }
        File.Delete(Application.persistentDataPath + SaveFilename);
    }
}
