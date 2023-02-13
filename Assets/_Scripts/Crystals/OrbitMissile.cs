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

    public void Spawn(Vector3 localPos, int missileIndex, int level)
    {
        gameObject.SetActive(true);
        transform.localPosition = localPos;
        transform.RotateAround(transform.parent.position, transform.parent.up, missileIndex * (360 / level));
        _particlesNormal.Play();
        _renderer.enabled = true;
    }

    public IEnumerator DestroyMissile()
    {
        _renderer.enabled = false;
        _particlesNormal.Stop();
        yield return _destroyDelay;
        gameObject.SetActive(false);
    }
}
