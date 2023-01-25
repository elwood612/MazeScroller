using UnityEngine;

public class Wall : MonoBehaviour
{
    private Renderer _renderer;
    private bool _mazeBorder, _mazePath;

    public bool MazeBorder => _mazeBorder;
    public bool MazePath => _mazePath;

    private void Awake()
    {
        _renderer = GetComponentInChildren<Renderer>();
    }

    private void Start()
    {
        DeactivateWall();
    }

    public void WallIsBorder()
    {
        _renderer.enabled = true;
        _mazeBorder = true;
        _mazePath = false;
    }

    public void WallIsPath()
    {
        _renderer.enabled = false;
        _mazeBorder = false;
        _mazePath = true;
    }

    public void DeactivateWall()
    {
        _renderer.enabled = false;
        _mazeBorder = false;
        _mazePath = false;
    }
}
