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
};

//class member variables
b2Body* body;
_moveState moveState;

physicsController::physicsController(){
    
}

float* physicsController::Step(){
    //inside Step()
    b2Vec2 vel = body->GetLinearVelocity();
    switch ( moveState )
    {
        case MS_LEFT:  vel.x = -1; break;
        case MS_STOP:  vel.x =  0; break;
        case MS_RIGHT: vel.x =  1; break;
    }
    body->SetLinearVelocity( vel );
    
    b2Vec2 pos = body->GetPosition();
    float p[2] = {pos.x,pos.y};
    printf("\n%.2f %.2f\n",pos.x,pos.y);
    return p;
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
	myBodyDef.position.Set(0, 10);
	body = m_world->CreateBody(&myBodyDef);
	body->CreateFixture(&myFixtureDef);
	
	//a static body
	myBodyDef.type = b2_staticBody;
	myBodyDef.position.Set(0, 0);
	b2Body* staticBody = m_world->CreateBody(&myBodyDef);
	
	//add four walls to the static body
	polygonShape.SetAsBox( 20, 1, b2Vec2(0, 0), 0);//ground
	staticBody->CreateFixture(&myFixtureDef);
	polygonShape.SetAsBox( 20, 1, b2Vec2(0, 40), 0);//ceiling
	staticBody->CreateFixture(&myFixtureDef);
	polygonShape.SetAsBox( 1, 20, b2Vec2(-20, 20), 0);//left wall
	staticBody->CreateFixture(&myFixtureDef);
	polygonShape.SetAsBox( 1, 20, b2Vec2(20, 20), 0);//right wall
	staticBody->CreateFixture(&myFixtureDef);
	
	moveState = MS_STOP;
    
}

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
        default:
            break;
    }
    
}




