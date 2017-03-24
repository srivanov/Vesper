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

void TTransform::setPosicion(glm::vec3 pos){
	matriz = glm::translate(glm::mat4(1.0f), pos);
}

void TTransform::trasladar(glm::vec3 pos){
	matriz = glm::translate(matriz, pos);
}

void TTransform::setRotacion(glm::vec3 rot){
	glm::mat4 m(1.0f);
	aplicarRotacion(m, rot);
}

void TTransform::rotar(glm::vec3 rot){
	aplicarRotacion(matriz, rot);
}

void TTransform::aplicarRotacion(const glm::mat4 &m, glm::vec3 &rot){
	if (rot.z != 0.0f)
		matriz = glm::rotate(m, glm::radians(rot.z), glm::vec3(0.0f, 0.0f, 1.0f));
	
	if (rot.y != 0.0f)
		matriz = glm::rotate(m, glm::radians(rot.y), glm::vec3(0.0f, 1.0f, 0.0f));
	
	if (rot.x != 0.0f)
		matriz = glm::rotate(m, glm::radians(rot.x), glm::vec3(1.0f, 0.0f, 0.0f));
}

void TTransform::escalar(glm::vec3 esc){
	matriz = glm::scale(matriz, esc);
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


