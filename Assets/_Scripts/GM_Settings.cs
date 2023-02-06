using UnityEngine;

[CreateAssetMenu(fileName = "GameManagerSettings", menuName = "Scriptable Objects/Game Manager Settings")]
public class GM_Settings : ScriptableObject
{
    public AnimationCurve TileSpeedCurve;
    public AnimationCurve RunnerSpeedCurve;
    public AnimationCurve TileSpawnerWidthCurve;
}
