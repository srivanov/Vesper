
#include "player.hpp"

player::player(){
	component* aux = new class render();
	this->insertComponent((char*)"render", aux);
	aux = new armas();
	this->insertComponent((char*)"armas", aux);
	aux = new physics();
	this->insertComponent((char*)"physics", aux);

	aux = new habilidadEspecial();
	((habilidadEspecial*)aux)->setTipo(tHabINVISIBLE);
    this->insertComponent((char*)"habilidadEspecial", aux);

	aux = new transform3D();
    this->insertComponent((char*)"transform3D", aux);

	aux = new salud();
    this->insertComponent((char*)"salud", aux);
	
	std::map<char*,component*>::iterator iter = this->getIteradorBegin();
	while(iter != this->getIteradorEnd()){
		iter->second->setFather(this);
		iter++;
	}
	setRenderizable(true);
    physics* fisica = (physics*)findComponent("physics");
    
    dvector3D dim(1,1,1);
    dvector3D pos(0,0,0);
	
	velocidad = 1;
    muero = false;
    arma = (armas*)findComponent("armas");
    fisica->crearBodyDinamico(dim, pos);
	aux = NULL;
	setType(tPLAYER);
}

player::~player(){
	
}

void player::atacar(){
	
	arma->shoot();
}

void player::cambiarArma(){
	arma = (armas*)findComponent("armas");
	arma->changeGun();
}

void player::contacto(GameObject *g){
	if(*g->getType() == tPALA){
        arma->insertarArma(9);
	}
	if(*g->getType() == tMONEDAS){
		((habilidadEspecial*)findComponent("habilidadEspecial"))->aumentarMoneda();
	}
}

bool const* player::getmuero(){
    return &muero;
}

void player::mover(dvector3D &vel){
	vel *= velocidad;
	transform3D* go = (transform3D*)findComponent("transform3D");
	if(go != NULL)
		go->mover(vel);
}

void player::setVelocidad(unsigned int vel){
	velocidad = vel;
}

void player::activarHab(){
	if(habActiva())
		((habilidadEspecial*)findComponent("habilidadEspecial"))->activar();
}

bool player::habActiva(){
	return ((habilidadEspecial*)findComponent("habilidadEspecial"))->puedoUsar();
}

unsigned int* player::getVel(){
    return &velocidad;
}

