using System.Collections;
using UnityEngine;

public class Crystal : MonoBehaviour
{
    [SerializeField] private ParticleSystem particlesNormal;
    [SerializeField] private ParticleSystem particlesExplosion;
    
    private Renderer _renderer;
    private ParticleSystem.MainModule particlesNormalModule;
    private ParticleSystem.MainModule particlesExplosionModule;
    private bool canExplode = false, hasExploded = false;

    private void Awake()
    {
        _renderer = GetComponentInChildren<Renderer>();
        particlesNormalModule = particlesNormal.main;
        particlesExplosionModule = particlesExplosion.main;
    }

    public IEnumerator SelfDestruct()
    {
        if (!canExplode || hasExploded) { yield break; }

        hasExploded = true;
        particlesExplosion.Play();
        particlesNormal.Stop();
        _renderer.enabled = false;
        yield return new WaitForSeconds(1f);
        Destroy(gameObject);
    }

    private void SetColor(Material color)
    {
        _renderer.material = color;
        particlesNormalModule.startColor = color.color;
        particlesExplosionModule.startColor = color.color;
    }
}
