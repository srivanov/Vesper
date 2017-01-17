
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
	
	this->rotacion = 0;
	velocidad[0] = 0;
	velocidad[1] = 0;
}

void physics::crearBodyEstatico(float* dimension, float* posicion, float rotacion){
	b2BodyDef myBodyDef;
	b2PolygonShape polygonShape;
	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &polygonShape;
	myFixtureDef.density = 1;
	myBodyDef.type = b2_staticBody;
	myBodyDef.position.Set(posicion[0], posicion[1]);
	body = mundoBox2D::Instance()->getWorld()->CreateBody(&myBodyDef);
	polygonShape.SetAsBox(dimension[0]/2.0f, dimension[1]/2.0f);
	body->CreateFixture(&myFixtureDef);
	
	this->rotacion = rotacion;
	velocidad[0] = 0;
	velocidad[1] = 0;
}

//void physics::update(float* anguloFinal, float* angulo, float* mousePosition){
void physics::update(){
	//TO DO: COMPROBAR QUE EL BODY NO SEA ESTATICO
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

void physics::setPosition(float* pos){
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
