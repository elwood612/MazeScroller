using UnityEngine;

public class TileSpawner : MonoBehaviour
{
    private int _counter = 0;
    private int _randomDisableTile;
    private float _width;
    private float _xPos;
    private float _smooth = 3f; // the larger this is, the slower you move
    private float _delta = 0.1f;
    private bool _toggle = false;
    private float _middleOfScreen, _edgeOfScreen;
    private Vector3 _target;
    private Vector3 _velocity = Vector3.zero;
    private AnimationCurve _widthCurve;

    private void Awake()
    {
        Initialize();
    }

    private void Initialize()
    {
        _widthCurve = GameManager.Instance.TileSpawnerCurve;
        _target = transform.position;
        _middleOfScreen = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width / 2, Screen.height, 100)).x;
        _edgeOfScreen = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width, Screen.height, 100)).x;
        CalculateWidth(GameManager.Instability); // we subscribe too late to catch the first state update
    }

    private void OnEnable()
    {
        GameManager.OnInstabilityChanged += CalculateWidth;
    }

    private void OnDisable()
    {
        GameManager.OnInstabilityChanged -= CalculateWidth;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Row"))
        {
            if (++_counter > _randomDisableTile && _width > 1.2f)
            {
                _counter = 0;
                _randomDisableTile = Random.Range(3, 10);
                other.GetComponent<Row>().ShouldDisableRandomTiles = true;
                // might want to disable another one at high instability
            }
        }
    }

    private void Update()
    {
        if (Vector3.Magnitude(transform.position - _target) < _delta && GameManager.Instability > 0) 
        { 
            SetNewTarget(); // need to make this dependent on TileSpeed
        }
        UpdateSizeAndPosition();
    }

    private void UpdateSizeAndPosition()
    {
        transform.localScale = new Vector3(_width * GameManager.TileLength, 1, 1);
        transform.position = Vector3.SmoothDamp(transform.position, _target, ref _velocity, _smooth);
    }

    private void CalculateWidth(int instability)
    {
        // !! DO NOT DELETE THE CASTS !! V.S. IS WRONG !!
        _width = _widthCurve.Evaluate((float)instability / (float)GameManager.MaxInstability);
    }

    private void SetNewTarget()
    {
        int sign = _toggle ? 1 : -1;
        _toggle = _toggle ? false : true;

        _xPos = Random.Range(_middleOfScreen, _edgeOfScreen - _width / 2);
        _target = new Vector3(_xPos * sign, transform.position.y, transform.position.z);
    }
}
