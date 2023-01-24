using UnityEngine;

public class GameManager : Singleton<GameManager>
{
    [SerializeField] private GameObject _environment;
    private Vector3 _speed = new Vector3(0, 0, -2);

    void Update()
    {
        _environment.transform.Translate(_speed * Time.deltaTime);
    }
}
