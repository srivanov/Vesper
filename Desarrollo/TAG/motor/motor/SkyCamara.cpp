//
//  SkyCamara.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 5/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "SkyCamara.hpp"

SkyCamara::SkyCamara(TNodo* padre, int ID){
	buildTransform();
	nodo = new TNodo();
	m_camara = new TCamara();
	m_camara->setID(ID);
	front = dvector3D(0,0,-1);
	nodo->setEntidad(m_camara);
	TransNodos[0]->addHijo(nodo);
	padre->addHijo(TransNodos[2]);
	
	glm::mat4 m = glm::lookAt(glmConv::v3d2glm(posicion), glmConv::v3d2glm(posicion+front), glm::vec3(0,1,0));
	Trans[0]->cargar(m);
}

SkyCamara::~SkyCamara(){
	
}

void SkyCamara::setNearValue(float n){
	m_camara->setNearValue(n);
}

void SkyCamara::setFarValue(float f){
	m_camara->setFarValue(f);
}

void SkyCamara::setCamTarget(dvector3D &tar){
	camTarget = tar;
	rotateToTarget(camTarget);
}

void SkyCamara::rotateToTarget(dvector3D &tar){
	glm::vec3 pos = glmConv::v3d2glm(posicion), target = glmConv::v3d2glm(tar);
	glm::mat4 m = glm::lookAt(pos, target, glm::vec3(0,1,0));
	m = glm::inverse(m);
	m[3] = glm::vec4(0,0,0,1);
	Trans[0]->cargar(m);
}


