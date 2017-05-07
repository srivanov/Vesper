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
	public float distVision = 30;

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

        if (enemyhealth.currentHealth < 0 && playerhealth.currentHealth < 0)
        {
			nav.enabled = false;
        }
        else {
			Vector3 distancia = me.position - player.position;
			if(distancia.magnitude < distVision){
				nav.SetDestination (player.position);
			}
        }
	}
}
