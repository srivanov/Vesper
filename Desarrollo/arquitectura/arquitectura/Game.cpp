
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
    renderizador->closeWindow();
	delete renderizador;
	delete jugador;
//	delete pinstance;
}

void Game::start(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver){
	
	renderizador->crearWindow(ancho, alto, color, fullscreen, stencilbuffer, vsync, receiver);
//	renderizador->setTexto();
    jugador->addNodo("3d/sphere.3ds");
	jugador->setTexture("3d/texture.png");
	float* p = new float[3]{10, 10, 0};
	jugador->setPosicion(new float[3]{10, 10, 0});
	cam->addCamara(new float[3]{p[0], p[1]-5, p[2]-10}, jugador->getPosicion());
	
	if(nivel->cargarNivel("2"))
		nivel->dibujarMapa();
	
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

void Game::rotarConRaton(float* posRaton){
	jugador->rotarConRaton(posRaton);
}
