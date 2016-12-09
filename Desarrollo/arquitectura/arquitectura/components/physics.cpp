
#include "physics.hpp"

physics::physics(){
    body = NULL;
}

physics::~physics(){
    
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

void physics::update(float* velocidad, float * posicion, float* anguloFinal, int* mousePosition){
  
        //inside Step()
        b2Vec2 vel;
        vel.x = velocidad[0];
        vel.y = velocidad[1];
        
//        angulo[0] = (float)mousePosition[0] - body->GetPosition().x;
//        angulo[1] = (float)mousePosition[1] - body->GetPosition().y;
//        
//        anguloFinal[0] = atan2f(-angulo[0], angulo[1])* 180 / 3.14159265 + 90;
    
        body->SetLinearVelocity( vel );
//        body->SetTransform(body->GetPosition(), anguloFinal[0]);
    
        posicion[0] = body->GetPosition().x;
        posicion[1] = body->GetPosition().y;
}
