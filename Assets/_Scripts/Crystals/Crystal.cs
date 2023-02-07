using System;
using System.Collections;
using UnityEngine;

public class Crystal : MonoBehaviour
{
    [SerializeField] private ParticleSystem particlesNormal;
    [SerializeField] private ParticleSystem particlesExplosion;
    
    private Renderer _renderer;
    private ParticleSystem.MainModule particlesNormalModule;
    private ParticleSystem.MainModule particlesExplosionModule;

    private void Awake()
    {
        _renderer = GetComponentInChildren<Renderer>();
        particlesNormalModule = particlesNormal.main;
        particlesExplosionModule = particlesExplosion.main;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player"))
        {
            GameManager.Score++;
            StartCoroutine(SelfDestruct());
        }
    }

    private IEnumerator SelfDestruct()
    {
        particlesExplosion.Play();
        particlesNormal.Stop();
        _renderer.enabled = false;

        // Need to implement object pooling
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
