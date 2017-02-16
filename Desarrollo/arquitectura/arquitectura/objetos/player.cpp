
#include "player.hpp"
#include "alarma.hpp"
#include "fuente.hpp"
#include "puerta.hpp"

player::player(){
    //TO DO: que se canse al correr
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
	
    obj_colisionado = NULL;
	velocidad = 2;
    muero = false;
    arma = (armas*)findComponent("armas");
    fisica->crearBodyDinamico(dim, pos);
	aux = NULL;
	setType(tPLAYER);
}

player::~player(){
	
}

void player::update(){
    GameObject::update();
    arma->update();
}

void player::render(){
    GameObject::render();
    arma->render();
}

void player::atacar(){
	if(*(arma->getArmaActual()->getType()) == tPALAc)
        cuerpoacuerpo();
    else
        arma->shoot();
}

void player::cambiarArma(){
	arma->changeGun();
    std::cout << *arma->getArmaActual()->getType() << std::endl;
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

void player::contacto(GameObject *g){
    if(*g->getType() == tPALA){
        arma->insertarArma(9);
    }
    if(*g->getType() == tMONEDAS){
        ((habilidadEspecial*)findComponent("habilidadEspecial"))->aumentarMoneda();
    }
    if(*g->getType() == tALARMA){
        
    }
    obj_colisionado = g;
}

void player::contactoEnd(GameObject *g){
    obj_colisionado = NULL;
}

void player::accionar(){
    if(obj_colisionado != NULL){
        if(*obj_colisionado->getType() == tALARMA){
            if(!(static_cast<alarma*>(obj_colisionado)->estaActivado())){
                static_cast<alarma*>(obj_colisionado)->activar();
            }
		}else if(*obj_colisionado->getType() == tPUERTA){
			if(!(static_cast<puerta*>(obj_colisionado))->estasAbierta()){
				static_cast<puerta*>(obj_colisionado)->abre();
			}else
				static_cast<puerta*>(obj_colisionado)->cierra();
		}
    }
}

void player::cuerpoacuerpo(){
    //TO DO: revisar
    if(obj_colisionado != NULL){
        if(*obj_colisionado->getType() == tALARMA){
            if(*(arma->getArmaActual()->getType()) == tPALAc){
                static_cast<alarma*>(obj_colisionado)->muere();
                obj_colisionado = NULL;
            }
        }else if(*obj_colisionado->getType() == tFUENTE){
            if(*(arma->getArmaActual()->getType()) == tPALAc){
                static_cast<fuente*>(obj_colisionado)->muere();
                obj_colisionado = NULL;
            }
        }
    }
}

