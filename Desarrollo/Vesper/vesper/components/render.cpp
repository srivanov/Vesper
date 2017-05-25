
#include "render.hpp"
#include "../objetos/GameObject.hpp"
#include <iostream>
#include "../objetos/Camera.hpp"
//#include <string>

render::render(){
	nodo = NULL;
	camara = NULL;
	luz = NULL;
	vent = ventana::Instance();
	engine = SkyEngine::Instance();
}

render::~render(){
	delete nodo;
	nodo = NULL;
	delete luz;
	delete camara;
	std::vector<SkyMalla*>::iterator it = all_nodos.begin();
	while(it != all_nodos.end()){
//		delete (*it); // GALLEGO
		++it;
	}
	all_nodos.clear();
}

void render::update(){
//	if (nodo != NULL) {
//		//nodo->_setNodePosition(*getFather()->getPosition());
//	}
}

void render::crearWindow(uint32_t ancho, uint32_t alto, uint32_t color, bool fullscreen, bool stencilbuffer, bool vsync, bool receiver){
	vent->crearWindow(ancho, alto, color, fullscreen, stencilbuffer, vsync, receiver);
	engine->init();
}

bool render::run(){
	return vent->isRunning();
}

void render::setNode(char *filename){
    if(nodo == NULL){
//		IMesh* aux = ventana::Instance()->getSceneManager()->getMesh(filename);
//		// si no consigue cargar la malla 3D cargamos un cubo de irrlicht
//		if(aux == NULL)
//			nodo = new nodeMesh(ventana::Instance()->getSceneManager()->addCubeSceneNode(1.0f, 0, -1, vector3df(0,0,0), vector3df(0,0,0), vector3df(1,1,1)));
//		else
//			nodo = new nodeMesh(ventana::Instance()->getSceneManager()->addMeshSceneNode(aux));
//		aux = NULL;
        dvector3D rota = dvector3D(90,0,0);
//		nodo->_setNodePosition(*getFather()->getPosition());
//        nodo->_setNodeRotation(rota);
		nodo = engine->crearMalla(NULL, tMallaDinamica);
		nodo->setMalla(filename);
		nodo->setPosicion(*getFather()->getPosition());
		nodo->setRotacion(rota);
    }
}

void render::changeNode(char* filename){
	if(nodo != nullptr)
		nodo = engine->crearMalla(NULL, tMallaDinamica);
	nodo->setMalla(filename);
	dvector3D rota = dvector3D(270,0,0); // GALLEGO
	nodo->setPosicion(*getFather()->getPosition());
	nodo->setRotacion(rota);
}

void render::anyadirArma(){
//    if(nodo != NULL)
//        nodo->setPortatil(ventana::Instance()->getSceneManager()->addCubeSceneNode(0.5f, nodo->_getNode(), -1, vector3df(1,1,-1), vector3df(0,0,0), vector3df(1,1,1)));
}

void render::setNodeTexture(char* filename){
	if(nodo != nullptr)
		nodo->setTextura(filename);
}

bool render::setNodePosition(dvector3D &pos){
	if(nodo != nullptr){
		nodo->setPosicion(pos);
		return true;
	}
	return false;
}

bool render::setNodeRotation(dvector3D &rot){
	if(nodo != nullptr){
        dvector3D r(0,0,rot.z);
        nodo->setRotacion(r);
		return true;
	}
	return false;
}

void render::deleteNode(){
	delete nodo;
	nodo = NULL;
}

void render::beginDraw() {
	vent->beginDraw();
}

void render::dibujar(){
	engine->Draw();
}

