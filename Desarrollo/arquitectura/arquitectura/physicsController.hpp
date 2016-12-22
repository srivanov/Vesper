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
//#include <OpenGL/OpenGL.h>
//#include <GLUT/glut.h>

class physicsController{
    public:
        physicsController();
        void Footest();
        void setMoveState(int u);
        void Step(float* velocidad, float* posicion,float* posmouseFinal, int* rotacion);
		void dispararBala();
		void update();
		void getBulletPosition(float* pos);
	
    private:
		b2World* mundo;
		float angulo[2];
		b2Body* body;
        b2Body* body2;
		b2Body* bullet;
};

#endif /* physicsController_hpp */

