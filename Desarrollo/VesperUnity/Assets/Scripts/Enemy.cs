using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class Enemy : MonoBehaviour {

    Transform player;
    Transform me;
    EnemyHealth enemyhealth;
    PlayerHealth playerhealth;
    NavMeshAgent nav;

    // Use this for initialization
    void Start () {
        player = GameObject.FindGameObjectWithTag("Player").transform;
        me = GetComponent<Transform>();
        enemyhealth = GetComponent<EnemyHealth>();
        playerhealth = player.GetComponent<PlayerHealth>();
         
        nav = GetComponent<NavMeshAgent>();
    }

    // Update is called once per frame
    void Update () {

        if (enemyhealth.currentHealth > 1 && playerhealth.currentHealth > 1)
        {
            nav.SetDestination(player.position);
        }
        else
        {
            nav.enabled = false;
        }
	}
}
