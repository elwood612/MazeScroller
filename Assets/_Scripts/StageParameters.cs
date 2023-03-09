using UnityEngine;
using UnityEngine.UIElements;

[CreateAssetMenu(fileName = "StageParameters", menuName = "Scriptable Objects/Stage Parameters")]
public class StageParameters : ScriptableObject
{
    [Header("Stage Stats")]
    [Range(0, 100)] public int StageLength = 70;
    [Range(1, 5)] public int TotalStars = 3;
    [Range(0, 20)] public float MinSpeed = 10f;
    [Range(0, 50)] public int TilePenalty = 20;
    [Tooltip("The higher this is, the fewer rows have holes.")]
    [Range(0, 10)] public int TileDestroyMinRows = 1;

    [Header("Spawner Width")]
    public float TileSpawnerWidthMin = 2.1f;
    public float TileSpawnerWidthMax = 2.6f;

    [Header("Colored Tiles Over Time")]
    public AnimationCurve ColorMinRows = new AnimationCurve(new Keyframe(0, 3), new Keyframe(1, 1));
    public AnimationCurve ColorMaxRows = new AnimationCurve(new Keyframe(0, 8), new Keyframe(1, 3));

    [Header("Crystals Over Time")]
    public AnimationCurve CrystalMinRows = new AnimationCurve(new Keyframe(0, 2), new Keyframe(1, 0));
    public AnimationCurve CrystalMaxRows = new AnimationCurve(new Keyframe(0, 4), new Keyframe(1, 1));
    public AnimationCurve CrystalMaxLevel = new AnimationCurve(new Keyframe(0, 0), new Keyframe(1, 1));

    [Header("Dialogue")]
    public Dialogue AssociatedDialogue;

    [HideInInspector] public int CrystalLevel => (int)GameManager.Instance.Parameters[GameManager.CurrentStage].CrystalMaxLevel
            .Evaluate(Random.Range(0f, (float)GameManager.StageProgress / (float)GameManager.Instance.Parameters[GameManager.CurrentStage].StageLength));

    /// <summary>
    /// Whoa, you can use OnEnable here?? Bring all randomization into this class please
    /// Ok thanks
    /// </summary> 
    //private void OnEnable()
    //{
    //    GameManager.OnStageEnd += RandomizeValues;
    //}

    //private void OnDisable()
    //{
    //    GameManager.OnStageEnd -= RandomizeValues;
    //}



    //private void RandomizeValues()
    //{
        
    //}
}
