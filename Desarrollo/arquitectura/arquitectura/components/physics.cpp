
#include "physics.hpp"

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
    b2PolygonShape polygonShape;
    polygonShape.SetAsBox(dimension[0], dimension[1]); //a 2x2 rectangle
    
    //fixture definition
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &polygonShape;
    myFixtureDef.density = 1;
    
    //create dynamic body
    myBodyDef.position.Set(posicion[0], posicion[1]);
    body = mundoBox2D::Instance()->getWorld()->CreateBody(&myBodyDef);
    body->CreateFixture(&myFixtureDef);

}

void physics::update(float* velocidad, float * posicion, float* anguloFinal, float* angulo, float* mousePosition){
	
	if(velocidad != NULL){
        //inside Step()
        b2Vec2 vel;
        vel.x = velocidad[0];
        vel.y = velocidad[1];
	
		body->SetLinearVelocity( vel );
	
		posicion[0] = body->GetPosition().x;
		posicion[1] = body->GetPosition().y;
	}
	if(mousePosition != NULL){
        angulo[0] = (float)mousePosition[0] - body->GetPosition().x;
        angulo[1] = (float)mousePosition[1] - body->GetPosition().y;
		
        anguloFinal[2] = atan2f(-angulo[0], angulo[1])* 180 / 3.14159265 + 90;
		
		//paso el coseno y seno de la rotacion a unitario
		float length = sqrt((angulo[0]*angulo[0])+(angulo[1]*angulo[1]));
		angulo[0] = angulo[0] / length;
		angulo[1] = angulo[1] / length;
		
//		printf("%.2f %.2f\n", angulo[0], angulo[1]);
        body->SetTransform(body->GetPosition(), anguloFinal[2]);
	}
	
}
