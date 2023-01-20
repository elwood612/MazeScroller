using UnityEngine;
using UnityEditor;

public class Developer
{
    [MenuItem("Developer/Clear Saves")]
    public static void ClearSaves()
    {
        PlayerPrefs.DeleteAll();
        Debug.Log("All saves cleared");
    }
}
