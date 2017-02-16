
#include "Game.hpp"
#include <cstdlib>
#include "GUI/GUIManager.h"
//Game* Game::pinstance = 0;

Game* Game::Instance(){
	static Game pinstance;
	return &pinstance;
	//if(pinstance == 0){
	//	pinstance = new Game();
	//}
	//return pinstance;
}

Game::Game(){
	renderizador = new class render();
	entrada = new input();
	running = true;
    jugador = new player();
	cam = new camara();
	nivelazo = new nivel();
}

Game::~Game(){
	//TO DO: revisar deletes de ncp, alarmita... (estan abajo en start)
	delete entrada;
	delete cam;
	delete nivelazo;
	delete jugador;
	renderizador->closeWindow();
	delete renderizador;
    if(bala_aux == NULL)
        delete bala_aux;
    
}

void Game::start(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver){
	
	renderizador->crearWindow(ancho, alto, color, fullscreen, stencilbuffer, vsync, receiver);
//	renderizador->setTexto();
    jugador->addNodo("3d/sphere.3ds");
	jugador->setTexture("3d/texture.png");
    dvector3D jpos(10,10,0);
	jugador->setPosicion(jpos);
	dvector3D campos(jpos.x, jpos.y - 5, jpos.z - 10);
	cam->addCamara(campos, *jugador->getPosicion());
	
	if(nivelazo->cargarNivel("3"))
		nivelazo->dibujarMapa();
	
	World_BlackBoard::instance();
	NPC_library::instance();
	trigger_system::_instance();
//    menu.inicializar();
}

void Game::stop(){
	running = false;
}

void Game::render(){
	jugador->render();
    renderizador->dibujar();
}

bool Game::isRunning(){
	if(running)
		return renderizador->run();
	return false;
}

player* Game::getPlayer(){
    return jugador;
}


void Game::update(){
	nivelazo->update();
	entrada->update();
	jugador->update();
	cam->movimientoInteligente(*jugador->getPosicion());
	
    trigger_system::_instance()->update();
	
    Fps::Instance()->update();
	mundoBox2D::Instance()->update();
//    GUIManager::i().updateAllGuis();
}

void Game::zoom(bool z){
    cam->setZoom(z);
}

void Game::atacarJugador(){
	jugador->atacar();
}

void Game::cambiarArmaJugador(){
	jugador->cambiarArma();
}

void Game::rotarConRaton(dvector3D posRaton){
	jugador->rotarConRaton(posRaton);
}

camara* Game::getCamara(){
    return cam;
}
