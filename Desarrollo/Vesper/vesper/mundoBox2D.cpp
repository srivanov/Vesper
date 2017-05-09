
#include "mundoBox2D.hpp"
#include "objetos/PhysicObjects/PhysicObject.hpp"

static bool isType(PhysicObject* p1, ObjectType tipo);

//para crear y devolver la instancia del Juego
mundoBox2D* mundoBox2D::Instance(){
    
    static mundoBox2D pinstance;
    return &pinstance;
}

mundoBox2D::mundoBox2D()
{
	world = new b2World(b2Vec2(0.0f, 0.0f)); //mundo sin gravedad
	world->SetAllowSleeping(true);
	timeStep = 1/20.0;      //the length of time passed to simulate (seconds)
	velocityIterations = 8;   //how strongly to correct velocity
	positionIterations = 3;   //how strongly to correct position
	
	world->SetContactListener(&contacto);
}

mundoBox2D:: ~mundoBox2D() {
	printf("DELETE MUNDO BOX 2D\n");
	delete world;
}

//TO DO: implementar metodo para limpiar el mundo fisico (se puede usar world->getBodyList())
void mundoBox2D::cleanWorld(){
	b2Joint* joint = world->GetJointList();
	b2Body* body =  world->GetBodyList(), *next;
	while (body) {
		next = body->GetNext();
		world->DestroyBody(body);
		body = next;
	}
}


b2World* mundoBox2D::getWorld(){
    return world;
}

void mundoBox2D::update(){
	world->Step(timeStep, velocityIterations, positionIterations);
}

void ContactListener::BeginContact(b2Contact* contact){
	//Si los dos son bodys dinamicos el fixtureA es el que choca
	//Si uno es estatico sera el fixtureB, el fixtureA sera el dinamico
	b2Fixture *fixA = contact->GetFixtureA(), *fixB = contact->GetFixtureB();
	
	PhysicObject* g1 = static_cast<PhysicObject*>(fixA->GetBody()->GetUserData());
	PhysicObject* g2 = static_cast<PhysicObject*>(fixB->GetBody()->GetUserData());
	
	if(fixA->IsSensor())
		esSensor(g1, g2);
	else if(fixB->IsSensor())
		esSensor(g2, g1);
	else{
        contacta(g1, g2); contacta(g2, g1);
	}
	
	
//	if(g1 && g2){
//		if(g1->getObjectType()==REHEN && g2->getObjectType()==PLAYER)
//			g1->atarCuerda(contact->GetFixtureB()->GetBody());
//		else if(g1->getObjectType()==PLAYER && g2->getObjectType()==REHEN)
//			g2->atarCuerda(contact->GetFixtureA()->GetBody());
//		else{}
//	}
//	if((g1 && g1->getObjectType()==BALA) || (g2 && g2->getObjectType()==BALA)){
//		if(!contact->GetFixtureA()->IsSensor() && !contact->GetFixtureB()->IsSensor()){
//			if(g1)
//				g1->contacto(g2);
//			if(g2)
//				g2->contacto(g1);
//		}
//	}
}

void ContactListener::EndContact(b2Contact* contact) {
	PhysicObject* g1 = static_cast<PhysicObject*>(contact->GetFixtureA()->GetBody()->GetUserData());
	PhysicObject* g2 = static_cast<PhysicObject*>(contact->GetFixtureB()->GetBody()->GetUserData());
	if(g1 != NULL)
		g1->contactoEnd(g2);
	if(g2 != NULL)
		g2->contactoEnd(g1);
}

void ContactListener::contacta(PhysicObject* p1, PhysicObject* p2){
	if(p1)
		p1->contacto(p2);
}

void ContactListener::atarlos(PhysicObject* p1, b2Body* bod){
	p1->atarCuerda(bod);
}

void ContactListener::esSensor(PhysicObject *g1s, PhysicObject *g2){
	//TO DO: revisar si quito la linea de abajo
	//para que el enemigo pueda ver la bala y que la IA la esquive
	if(!isType(g2, BALA)){
		contacta(g1s, g2);
		//no aviso al objeto que entra en el sensor porque
		//no tiene que interactuar con el sensor sino con el enemigo
	}
}

static bool isType(PhysicObject* p1, ObjectType tipo){
	if(p1)
		if(p1->getObjectType()==tipo)
			return true;
	return false;
}
