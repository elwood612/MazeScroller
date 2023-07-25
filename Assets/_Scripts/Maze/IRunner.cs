using TMPro;
using UnityEngine.UI;
public interface IRunner
{
    public bool IsInTransition { get; set; }
    public Tile CurrentTile { get; set; }
    public Tile PreviousTile { get; set; }
    public TextMeshProUGUI DialogueBox { get; }
    public TextMeshProUGUI AnswerBox { get; }
    public Image GlowBox { get; }
    public Image RunnerFace { get; }
    public void CalculateNextTargetWrapper(Tile tile);
    public void BeginTransition();
    public void BeginStage();
    public void SetCurrentTile(Tile tile);
}
