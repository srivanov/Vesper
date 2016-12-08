
#include "render.hpp"
#include "GameObject.hpp"

render::render(){
	nodo = NULL;
	camara = NULL;
	texto = NULL;
}

render::~render(){
	
}

void render::crearWindow(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver){
	ventana::Instance()->crearWindow(ancho, alto, color, fullscreen, stencilbuffer, vsync, receiver);
	setTexto();
}

bool render::run(){
	return ventana::Instance()->getDevice()->run();
}

void render::setNode(char *filename){
    if(nodo == NULL){
        nodo = new nodeMesh(ventana::Instance()->getSceneManager()->addMeshSceneNode(ventana::Instance()->getSceneManager()->getMesh(filename)));
		nodo->_setNodePosition(padre->getPosicion());
		printf("cargado!\n");
    }
}

void render::dropNode(){
    nodo = NULL;
}

void render::actualizarRender(){
	if(nodo != NULL)
		nodo->_setNodePosition(padre->getPosicion());
}

void render::setTexto(){
	texto = ventana::Instance()->getDevice()->getGUIEnvironment()->addStaticText(irr::core::stringw(Fps::Instance()->get()).c_str(), core::rect<s32>(10,10,40,22), true);
}

void render::dibujar(){
	texto->setText(irr::core::stringw(Fps::Instance()->get()).c_str());
    ventana::Instance()->getDriver()->beginScene(true, true, SColor(255, 255, 255, 255));
    ventana::Instance()->getSceneManager()->drawAll();
	ventana::Instance()->getDevice()->getGUIEnvironment()->drawAll();
    ventana::Instance()->getDriver()->endScene();
}

void render::addCamera(float* p, float* l){
	camara = ventana::Instance()->getSceneManager()->addCameraSceneNode(0, vector3df(p[0], p[1], p[2]), vector3df(l[0], l[1], l[2]));
}

void render::closeWindow(){
	ventana::Instance()->deviceDrop();
}

