
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
	cam = new camara();
	nivelazo = new nivel();
    pausa = true;
    layoutPrueba = NULL;
}

Game::~Game(){
	//TO DO: revisar deletes de ncp, alarmita... (estan abajo en start)
	delete entrada;
	delete cam;
	delete nivelazo;
	renderizador->closeWindow();
	delete renderizador;
    if(bala_aux == NULL)
        delete bala_aux;
    
}

void Game::start(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver){
	
	renderizador->crearWindow(ancho, alto, color, fullscreen, stencilbuffer, vsync, receiver);
//	renderizador->setTexto();
    dvector3D posJ, campos(0, -5, -10);
    if(nivelazo->cargarNivel("3")) {
        nivelazo->dibujarMapa();
        posJ = *nivelazo->getPlayer()->getPosicion();
    }
    campos.operator+(posJ);
//    campos = dvector3D(10,0,-10);
//    dvector3D k;
    cam->addCamara(campos, posJ);
    
    NpcLibrary::instancia();
    LevelBlackBoard::instance();
	trigger_system::_instance();
	layoutPrueba = new LayoutGUI();
}

void Game::stop(){
	running = false;
}

void Game::render(){
	if(!pausa){
		nivelazo->render();
	}
	renderizador->dibujar(pausa);
}

bool Game::isRunning(){
	if(running)
		return renderizador->run();
	return false;
}

void Game::update(){
	if(!pausa){
		nivelazo->update();
		entrada->update();
		cam->movimientoInteligente(*nivelazo->getPlayer()->getPosicion());
		trigger_system::_instance()->update();
		mundoBox2D::Instance()->update();
	}else{
		processEvents();
		layoutPrueba->update();
	}
    
	Fps::Instance()->update();
}

void Game::zoom(bool z){
    cam->setZoom(z);
}

void Game::atacarJugador(){
    nivelazo->atacarJugador();
}

void Game::cambiarArmaJugador(){
    nivelazo->cambiarArmaJugador();
}

void Game::rotarConRaton(dvector3D posRaton){
    nivelazo->rotarConRaton(posRaton);
}

camara* Game::getCamara(){
    return cam;
}

void Game::setPausa(bool p){
	pausa = p;
}

player* Game::getPlayer() {
    return nivelazo->getPlayer();
}

void Game::processEvents() {
	MyEventReceiver* rec = MyEventReceiver::Instance();
	layoutPrueba->posicionarRaton(rec->getMousePosition().x, rec->getMousePosition().y);
	if(rec->getLeftClick())
		layoutPrueba->inyectarClick();
	else
		layoutPrueba->inyectarClickUP();
}

