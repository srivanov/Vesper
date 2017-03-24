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
	
	glm::mat4 m = glm::lookAt(glmConverter(posicion), glmConverter(posicion+front), glm::vec3(0,1,0));
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

//static float prodEsc(dvector3D t, dvector3D p){
//	return t.x*p.x + t.y*p.y + t.z*p.z;
//}
//
//static float modulo(dvector3D p){
//	return std::sqrt((p.x*p.x)+(p.y*p.y)+(p.z*p.z));
//}

void SkyCamara::setCamTarget(dvector3D tar){
	camTarget = tar;
	rotateToTarget(camTarget);
}

void SkyCamara::rotateToTarget(dvector3D tar){
//	dvector3D TC = tar-posicion;
//	dvector3D a = front-posicion;
//	
//	dvector3D b(TC.x, 0, TC.z);
//	
//	float p = prodEsc(a,b), ma = modulo(a), mb = modulo(b);
//	float res = p/(ma * mb);
//	float resX = std::acos(res)*180/3.1415;
//	
//	b = dvector3D(0, TC.y, TC.z);
//	
//	p = prodEsc(a,b); ma = modulo(a); mb = modulo(b);
//	res = p/(ma * mb);
//	float resY = std::acos(res)*180/3.1415;
//	
//	//miramos si los angulos son negativos
//	if(TC.x < 0)
//		resX *= -1;
//	if(TC.y < 0)
//		resY *= -1;
//	
//	printf("EJE X: %.2f\nEJE Y: %.2f\n",resX, resY);
//	dvector3D rfinal(0,resX,0);
//	rotar(rfinal);
	
	glm::mat4 m = glm::lookAt(glmConverter(posicion), glmConverter(tar), glm::vec3(0,1,0));
	m = glm::inverse(m);
	m[3] = glm::vec4(0,0,0,1);
	Trans[0]->cargar(m);
}


