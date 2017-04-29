using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyAttack : MonoBehaviour {

    public float timeAttack = 0.5f;
    public int attackDamage = 10;

    GameObject player;
    PlayerHealth playerhealth;
    EnemyHealth enemyheath;

    bool PlayerInRange;
    float tiempo;
	// Use this for initialization
	void Start () {
        player = GameObject.FindGameObjectWithTag("Player");
        playerhealth = player.GetComponent<PlayerHealth>();
        enemyheath = GetComponent<EnemyHealth>();
        tiempo = 0f;
	}
	
	// Update is called once per frame
	void Update () {
        tiempo += Time.deltaTime;
        if (tiempo >= timeAttack && PlayerInRange && enemyheath.currentHealth > 0)
        {
            Attack();
        }
	}
    void OnTriggerEnter(Collider other)
    {
        if(other.gameObject == player)
        {
            PlayerInRange = true;
        }
    }
    void OnTriggerExit(Collider other)
    {
        if (other.gameObject == player)
        {
            PlayerInRange = false;
        }
    }
    private void Attack()
    {
        tiempo = 0f;

        if (playerhealth.currentHealth > 0)
        {
            playerhealth.TakeDamage(attackDamage);
        }
    }
}
