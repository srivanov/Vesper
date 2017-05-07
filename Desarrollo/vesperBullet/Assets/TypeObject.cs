using System.Collections;
using System.Collections.Generic;
using UnityEngine;
	

public class TypeObject : MonoBehaviour {

	public string tipo = "Piedra";
	GameObject player;
	bool delete;

	// Use this for initialization
	void Start () {
		player = GameObject.FindGameObjectWithTag ("Player");
		delete = false;
	}
	
	// Update is called once per frame
	void Update () {
		if (delete)
			Destroy (this.gameObject);
	}

	public string typeObject(){
		return tipo;
	}
	void OnTriggerEnter(Collider other)
	{
		if (tipo == "Puerta") {
			if (player.GetComponent<PlayerObject> ().Llave ())
				delete = true;
		}
		else if (other.gameObject == player) {
			delete = true;
		}

	}
}
