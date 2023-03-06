using System;
using System.Collections.Generic;
using UnityEngine;

public class DialogueManager : MonoBehaviour
{
    private Queue<string> _currentDialogue = new Queue<string>();
    private bool _isDialogueActive = false;

    public static DialogueManager Instance;
    public static event Action<string> OnNextSentence;
    public static event Action OnDialogueEnd;
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
        if (GameManager.CurrentState == GameState.Transition) { GameManager.Instance.UpdateGameState(GameState.Progressing); }
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
}
