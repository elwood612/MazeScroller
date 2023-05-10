using UnityEngine;

[CreateAssetMenu(fileName = "StageDialogue", menuName = "Scriptable Objects/Stage Dialogue")]
public class StageDialogue : ScriptableObject
{
    [TextArea]
    [SerializeField] private string _query;
    [TextArea]
    [SerializeField] private string[] _comments;
    [TextArea(15, 20)]
    [SerializeField] private string _answer;
    [TextArea(15, 20)]
    [SerializeField] private string _compassionateAnswer;
    public string Query => _query;
    public string[] Comments => _comments;
    public string Answer => _answer;
    public string CompassionateAnswer => _compassionateAnswer;
}
