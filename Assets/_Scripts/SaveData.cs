using UnityEngine;
using System.IO;

public class SaveData : MonoBehaviour
{
    public static SaveData Instance;

    public int SavedCurrentScore;
    public int SavedHighScore;
    public int SavedGlobalDialogueCounter;
    //public int SavedSpecialDialogueCounter;
    //public int SavedEarlyDialogueCounter;
    //public int SavedMidDialogueCounter;
    //public int SavedLateDialogueCounter;
    public bool SavedIsAudioEnabled;
    public bool SavedIsMusicEnabled;
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
        //Instance.SavedSpecialDialogueCounter = GameManager.SpecialDialogueCounter;
        //Instance.SavedEarlyDialogueCounter = GameManager.EarlyDialogueCounter;
        //Instance.SavedMidDialogueCounter = GameManager.MidDialogueCounter;
        //Instance.SavedLateDialogueCounter = GameManager.LateDialogueCounter;
        Instance.SavedIsAudioEnabled = GameManager.IsAudioEnabled;
        Instance.SavedIsMusicEnabled = GameManager.IsMusicEnabled;
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
        //GameManager.SpecialDialogueCounter = Instance.SavedSpecialDialogueCounter;
        //GameManager.EarlyDialogueCounter = Instance.SavedEarlyDialogueCounter;
        //GameManager.MidDialogueCounter = Instance.SavedMidDialogueCounter;
        //GameManager.LateDialogueCounter = Instance.SavedLateDialogueCounter;
        GameManager.IsAudioEnabled = Instance.SavedIsAudioEnabled;
        GameManager.IsMusicEnabled = Instance.SavedIsMusicEnabled;
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
