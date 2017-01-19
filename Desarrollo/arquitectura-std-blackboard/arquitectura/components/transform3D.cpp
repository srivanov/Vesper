
#include "transform3D.hpp"
#include "../objetos/GameObject.hpp"

transform3D::transform3D(){
	
}

transform3D::~transform3D(){
	
}

void transform3D::update(){
	
}

void transform3D::setPosition(float* pos){
	if(pos != NULL){
		physics* go = (physics*)getFather()->findComponent("physics");
		if(go != NULL){
			go->setPosition(pos);
		}
	}
}

void transform3D::mover(float* velocidad){
	if(velocidad != NULL){
		physics* go = (physics*)getFather()->findComponent("physics");
		if(go != NULL){
			go->setVelocity(velocidad);
		}
	}
}

float transform3D::rotarConRaton(float *rotacion){
	if(rotacion != NULL){
		physics* go = (physics*)getFather()->findComponent("physics");
		if(go != NULL){
			return go->rotarConRaton(rotacion);
		}
	}
	return 0.0f;
}

void transform3D::rotar(float anguloRotacion){
	physics* go = (physics*)getFather()->findComponent("physics");
	if(go != NULL){
		return go->rotar(anguloRotacion);
	}
}
