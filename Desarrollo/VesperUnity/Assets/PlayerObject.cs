using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerObject : MonoBehaviour {

	public int monedas;
	public bool llave;

	// Use this for initialization
	void Start () {
		llave = false;
		monedas = 0;
	}
	
	// Update is called once per frame
	void Update () {
		
	}
	void OnTriggerEnter(Collider other)
	{
		if(other.gameObject.CompareTag("Objectos"))
		{
			TypeObject type = other.gameObject.GetComponent<TypeObject> ();
			if (type.tipo == "Piedra") {
				print ("PIEDRA");
			} else if (type.tipo == "Llave") {
				print ("LLAVE");
				llave = true;
			}
			else if (type.tipo == "Moneda") {
				print ("MONEDA");
				monedas++;
			}

		}
	}
}
