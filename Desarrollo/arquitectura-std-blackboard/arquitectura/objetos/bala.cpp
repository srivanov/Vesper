
#include "bala.hpp"

bala::bala(float* pos, float* dir, float vel){
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
	
	velocidad = 3.0f;
	direccion[0] = dir[0] * velocidad;
	direccion[1] = dir[1] * velocidad;
//	printf("%2.f %.2f\n", dir[0], dir[1]);
	intervalo = clock();
	tiempo_vida = vel;
	muerto = false;
	aux = NULL;
	delete aux;
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
	//	std::map<char*, component>::iterator iter = components.begin();
	//	while (iter != components.end()) {
	//		iter->second.update();
	//		iter++;
	//	}
//	if(difftime(time(NULL), tiempo_vida) >= 3.0 && muerto == false)
	GameObject::update();
	if(2000.0 * (clock() - intervalo) / CLOCKS_PER_SEC >= tiempo_vida*1000.0 && muerto == false)
		muerto = true;
}

bool bala::muero(){
	return muerto;
}
