
#include "Game.hpp"
#include <cstdlib>

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
//	nivelazo = new Level;
    pausa = true;
//    layoutPrueba = NULL;
}

Game::~Game(){
	printf("DELETE GAME\n");
	//TO DO: revisar deletes de ncp, alarmita... (estan abajo en start)
	delete entrada;
//	delete nivelazo;
	renderizador->closeWindow();
	delete renderizador;
    
}

void Game::start(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver){
	
	renderizador->crearWindow(ancho, alto, color, fullscreen, stencilbuffer, vsync, receiver);
    
    maquina.Init();
    
//    if(!nivelazo->inicializar("3")) {
//        exit(0);
//    }
    
    
//	layoutPrueba = new LayoutGUI();
}

void Game::stop(){
	running = false;
}

void Game::render(){
//	if(!pausa){
//		nivelazo->render();
//	}
    renderizador->beginDraw();
	if(*maquina.actualState->getState() == PLAYING)
		renderizador->dibujar();
    maquina.render();
    renderizador->endDraw();
}

bool Game::isRunning(){
	if(running)
		return renderizador->run();
	return false;
}

void Game::update(){
	if(!pausa){
//		nivelazo->update();
		entrada->update();
	}else{
//		processEvents();
//		layoutPrueba->update();
	}
    running = maquina.update();
    Fps::Instance()->update();
}



void Game::processEvents() {
//	MyEventReceiver* rec = MyEventReceiver::Instance();
//	layoutPrueba->posicionarRaton(rec->getMousePosition().x, rec->getMousePosition().y);
//	if(rec->getLeftClick())
//		layoutPrueba->inyectarClick();
//	else
//		layoutPrueba->inyectarClickUP();
}

