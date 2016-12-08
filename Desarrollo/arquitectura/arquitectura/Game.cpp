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
//	entrada = new input();
	running = true;
    p = new player();
	c = new camara();
}

Game::~Game(){
	c->~camara();
	p->~player();
	renderizador->~render();
	free(pinstance);
}

void Game::start(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver){
	
	renderizador->crearWindow(ancho, alto, color, fullscreen, stencilbuffer, vsync, receiver);

    p->addNodo("../../../arquitectura/3d/muro.3ds");
	c->addCamara(new float[3]{0,-10,-10}, new float[3]{0,0,0});
}

void Game::stop(){
	running = false;
}

void Game::render(){
	p->render();
    renderizador->dibujar();
}

bool Game::isRunning(){
	if(running)
		return renderizador->run();
	return false;
}

void Game::update(){
//	entrada->update();
	p->update();
}
