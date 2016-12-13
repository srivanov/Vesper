
#include "bala.hpp"

bala::bala(float* pos, float* dir){
    component* aux = new class render();
    this->insertComponent((char*)"render", aux);
    aux = new physics();
    this->insertComponent((char*)"physics", aux);
    aux = new transform3D();
    this->insertComponent((char*)"transform3D", aux);
    
    std::map<char*,component*>::iterator iter = this->getIteradorBegin();
    while(iter != this->getIteradorEnd()){
        iter->second->setFather(this);
        iter++;
    }
    setRenderizable(true);
    physics* fisica = (physics*)findComponent("physics");
    fisica->crearBodyDinamico(new float[2]{0.1,0.1}, pos);
	
	direccion = new float[2]{0,0};
	direccion[0] = dir[0];
	direccion[1] = dir[1];
	
}

bala::~bala(){
    
}

float* bala::getDireccion(){
	return direccion;
}
