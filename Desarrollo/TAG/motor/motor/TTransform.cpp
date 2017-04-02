//
//  TTransform.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 7/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "TTransform.hpp"

TTransform::TTransform(){
	pila = Pila::Instance();
}

TTransform::~TTransform(){
	pila = nullptr;
}

void TTransform::identidad(){
	matriz = glm::mat4();
}

void TTransform::cargar(glm::mat4 &m){
	matriz = m;
}

void TTransform::trasponer(){
	matriz = glm::transpose(matriz);
}

void TTransform::setPosicion(dvector3D &pos){
	glm::vec3 p = glmConv::v3d2glm(pos);
	matriz = glm::translate(glm::mat4(1.0f), p);
}

void TTransform::trasladar(dvector3D &pos){
	glm::vec3 p = glmConv::v3d2glm(pos);
	matriz = glm::translate(matriz, p);
}

void TTransform::setRotacion(dvector3D &rot){
	glm::mat4 m(1.0f);
	glm::vec3 r = glmConv::v3d2glm(rot);
	aplicarRotacion(m, r);
}

void TTransform::rotar(dvector3D &rot){
	glm::vec3 r = glmConv::v3d2glm(rot);
	aplicarRotacion(matriz, r);
}

void TTransform::aplicarRotacion(const glm::mat4 &m, glm::vec3 &rot){
	if (rot.z != 0.0f)
		matriz = glm::rotate(m, glm::radians(rot.z), glm::vec3(0.0f, 0.0f, 1.0f));
	
	if (rot.y != 0.0f)
		matriz = glm::rotate(m, glm::radians(rot.y), glm::vec3(0.0f, 1.0f, 0.0f));
	
	if (rot.x != 0.0f)
		matriz = glm::rotate(m, glm::radians(rot.x), glm::vec3(1.0f, 0.0f, 0.0f));
}

void TTransform::escalar(dvector3D &esc){
	glm::vec3 e = glmConv::v3d2glm(esc);
	matriz = glm::scale(matriz, e);
}

void TTransform::beginDraw(){
	//IMPORTANTE: siempre postorden
	pila->push(pila->actual);
	pila->actual = pila->actual * matriz;
//	printf("BEGIN DRAW Transform\n");
}

void TTransform::endDraw(){
	pila->actual = *pila->pop();
//	printf("END DRAW Transform\n");
}


