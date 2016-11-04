//
//  worldBox2D.cpp
//  prob2
//
//  Created by Stoycho Ivanov Atanasov on 4/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "mundoBox2D.hpp"

const float kPixelsPerMeter = 32.0f;
const float kGravity = -kPixelsPerMeter / 0.7f; // adjust this to taste

mundoBox2D::mundoBox2D()
{
	i=0;
	world = new b2World(b2Vec2(0.0f, kGravity));
	world->SetAllowSleeping(true);
	world->SetContinuousPhysics(true);
//	world->SetContactListener(this);
}
