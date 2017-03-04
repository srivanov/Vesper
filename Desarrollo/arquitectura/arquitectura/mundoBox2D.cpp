
#include "mundoBox2D.hpp"
#include "objetos/GameObject.hpp"

//para crear y devolver la instancia del Juego
mundoBox2D* mundoBox2D::Instance(){
    
	static mundoBox2D pinstance;
    return &pinstance; //la devuelve
}

mundoBox2D::mundoBox2D()
{
	world = new b2World(b2Vec2(0.0f, 0.0f)); //mundo sin gravedad
	world->SetAllowSleeping(true);
	velocityIterations = 8;   //how strongly to correct velocity
	positionIterations = 3;   //how strongly to correct position
	
	world->SetContactListener(&contacto);
}

mundoBox2D:: ~mundoBox2D() { //borra todos los cuerpos y joints. No usar sus punteros despues
	delete world;
}

b2World* mundoBox2D::getWorld(){
    return world;
}

void mundoBox2D::update(const long &timePerFrame){
	float32 timeStep = (float)(timePerFrame/1000.0f);
	world->Step(timeStep, velocityIterations, positionIterations);
}

//TO DO: implementar instansceof

void ContactListener::BeginContact(b2Contact* contact){
	//Si los dos son bodys dinamicos el fixtureA es el que choca
	//Si uno es estatico sera el fixtureB, el fixtureA sera el dinamico
	GameObject* g1 = static_cast<GameObject*>(contact->GetFixtureA()->GetBody()->GetUserData());
    GameObject* g2 = static_cast<GameObject*>(contact->GetFixtureB()->GetBody()->GetUserData());
	if(g1 != NULL && g2 != NULL){
		g1->contacto(static_cast<GameObject*>(contact->GetFixtureB()->GetBody()->GetUserData()));
    
//		gdsss2->setTexture("3d/rocas.jpg");
    	g2->contacto(static_cast<GameObject*>(contact->GetFixtureA()->GetBody()->GetUserData()));
	}
}

void ContactListener::EndContact(b2Contact* contact) {
    GameObject* g1 = static_cast<GameObject*>(contact->GetFixtureA()->GetBody()->GetUserData());
    GameObject* g2 = static_cast<GameObject*>(contact->GetFixtureB()->GetBody()->GetUserData());
	if(g1 != NULL && g2 != NULL){
    	g1->contactoEnd(static_cast<GameObject*>(contact->GetFixtureB()->GetBody()->GetUserData()));
    	g2->contactoEnd(static_cast<GameObject*>(contact->GetFixtureA()->GetBody()->GetUserData()));
	}
}
