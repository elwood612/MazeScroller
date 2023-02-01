public interface IRunner
{
    public Tile CurrentTile { get; set; }
    public Tile PreviousTile { get; set; }
    public void TilePrepareDecision(Tile tile);
}
