using UnityEngine;

public class Player : Runner
{
    private void OnEnable()
    {
        DrawMaze.OnTileAdded += AddTileToPath;
        DrawMaze.OnTileRemoved += RemoveTileFromPath;
        Tile.OnTileDestroy += RemoveTileFromPath;
        //Tile.OnTileDeactivate += RemoveTileFromPath;
    }

    private void OnDisable()
    {
        DrawMaze.OnTileAdded -= AddTileToPath;
        DrawMaze.OnTileRemoved -= RemoveTileFromPath;
        Tile.OnTileDestroy -= RemoveTileFromPath;
        //Tile.OnTileDeactivate -= RemoveTileFromPath;
    }

    protected override void SelfDestruct()
    {
        _rb.isKinematic = false;
    }
}
