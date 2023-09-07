using UnityEngine;
using System.IO;

public class SaveData : MonoBehaviour
{
    public static SaveData Instance;

    public int SavedCurrentScore;
    public int SavedHighScore;
    public int SavedGlobalDialogueCounter;
    public bool SavedIsAudioEnabled;
    public bool SavedIsMusicEnabled;
    public bool SavedIsHapticEnabled;
    public bool SavedNeedDialogueBoxHint;
    public bool SavedGameUnderway;

    public bool[] SavedDoTutorial;

    public static string SaveFilename = "/playerSave.json";

    private void Awake()
    {
        if (Instance == null) { Instance = this; }
        else { Destroy(this); }
    }

    public static void SavePlayerSettings()
    {
        Instance.SavedCurrentScore = GameManager.CurrentScore;
        Instance.SavedHighScore = GameManager.HighScore;
        Instance.SavedGlobalDialogueCounter = GameManager.GlobalDialogueCounter;
        Instance.SavedIsAudioEnabled = GameManager.IsAudioEnabled;
        Instance.SavedIsMusicEnabled = GameManager.IsMusicEnabled;
        Instance.SavedIsHapticEnabled = GameManager.IsHapticEnabled;
        Instance.SavedNeedDialogueBoxHint = GameManager.NeedDialogueBoxHint;
        Instance.SavedDoTutorial = GameManager.DoTutorial;
        Instance.SavedGameUnderway = GameManager.GameUnderway;

        File.WriteAllText(Application.persistentDataPath + SaveFilename, JsonUtility.ToJson(Instance));
    }

    public static void LoadPlayerSettings()
    {
        if (!File.Exists(Application.persistentDataPath + SaveFilename)) { return; }
        JsonUtility.FromJsonOverwrite(File.ReadAllText(Application.persistentDataPath + SaveFilename), Instance);

        GameManager.CurrentScore = Instance.SavedCurrentScore;
        GameManager.HighScore = Instance.SavedHighScore;
        GameManager.GlobalDialogueCounter = Instance.SavedGlobalDialogueCounter;
        GameManager.IsAudioEnabled = Instance.SavedIsAudioEnabled;
        GameManager.IsMusicEnabled = Instance.SavedIsMusicEnabled;
        GameManager.IsHapticEnabled = Instance.SavedIsHapticEnabled;
        GameManager.NeedDialogueBoxHint = Instance.SavedNeedDialogueBoxHint;
        GameManager.DoTutorial = Instance.SavedDoTutorial;
        GameManager.GameUnderway = Instance.SavedGameUnderway;
    }

    public static void ClearAllSettings()
    {
        if (!File.Exists(Application.persistentDataPath + SaveFilename)) { return; }
        File.Delete(Application.persistentDataPath + SaveFilename);
    }
}
