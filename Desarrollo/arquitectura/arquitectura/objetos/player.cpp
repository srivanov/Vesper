
#include "player.hpp"

player::player(){
	component* aux = new class render();
	this->insertComponent((char*)"render", aux);
	aux = new input();
	this->insertComponent((char*)"input", aux);
	aux = new physics();
	this->insertComponent((char*)"physics", aux);
	aux = new pala();
    this->insertComponent((char*)"pala", aux);
	aux = new armasArrojadizas();
    this->insertComponent((char*)"armasArrojadizas", aux);
	aux = new piedra();
    this->insertComponent((char*)"piedra", aux);
	aux = new habilidadEspecial();
    this->insertComponent((char*)"habilidadEspecial", aux);
	aux = new martilloDeJuguete();
    this->insertComponent((char*)"martilloDeJuguete", aux);
	aux = new transform3D();
    this->insertComponent((char*)"transform3D", aux);
	aux = new armasDisparo();
    this->insertComponent((char*)"armasDisparo", aux);
	aux = new salud();
    this->insertComponent((char*)"salud", aux);
	
	std::map<char*,component*>::iterator iter = this->getIteradorBegin();
	while(iter != this->getIteradorEnd()){
		iter->second->setFather(this);
		iter++;
	}
	setRenderizable(true);
}

player::~player(){
	
}
