using UnityEngine;
using UnityEngine.Tilemaps;

[RequireComponent(typeof(Camera))]
public class CameraBehavior : MonoBehaviour
{
    [Header("Transition Position & Rotation")]
    [SerializeField] private Vector3 _transitionPosition;
    [SerializeField] private Quaternion _transitionRotation;
    [Header("Stage Position & Rotation")]
    [SerializeField] private Vector3 _stagePosition;
    [SerializeField] private Quaternion _stageRotation;
    [Header("Main Menu Position & Rotation")]
    [SerializeField] private Vector3 _menuPosition;
    [SerializeField] private Quaternion _menuRotation;

    [HideInInspector] public bool _goodToShake = false;

    private Vector3 _targetPosition;
    private Vector3 _refVelocity;
    private Quaternion _targetRotation;
    private Quaternion _refDeriv;
    private bool _goodToMove = false;
    private bool _goodToRotate = false;
    private bool _firstMove = true;
    
    private float _delta = 0.1f;
    private float _smooth = 1f; // the larger this is, the slower you move
    private float _shakeDuration = 0f;
    private float _shakeAmount = 0.25f;
    private float _decreaseFactor = 1.0f;

    private void OnEnable()
    {
        GameManager.OnStateChanged += SetTargetForStage;
        GameManager.OnMainMenuOpen += SetTargetForMenu;
        GameManager.OnMainMenuClose += SetTargetForTransition;
        Tile.OnChargedTileHit += EnableCameraShake;
        Runner.OnTransitionReached += SetTargetForTransition;
    }

    private void OnDisable()
    {
        GameManager.OnStateChanged -= SetTargetForStage;
        GameManager.OnMainMenuOpen -= SetTargetForMenu;
        GameManager.OnMainMenuClose -= SetTargetForTransition;
        Tile.OnChargedTileHit -= EnableCameraShake;
        Runner.OnTransitionReached -= SetTargetForTransition;
    }

    private void Update()
    {
        if (_goodToMove) { MoveCamera(); }
        if (_goodToRotate) { RotateCamera(); }
        if (_goodToShake) { ShakeCamera(); }
    }

    private void SetTargetForTransition()
    {
        if (_firstMove) 
        { 
            _firstMove = false;
            return; 
        }

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

    private void SetTargetForMenu()
    {
        _targetPosition = _menuPosition;
        _targetRotation = _menuRotation;

        _goodToMove = true;
        _goodToRotate = true;
    }

    private void EnableCameraShake()
    {
        _goodToShake = true;
        _shakeDuration = 0.5f;
    }

    private void MoveCamera()
    {
        transform.position = Vector3.SmoothDamp(transform.position, _targetPosition, ref _refVelocity, _smooth);
        if (GameManager.CompareVectorsAsInts(transform.position, _targetPosition))
        {
            _goodToMove = false;
            if (GameManager.CurrentState == GameState.Transition && GameManager.IsStageCompleted)
            {
                GameManager.Instance.EndStage();
            }
        }
    }

    private void RotateCamera()
    {
        transform.rotation = CameraHelperMethods.SmoothDamp(transform.rotation, _targetRotation, ref _refDeriv, _smooth);
        if (CameraHelperMethods.CompareQuaternions(transform.rotation, _targetRotation, _delta))
        {
            _goodToRotate = false;
        }
    }

    private void ShakeCamera()
    {
        if (_shakeDuration > 0)
        {
            transform.localPosition = _targetPosition + Random.insideUnitSphere * _shakeAmount;
            _shakeDuration -= Time.deltaTime * _decreaseFactor;
        }
        else
        {
            _shakeDuration = 0f;
            transform.localPosition = _targetPosition;
            _goodToShake = false;
        }
    }
}
