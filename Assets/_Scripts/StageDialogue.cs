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
    [SerializeField] private string[] _comment;
    [TextArea]
    [SerializeField] private string[] _answer;
    public string Query => _query;
    public string[] Comment => _comment;
    public string[] Answer => _answer;

    //[SerializeField] private Dialogue _query;
    //[SerializeField] private Dialogue _comment;
    //[SerializeField] private Dialogue _answer;
    //public Dialogue Query => _query;
    //public Dialogue Comment => _comment;
    //public Dialogue Answer => _answer;
    
}
