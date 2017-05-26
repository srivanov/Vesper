
#include "render.hpp"
#include "../objetos/GameObject.hpp"
#include <iostream>
#include "../objetos/Camera.hpp"
//#include <string>

render::render(bool animada){
	nodo = NULL;
	camara = NULL;
	luz = NULL;
    nodo_suelo = nullptr;
	vent = ventana::Instance();
	engine = SkyEngine::Instance();
}

render::~render(){
	delete nodo;
	nodo = NULL;
    if(nodo_suelo){
        delete nodo_suelo;
        nodo_suelo = nullptr;
    }
    if(luz)
        luz = engine->removeLight(luz);
	//delete luz;
    if(camara != NULL)
        camara = engine->removeCam(camara);

	while(!all_nodos.empty()){
        SkyNodo * n = all_nodos[0];
        delete n;
        all_nodos.erase(all_nodos.begin());
	}
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
        
        dvector3D rota = dvector3D(90,0,0);
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
	dvector3D rota = dvector3D(90,0,0);
	nodo->setPosicion(*getFather()->getPosition());
	nodo->setRotacion(rota);
}

void render::anyadirArma(){
//    if(nodo != NULL)
//        nodo->setPortatil(ventana::Instance()->getSceneManager()->addCubeSceneNode(0.5f, nodo->_getNode(), -1, vector3df(1,1,-1), vector3df(0,0,0), vector3df(1,1,1)));
}

void render::setNodeTexture(char* filename){
    if(nodo != nullptr){
         nodo->setTextura(filename);
    }
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
    nodo = nullptr;
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
 
        
	}
	if(camara != nullptr){
		dvector3D act( (next_pos.x - prev_pos.x) * interpolation + prev_pos.x, (next_pos.y - prev_pos.y) * interpolation + prev_pos.y, (next_pos.z - prev_pos.z) * interpolation + prev_pos.z);
		
		setCamPos(act);
		setCamTarget(act-static_cast<Camera*>(getFather())->getOffset());
	}
}

void render::endDraw() {
	vent->endDraw();
}

void render::addCamera(dvector3D &p, dvector3D &l){
	camara = engine->crearCamara(NULL);
    engine->setActiveCam(camara->getID());
	camara->setPosicion(p);
	camara->setCamTarget(l);
	camara->setNearValue(1);
	camara->setFarValue(100);
	luz = engine->crearLuz(camara);
	luz->setAmbient(0.7);
	luz->setDiffuse(1.0);
	dvector3D c(-10,18,10);
	luz->setPosicion(c);
	luz->setLightDirection(dvector3D(7,-5,-20));
}

void render::closeWindow(){
	vent->deviceDrop();
}

void render::CreateGround(int alto, int ancho){
	
	nodo_suelo = creaNodo("3d/cesped.obj", "", tMallaEstatica, nullptr);
	dvector3D m((alto/2.f)-0.5, (ancho/2.f)-0.5, -0.1);
	nodo_suelo->setPosicion(m);
	m = dvector3D(alto, ancho, 0);
	nodo_suelo->escalar(m);
	m = dvector3D(90,0,0);
	nodo_suelo->rotar(m);
     
}

void render::dibujarMuro(int *tilemap,int anchoMapa, int altoMapa){
	SkyMalla* aux;
	char* tex = "3d/rocas.png";
	int h1 = altoMapa;
	int w1 = anchoMapa;
    dvector3D m;
	
	size_t size = altoMapa*anchoMapa,it;
	
	for(it=0;it<size;it++){
		if(tilemap[it] == 1 || tilemap[it] == 20){
			int y = (int) it / (anchoMapa);
			int x = (int) it % (anchoMapa);
			
            if(tilemap[it] == 1)
				aux = creaNodo("3d/muros.obj", "", tMallaEstatica, NULL);
            else
				aux = creaNodo("3d/arbusto.obj", "", tMallaEstatica, NULL);
			m = dvector3D(x,y,-0.1);
			aux->setPosicion(m);
			all_nodos.push_back(aux);
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

