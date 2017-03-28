
#include "puerta.hpp"

puerta::puerta(){
	component* aux = new class render();
	this->insertComponent((char*)"render", aux);
	aux = new transform3D();
    this->insertComponent((char*)"transform3D", aux);
	aux = new physics();
	this->insertComponent((char*)"physics", aux);
	
	std::map<char*,component*>::iterator iter = this->getIteradorBegin();
	while(iter != this->getIteradorEnd()){
		iter->second->setFather(this);
		iter++;
	}
	setRenderizable(true);
	
	physics* fisica = (physics*)findComponent("physics");
	
	dvector3D dim(1,1,1);
	dvector3D pos(0,0,0);
	
	fisica->crearBodyEstatico(dim, pos, 90.f);
	
    muero = false;
	abierta = false;
	door = NULL;
	aux = NULL;
	setType(tPUERTA);
}

puerta::~puerta(){
    if(door != NULL)
		delete door;
}

void puerta::update(){
	GameObject::update();
}

void puerta::contacto(GameObject *g){
    if(*g->getType() == tPLAYER){
//        muero = true;
    }
}

void puerta::contactoEnd(GameObject *g){
	
}

bool const* puerta::getmuero(){
    return &muero;
}

void puerta::abre(){
	if(door != NULL)
        if(door->abre()){
			abierta = true;
    		this->setTexture("3d/rojo.png");
        }
}

void puerta::cierra(){
    this->setTexture("3d/puerta.jpg");
	abierta = false;
}

bool puerta::estasAbierta(){
	return abierta;
}

void puerta::setTipo(typePuerta t){
	switch (t) {
//		case tBLINDADA:
//			door = new blindada();
//			break;
//		case tBLOQUEADA:
//			door = new bloqueada();
//			break;
		case tCHIRRIANTE:
			door = new chirriante();
			break;
//		case tCONALARMA:
//			door = new conAlarma();
//			break;
//		case tCONLLAVE:
//			door = new conLlave();
//			break;
//		case tCONPUZZLE:
//			door = new conPuzzle();
//			break;
//		case tDESTRUCTIVA:
//			door = new destructiva();
//			break;
  default:
			break;
	}
}

