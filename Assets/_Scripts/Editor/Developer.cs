using UnityEngine;
using UnityEditor;

public class Developer
{
#if UNITY_EDITOR
    [MenuItem("Developer/Clear Saves")]
    public static void ClearSaves()
    {
        PlayerPrefs.DeleteAll();
        Debug.Log("All saves cleared");
    }
#endif
}