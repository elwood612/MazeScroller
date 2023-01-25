using System;
using UnityEngine;

public class Row : MonoBehaviour
{
    public event Action OnRowReset;

    private void Update()
    {
        transform.Translate(GameManager.TileSpeed * Time.deltaTime);
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("BottomOfBoard")) { SendBackToTop(); }
    }

    private void SendBackToTop()
    {
        transform.position += GameManager.BoardLength;
        OnRowReset?.Invoke();
    }
}
