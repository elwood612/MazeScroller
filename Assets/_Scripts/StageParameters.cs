using UnityEngine;

[CreateAssetMenu(fileName = "StageParameters", menuName = "Scriptable Objects/Stage Parameters")]
public class StageParameters : ScriptableObject
{
    [Header("Stage Stats")]
    public int StageLength = 70;
    public int Stars = 3;
    public float BonusRecoveryTime = 2;
    public float MinSpeed = 10f;
    public int EasyIntro = 5;

    [Header("Spawner Width")]
    public float TileSpawnerWidthMin = 1.8f;
    public float TileSpawnerWidthMax = 4.8f;

    [Header("Colored Tiles")]
    public AnimationCurve ColorMinRows = new AnimationCurve(new Keyframe(0, 3), new Keyframe(1, 1));
    public AnimationCurve ColorMaxRows = new AnimationCurve(new Keyframe(0, 8), new Keyframe(1, 3));

    [Header("Crystals")]
    public AnimationCurve CrystalMinRows = new AnimationCurve(new Keyframe(0, 2), new Keyframe(1, 0));
    public AnimationCurve CrystalMaxRows = new AnimationCurve(new Keyframe(0, 4), new Keyframe(1, 1));
    public AnimationCurve CrystalMaxLevel = new AnimationCurve(new Keyframe(0, 0), new Keyframe(1, 1));

    [Header("Dialogue")]
    public Dialogue AssociatedDialogue;

    /// <summary>
    /// Whoa, you can use OnEnable here?? Bring all randomization into this class please
    /// Ok thanks
    /// </summary> 
    //private void OnEnable()
    //{
    //    AssociatedDialogue = CreateInstance<Dialogue>();
    //}
}
