
#include "render.hpp"
#include "../objetos/GameObject.hpp"
#include <iostream>
#include <string>

//TODO: Hacer que cambie de modelo al cambiar de arma con el tab

render::render(){
	nodo = NULL;
	camara = NULL;
//	texto = NULL;
	vent = ventana::Instance();
	engine = SkyEngine::Instance();
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
	vent->crearWindow(ancho, alto, color, fullscreen, stencilbuffer, vsync, receiver);
//	setTexto();
}

bool render::run(){
//	return ventana::Instance()->getDevice()->run();
	return vent->isRunning();
}

void render::setNode(char *filename){
    if(nodo == NULL){
//		IMesh* aux = ventana::Instance()->getSceneManager()->getMesh(filename);
		nodo = engine->crearMalla(NULL, tMallaDinamica);
		// si no consigue cargar la malla 3D cargamos un cubo de irrlicht
//		if(aux == NULL)
//			nodo = new nodeMesh(ventana::Instance()->getSceneManager()->addCubeSceneNode(1.0f, 0, -1, vector3df(0,0,0), vector3df(0,0,0), vector3df(1,1,1)));
//		
//		else
//			nodo = new nodeMesh(ventana::Instance()->getSceneManager()->addMeshSceneNode(aux));
//		aux = NULL;
		nodo->setMalla(filename);
		nodo->setPosicion(*getFather()->getPosition());
//		nodo->_setNodePosition(*getFather()->getPosition());
//		printf("cargado!\n");
    }
}

void render::anyadirArma(){
//    if(nodo != NULL)
//        nodo->setPortatil(ventana::Instance()->getSceneManager()->addCubeSceneNode(0.5f, nodo->_getNode(), -1, vector3df(1,1,-1), vector3df(0,0,0), vector3df(1,1,1)));
}

void render::setNodeTexture(char* filename){
	if(nodo != NULL){
//		nodo->_setMaterialFlag(EMF_LIGHTING, false);
//		nodo->_setMaterialTexture(ventana::Instance()->getDriver()->getTexture(filename));
		nodo->setTextura(filename);
	}
}

bool render::setNodePosition(dvector3D &pos){
	if(nodo != NULL){
//		nodo->_setNodePosition(pos);
		nodo->setPosicion(pos);
		return true;
	}
	return false;
}

bool render::setNodeRotation(dvector3D &rot){
	if(nodo != NULL){
//		nodo->_setNodeRotation(rot);
		nodo->setRotacion(rot);
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
//	texto = ventana::Instance()->getDevice()->getGUIEnvironment()->addStaticText(irr::core::stringw(Fps::Instance()->get()).c_str(), core::rect<s32>(10,10,34,22), true);
//    texto->setBackgroundColor(SColor(255,255,0,255));
//    texto->setOverrideColor(SColor(255,255,255,255));
}

void render::beginDraw() {
//    ventana::Instance()->getDriver()->beginScene(true, true, SColor(255, 255, 255, 255));
	vent->beginDraw();
}

void render::dibujar(){
//	texto->setText(irr::core::stringw(Fps::Instance()->get()).c_str());
	
//    GUIManager::i().drawAllGuis();
//	ventana::Instance()->getSceneManager()->drawAll();
	engine->Draw();
//	ventana::Instance()->getDevice()->getGUIEnvironment()->drawAll();
}

void render::endDraw() {
//    ventana::Instance()->getDriver()->endScene();
	vent->endDraw();
}

void render::addCamera(dvector3D &p, dvector3D &l){
//	camara = ventana::Instance()->getSceneManager()->addCameraSceneNode(0, vector3df(p.x, p.y, p.z), vector3df(l.x, l.y, l.z));
	camara = engine->crearCamara(NULL);
	camara->setPosicion(p);
	camara->setCamTarget(l);
    camara->setNearValue(1);
    camara->setFarValue(200);
	SkyLuz* luz = engine->crearLuz(NULL);
	luz->_setAmbient(0.5);
	luz->_setDiffuse(20);
	dvector3D c(25,25,-25);
	luz->setPosicion(c);
}

void render::closeWindow(){
	vent->deviceDrop();
}

void render::CreateGround(int alto, int ancho){
    
    
//    IMesh* suelo = ventana::Instance()->getSceneManager()->getGeometryCreator()->createPlaneMesh(core::dimension2df(alto,ancho));
//    nodo_suelo = ventana::Instance()->getSceneManager()->addMeshSceneNode(suelo);
	nodo_suelo = engine->crearMalla(NULL, tMallaEstatica);
	nodo_suelo->setMalla("3d/cube.obj");
//	std::string s = "3d/colorverde.png";
	nodo_suelo->setTextura("3d/colorverde.png");
//    nodo_suelo->setMaterialFlag(EMF_LIGHTING, false);
//    nodo_suelo->setMaterialTexture(0, ventana::Instance()->getDriver()->getTexture("3d/colorverde.png"));
	dvector3D m((alto/2.f)-0.5, (ancho/2.f)-0.5, 0.5);
    nodo_suelo->setPosicion(m);
//    nodo_suelo->setRotacion(dvector3D(90,0,90));
	m = dvector3D(ancho,alto/4.f, 0.1);
	nodo_suelo->escalar(m);
	
}

void render::dibujarMuro(int *tilemap,int anchoMapa, int altoMapa){
//	IMesh* muro  = ventana::Instance()->getSceneManager()->getMesh("3d/muro.obj");
//	
//	if(!muro){
//		printf("muro no cargado\n");
//	}

//	ISceneNode* nodo;
	SkyMalla* node;
	char* s = "3d/rocas.png";
    

    int h1 = altoMapa;
    int w1 = anchoMapa;
    
    size_t size = altoMapa*anchoMapa,it;
    
    for(it=0;it<size;it++){
        if(tilemap[it] == 1){
            int y = (int) it / (anchoMapa);
            int x = (int) it % (anchoMapa);
//			nodo = ventana::Instance()->getSceneManager()->addCubeSceneNode(1.0f, 0, -1, vector3df(0,0,0), vector3df(0,0,0), vector3df(1,1,1));
			nodo = engine->crearMalla(NULL, tMallaEstatica);
			nodo->setMalla("3d/muro.obj");
			nodo->setTextura(s);
//            nodo->setMaterialFlag(EMF_LIGHTING, false);
//            nodo->setMaterialTexture(0, ventana::Instance()->getDriver()->getTexture("3d/rocas.png"));
			dvector3D m(x,y,0);
			nodo->setPosicion(m);
            //std::cout << x << "|" << y << std::endl;
        }
    }
    

}

void render::setCamPos(dvector3D &pos){
//	camara->setPosition(vector3df(pos.x, pos.y, pos.z));
	camara->setPosicion(pos);
}

dvector3D* render::getCamPos(){
	dvector3D getcam(camara->getPosicion());
	
	return &getcam;
//    return &getcam;
}

void render::setCamTarget(dvector3D &pos){
//	camara->setTarget(vector3df(pos.x, pos.y, pos.z));
	camara->setCamTarget(pos);
}
