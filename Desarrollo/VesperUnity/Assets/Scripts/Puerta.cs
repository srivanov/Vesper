using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Puerta : MonoBehaviour {

	bool playerNear;
	bool Open;
	GameObject player;

	// Use this for initialization
	void Start () {
		playerNear = Open = false;
		player = GameObject.FindGameObjectWithTag ("Player");
	}
	
	// Update is called once per frame
	void Update () {
		if (Open) {
			print ("ABIERTA");
		}
	}
	public void OpenPuerta(){
		Open = true;
	}
	void OnTriggerEnter(Collider other)
	{
		if(other.gameObject == player)
		{
			playerNear = true;
		}
	}
	void OnTriggerExit(Collider other)
	{
		if (other.gameObject == player)
		{
			playerNear = false;
		}
	}
}
