using System.Collections;
using UnityEngine;

public class SampleTile : MonoBehaviour
{
    private WaitForSeconds _resetDelay = new WaitForSeconds(0.3f);

    private void OnEnable()
    {
        Runner.OnTransitionReached += ResetTransformWrapper;
    }

    private void OnDisable()
    {
        Runner.OnTransitionReached -= ResetTransformWrapper;
    }

    private void Update()
    {
        GameManager.AddBoardMotion(transform);
    }

    // This avoids floating point errors. Possibly a dumb solution but it works for now.
    private void ResetTransformWrapper() { StartCoroutine(ResetTransform()); }
    private IEnumerator ResetTransform()
    {
        yield return _resetDelay;
        transform.position = new Vector3(-100, 0, 0);
    }
}
