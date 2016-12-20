
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
	fisica->crearBodyDinamico(new float[2]{0.1,0.1}, new float[2]{pos[0]+dir[0], pos[1]+dir[1]});
	
	direccion = new float[2]{0,0};
	direccion[0] = dir[0];
	direccion[1] = dir[1];
	tiempo_vida = time(NULL);
	muerto = false;
}

bala::~bala(){
	class render* ren = (class render*)findComponent("render");
	if(ren != NULL)
		ren->deleteNode();
}

float* bala::getDireccion(){
	return direccion;
}

void bala::update(){
	if(difftime(time(NULL), tiempo_vida) >= 3.0 && muerto == false)
		muerto = true;
}

bool bala::muero(){
	return muerto;
}
