
#include "render.hpp"
#include "../objetos/GameObject.hpp"
#include <iostream>

//TODO: Hacer que cambie de modelo al cambiar de arma con el tab

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
		//nodo->_setNodePosition(*getFather()->getPosition());
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
		nodo->_setNodePosition(*getFather()->getPosition());
//		printf("cargado!\n");
    }
}

void render::anyadirArma(){
    if(nodo != NULL)
        nodo->setPortatil(ventana::Instance()->getSceneManager()->addCubeSceneNode(0.5f, nodo->_getNode(), -1, vector3df(1,1,-1), vector3df(0,0,0), vector3df(1,1,1)));
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

void render::beginDraw() {
    ventana::Instance()->getDriver()->beginScene(true, true, SColor(255, 255, 255, 255));
}

void render::dibujar(){
//	texto->setText(irr::core::stringw(Fps::Instance()->get()).c_str());
	
//    GUIManager::i().drawAllGuis();
	ventana::Instance()->getSceneManager()->drawAll();
	
//	ventana::Instance()->getDevice()->getGUIEnvironment()->drawAll();
}

void render::endDraw() {
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

void render::CreateGround(int alto, int ancho){
    
    
    IMesh* suelo = ventana::Instance()->getSceneManager()->getGeometryCreator()->createPlaneMesh(core::dimension2df(alto,ancho));
    nodo_suelo = ventana::Instance()->getSceneManager()->addMeshSceneNode(suelo);
    nodo_suelo->setMaterialFlag(EMF_LIGHTING, false);
    nodo_suelo->setMaterialTexture(0, ventana::Instance()->getDriver()->getTexture("3d/colorverde.jpg"));
    
    nodo_suelo->setPosition(vector3df((alto/2.f)-0.5, (ancho/2.f)-0.5, 0.5));
    nodo_suelo->setRotation(vector3df(90,180,180));
    
}

void render::dibujarMuro(int *tilemap,int anchoMapa, int altoMapa){
	IMesh* muro  = ventana::Instance()->getSceneManager()->getMesh("3d/muro.3ds");
	
	if(!muro){
		printf("muro no cargado\n");
	}

	ISceneNode* nodo;
	
    

    int h1 = altoMapa;
    int w1 = anchoMapa;
    
    size_t size = altoMapa*anchoMapa,it;
    
    for(it=0;it<size;it++){
        if(tilemap[it] == 1){
            int y = (int) it / (anchoMapa) ;
            int x = (int) it % (anchoMapa) ;
//            nodo = ventana::Instance()->getSceneManager()->addMeshSceneNode(muro);
			nodo = ventana::Instance()->getSceneManager()->addCubeSceneNode(1.0f, 0, -1, vector3df(0,0,0), vector3df(0,0,0), vector3df(1,1,1));
            nodo->setMaterialFlag(EMF_LIGHTING, false);
            nodo->setMaterialTexture(0, ventana::Instance()->getDriver()->getTexture("3d/rocas.jpg"));
            nodo->setPosition(vector3df(x,y,0));
            //std::cout << x << "|" << y << std::endl;
        }
    }
    

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
