using UnityEngine;

public class Wall : MonoBehaviour
{
    [SerializeField] LayerMask _tileLayer;
    private Renderer[] _renderers;
    private bool _mazeBorder, _mazePath, _isDestroyed = false;

    public bool MazeBorder => _mazeBorder;
    public bool MazePath => _mazePath;
    public bool IsDestroyed => _isDestroyed;

    private void Awake()
    {
        _renderers = GetComponentsInChildren<Renderer>();
    }

    private void Start()
    {
        HideWall();
        TryDestroyWall();
    }

    public void WallIsBorder()
    {
        _renderers[0].enabled = true;
        _mazeBorder = true;
        _mazePath = false;
    }

    public void WallIsPath()
    {
        _renderers[0].enabled = false;
        _mazeBorder = false;
        _mazePath = true;
    }

    public void HideWall()
    {
        _renderers[0].enabled = false;
        _mazeBorder = false;
        _mazePath = false;
    }

    public bool DestroyConditions()
    {
        Collider[] colliders = Physics.OverlapSphere(transform.position, 1f, _tileLayer);
        int destroy = colliders.Length;
        foreach (Collider collider in colliders)
        {
            if (collider.GetComponent<Tile>().IsDestroyed) { destroy--; }
        }
        return destroy == 0;
    }

    // Good but need to account for first row edge case.
    // Also find a good time to call it as tiles get destroyed, because OnRowReset will NOT work
    public void TryDestroyWall() 
    {
        if (!DestroyConditions()) { return; }
        HideWall();
        _renderers[1].enabled = false;
        _isDestroyed = true;
    }
}
