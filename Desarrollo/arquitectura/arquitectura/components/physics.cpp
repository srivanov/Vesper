
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

void physics::crearObjetosEstaticos(std::vector<dvector2D> &v){
//	b2PolygonShape poligono, p2;
//	p2.SetAsBox(3, 3);
//	b2FixtureDef myFixtureDef;
//	b2BodyDef myBody;
//	b2Body* body_aux;
//	std::vector<dvector2D>::iterator iter_sep, it = v.begin();
//	
//	iter_sep = std::find(v.begin(), v.end(), INT_MAX);
//	
//	int i=0;
//	if(iter_sep != v.end()){
//		
//		while (it != iter_sep) {
//			poligono.m_vertices[i].Set(it->x, it->y);
//			it++; i++;
//		}
////		poligono.m_vertices[7].Set(0, 0);
////		poligono.m_vertices[8].Set(0, 0);
//		myFixtureDef.shape = &p2;
//		myBody.type = b2_staticBody;
//		myBody.position.Set(0, 0);
//		body_aux = mundoBox2D::Instance()->getWorld()->CreateBody(&myBody);
//		body_aux->CreateFixture(&myFixtureDef);
//	}
}

void physics::update(){
	//TO DO: COMPROBAR QUE EL BODY NO SEA ESTATICO
	//inside Step()

	body->SetLinearVelocity( vel );
	
//	getFather()->setPosicion(new float[3]{body->GetPosition().x, body->GetPosition().y, 0});
    dvector3D aux(body->GetPosition().x, body->GetPosition().y, 0);
    
    getFather()->setPosicion(aux);
	
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
	body->SetTransform(b2Vec2(pos.x,pos.y), body->GetAngle());
}

void physics::setVelocity(dvector3D &veloc){
	vel.x = veloc.x;
	vel.y = veloc.y;
}

float physics::rotarConRaton(dvector3D &posRaton){
//	if(posRaton != NULL){
		
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
//	}
	return 0.0f;
}

void physics::rotar(float anguloRotacion){
	body->SetTransform(body->GetPosition(), anguloRotacion);
}
