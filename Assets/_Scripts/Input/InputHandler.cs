using UnityEngine;
using UnityEngine.InputSystem;

public class InputHandler : MonoBehaviour
{
    private PlayerInput _playerInput;
    private InputAction _pressAction, _drawAction;
    private static bool _isPressingScreen;
    private static Vector3 _pressPosition = new Vector3();

    public static bool IsPressingScreen => _isPressingScreen;
    public static Vector2 PressPosition => _pressPosition;

    private void OnEnable()
    {
        _playerInput = GetComponent<PlayerInput>();
        _pressAction = _playerInput.actions["Press"];
        _drawAction = _playerInput.actions["Draw"];

        _pressAction.performed += HandlePress;
        _pressAction.canceled += HandlePress;
        _drawAction.performed += HandleDraw;
    }

    private void OnDisable()
    {
        _pressAction.performed -= HandlePress;
        _pressAction.canceled -= HandlePress;
        _drawAction.performed -= HandleDraw;
    }

    private void HandleDraw(InputAction.CallbackContext ctx)
    {
        _pressPosition = ctx.ReadValue<Vector2>();
    }

    private void HandlePress(InputAction.CallbackContext ctx)
    {
        _isPressingScreen = ctx.ReadValueAsButton();
    }
}
