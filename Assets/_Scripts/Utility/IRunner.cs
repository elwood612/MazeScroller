using UnityEngine;

public interface IRunner
{
    public Tile CurrentTile { get; set; }
    public Tile PreviousTile { get; set; }
    public void CalculateNextTargetWrapper(Tile tile);
}