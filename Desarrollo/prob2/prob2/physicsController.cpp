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

//class member variables
b2Body* body;
_moveState moveState;

physicsController::physicsController(){
	mundo = mundoBox2D::Instance()->getWorld();
	timeStep = 1/20.0;      //the length of time passed to simulate (seconds)
	velocityIterations = 8;   //how strongly to correct velocity
	positionIterations = 3;   //how strongly to correct position
}

void physicsController::Step(float* velocidad, float * posicion){
    //inside Step()
    b2Vec2 vel;
	vel.x = velocidad[0];
	vel.y = velocidad[1];
//    switch ( moveState )
//    {
//		case MS_STOP:	vel.x =	 0; vel.y =  0; break;
//        case MS_LEFT:	vel.x =	-5; vel.y =  0; break;
//        case MS_RIGHT:	vel.x =	 5; vel.y =  0; break;
//		case MS_UP:		vel.x =	 0; vel.y =  5; break;
//		case MS_DOWN:	vel.x =	 0; vel.y = -5; break;
//    }
    body->SetLinearVelocity( vel );
	
	mundo->Step( timeStep, velocityIterations, positionIterations);
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
	
	//a static body
	myBodyDef.type = b2_staticBody;
	myBodyDef.position.Set(0, 0);
//	b2Body* staticBody = m_world->CreateBody(&myBodyDef);
	
//	//add four walls to the static body
//	polygonShape.SetAsBox( 20, 1, b2Vec2(0, 0), 0);//ground
//	staticBody->CreateFixture(&myFixtureDef);
//	polygonShape.SetAsBox( 20, 1, b2Vec2(0, 40), 0);//ceiling
//	staticBody->CreateFixture(&myFixtureDef);
//	polygonShape.SetAsBox( 1, 20, b2Vec2(-20, 20), 0);//left wall
//	staticBody->CreateFixture(&myFixtureDef);
//	polygonShape.SetAsBox( 1, 20, b2Vec2(20, 20), 0);//right wall
//	staticBody->CreateFixture(&myFixtureDef);
	
	moveState = MS_STOP;
    
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



