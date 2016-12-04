//
//  input.cpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "input.hpp"

input::input(){
	r = MyEventReceiver::Instance();
}

input::~input(){
	
}

void input::update(){
	if(r->IsKeyDown('W')){}
		
}
