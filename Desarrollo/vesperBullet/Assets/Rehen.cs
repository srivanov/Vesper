using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class Rehen : MonoBehaviour {

	Transform player;
	Transform me;
	NavMeshAgent nav;
	public float distVision = 10;
	// Use this for initialization
	void Start () {
		player = GameObject.FindGameObjectWithTag("Player").transform;
		me = GetComponent<Transform>();
		nav = GetComponent<NavMeshAgent>();
	}
	
	// Update is called once per frame
	void Update () {
		Vector3 distancia = me.position - player.position;
		if(distancia.magnitude < distVision){
			nav.SetDestination (player.position);
		}

	}
}
