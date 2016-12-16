
#include "render.hpp"
#include "../objetos/GameObject.hpp"
#include "../objetos/escenarios.hpp"

render::render(){
	nodo = NULL;
	camara = NULL;
	texto = NULL;
}

render::~render(){
//	printf("DELETE render\n");
	delete nodo;
}

void render::update(){
	
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
		nodo->_setNodePosition(getFather()->getPosicion());
//		printf("cargado!\n");
    }
}

void render::setNodeTexture(char* filename){
	if(nodo != NULL){
		nodo->_setMaterialFlag(EMF_LIGHTING, false);
		nodo->_setMaterialTexture(ventana::Instance()->getDriver()->getTexture("3d/texture.png"));
	}
}

void render::dropNode(){
    nodo = NULL;
}

void render::deleteNode(){
	nodo->~nodeMesh();
	nodo = NULL;
}

void render::actualizarRender(){
	if(nodo != NULL){
		nodo->_setNodePosition(getFather()->getPosicion());
		getFather()->setRotacion(ventana::Instance()->posicionRaton(getFather()->getPosicion()));
		nodo->_setNodeRotation(getFather()->getRotacion());
	}
}

void render::setTexto(){
	texto = ventana::Instance()->getDevice()->getGUIEnvironment()->addStaticText(irr::core::stringw(Fps::Instance()->get()).c_str(), core::rect<s32>(10,10,34,22), true);
    texto->setBackgroundColor(SColor(255,255,0,255));
    texto->setOverrideColor(SColor(255,255,255,255));
}

void render::dibujar(){
	texto->setText(irr::core::stringw(Fps::Instance()->get()).c_str());
    ventana::Instance()->getDriver()->beginScene(true, true, SColor(255, 255, 255, 255));
    ventana::Instance()->getSceneManager()->drawAll();
	ventana::Instance()->getDevice()->getGUIEnvironment()->drawAll();
    ventana::Instance()->getDriver()->endScene();
}

void render::addCamera(float* p, float* l){
	camara = ventana::Instance()->getSceneManager()->addCameraSceneNode(0, vector3df(p[0], p[1], p[2]), vector3df(l[0], l[1], l[2]));
    camara->setNearValue(1);
    camara->setFarValue(20);
}

void render::closeWindow(){
	ventana::Instance()->deviceDrop();
}

void render::dibujarMapa(){
	IMesh* muro  = ventana::Instance()->getSceneManager()->getMesh("3d/muro.3ds");
//	IMesh* suelo = ventana::Instance()->getSceneManager()->getMesh("../../../arquitectura/3d/suelo.3ds");
	
	if(!muro){
		printf("muro no cargado\n");
//		return false;
	}
//	if(!suelo){
//		printf("suelo no cargado\n");
////		return false;
//	}
	
	int*** mapita;
	mapita = static_cast<escenarios*>(getFather())->getMapa();

	ISceneNode* nodo;
	ISceneNode* nodo_suelo;
    
//	nodo_suelo = ventana::Instance()->getSceneManager()->addCubeSceneNode(1,0,1,vector3df(0,0,0),vector3df(0,0,0),vector3df(static_cast<escenarios*>(getFather())->getAlto(), static_cast<escenarios*>(getFather())->getAncho(), 0.1));
//	nodo_suelo->setMaterialFlag(EMF_LIGHTING, false);
//	nodo_suelo->setMaterialTexture(0, ventana::Instance()->getDriver()->getTexture("../../../arquitectura/3d/verde.jpg"));
    
    //CARGAR PLANO
    
    IMesh* suelo = ventana::Instance()->getSceneManager()->getGeometryCreator()->createPlaneMesh(core::dimension2df(static_cast<escenarios*>(getFather())->getAlto(),static_cast<escenarios*>(getFather())->getAncho()));
    nodo_suelo = ventana::Instance()->getSceneManager()->addMeshSceneNode(suelo);
    nodo_suelo->setMaterialFlag(EMF_LIGHTING, false);
    nodo_suelo->setMaterialTexture(0, ventana::Instance()->getDriver()->getTexture("3d/colorverde.jpg"));
    
    nodo_suelo->setPosition(vector3df((static_cast<escenarios*>(getFather())->getAlto()/2)-0.5, (static_cast<escenarios*>(getFather())->getAncho()/2)-0.5, 0));
    
    nodo_suelo->setRotation(vector3df(90,180,180));
	
    for(int i=0; i< static_cast<escenarios*>(getFather())->getAlto() ;i++){
		for(int j=0; j< static_cast<escenarios*>(getFather())->getAncho() ; j++){
			if(mapita[0][i][j] == 21 || mapita[0][i][j] == 9){
				nodo = ventana::Instance()->getSceneManager()->addMeshSceneNode(muro);
				nodo->setMaterialFlag(EMF_LIGHTING, false);
				nodo->setMaterialTexture(0, ventana::Instance()->getDriver()->getTexture("3d/rocas.jpg"));
				nodo->setPosition(vector3df(i,j,0));
//				nodo = NULL;
			}
//			if(mapita[0][i][j] == 86){
//				nodo_suelo = ventana::Instance()->getSceneManager()->addMeshSceneNode(suelo);
//				nodo_suelo->setMaterialFlag(EMF_LIGHTING, false);
//				nodo_suelo->setMaterialTexture(0, ventana::Instance()->getDriver()->getTexture("../../../arquitectura/3d/verde.jpg"));
//				nodo_suelo->setPosition(vector3df(i,j,0));
////				nodo_suelo = NULL;
//			}
		}
	}
//	return true;

}

void render::setCamPos(float* pos){
	camara->setPosition(vector3df(pos[0], pos[1], pos[2]));
}

float* render::getCamPos(){
	float* p = new float[3];
	p[0] = camara->getPosition().X;
	p[1] = camara->getPosition().Y;
	p[2] = camara->getPosition().Z;
	return p;
}

void render::setCamTarget(float *pos){
	camara->setTarget(vector3df(pos[0], pos[1], pos[2]));
}
