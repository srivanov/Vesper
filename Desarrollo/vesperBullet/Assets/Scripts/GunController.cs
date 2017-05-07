using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GunController : MonoBehaviour {

	public GameObject BulletEmitter;
	public GameObject Bullet;
	public float BulletForwardForce;

	public int damagePerShot = 20; 

	bool col;
	GameObject enemy;
	EnemyHealth enemyhealth;

	// Use this for initialization
	void Start () {
		
	}
	void OnTriggerEnter(Collider other)
	{
		if(other.gameObject == enemy)
		{
			print ("choca enemigo");
			col = true;
			if(enemyhealth != null)
			{
				print ("enemyhealth != null");
				// ... the enemy should take damage.
				enemyhealth.TakeDamage (damagePerShot, Bullet.transform.position);
			}
		}
	}
	void OnTriggerExit(Collider other)
	{
		if (other.gameObject == enemy)
		{
			col = false;
			print ("no choca");
		}
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKeyDown(KeyCode.L)) {
			// Instanciamos la bala
			GameObject TempBulletHandler;
			TempBulletHandler = Instantiate (Bullet, BulletEmitter.transform.position, BulletEmitter.transform.rotation) as GameObject;

			// Rotamos las balas porque hay veces en las que la rotación no funciona por cómo esté el modelo original y su pivot
			TempBulletHandler.transform.Rotate(Vector3.left * 90);

			// Cogemos el RigidBody para controlarlo
			Rigidbody TempRigidBody;
			TempRigidBody = TempBulletHandler.GetComponent<Rigidbody> ();

			// Aplicar la fuerza correspondiente a la bala
			TempRigidBody.AddForce(transform.forward * BulletForwardForce);

			// Autodestrucción de balas a los 3 sec
			Destroy(TempBulletHandler, 3.0f);
		}
	}
}
