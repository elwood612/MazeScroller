using UnityEngine;
using System.IO;

public class SaveData : MonoBehaviour
{
    public static SaveData Instance;

    public int SavedLifetimeStars;
    public int SavedSpecialDialogueCounter;
    public int SavedEarlyDialogueCounter;
    public int SavedMidDialogueCounter;
    public int SavedLateDialogueCounter;
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
        Instance.SavedLifetimeStars = GameManager.LifetimeStars;
        Instance.SavedSpecialDialogueCounter = GameManager.SpecialDialogueCounter;
        Instance.SavedEarlyDialogueCounter = GameManager.EarlyDialogueCounter;
        Instance.SavedMidDialogueCounter = GameManager.MidDialogueCounter;
        Instance.SavedLateDialogueCounter = GameManager.LateDialogueCounter;
        Instance.SavedIsAudioEnabled = GameManager.IsAudioEnabled;
        Instance.SavedIsMusicEnabled = GameManager.IsMusicEnabled;
        Instance.SavedNeedDialogueBoxHint = GameManager.NeedDialogueBoxHint;
        Instance.SavedDoTutorial = GameManager.DoTutorial;

        File.WriteAllText(Application.persistentDataPath + SaveFilename, JsonUtility.ToJson(Instance));
    }

    public static void LoadPlayerSettings()
    {
        if (!File.Exists(Application.persistentDataPath + SaveFilename)) { return; }
        JsonUtility.FromJsonOverwrite(File.ReadAllText(Application.persistentDataPath + SaveFilename), Instance);

        GameManager.LifetimeStars = Instance.SavedLifetimeStars;
        GameManager.SpecialDialogueCounter = Instance.SavedSpecialDialogueCounter;
        GameManager.EarlyDialogueCounter = Instance.SavedEarlyDialogueCounter;
        GameManager.MidDialogueCounter = Instance.SavedMidDialogueCounter;
        GameManager.LateDialogueCounter = Instance.SavedLateDialogueCounter;
        GameManager.IsAudioEnabled = Instance.SavedIsAudioEnabled;
        GameManager.IsMusicEnabled = Instance.SavedIsMusicEnabled;
        GameManager.NeedDialogueBoxHint = Instance.SavedNeedDialogueBoxHint;
        GameManager.DoTutorial = Instance.SavedDoTutorial;
    }

    public static void ClearAllSettings()
    {
        if (!File.Exists(Application.persistentDataPath + SaveFilename)) { return; }
        File.Delete(Application.persistentDataPath + SaveFilename);
    }
}
