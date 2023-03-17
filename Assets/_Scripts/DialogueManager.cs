using System;
using System.Collections.Generic;
using UnityEngine;

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
        GameManager.OnDialogueStart += StartDialogue;
    }

    private void OnDisable()
    {
        GameManager.OnDialogueStart -= StartDialogue;
    }

    private void StartDialogue(Dialogue dialogue)
    {
        _isDialogueActive = true;
        OnDialogueOpen?.Invoke(true);
        _currentDialogue.Clear();
        foreach (string sentence in dialogue.Lines)
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
        if (GameManager.DoTutorial && _tutorialDialogueIndex == 5) { GameManager.DoTutorial = false; }
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
        StartDialogue(_tutorialDialogue[index]);
    }
}
