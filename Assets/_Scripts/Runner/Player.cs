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

    protected override void WallCrossing(Wall wall)
    {
        base.WallCrossing(wall);
        wall.Crossings++;
        wall.TimeCrossed = Time.timeSinceLevelLoad;
    }
}
