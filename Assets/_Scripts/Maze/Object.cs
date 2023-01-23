using UnityEngine;

public abstract class Object : MonoBehaviour
{
    private Renderer _renderer;

    private void Awake()
    {
        _renderer = GetComponent<Renderer>();
    }

    protected void EnableRenderer()
    {
        if (!_renderer.enabled) { _renderer.enabled = true; }
    }

    protected void DisableRenderer()
    {
        if (_renderer.enabled) { _renderer.enabled = false; }
    }
}
