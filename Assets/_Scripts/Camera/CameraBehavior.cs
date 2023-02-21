using UnityEngine;

[RequireComponent(typeof(Camera))]
public class CameraBehavior : MonoBehaviour
{
    [Header("Transition Position & Rotation")]
    [SerializeField] private Vector3 _transitionPosition;
    [SerializeField] private Quaternion _transitionRotation;
    [Header("Stage Position & Rotation")]
    [SerializeField] private Vector3 _stagePosition;
    [SerializeField] private Quaternion _stageRotation;

    private Vector3 _targetPosition;
    private Vector3 _refVelocity;
    private Quaternion _targetRotation;
    private Quaternion _refDeriv;
    private bool _goodToMove = false;
    private bool _goodToRotate = false;
    private float _delta = 0.1f;
    private float _smooth = 1f; // the larger this is, the slower you move

    private void OnEnable()
    {
        GameManager.OnStateChanged += SetTargetForStage;
        Runner.OnTransitionReached += SetTargetForTransition;
    }

    private void OnDisable()
    {
        GameManager.OnStateChanged -= SetTargetForStage;
        Runner.OnTransitionReached -= SetTargetForTransition;
    }

    private void Update()
    {
        if (_goodToMove) { MoveCamera(); }
        if (_goodToRotate) { RotateCamera(); }
    }

    private void SetTargetForTransition()
    {
        _targetPosition = _transitionPosition;
        _targetRotation = _transitionRotation;

        _goodToMove = true;
        _goodToRotate = true;
    }

    private void SetTargetForStage(GameState state)
    {
        if (state != GameState.Progressing) { return; }

        _targetPosition = _stagePosition;
        _targetRotation = _stageRotation;

        _goodToMove = true;
        _goodToRotate = true;
    }

    private void MoveCamera()
    {
        transform.position = Vector3.SmoothDamp(transform.position, _targetPosition, ref _refVelocity, _smooth);
        if (GameManager.CompareVectorsAsInts(transform.position, _targetPosition))
        {
            _goodToMove = false;
            if (GameManager.CurrentState == GameState.Transition)
            {
                GameManager.Instance.StartDialogue();
            }
        }
    }

    private void RotateCamera()
    {
        transform.rotation = QuaternionHelperMethods.SmoothDamp(transform.rotation, _targetRotation, ref _refDeriv, _smooth);
        if (QuaternionHelperMethods.CompareQuaternions(transform.rotation, _targetRotation, _delta))
        {
            _goodToRotate = false;
        }
    }
}
