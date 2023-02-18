public interface IRunner
{
    //public static event Action OnNewStage;
    public bool IsInTransition { get; set; }
    public Tile CurrentTile { get; set; }
    public Tile PreviousTile { get; set; }
    public void CalculateNextTargetWrapper(Tile tile);
    public void BeginTransition();
    public void BeginStage();
    public void SetCurrentTile(Tile tile);
}