using UnityEngine;

public class Player : Runner
{
    private void OnEnable()
    {
        DrawMaze.OnTileAdded += AddTileToPath;
        DrawMaze.OnTileRemoved += RemoveTileFromPath;
    }

    private void OnDisable()
    {
        DrawMaze.OnTileAdded -= AddTileToPath;
        DrawMaze.OnTileRemoved -= RemoveTileFromPath;
    }

    protected override void SelfDestruct()
    {
        _rb.isKinematic = false;
    }
}
