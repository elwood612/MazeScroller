using System;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;

public class DialogueManager : MonoBehaviour
{
    //[SerializeField] private Dialogue[] _tutorialDialogue;

    private Queue<string> _currentDialogue = new Queue<string>();
    private string _currentAnswer;
    private bool _isDialogueActive = false;
    private bool _isTutorialDialogueActive = false;
    private bool _isQuery = false;
    private int _tutorialDialogueIndex = 0;
    private Animator _runnerDialogueAnimator;

    public static DialogueManager Instance;
    public static event Action<string> OnNextSentence;
    public static event Action<string> OnNextAnswer;
    public static event Action OnDialogueEnd;
    public static event Action<bool> OnDialogueOpen;
    public bool IsDialogueActive => _isDialogueActive;
    public bool IsTutorialDialogueActive => _isTutorialDialogueActive;

    private void Awake()
    {
        if (Instance == null) { Instance = this; }
        else { Destroy(this); }
    }

    private void OnEnable()
    {
        GameManager.OnNextTutorial += NextTutorialDialogue;
    }

    private void OnDisable()
    {
        GameManager.OnNextTutorial -= NextTutorialDialogue;
    }

    private void StartDialogue(string[] sentences)
    {
        if (!_isQuery) { _isDialogueActive = true; }
        OnDialogueOpen?.Invoke(true);
        _currentDialogue.Clear();
        foreach (string sentence in sentences)
        {
            _currentDialogue.Enqueue(sentence);
        }
        NextSentence();
    }

    public void EndDialogue()
    {
        _isDialogueActive = false;
        _isTutorialDialogueActive = false;
        OnDialogueOpen?.Invoke(false);
        OnDialogueEnd?.Invoke();
        if (GameManager.CurrentState == GameState.Transition)
        { 
            if (GameManager.IsGameOver)
            {
                GameManager.Instance.GameOver();
                return;
            }
            if (_isQuery)
            {
                GameManager.Instance.UpdateGameState(GameState.Progressing);
                _isQuery = false;
            }
        }
        
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
        if (GameManager.DoTutorial[index]) 
        {
            _isTutorialDialogueActive = true;
            StartDialogue(GameManager.Instance.AllTutorialDialogue[index].Lines);
            GameManager.DoTutorial[index] = false;
        }
    }

    public void NextQuery(StageDialogue stageDialogue)
    {
        if (stageDialogue == null) { EndDialogue(); return; }
        string query = "<receiving incoming query>\n" + stageDialogue.Query;
        string[] sentences = { query };
        _isQuery = true;
        StartDialogue(sentences);
    }

    public void NextComment(StageDialogue stageDialogue)
    {
        if (stageDialogue == null) { EndDialogue(); return; }
        StartDialogue(stageDialogue.Comments);
    }

    public void NextAnswer(StageDialogue stageDialogue)
    {
        if (stageDialogue == null) { EndDialogue(); return; }
        string intro = "";
        string answer = 
            stageDialogue.Query +
            ":" + "\n" + "\"" +
            stageDialogue.Answer
            + "\"";
        if (GameManager.StageAnswer == Answer.Poor)
        {
            intro = "Don't worry, I'll make something up.\n\n";
        }
        else if (GameManager.StageAnswer == Answer.Acceptable)
        {
            intro = "Got your answer.\n\n";
        }
        else if (GameManager.StageAnswer == Answer.Excellent)
        {
            intro = "Oh we nailed this one!\n\n";
        }
        string[] sentences = { intro };
        StartDialogue(sentences);
        OnNextAnswer?.Invoke(answer);
    }

    public string GetRandomWord(StageDialogue stageDialogue)
    {
        string[] words = stageDialogue.Answer.Split(' ');
        List<string> parsedWords = new List<string>();
        foreach (string word in words)
        {
            if (word.Length > 3) { parsedWords.Add(word); }
        }
        return parsedWords.Count > 0 ? parsedWords[Random.Range(0, parsedWords.Count)] : "";
    }
}
