using System;
using System.Collections.Generic;
using UnityEngine;

public class DialogueManager : MonoBehaviour
{
    private Queue<string> _currentDialogue = new Queue<string>();

    public static event Action<string> OnNextSentence;

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
        _currentDialogue.Clear();
        foreach (string sentence in dialogue.Lines)
        {
            _currentDialogue.Enqueue(sentence);
        }

        NextSentence();
    }

    private void EndDialogue()
    {
        Debug.Log("Here is where we start new stage.");
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
