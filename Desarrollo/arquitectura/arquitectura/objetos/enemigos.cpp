
#include "enemigos.hpp"

enemigos::enemigos(){
	component* aux = new class render();
	this->insertComponent((char*)"render", aux);
	aux = new physics();
	this->insertComponent((char*)"physics", aux);
	aux = new transform3D();
    this->insertComponent((char*)"transform3D", aux);
	aux = new salud();
    this->insertComponent((char*)"salud", aux);
	aux = new IAEnemigos();
    this->insertComponent((char*)"IAEnemigos", aux);
	aux = new sed();
    this->insertComponent((char*)"sed", aux);
	aux = new hambre();
    this->insertComponent((char*)"hambre", aux);
	aux = new ataque();
    this->insertComponent((char*)"ataque", aux);
}

enemigos::~enemigos(){
    
}
