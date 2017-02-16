
#include "render.hpp"
#include "../objetos/GameObject.hpp"
#include "../objetos/nivel.hpp"
#include "../GUI/GUIManager.h"

render::render(){
	nodo = NULL;
	camara = NULL;
	texto = NULL;
}

render::~render(){
	delete nodo;
	nodo = NULL;
}

void render::update(){
	if (nodo != NULL) {
		nodo->_setNodePosition(*getFather()->getPosicion());
	}
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
		IMesh* aux = ventana::Instance()->getSceneManager()->getMesh(filename);
		// si no consigue cargar la malla 3D cargamos un cubo de irrlicht
		if(aux == NULL)
			nodo = new nodeMesh(ventana::Instance()->getSceneManager()->addCubeSceneNode(1.0f, 0, -1, vector3df(0,0,0), vector3df(0,0,0), vector3df(1,1,1)));
		else
			nodo = new nodeMesh(ventana::Instance()->getSceneManager()->addMeshSceneNode(aux));
		aux = NULL;
		nodo->_setNodePosition(*getFather()->getPosicion());
//		printf("cargado!\n");
    }
}

void render::setNodeTexture(char* filename){
	if(nodo != NULL){
		nodo->_setMaterialFlag(EMF_LIGHTING, false);
		nodo->_setMaterialTexture(ventana::Instance()->getDriver()->getTexture(filename));
	}
}

bool render::setNodePosition(dvector3D &pos){
	if(nodo != NULL){
		nodo->_setNodePosition(pos);
		return true;
	}
	return false;
}

bool render::setNodeRotation(dvector3D &rot){
	if(nodo != NULL){
		nodo->_setNodeRotation(rot);
		return true;
	}
	return false;
}

void render::dropNode(){
    nodo = NULL;
}

void render::deleteNode(){
	delete nodo;
	nodo = NULL;
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
//    GUIManager::i().drawAllGuis();
    ventana::Instance()->getDriver()->endScene();
}

void render::addCamera(dvector3D &p, dvector3D &l){
	camara = ventana::Instance()->getSceneManager()->addCameraSceneNode(0, vector3df(p.x, p.y, p.z), vector3df(l.x, l.y, l.z));
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
	
	std::vector<int>* mapita;
	mapita = static_cast<nivel*>(getFather())->getMapa();

	ISceneNode* nodo;
	ISceneNode* nodo_suelo;
    
//	nodo_suelo = ventana::Instance()->getSceneManager()->addCubeSceneNode(1,0,1,vector3df(0,0,0),vector3df(0,0,0),vector3df(static_cast<nivel*>(getFather())->getAlto(), static_cast<nivel*>(getFather())->getAncho(), 0.1));
//	nodo_suelo->setMaterialFlag(EMF_LIGHTING, false);
//	nodo_suelo->setMaterialTexture(0, ventana::Instance()->getDriver()->getTexture("../../../arquitectura/3d/verde.jpg"));
    
    //CARGAR PLANO
    
    IMesh* suelo = ventana::Instance()->getSceneManager()->getGeometryCreator()->createPlaneMesh(core::dimension2df(static_cast<nivel*>(getFather())->getAlto(),static_cast<nivel*>(getFather())->getAncho()));
    nodo_suelo = ventana::Instance()->getSceneManager()->addMeshSceneNode(suelo);
    nodo_suelo->setMaterialFlag(EMF_LIGHTING, false);
    nodo_suelo->setMaterialTexture(0, ventana::Instance()->getDriver()->getTexture("3d/colorverde.jpg"));
    
    nodo_suelo->setPosition(vector3df((static_cast<nivel*>(getFather())->getAlto()/2)-0.5, (static_cast<nivel*>(getFather())->getAncho()/2)-0.5, 0));
    
    nodo_suelo->setRotation(vector3df(90,180,180));
	

    int h1 = static_cast<nivel*>(getFather())->getAlto();
    int w1 = static_cast<nivel*>(getFather())->getAncho();
	
    for(int j = 0; j<h1; j++){
        for(int k = w1-static_cast<nivel*>(getFather())->getAncho(); k<w1; k++){
			if(mapita->at(k) == 1){
				nodo = ventana::Instance()->getSceneManager()->addMeshSceneNode(muro);
				nodo->setMaterialFlag(EMF_LIGHTING, false);
				nodo->setMaterialTexture(0, ventana::Instance()->getDriver()->getTexture("3d/rocas.jpg"));
				nodo->setPosition(vector3df(j,k - w1 + static_cast<nivel*>(getFather())->getAncho(),0));
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
        w1 += static_cast<nivel*>(getFather())->getAncho();
	}
    
//	return true;

}

void render::setCamPos(dvector3D &pos){
	camara->setPosition(vector3df(pos.x, pos.y, pos.z));
}

dvector3D* render::getCamPos(){
    dvector3D getcam(camara->getPosition().X, camara->getPosition().Y, camara->getPosition().Z);
    return &getcam;
}

void render::setCamTarget(dvector3D &pos){
	camara->setTarget(vector3df(pos.x, pos.y, pos.z));
}
