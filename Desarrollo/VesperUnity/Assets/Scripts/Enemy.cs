using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class Enemy : MonoBehaviour {

    Transform player;
    EnemyHealth enemyhealth;
    //PlayerHealth playerhealth;
    NavMeshAgent nav;

    // Use this for initialization
    void Start () {
        player = GameObject.FindGameObjectWithTag("Player").transform;
        // PLAYER AND ENEMY HEALTH INIT
        
         enemyhealth = GetComponent<EnemyHealth>();
         //playerHealth = player.GetComponent<PlayerHealth>();
         
        nav = GetComponent<NavMeshAgent>();
    }

    // Update is called once per frame
    void Update () {
        if (enemyhealth.currentHealth > 0)
        {
            nav.SetDestination(player.position);
        }
        else
        {
            nav.enabled = false;
        }
	}
}
