using UnityEngine;

public class Wall : MonoBehaviour
{
    private Renderer _renderer;

    private void Start()
    {
        _renderer = GetComponentInChildren<Renderer>();
    }

    public void EnableRenderer()
    {
        _renderer.enabled = true;
    }

    public void DisableRenderer()
    {
        _renderer.enabled = false;
    }
}
