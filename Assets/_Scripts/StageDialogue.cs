using UnityEngine;

[CreateAssetMenu(fileName = "StageDialogue", menuName = "Scriptable Objects/Stage Dialogue")]
public class StageDialogue : ScriptableObject
{
    [SerializeField] private int _minimumStars;
    [SerializeField] private bool _exact;
    public int MinimumStars => _minimumStars;
    public bool Exact => _exact;


    [TextArea]
    [SerializeField] private string _query;
    [TextArea]
    [SerializeField] private string[] _comments;
    [TextArea(15, 20)]
    [SerializeField] private string _answer;
    public string Query => _query;
    public string[] Comments => _comments;
    public string Answer => _answer;
}
