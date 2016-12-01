//
//  Game.cpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 1/12/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Game.hpp"

Game* Game::pinstance = 0;

Game* Game::Instance(){
	if(pinstance == 0){
		pinstance = new Game();
	}
	return pinstance;
}

Game::Game(){
	
}

Game::~Game(){
	
}

void Game::update(){
	
}

void Game::render(){
	
}

bool Game::isRunning(){
//	return interfaceIrr->_deviceRun();
	return true;
}
