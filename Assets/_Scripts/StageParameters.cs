using UnityEngine;
using UnityEngine.UIElements;

[CreateAssetMenu(fileName = "StageParameters", menuName = "Scriptable Objects/Stage Parameters")]
public class StageParameters : ScriptableObject
{
    public bool TutorialStage;

    [Header("Stage Stats")]
    [Range(0, 100)] public int StageLength = 80;
    [Range(1, 5)] public int TotalStars = 2;
    [Tooltip("The higher this is, the fewer rows have holes.")]
    //[Range(0, 10)] public int MissingTilesChance = 1;
    public Color TileColor = new Color(0.1725489f, 0.3896077f, 0.490196f, 1f);

    //[Header("Spawner Width")]
    //public float TileSpawnerWidthMin = 2.1f;
    //public float TileSpawnerWidthMax = 2.6f;

    //[Header("Colored Tiles Over Time")]
    //public AnimationCurve ColorMinRows = new AnimationCurve(new Keyframe(0, 4), new Keyframe(1, 2));
    //public AnimationCurve ColorMaxRows = new AnimationCurve(new Keyframe(0, 8), new Keyframe(1, 4));

    //[Header("Crystals Over Time")]
    //public AnimationCurve CrystalMaxLevel = new AnimationCurve(new Keyframe(0, 0), new Keyframe(1, 3));
    //public AnimationCurve CrystalSpawnChance = new AnimationCurve(new Keyframe(0, 0.2f), new Keyframe(1, 0.5f));

    [Header("Dialogue")]
    public Dialogue AssociatedDialogue;
}
