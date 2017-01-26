
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
	
	if(nivelazo->cargarNivel("2"))
		nivelazo->dibujarMapa();
	
	World_BlackBoard::instance();
	NPC_library::instance();
	trigger_system::_instance();
	
	contador_npc=0;
	enemigos* npc = new enemigos(contador_npc);
	contador_npc++;
    dvector3D nodepos(10,15,0);
	npc->setPosicion(nodepos);
	npc->addNodo("");
	npc->setTexture("3d/enemy.jpg");
	npcs.insert(npcs.end(), npc);
	
    alarma * alarmita = new alarma(contador_npc);
    alarmita->addNodo("3d/alarmita.3ds");
    alarmita->setTexture("3d/alarmita.jpg");
    dvector3D posal(5,3,0);
    alarmita->setPosicion(posal);
    
    contador_npc++;
    alarmas.insert(alarmas.end(), alarmita);
	
    //TO DO: descomentar codigo de abajo
    
    fuente * fuentezita = new fuente(contador_npc);
    fuentezita->addNodo("");
    fuentezita->setTexture("3d/fuenten.jpg");
    dvector3D posf(0,10,0);
    fuentezita->setPosicion(posf);
    
    contador_npc++;
    fuentes.insert(fuentes.end(), fuentezita);
    
    comida * comidita = new comida(contador_npc);
    comidita->addNodo("");
    comidita->setTexture("3d/pizza.jpg");
    dvector3D poscom(0,0,0);
    comidita->setPosicion(poscom);
    
    contador_npc++;
    comidas.insert(comidas.end(), comidita);
    
    botiquin * botiqueen = new botiquin(contador_npc);
    botiqueen->addNodo("");
    botiqueen->setTexture("3d/botiquin.jpg");
    dvector3D posbot(10,0,0);
    botiqueen->setPosicion(posbot);
    
    contador_npc++;
    botiquines.insert(botiquines.end(), botiqueen);
    
    
//  delete npc;
//  delete alarmita;
//	delete fuentezita;
//	delete comidita;
//	delete botiqueen;
}

void Game::stop(){
	running = false;
}

void Game::render(){
	jugador->render();
	
	std::vector<enemigos*>::iterator it = npcs.begin();
	while (it != npcs.end()) {
		(*it)->render();
		it++;
	}
	
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
	
	std::vector<enemigos*>::iterator it = npcs.begin();
	while (it != npcs.end()) {
		(*it)->update();
		it++;
	}
    std::vector<comida*>::iterator it2 = comidas.begin();
    while (it2 != comidas.end()) {
        (*it2)->update();
        it2++;
    }
	std::vector<alarma*>::iterator it3 = alarmas.begin();
	while (it3 != alarmas.end()) {
		(*it3)->update();
		it3++;
	}
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
