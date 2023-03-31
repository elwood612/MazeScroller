using System;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;

public class DialogueManager : MonoBehaviour
{
    [SerializeField] private Dialogue[] _tutorialDialogue;

    private Queue<string> _currentDialogue = new Queue<string>();
    private bool _isDialogueActive = false;
    private int _tutorialDialogueIndex = 0;
    private Animator _runnerDialogueAnimator;

    public static DialogueManager Instance;
    public static event Action<string> OnNextSentence;
    public static event Action OnDialogueEnd;
    public static event Action<bool> OnDialogueOpen;
    public bool IsDialogueActive => _isDialogueActive;

    private void Awake()
    {
        if (Instance == null) { Instance = this; }
        else { Destroy(this); }
    }

    private void OnEnable()
    {
        GameManager.OnNextDialogue += ParseDialogue;
    }

    private void OnDisable()
    {
        GameManager.OnNextDialogue -= ParseDialogue;
    }

    private void ParseDialogue(Dialogue dialogue)
    {
        StartDialogue(dialogue.Lines);
    }

    private void StartDialogue(string[] sentences, bool query = false)
    {
        if (!query) { _isDialogueActive = true; }
        OnDialogueOpen?.Invoke(true);
        _currentDialogue.Clear();
        foreach (string sentence in sentences)
        {
            _currentDialogue.Enqueue(sentence);
        }
        NextSentence();
    }

    private void EndDialogue()
    {
        _isDialogueActive = false;
        OnDialogueOpen?.Invoke(false);
        if (GameManager.CurrentState == GameState.Transition) { GameManager.Instance.UpdateGameState(GameState.Progressing); }
        //if (GameManager.DoTutorial && _tutorialDialogueIndex == 5) { GameManager.DoTutorial = false; }
        OnDialogueEnd?.Invoke();
    }

    public void NextSentence()
    {
        if (_currentDialogue.Count == 0)
        {
            EndDialogue();
            return;
        }
        OnNextSentence?.Invoke(_currentDialogue.Dequeue());
    }

    public void NextTutorialDialogue(int index)
    {
        _tutorialDialogueIndex = index;
        StartDialogue(_tutorialDialogue[index].Lines);
    }

    public void NextQuery(StageDialogue stageDialogue)
    {
        if (stageDialogue == null) { EndDialogue(); return; }
        string query = "<incoming query>\n" + stageDialogue.Query;
        string[] sentences = { query };
        StartDialogue(sentences, true);
    }

    public void NextComment(StageDialogue stageDialogue)
    {
        if (stageDialogue == null) { EndDialogue(); return; }
        StartDialogue(stageDialogue.Comments);
    }

    //public void NextAnswer(StageDialogue stageDialogue)
    //{
    //    if (stageDialogue == null) { EndDialogue(); return; }
    //    StartDialogue(stageDialogue.Answer);
    //}

    public string GetRandomWord(StageDialogue stageDialogue)
    {
        string[] words = stageDialogue.Answer.Split(' ');
        return words[Random.Range(0, words.Length)];
    }
}
