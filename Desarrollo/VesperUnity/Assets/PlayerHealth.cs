using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerHealth : MonoBehaviour {

    public int startingHealth = 100;
    public int currentHealth;
    public Slider healthSlider;

    // Use this for initialization
    bool Damaged;
    bool Dead;
	void Start () {
        Damaged = false;
        currentHealth = startingHealth;
        Dead = false;
	}
	
	// Update is called once per frame
	void Update () {
		
	}
    public void TakeDamage(int amount)
    {
        Damaged = true;
        currentHealth -= amount;
        healthSlider.value = currentHealth;

        if (currentHealth <= 0)
            Dead = true;
    }
}
