using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyHealth : MonoBehaviour {

    public int startingHealth = 100;
    public int currentHealth;

    int Sed;
    int Hambre;
    float time;
    bool dead;
    //CapsuleCollider capsulecollider;

	// Use this for initialization
	void Start () {
        dead = false;
        currentHealth = startingHealth;
        //capsulecollider = GetComponent<CapsuleCollider>();
        Sed = Random.Range(0,20);
        Hambre = Random.Range(0, 20);
        time = 0f;
    }
	
	// Update is called once per frame
	void Update () {
        time += Time.deltaTime;
        if(time > 2.0f)
        {
            Hambre++;
            Sed++;
        }
	}
    public void TakeDamage(int amount, Vector3 hitpoint)
    {
        if (dead)
            return;

        currentHealth -= amount;

        if (currentHealth <= 0)
            Dead();
    }
    void Dead()
    {
        dead = true;
        //capsulecollider.isTrigger = true;
        GetComponent<Rigidbody>().isKinematic = true;

    }
}
