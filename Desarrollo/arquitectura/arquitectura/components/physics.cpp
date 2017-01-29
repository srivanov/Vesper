
#include "physics.hpp"
#include "../objetos/GameObject.hpp"
#include <OpenGL/gl.h>

physics::physics(){
    body = NULL;
	
//	b2BodyDef myBodyDef;
//	b2PolygonShape polygonShape;
//	b2FixtureDef myFixtureDef;
//	myFixtureDef.shape = &polygonShape;
//	myFixtureDef.density = 1;
//	myBodyDef.type = b2_staticBody;
//	myBodyDef.position.Set(0, 0);
//	b2Body* staticBody = mundoBox2D::Instance()->getWorld()->CreateBody(&myBodyDef);
//	polygonShape.SetAsBox( 20, 1, b2Vec2(0, 0), 0);//ground
//	staticBody->CreateFixture(&myFixtureDef);
}

physics::~physics(){
	if(body!=NULL)
		mundoBox2D::Instance()->getWorld()->DestroyBody(body);
}

void physics::crearBodyDinamico(dvector3D &dimension, dvector3D &posicion){
    //body definition
    b2BodyDef myBodyDef;
    myBodyDef.type = b2_dynamicBody;
    
    //shape definition
    b2CircleShape circleShape;
	circleShape.m_radius = dimension.x/2.0f;
//    polygonShape.SetAsBox(dimension[0], dimension[1]); //a 2x2 rectangle
	
    //fixture definition
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &circleShape;
    myFixtureDef.density = 1;
	
    //create dynamic body
    myBodyDef.position.Set(posicion.x, posicion.y);
    body = mundoBox2D::Instance()->getWorld()->CreateBody(&myBodyDef);
    body->CreateFixture(&myFixtureDef);
	
	body->SetUserData(getFather());
	
	this->rotacion = 0;
	vel.x = 0;
	vel.y = 0;
	
	if(*getFather()->getType() == tPLAYER){
		b2PolygonShape polygonShape;
		polygonShape.SetAsBox(2.0f, 2.0f);
//		polygonShape.m_radius = 3;
		myFixtureDef.shape = &polygonShape;
		myFixtureDef.isSensor = true;
		body->CreateFixture(&myFixtureDef);
	}
}

void physics::crearBodyEstatico(dvector3D &dimension, dvector3D &posicion, float rotacion){
	b2BodyDef myBodyDef;
	b2PolygonShape polygonShape;
	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &polygonShape;
	myFixtureDef.density = 1;
	myBodyDef.type = b2_staticBody;
	myBodyDef.position.Set(posicion.x, posicion.y);
	body = mundoBox2D::Instance()->getWorld()->CreateBody(&myBodyDef);
	polygonShape.SetAsBox(dimension.x/2.0f, dimension.y/2.0f);
	body->CreateFixture(&myFixtureDef);
	
	body->SetUserData(getFather());
	
	this->rotacion = rotacion;
	vel.x = 0;
	vel.y = 0;
}

//void physics::update(float* anguloFinal, float* angulo, float* mousePosition){
void physics::update(){
	//TO DO: COMPROBAR QUE EL BODY NO SEA ESTATICO
	if(body->GetType() != b2_staticBody){
		body->SetLinearVelocity( vel );
		dvector3D aux(body->GetPosition().x, body->GetPosition().y, 0);
		getFather()->setPosicion(aux);
	}
}

void physics::setPosition(dvector3D &pos){
	body->SetTransform(b2Vec2(pos.x,pos.y), body->GetAngle());
}

void physics::setVelocity(dvector3D &veloc){
	vel.x = veloc.x;
	vel.y = veloc.y;
}

float physics::rotarConRaton(dvector3D &posRaton){
		
    b2Vec2 aux;
    //TO DO: Mirar si se puede hacer en una linea
    aux.x = posRaton.x - body->GetPosition().x;
    aux.y = posRaton.y - body->GetPosition().y;
    
    rotacion = atan2f(-aux.x, aux.y)* 180 / 3.14159265 + 90;
    
    //paso el coseno y seno de la rotacion a unitario
    float length = sqrt((aux.x*aux.x)+(aux.y*aux.y));
    angulo_disparo.x = aux.x / length;
    angulo_disparo.y = aux.y / length;
    
    getFather()->setDirDisparo(angulo_disparo);
    
    body->SetTransform(body->GetPosition(), rotacion);
    
    return rotacion;
}

void physics::rotar(float anguloRotacion){
	body->SetTransform(body->GetPosition(), anguloRotacion);
}


