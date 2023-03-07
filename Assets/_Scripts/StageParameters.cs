using UnityEngine;

[CreateAssetMenu(fileName = "StageParameters", menuName = "Scriptable Objects/Stage Parameters")]
public class StageParameters : ScriptableObject
{
    public int StageLength = 100;
    public int Stars = 3;
    public float BonusRecoveryTime = 2;
    public float MinSpeed = 10f;
    public int EasyIntro = 5;

    public float TileSpawnerWidthMin = 1.8f;
    public float TileSpawnerWidthMax = 4.8f;

    public int ColorSpawnChanceMin = 2;
    public int ColorSpawnChanceMax = 8;

    public int CrystalSpawnChanceMin = 1;
    public int CrystalSpawnChanceMax = 6;

    public AnimationCurve CrystalLevelDistribution = new AnimationCurve(new Keyframe(0, 0), new Keyframe(1, 1));

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
