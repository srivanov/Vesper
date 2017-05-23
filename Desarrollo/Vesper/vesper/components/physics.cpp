
#include "physics.hpp"
#include "../objetos/PhysicObjects/PhysicObject.hpp"

physics::physics(){
    body = NULL;
	atar = false;
}

physics::~physics(){
	if(body!=NULL)
		mundoBox2D::Instance()->getWorld()->DestroyBody(body);
    body = NULL;
}

void physics::crearBodyDinamico(dvector3D &dimension, dvector3D &posicion){
    //body definition
	b2BodyDef myBodyDef;
    myBodyDef.type = b2_dynamicBody;
    
    //shape definition
	b2CircleShape circleShape;
	circleShape.m_radius = (dimension.x - 0.05f)/2.0f;
//    polygonShape.SetAsBox(dimension[0], dimension[1]); //a 2x2 rectangle
	
    //fixture definition
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &circleShape;
    myFixtureDef.density = 1.0f;
	
    //create dynamic body
    myBodyDef.position.Set(posicion.x, posicion.y);
    body = mundoBox2D::Instance()->getWorld()->CreateBody(&myBodyDef);
    body->CreateFixture(&myFixtureDef);
	
	body->SetUserData(static_cast<PhysicObject*>(getFather()));
	
	this->rotacion = 0;
	vel.x = 0;
	vel.y = 0;
	
    if(getFather()->getObjectType() == PLAYER){
        //body = NULL;
    }
}

bool physics::RayCastControl(dvector3D posIni,dvector3D posFin){
    return mundoBox2D::Instance()->raycastContact(posIni, posFin);
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
	
	body->SetUserData(static_cast<PhysicObject*>(getFather()));
	
	this->rotacion = rotacion;
	vel.x = 0;
	vel.y = 0;
}

void physics::crearBodyKinematico(dvector3D &dimension, dvector3D &posicion, float rotacion){
	b2BodyDef myBodyDef;
	b2PolygonShape polygonShape;
	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &polygonShape;
	myFixtureDef.density = 1;
	myBodyDef.type = b2_kinematicBody;
	myBodyDef.position.Set(posicion.x, posicion.y);
	body = mundoBox2D::Instance()->getWorld()->CreateBody(&myBodyDef);
	polygonShape.SetAsBox(dimension.x/2.0f, dimension.y/2.0f);
	body->CreateFixture(&myFixtureDef);
	
	body->SetUserData(static_cast<PhysicObject*>(getFather()));
	
	this->rotacion = rotacion;
	vel.x = 0;
	vel.y = 0;
}

void physics::crearObjetosEstaticos(std::vector<dvector2D> &v, std::vector<dvector2D> &p, int ancho, int alto){
	b2FixtureDef myFixtureDef;
	b2BodyDef myBody;
	b2Body* body_aux;
	
	std::vector<dvector2D>::iterator it = v.begin(), itp = p.begin();
	std::vector<int> longitud;
	b2Vec2 *vertices;
	
	int i=0;
	while(it != v.end()){
		if((*it) == INT_MAX){
			longitud.push_back(i);
			i=0;
			it++;
		}else{
			it++; i++;
		}
	}
	
	it = v.begin();
	for (auto j=longitud.begin(); j != longitud.end(); j++) {
		i=0;
		vertices = new b2Vec2[(*j)];
		while (i < (*j)) {
			vertices[i].Set((*it).x/ancho, (*it).y/alto);
			i++; it++;
		}
		b2ChainShape poligono;
		poligono.CreateChain(vertices, (*j));
		myFixtureDef.shape = &poligono;
		myBody.type = b2_staticBody;
		myBody.position.Set((*itp).x - 0.5, (*itp).y - 0.5);
		body_aux = mundoBox2D::Instance()->getWorld()->CreateBody(&myBody);
		body_aux->CreateFixture(&myFixtureDef);
		
		it++; itp++;
		delete [] vertices;
	}
}

void physics::attachSensor(float radio){
	if (body) {
		//	b2PolygonShape polygonShape2;
		//	//add semicircle radar sensor to tower
		//	float radius = 3;
		//	b2Vec2 vertices[3];
		//	vertices[0].Set(0,0);
		//	for (int i = 0; i < 2; i++) {
		//		float angle = i / 2.0 * 90 * DEGTORAD;
		//		vertices[i+1].Set( radius * cosf(angle), radius * sinf(angle) );
		//	}
		//	polygonShape2.Set(vertices, 3);
		//	myFixtureDef.shape = &polygonShape2;
		//	myFixtureDef.isSensor = true;
		//	myFixtureDef.density = 0.0f;
		//	body->CreateFixture(&myFixtureDef);
		b2CircleShape circle;
		circle.m_radius = radio;
		b2FixtureDef mf;
		mf.shape = &circle;
		mf.isSensor = true;
		mf.density = 0.f;
//		mf.friction = 0.f;
		body->CreateFixture(&mf);
	}
}

void physics::update(){
	//inside Step()
    if(body){
        if(body->GetType() != b2_staticBody){
            body->SetLinearVelocity( vel );
        }
        dvector3D aux(body->GetPosition().x, body->GetPosition().y, 0);
        static_cast<GameObject*>(getFather())->setPosition(aux);
    }
	if(atar){atarP(); atar = false;}
}

void physics::atarCuerda(b2Body *atado){
	atar = true;
	ata = atado;
}

void physics::atarP(){
	b2DistanceJointDef jointdef;
	jointdef.bodyA = body;
	jointdef.bodyB = ata;
	jointdef.collideConnected = true;
	jointdef.length = 3.f;
	mundoBox2D::Instance()->getWorld()->CreateJoint(&jointdef);
}

void physics::setPosition(dvector3D &pos){
    if(body)
        body->SetTransform(b2Vec2(pos.x,pos.y), body->GetAngle());
}

void physics::setVelocity(dvector3D &veloc){
	vel.x = veloc.x;
	vel.y = veloc.y;
}

float physics::rotarConRaton(dvector3D &posRaton){
	if(body != NULL){
		
        b2Vec2 aux;
        //TO DO: Mirar si se puede hacer en una linea
        aux.x = posRaton.x - body->GetPosition().x;
        aux.y = posRaton.y - body->GetPosition().y;
        
        rotacion = atan2f(-aux.x, aux.y)* 180 / 3.14159265 + 90;
        
        //paso el coseno y seno de la rotacion a unitario
        float length = sqrt((aux.x*aux.x)+(aux.y*aux.y));
        angulo_disparo.x = aux.x / length;
        angulo_disparo.y = aux.y / length;
        
        
        PhysicObject * ph = static_cast<PhysicObject*>(getFather());
        ph->setDirDisparo(angulo_disparo);
    
        body->SetTransform(body->GetPosition(), rotacion);
    
        return rotacion;
	}
	return 0.0f;
}

void physics::rotar(float anguloRotacion){
    if(body)
        body->SetTransform(body->GetPosition(), anguloRotacion);
}
