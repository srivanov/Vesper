
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
	fisica->crearBodyDinamico(new float[2]{(float)(0.1),(float)(0.1)}, new float[2]{pos[0]+dir[0]*1.5f, pos[1]+dir[1]*1.5f});
	
	direccion[0] = dir[0];
	direccion[1] = dir[1];
	tiempo_vida = clock();
	muerto = false;
}

bala::~bala(){
//	printf("DELETE bala\n");
//	delete direccion;
	class render* ren = (class render*)findComponent("render");
	if (ren != NULL)
		ren->deleteNode();

}

float* bala::getDireccion(){
	return direccion;
}

void bala::update(){
//	if(difftime(time(NULL), tiempo_vida) >= 3.0 && muerto == false)
	if(2000.0 * (clock()-tiempo_vida) / CLOCKS_PER_SEC >= 3000.0 && muerto == false)
		muerto = true;
}

bool bala::muero(){
	return muerto;
}
