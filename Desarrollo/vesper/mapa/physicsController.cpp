//
//  physicsController.cpp
//  prob2
//
//  Created by Stoycho Ivanov Atanasov on 4/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "physicsController.hpp"

//enumeration of possible input states
enum _moveState {
	MS_STOP = 0,
	MS_LEFT,
	MS_RIGHT,
	MS_UP,
	MS_DOWN,
};

physicsController::physicsController(){
	mundo = mundoBox2D::Instance()->getWorld();
}

void physicsController::Step(float* velocidad, float * posicion, float* anguloFinal, int* mousePosition){
    //inside Step()
    b2Vec2 vel;
	vel.x = velocidad[0];
	vel.y = velocidad[1];

    angulo[0] = (float)mousePosition[0] - body->GetPosition().x;
    angulo[1] = (float)mousePosition[1] - body->GetPosition().y;

    anguloFinal[0] = atan2f(-angulo[0], angulo[1])* 180 / 3.14159265 + 90;
	
    body->SetLinearVelocity( vel );
    body->SetTransform(body->GetPosition(), anguloFinal[0]);
//	mundo->Step( timeStep, velocityIterations, positionIterations);
	posicion[0] = body->GetPosition().x;
	posicion[1] = body->GetPosition().y;
    
	
//	printf("\n%u\n",moveState);
//    float p[2] = {body->GetPosition().x,body->GetPosition().y};
//    printf("\n%.2f %.2f\n",body->GetPosition().x,body->GetPosition().y);
//    return p;
}

void physicsController::Footest() {
    b2World* m_world = mundoBox2D::Instance()->getWorld();
    
	//body definition
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody;
    
	
	//shape definition
	b2PolygonShape polygonShape;
	polygonShape.SetAsBox(1, 1); //a 2x2 rectangle
	
	//fixture definition
	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &polygonShape;
	myFixtureDef.density = 1;
	
	//create dynamic body
	myBodyDef.position.Set(0, 0);
	body = m_world->CreateBody(&myBodyDef);
	body->CreateFixture(&myFixtureDef);
    
    myBodyDef.position.Set(10, 0);
    body2 = m_world->CreateBody(&myBodyDef);
    body2->CreateFixture(&myFixtureDef);
	
	//a static body
	myBodyDef.type = b2_staticBody;
	myBodyDef.position.Set(0, 0);
//	b2Body* staticBody = m_world->CreateBody(&myBodyDef);
	
	//add four walls to the static body
//	polygonShape.SetAsBox( 20, 1, b2Vec2(0, 0), 0);//ground
//	staticBody->CreateFixture(&myFixtureDef);
//	polygonShape.SetAsBox( 20, 1, b2Vec2(0, 40), 0);//ceiling
//	staticBody->CreateFixture(&myFixtureDef);
//	polygonShape.SetAsBox( 1, 20, b2Vec2(-20, 20), 0);//left wall
//	staticBody->CreateFixture(&myFixtureDef);
//	polygonShape.SetAsBox( 1, 20, b2Vec2(20, 20), 0);//right wall
//	staticBody->CreateFixture(&myFixtureDef);
	
//	moveState = MS_STOP;

	
}

bool physicsController::raycast(){
    
    //hacer el rayo
    b2RayCastInput input;
    input.p1.Set(0.0f, 0.0f);
    input.p2.Set(10.0f, 0.0f);
    input.maxFraction = 10.0f;
    
    b2RayCastOutput output;
    //bool hit = fixture->raycast(&output, input, 0);
    
    //comprobar que body 2 ve a body
//    if(body2->GetWorldPoint(body->get)){
//        
//    }
    
    return false;
}

/*
void physicsController::setMoveState(int u){
    switch (u) {
        case 0:
            moveState = MS_STOP;
            break;
        case 1:
            moveState = MS_LEFT;
            break;
        case 2:
            moveState = MS_RIGHT;
            break;
		case 3:
			moveState = MS_UP;
			break;
		case 4:
			moveState = MS_DOWN;
			break;
		default:
            break;
    }
    
}
*/

void physicsController::dispararBala(){
	b2BodyDef bala;
	bala.type = b2_kinematicBody;
	bala.position.Set(body->GetPosition().x, body->GetPosition().y);
	bullet = mundoBox2D::Instance()->getWorld()->CreateBody(&bala);
	bullet->SetLinearVelocity(b2Vec2(1,0));
//	while(bullet->GetPosition().x < body->GetPosition().x + 50){
//		mundoBox2D::Instance()->getWorld()->Step(timeStep, velocityIterations, positionIterations);
//		printf("%.2f %.2f\n",bullet->GetPosition().x,bullet->GetPosition().y);
//	}
	
}

void physicsController::getBulletPosition(float* pos){
	pos[0] = bullet->GetPosition().x;
	pos[1] = bullet->GetPosition().y;
}

void physicsController::update(){
	mundoBox2D::Instance()->update();
}
