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

void TTransform::trasladar(glm::vec3 pos){
	matriz = glm::translate(matriz, pos);
}

void TTransform::rotar(glm::vec3 rot){
	if (rot.z != 0.0f)
		matriz = glm::rotate(matriz, glm::radians(rot.z), glm::vec3(0.0f, 0.0f, 1.0f));
	
	if (rot.y != 0.0f)
		matriz = glm::rotate(matriz, glm::radians(rot.y), glm::vec3(0.0f, 1.0f, 0.0f));
	
	if (rot.x != 0.0f)
		matriz = glm::rotate(matriz, glm::radians(rot.x), glm::vec3(1.0f, 0.0f, 0.0f));
}

void TTransform::escalar(glm::vec3 esc){
	matriz = glm::scale(matriz, esc);
}

void TTransform::beginDraw(){
	//TO DO: mirar si es preorden o postorden
	pila->push(matriz);
	pila->actual = pila->actual * *pila->top();
//	printf("BEGIN DRAW Transform\n");
}

void TTransform::endDraw(){
	pila->actual = *pila->pop();
//	printf("END DRAW Transform\n");
}


