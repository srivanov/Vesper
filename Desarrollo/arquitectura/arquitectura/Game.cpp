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
	entrada = new input();
	running = true;
    p = new player();
	c = new camara();
	escenarios* uno = new escenarios();
}

Game::~Game(){
	c->~camara();
	p->~player();
    renderizador->closeWindow();
	renderizador->~render();
	free(pinstance);
}

void Game::start(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver){
	
	renderizador->crearWindow(ancho, alto, color, fullscreen, stencilbuffer, vsync, receiver);
//	renderizador->setTexto();
    p->addNodo("../../../arquitectura/3d/muro.3ds");
	c->addCamara(new float[3]{0,-10,-10}, new float[3]{0,0,0});
	uno->cargarNivel(2);
}

void Game::stop(){
	running = false;
}

void Game::render(){
	p->render();
    iter = balas.begin();
    while (iter != balas.end()){
        bala_aux = *iter;
        bala_aux->render();
        iter++;
    }
    renderizador->dibujar();
}

bool Game::isRunning(){
	if(running)
		return renderizador->run();
	return false;
}

player* Game::getPlayer(){
    return p;
}

bala* Game::insertBala(){
    bala_aux = new bala(p->getPosicion());
    bala_aux->addNodo("../../../arquitectura/3d/bala.3ds");
    balas.insert(balas.begin(), bala_aux);
    return bala_aux;
}

void Game::update(){
	entrada->update();
	p->update();
    iter = balas.begin();
    while (iter != balas.end()){
        bala_aux = *iter;
        bala_aux->mover(new float[2]{1,0});
        iter++;
    }
	Fps::Instance()->update();
    mundoBox2D::Instance()->update();
}
