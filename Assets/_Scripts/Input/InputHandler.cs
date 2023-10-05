//using UnityEditor; // not needed once debug is done
using UnityEngine;
using UnityEngine.InputSystem;

public class InputHandler : MonoBehaviour
{
    private PlayerInput _playerInput;
    private InputAction _pressAction, _drawAction;
    //private InputAction _debugPauseAction;
    private static bool _isPressingScreen;
    private static Vector3 _pressPosition = new Vector3();

    public static bool IsPressingScreen => _isPressingScreen;
    public static Vector2 PressPosition => _pressPosition;

    private void Awake()
    {
        _playerInput = GetComponent<PlayerInput>();
        _pressAction = _playerInput.actions["Press"];
        _drawAction = _playerInput.actions["Draw"];
        //_debugPauseAction = _playerInput.actions["Pause"];
    }

    private void OnEnable()
    {
        _pressAction.performed += HandlePress;
        _pressAction.canceled += HandlePress;
        _drawAction.performed += HandleDraw;
        //_debugPauseAction.performed += DebugHandlePause;
    }

    private void OnDisable()
    {
        _pressAction.performed -= HandlePress;
        _pressAction.canceled -= HandlePress;
        _drawAction.performed -= HandleDraw;
        //_debugPauseAction.performed -= DebugHandlePause;
    }

    private void HandleDraw(InputAction.CallbackContext ctx)
    {
        _pressPosition = ctx.ReadValue<Vector2>();
    }

    private void HandlePress(InputAction.CallbackContext ctx)
    {
        _isPressingScreen = ctx.ReadValueAsButton();
    }

    //private void DebugHandlePause(InputAction.CallbackContext ctx)
    //{
    //    EditorApplication.isPaused = true;
    //}
}
