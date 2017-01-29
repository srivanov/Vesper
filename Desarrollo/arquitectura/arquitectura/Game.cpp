
#include "Game.hpp"
#include <cstdlib>
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
	balas.clear();
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
	
	if(nivelazo->cargarNivel("1"))
		nivelazo->dibujarMapa();
	
	World_BlackBoard::instance();
	NPC_library::instance();
	trigger_system::_instance();
}

void Game::stop(){
	running = false;
}

void Game::render(){
	jugador->render();
	
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
    return jugador;
}

bala* Game::insertBala(float vel){
    //TO DO: Hacer la gestion de las balas en la clase bala
    bala_aux = new bala(*jugador->getPosicion(), *jugador->getDirDisparo(), vel);
    bala_aux->addNodo("3d/bala.3ds");
    balas.insert(balas.begin(), bala_aux);
    return bala_aux;
}

void Game::update(){
	nivelazo->update();
	entrada->update();
	jugador->update();
	cam->movimientoInteligente(*jugador->getPosicion());
	
    iter = balas.begin();
    while (iter != balas.end()){
        bala_aux = *iter;
        bala_aux->mover(*bala_aux->getDireccion());
		bala_aux->update();
		if(*bala_aux->getmuero()){
			delete bala_aux;
            bala_aux = NULL;
			iter = balas.erase(iter);
		}else
			iter++;
    }
	
    trigger_system::_instance()->update();
	
    Fps::Instance()->update();
	mundoBox2D::Instance()->update();
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
