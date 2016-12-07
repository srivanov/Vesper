//
//  input.cpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "input.hpp"
#include "GameObject.hpp"

input::input(){
	r = MyEventReceiver::Instance();
}

input::~input(){
	
}

void input::update(){
	if(MyEventReceiver::Instance()->IsKeyDown('W')){
		transform3D *com = (class transform3D*)padre->findComponent("transform3D");
		if(com != NULL)
			com->hola();
	}
}
