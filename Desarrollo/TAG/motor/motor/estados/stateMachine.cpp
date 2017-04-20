//
//  stateMachine.cpp
//  estados
//
//  Created by Stoycho Ivanov Atanasov on 16/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "stateMachine.hpp"

stateMachine::stateMachine(){
	actualState = states::Instance();
	running = true;
}

void stateMachine::Init() {
    menusManager.Init();
    if(!nivelazo.inicializar())
		exit(0);
}

bool stateMachine::update(){
	actualState->update();
	
	if(actualState->destruir){
//		nivelazo.destroy();
		actualState->destruir = false;
	}
	
	if(*actualState->getState() == PLAYING)
		nivelazo.update();
	else if(*actualState->getState() == MENU)
		menusManager.update();
	else if(*actualState->getState() == STOP)
		stop();
	return running;
}

void stateMachine::render(){
	if(*actualState->getState() == PLAYING){
		nivelazo.Draw();
	}else if(*actualState->getState() == MENU)
		menusManager.render();
}
