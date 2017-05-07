using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class BulletScript : MonoBehaviour{
	public int damagePerShot = 20; 
	public GameObject bullet;
	public GameObject enemy;

	//bool col;
	//GameObject enemy;
	EnemyHealth enemyhealth;

	// Use this for initialization
	void Start ()
	{
		enemyhealth = GetComponent<EnemyHealth>();	
	}
	void OnTriggerEnter(Collider other)
	{
		if(other.gameObject == enemy)
		{
			print ("choca enemigo");
			//col = true;
			if(enemyhealth != null)
			{
				print ("enemyhealth != null");
				// ... the enemy should take damage.
				enemyhealth.TakeDamage (damagePerShot, bullet.transform.position);
			}
		}
	}
	void OnTriggerExit(Collider other)
	{
		if (other.gameObject == enemy)
		{
			//col = false;
			print ("no choca");
		}
	}
	// Update is called once per frame
	void Update ()
	{
		
	}
}

