using UnityEngine;

[CreateAssetMenu(fileName = "Dialogue", menuName = "Scriptable Objects/Dialogue")]
public class Dialogue : ScriptableObject
{
    [TextArea]
    [SerializeField] private string[] _lines;
    public string[] Lines => _lines;
}
