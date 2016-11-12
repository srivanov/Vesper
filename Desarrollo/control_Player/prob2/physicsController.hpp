//
//  physicsController.hpp
//  prob2
//
//  Created by Stoycho Ivanov Atanasov on 4/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef physicsController_hpp
#define physicsController_hpp

#include <stdio.h>
#include <Box2D/Box2D.h>
#include "mundoBox2D.hpp"

class physicsController{
    public:
        physicsController();
        void Footest();
        void setMoveState(int u);
        void Step(float* velocidad, float* posicion,float* posmouseFinal, int* rotacion);
    private:
	b2World* mundo;
	float32 timeStep;      //the length of time passed to simulate (seconds)
	int32 velocityIterations;   //how strongly to correct velocity
	int32 positionIterations;   //how strongly to correct position
};

#endif /* physicsController_hpp */

