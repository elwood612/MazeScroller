using System.Collections;
using UnityEngine;

public class OrbitMissile : MonoBehaviour
{
    [SerializeField] private Renderer _renderer;
    [SerializeField] private ParticleSystem _particlesNormal;
    [SerializeField] private ParticleSystem _particlesExplosion;
    private WaitForSeconds _destroyDelay = new WaitForSeconds(1f);

    private void OnEnable()
    {
        _renderer.enabled = true;
    }

    private void Update()
    {
        transform.RotateAround(transform.parent.position, transform.parent.up, -180 * Time.deltaTime);
    }

    public IEnumerator DestroyMissile()
    {
        _renderer.enabled = false;
        _particlesNormal.Stop();
        yield return _destroyDelay;
        gameObject.SetActive(false);
    }
}
