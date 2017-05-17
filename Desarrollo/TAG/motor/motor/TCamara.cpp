//
//  TCamara.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 7/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "TCamara.hpp"
#include "TNodo.hpp"
#include "SkyWindow.hpp"

TCamara::TCamara() : ID(0), Zoom(ZOOM), nearV(0.1f), farV(20.0f){
	esPerspectiva = true;
	sh = ShaderManager::Instance()->getActivo();
	tam = SkyWindow::Instance()->getSIZE();
	calcularProyection();
	pila = Pila::Instance();
}

TCamara::~TCamara(){
	
}

void TCamara::setPerspectiva(){
	
	esPerspectiva = true;
}

void TCamara::setParalela(){
	
	esPerspectiva = false;
}

void TCamara::setNearValue(float n){
	nearV = n;
	calcularProyection();
}

void TCamara::setFarValue(float f){
	farV = f;
	calcularProyection();
}

void TCamara::Draw(TNodo* n){
	
	TNodo* nod = n;
	while(nod->getPadre()){
		nod = nod->getPadre();
		if(nod->getEntidad())
			trans.push(nod->getEntidad()->getMT());
	}
	
	glm::mat4 aux;
	matriz = glm::mat4();
	
	while(trans.size() > 0){
		aux = trans.top();
		matriz = matriz * aux;
		trans.pop();
	}
	sh = ShaderManager::Instance()->getActivo();
	glUniform3f(glGetUniformLocation(sh->Program, "viewPos"),matriz[3].x,matriz[3].y,matriz[3].z);
	matriz = glm::inverse(matriz);
//	glm::vec3 pos = glm::column(matriz, 3);
//	matriz = glm::lookAt(pos, pos + glm::vec3(0,0,-1), glm::vec3(0,1,0));
	
	pila->mView = matriz;
	pila->mProjection = projection;
	
	
//	glUniformMatrix4fv(glGetUniformLocation(sh->Program, "view"), 1, GL_FALSE, glm::value_ptr(matriz));
//	
//	glUniformMatrix4fv(glGetUniformLocation(sh->Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	
//	matriz = glm::inverse(matriz);
//	for (int i=0; i<matriz.length(); i++) {
//		printf("%.1f %.1f %.1f %.1f \n",matriz[i].x,matriz[i].y,matriz[i].z,matriz[i].w);
//	}
//	std::cout << std::endl;
}