//		INTERPOLATION
void render::DrawNode(dvector3D &prev_pos, dvector3D &next_pos, dvector3D &prev_rot, dvector3D &next_rot, float &interpolation){
	
	if(nodo != nullptr){
		dvector3D act( (next_pos.x - prev_pos.x) * interpolation + prev_pos.x, (next_pos.y - prev_pos.y) * interpolation + prev_pos.y, 0 );
		nodo->setPosicion(act);

		float r2d2 = 0.0f;
		if(next_rot.z > 270.0f && prev_rot.z < 90.0f)
			r2d2 = -360.0f;
		if(next_rot.z < 90.0f && prev_rot.z > 270.0f)
			r2d2 = 360.0f;
		
		act = dvector3D(nodo->getRotacion().x, 0, (next_rot.z - prev_rot.z + r2d2)*interpolation + prev_rot.z);
		nodo->setRotacion(act);
		
//		if(getFather()->getObjectType() == BALA){
//			printf("%.1f - %.1f\n", prev_pos.x, next_pos.x);
//		}
	}
	if(camara != nullptr){
		dvector3D act( (next_pos.x - prev_pos.x) * interpolation + prev_pos.x, (next_pos.y - prev_pos.y) * interpolation + prev_pos.y, (next_pos.z - prev_pos.z) * interpolation + prev_pos.z);
		
		setCamPos(act);
		setCamTarget(act+dvector3D(0,3,-6.5));
	}
}

void render::endDraw() {
	vent->endDraw();
}

void render::addCamera(dvector3D &p, dvector3D &l){
	camara = engine->crearCamara(NULL);
	camara->setPosicion(p);
	camara->setCamTarget(l);
	camara->setNearValue(1);
	camara->setFarValue(100);
	luz = engine->crearLuz(camara);
	luz->setAmbient(0.5);
	luz->setDiffuse(0.8);
	dvector3D c(-3,1,-1);
	luz->setPosicion(c);
	luz->setLightDirection(dvector3D(5,-1,0));
}

void render::closeWindow(){
	vent->deviceDrop();
}

void render::CreateGround(int alto, int ancho){

//    nodo_suelo->setPosition(vector3df((alto/2.f)-0.5, (ancho/2.f)-0.5, 0.5));
//    nodo_suelo->setRotation(vector3df(90,180,180));
	
	nodo_suelo = creaNodo("3d/muro.obj", "3d/rocas.png", tMallaEstatica, nullptr);
	dvector3D m((alto/2.f)-0.5, (ancho/2.f)-0.5, -0.5);
	nodo_suelo->setPosicion(m);
	m = dvector3D(alto, ancho, 0.1);
	nodo_suelo->escalar(m);
//	m = dvector3D(90,180,180);
//	nodo_suelo->rotar(m);
}

void render::dibujarMuro(int *tilemap,int anchoMapa, int altoMapa){
	SkyMalla* node;
	char* tex = "3d/rocas.png";
	int h1 = altoMapa;
	int w1 = anchoMapa;
	
	size_t size = altoMapa*anchoMapa,it;
	
	for(it=0;it<size;it++){
		if(tilemap[it] == 1 || tilemap[it] == 20){
			int y = (int) it / (anchoMapa);
			int x = (int) it % (anchoMapa);
			
			if(tilemap[it] == 1)
				nodo = creaNodo("3d/muro.obj", "3d/rocas.png", tMallaEstatica, NULL);
			else
				nodo = creaNodo("3d/arbusto.obj", "", tMallaEstatica, NULL);
			dvector3D m(x,y,0);
			nodo->setPosicion(m);
			all_nodos.push_back(nodo);
		}
	}
}

SkyMalla* render::creaNodo(char* malla, char* textura, tipoMalla t, SkyNodo* padre){
	SkyMalla* aux;
	aux = engine->crearMalla(padre, t);
	aux->setMalla(malla);
	if(textura != "")
		aux->setTextura(textura);
	return aux;
}

void render::setCamPos(dvector3D &pos){
	camara->setPosicion(pos);
}

dvector3D* render::getCamPos(){
	cam_pos = camara->getPosicion();
	return &cam_pos;
}

void render::setCamTarget(dvector3D pos){
	camara->setCamTarget(pos);
}

