
#include "physics.hpp"
#include "../objetos/GameObject.hpp"

physics::physics(){
    body = NULL;
}

physics::~physics(){
	mundoBox2D::Instance()->getWorld()->DestroyBody(body);
	//delete angulo;
}

void physics::crearBodyDinamico(float* dimension, float* posicion){
    //body definition
    b2BodyDef myBodyDef;
    myBodyDef.type = b2_dynamicBody;
    
    //shape definition
    b2CircleShape circleShape;
	circleShape.m_radius = dimension[0]/2.0f;
//    polygonShape.SetAsBox(dimension[0], dimension[1]); //a 2x2 rectangle
	
    //fixture definition
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &circleShape;
    myFixtureDef.density = 1;
    
    //create dynamic body
    myBodyDef.position.Set(posicion[0], posicion[1]);
    body = mundoBox2D::Instance()->getWorld()->CreateBody(&myBodyDef);
    body->CreateFixture(&myFixtureDef);
	
	rotacion = 0;
	velocidad[0] = 0;
	velocidad[1] = 0;
}

void physics::crearBodyEstatico(float* dimension, float* posicion, float rotacion){
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_staticBody;
	
	b2PolygonShape polygonShape;
	polygonShape.SetAsBox(dimension[0], dimension[1]);
	
	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &polygonShape;
	myFixtureDef.density = 1;
	
	myBodyDef.position.Set(posicion[0], posicion[1]);
	body = mundoBox2D::Instance()->getWorld()->CreateBody(&myBodyDef);
	body->CreateFixture(&myFixtureDef);
	
	this->rotacion = rotacion;
	velocidad[0] = 0;
	velocidad[1] = 0;
}

//void physics::update(float* anguloFinal, float* angulo, float* mousePosition){
void physics::update(){
	
	//inside Step()
	b2Vec2 vel;
	vel.x = velocidad[0];
	vel.y = velocidad[1];

	body->SetLinearVelocity( vel );

//	getFather()->setPosicion(new float[3]{body->GetPosition().x, body->GetPosition().y, 0});
	float* aux = getFather()->getPosicion();
	aux[0] = body->GetPosition().x;
	aux[1] = body->GetPosition().y;
	
//	posicion[0] = body->GetPosition().x;
//	posicion[1] = body->GetPosition().y;
	
	
//	if(mousePosition != NULL){
//        angulo[0] = (float)mousePosition[0] - body->GetPosition().x;
//        angulo[1] = (float)mousePosition[1] - body->GetPosition().y;
//		
//        anguloFinal[2] = atan2f(-angulo[0], angulo[1])* 180 / 3.14159265 + 90;
//		
//		//paso el coseno y seno de la rotacion a unitario
//		float length = sqrt((angulo[0]*angulo[0])+(angulo[1]*angulo[1]));
//		angulo[0] = angulo[0] / length;
//		angulo[1] = angulo[1] / length;
//		
////		printf("%.2f %.2f\n", angulo[0], angulo[1]);
//        body->SetTransform(body->GetPosition(), anguloFinal[2]);
//	}
	
}

void physics::setPosition(float* pos){
	printf("222");
	body->SetTransform(b2Vec2(pos[0],pos[1]), body->GetAngle());
}

void physics::setVelocity(float* vel){
	velocidad[0] = vel[0];
	velocidad[1] = vel[1];
}

float physics::rotarConRaton(float* posRaton){
	if(posRaton != NULL){
		float aux[2];
		aux[0] = posRaton[0] - body->GetPosition().x;
		aux[1] = posRaton[1] - body->GetPosition().y;
		
		rotacion = atan2f(-aux[0], aux[1])* 180 / 3.14159265 + 90;
		
		//paso el coseno y seno de la rotacion a unitario
		float length = sqrt((aux[0]*aux[0])+(aux[1]*aux[1]));
		angulo_disparo[0] = aux[0] / length;
		angulo_disparo[1] = aux[1] / length;
		
		getFather()->setDirDisparo(angulo_disparo);
		
		body->SetTransform(body->GetPosition(), rotacion);
		
		return rotacion;
	}
	return 0.0f;
}

void physics::rotar(float anguloRotacion){
	body->SetTransform(body->GetPosition(), anguloRotacion);
}
