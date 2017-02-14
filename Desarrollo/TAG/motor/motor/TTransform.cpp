//
//  TTransform.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 7/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "TTransform.hpp"

TTransform::TTransform(){
	
}

TTransform::~TTransform(){
	
}

void TTransform::identidad(){
	actual = glm::mat4();
}

void TTransform::cargar(glm::mat4 &m){
	actual = m;
}

void TTransform::trasponer(){
	actual = glm::transpose(actual);
}

void TTransform::trasladar(glm::vec3 pos){
	actual = glm::translate(actual, pos);
}

void TTransform::rotar(glm::vec3 rot){
	if (rot.z != 0.0f)
		actual = glm::rotate(actual, glm::radians(rot.z), glm::vec3(0.0f, 0.0f, 1.0f));
	
	if (rot.y != 0.0f)
		actual = glm::rotate(actual, glm::radians(rot.y), glm::vec3(0.0f, 1.0f, 0.0f));
	
	if (rot.x != 0.0f)
		actual = glm::rotate(actual, glm::radians(rot.x), glm::vec3(1.0f, 0.0f, 0.0f));
}

void TTransform::escalar(glm::vec3 esc){
	actual = glm::scale(actual, esc);
}

void TTransform::beginDraw(glm::mat4 &matriz){
	//TO DO: mirar si es preorden o postorden
	actual = actual * matriz;
	pila.push(actual);
	
}

void TTransform::endDraw(){
	actual = pila.top();
	pila.pop();
}


