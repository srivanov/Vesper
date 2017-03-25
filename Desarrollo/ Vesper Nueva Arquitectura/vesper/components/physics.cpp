
#include "physics.hpp"
#include "../objetos/PhysicObjects/PhysicObject.hpp"
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
    body = NULL;
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
			vertices[i].Set((*it).y/ancho, (*it).x/alto);
			i++; it++;
		}
		b2ChainShape poligono;
		poligono.CreateChain(vertices, (*j));
		myFixtureDef.shape = &poligono;
		myBody.type = b2_staticBody;
		myBody.position.Set((*itp).y - 0.5, (*itp).x - 0.5);
		body_aux = mundoBox2D::Instance()->getWorld()->CreateBody(&myBody);
		body_aux->CreateFixture(&myFixtureDef);
//		body_aux->SetTransform(body_aux->GetPosition(), 90 * DEGTORAD);
		
		it++; itp++;
	}
}

void physics::update(){
	//TO DO: COMPROBAR QUE EL BODY NO SEA ESTATICO
	//inside Step()
    if(body){
        if(body->GetType() != b2_staticBody){
            body->SetLinearVelocity( vel );
        }
//	getFather()->setPosicion(new float[3]{body->GetPosition().x, body->GetPosition().y, 0});
        dvector3D aux(body->GetPosition().x, body->GetPosition().y, 0);
    
        getFather()->setPosition(aux);
    }
	
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
//	b2Vec2* verts;
//	for( b2Fixture *fix = body->GetFixtureList(); fix; fix = fix->GetNext() ){
//		if( fix->GetType() == b2_staticBody ){
//			b2PolygonShape *poly = (b2PolygonShape*)fix->GetShape();
//			
//			int count = poly->GetVertexCount();
//			verts = (b2Vec2*) poly->m_vertices;
//			
//			for( int i = 0; i < count; i++ ){
//				verts[i] = body->GetWorldPoint( verts[i] );
//			}
//			//verts now contains world co-ords of all the verts
//		}
//	}
//	//set up vertex array
//	GLfloat glverts[16]; //allow for polygons up to 8 vertices
//	glVertexPointer(2, GL_FLOAT, 0, glverts); //tell OpenGL where to find vertices
//	glEnableClientState(GL_VERTEX_ARRAY); //use vertices in subsequent calls to glDrawArrays
//	
//	//fill in vertex positions as directed by Box2D
//	for (int i = 0; i < verts->Length(); i++) {
//		glverts[i*2]   = verts[i].x;
//		glverts[i*2+1] = verts[i].y;
//	}
//	
//	//draw solid area
//	glColor4f( 249, 51, 255, 1);
//	glDrawArrays(GL_TRIANGLE_FAN, 0, verts->Length());
//	
//	//draw lines
//	glLineWidth(3); //fat lines
//	glColor4f( 1, 0, 1, 1 ); //purple
//	glDrawArrays(GL_LINE_LOOP, 0, verts->Length());
	
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
