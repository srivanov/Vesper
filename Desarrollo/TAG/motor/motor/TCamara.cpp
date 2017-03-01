//
//  TCamara.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 7/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "TCamara.hpp"
#include "TNodo.hpp"

TCamara::TCamara() : ID(0), Zoom(ZOOM){
	esPerspectiva = true;
	nearV = 0.1f;
	farV = 20.0f;
}

TCamara::~TCamara(){
	sh = nullptr;
}

void TCamara::setPerspectiva(){
	
	esPerspectiva = true;
}

void TCamara::setParalela(){
	
	esPerspectiva = false;
}

void TCamara::setNearValue(float n){
	nearV = n;
}

void TCamara::setFarValue(float f){
	farV = f;
}

void TCamara::Draw(TNodo* n){
	
	
	while(n->getPadre()){
		n = n->getPadre();
		if(n->getEntidad())
			trans.push(n->getEntidad()->getMT());
	}
	
	glm::mat4 aux;
	matriz = glm::mat4();
	
	while(trans.size() > 0){
		aux = trans.top();
		matriz = matriz * aux;
		trans.pop();
	}
	
	matriz = glm::inverse(matriz);
//	glm::vec3 pos = glm::column(matriz, 3);
//	matriz = glm::lookAt(pos, pos + glm::vec3(0,0,-1), glm::vec3(0,1,0));
	
	glUniformMatrix4fv(glGetUniformLocation(sh->Program, "view"), 1, GL_FALSE, glm::value_ptr(matriz));
	
	projection = glm::perspective(glm::radians(Zoom), (GLfloat)w/(GLfloat)h, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(sh->Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	
//	matriz = glm::inverse(matriz);
//	for (int i=0; i<matriz.length(); i++) {
//		printf("%.1f %.1f %.1f %.1f \n",matriz[i].x,matriz[i].y,matriz[i].z,matriz[i].w);
//	}
//	std::cout << std::endl;
}


