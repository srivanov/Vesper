
#include "bala.hpp"

bala::bala(dvector3D &pos, dvector3D &dir, float vel){
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
    
    dvector3D dim(0.1, 0.1, 0);

    pos.x += dir.x*1.5f;
    pos.y += dir.y*1.5f;
    pos.z = 0;
    
	fisica->crearBodyDinamico(dim, pos);
	
	velocidad = 3.0f;
    
	direccion.x = dir.x * velocidad;
	direccion.y = dir.y * velocidad;
//	printf("%2.f %.2f\n", dir[0], dir[1]);
	intervalo = clock();
	tiempo_vida = vel;
	muero = false;
	aux = NULL;
	setType(tBALA);
    GameObject::update();
    position = new dvector3D(getPosicion()->x,getPosicion()->y,getPosicion()->z);
    trigger_system::_instance()->add_trigger(P_RUIDO, time(NULL),position, 100, 5);
}

bala::~bala(){
	class render* ren = (class render*)findComponent("render");
    if (ren != NULL)
		ren->deleteNode();
}

dvector3D* bala::getDireccion(){
	return &direccion;
}

void bala::update(){
    
    //TO DO: no crear y eliminar memoria de las balas, simplemente activar y desactivarlas
    
	//	std::map<char*, component>::iterator iter = components.begin();
	//	while (iter != components.end()) {
	//		iter->second.update();
	//		iter++;
	//	}
//	if(difftime(time(NULL), tiempo_vida) >= 3.0 && muerto == false)
	GameObject::update();
	if(2000.0 * (clock() - intervalo) / CLOCKS_PER_SEC >= tiempo_vida*1000.0 && muero == false)
		muero = true;
}

bool const* bala::getmuero(){
	return &muero;
}

void bala::contacto(GameObject *g){
//    if(*g->getType() == tENEMIGOS){
//        muero = true;
//    }
}

void bala::contactoEnd(GameObject *g){
    
}
