using UnityEngine;
using UnityEngine.InputSystem;

public class InputHandler : MonoBehaviour
{
    private Controls _controls;
    private static bool _isPressingScreen;
    private static Vector2 _pressPosition = new Vector2();

    public static bool IsPressingScreen => _isPressingScreen;
    public static Vector2 PressPosition => _pressPosition;

    

    private void Awake()
    {
        _controls = new Controls();
    }

    private void OnEnable()
    {
        _controls.Enable();
        
        _controls.Gameplay.Press.performed += HandlePress;
        _controls.Gameplay.Press.canceled += HandlePress;
        _controls.Gameplay.Draw.performed += HandleDraw;
    }

    private void OnDisable()
    {
        _controls.Disable();
        
        _controls.Gameplay.Press.performed -= HandlePress;
        _controls.Gameplay.Press.canceled -= HandlePress;
        _controls.Gameplay.Draw.performed -= HandleDraw;
    }

    private void HandleDraw(InputAction.CallbackContext ctx)
    {
        _pressPosition = ctx.ReadValue<Vector2>();
    }

    private void HandlePress(InputAction.CallbackContext ctx)
    {
        _isPressingScreen = ctx.ReadValueAsButton();
    }

    private void Update()
    {
        if (IsPressingScreen) Debug.Log("Position = " + PressPosition);
    }
}
