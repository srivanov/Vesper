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
	renderizador = new class render();
	input = new class input();
}

Game::~Game(){
	
}

void Game::start(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver){
	
	renderizador->crearWindow(ancho, alto, color, fullscreen, stencilbuffer, vsync, receiver);
}

void Game::render(){
	
}

bool Game::isRunning(){
	return renderizador->run();
}

void Game::update(){
	input->update();
}
