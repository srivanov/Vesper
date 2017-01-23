
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
	nivel = new escenarios();
}

Game::~Game(){
	delete entrada;
	delete cam;
	delete nivel;
	balas.clear();
    renderizador->closeWindow();
	delete renderizador;
	delete jugador;
    for (int i=0; i<npcs.size(); i++) {
        delete npcs[i];
    }
    npcs.clear();
    for (int i=0; i<alarmas.size(); i++) {
        delete alarmas[i];
    }
    alarmas.clear();
    for (int i=0; i<fuentes.size(); i++) {
        delete fuentes[i];
    }
    fuentes.clear();
    for (int i=0; i<comidas.size(); i++) {
        delete comidas[i];
    }
    comidas.clear();
    for (int i=0; i<botiquines.size(); i++) {
        delete botiquines[i];
    }
    botiquines.clear();
//	delete pinstance;
}

void Game::start(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver){
	
	renderizador->crearWindow(ancho, alto, color, fullscreen, stencilbuffer, vsync, receiver);
//	renderizador->setTexto();
    jugador->addNodo("3d/sphere.3ds");
	jugador->setTexture("3d/texture.png");
	jugador->setPosicion(new float[3]{10, 10, 0});
	float* p = new float[3]{10, 10, 0};
	cam->addCamara(new float[3]{p[0], p[1]-5, p[2]-10}, jugador->getPosicion());
	
	if(nivel->cargarNivel("2"))
		nivel->dibujarMapa();
	
	World_BlackBoard::instance();
	NPC_library::instance();
	trigger_system::_instance();
	
	contador_npc=0;
	enemigos* npc = new enemigos(contador_npc);
	contador_npc++;
	npc->setPosicion(new float[3]{10, 30, 0});
	npc->addNodo("");
	npc->setTexture("3d/texture.png");
	npcs.insert(npcs.end(), npc);
    npc = NULL; delete npc;
    
    alarma * alarmita = new alarma(contador_npc);
    alarmita->addNodo("3d/alarmita.3ds");
    alarmita->setTexture("3d/alarmita.jpg");
    alarmita->setPosicion(new float[3]{30, 30, 0});
    
    contador_npc++;
    alarmas.insert(alarmas.end(), alarmita);
    alarmita = NULL; delete alarmita;
    
    fuente * fuentezita = new fuente(contador_npc);
    fuentezita->addNodo("");
    fuentezita->setTexture("3d/alarmita.jpg");
    fuentezita->setPosicion(new float[3]{0, 10, 0});
    
    contador_npc++;
    fuentes.insert(fuentes.end(), fuentezita);
    fuentezita = NULL; delete fuentezita;
    
    
    comida * comidita = new comida(contador_npc);
    comidita->addNodo("");
    comidita->setTexture("3d/alarmita.jpg");
    comidita->setPosicion(new float[3]{1, 1, 0});
    
    contador_npc++;
    comidas.insert(comidas.end(), comidita);
    comidita = NULL; delete comidita;
    
    botiquin * botiqueen = new botiquin(contador_npc);
    botiqueen->addNodo("");
    botiqueen->setTexture("3d/alarmita.jpg");
    botiqueen->setPosicion(new float[3]{10, 0, 0});
    
    contador_npc++;
    botiquines.insert(botiquines.end(), botiqueen);
    botiqueen = NULL; delete botiqueen;
    
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
    bala_aux = new bala(jugador->getPosicion(), jugador->getDirDisparo(), vel);
    bala_aux->addNodo("3d/bala.3ds");
    balas.insert(balas.begin(), bala_aux);
    return bala_aux;
}

void Game::update(){
	entrada->update();
	jugador->update();
	cam->movimientoInteligente(jugador->getPosicion());
    iter = balas.begin();
    while (iter != balas.end()){
        bala_aux = *iter;
        bala_aux->mover(bala_aux->getDireccion());
		bala_aux->update();
		if(bala_aux->muero()){
			delete bala_aux;
			iter = balas.erase(iter);
		}else
			iter++;
    }
    trigger_system::_instance()->update();
	Fps::Instance()->update();
    mundoBox2D::Instance()->update();
	
	std::vector<enemigos*>::iterator it = npcs.begin();
	while (it != npcs.end()) {
		(*it)->update();
		it++;
	}
    
    for (int i=0; i<comidas.size(); i++) {
        comidas[i]->update();
    }
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

void Game::rotarConRaton(float* posRaton){
	jugador->rotarConRaton(posRaton);
}
