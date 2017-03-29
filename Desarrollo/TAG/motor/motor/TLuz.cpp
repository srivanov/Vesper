//
//  TLuz.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 7/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "TLuz.hpp"
#include "TNodo.hpp"

TLuz::TLuz() : ID(0){
	pos = glm::vec3();
	sh = ShaderManager::Instance()->getActivo();
    lambient = 0.15f;
    ldiffuse = 2.5f;
    lspecular = 1.0f;
}

TLuz::~TLuz(){
	sh = nullptr;
}

void TLuz::setIntensidad(glm::vec4 c){
	color = c;
}

glm::vec4 TLuz::getIntensidad(){
	return color;
}

void TLuz::Draw(TNodo* n){
	
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
	pos = glm::column(matriz, 3);
//	printf("LUZ:         %.1f %.1f %.1f \n", pos.x, pos.y, pos.z);
	glUniform3f(glGetUniformLocation(sh->Program, "light.position"), pos.x, pos.y, pos.z);
	
	//propiedades de la luz
	glUniform3f(glGetUniformLocation(sh->Program, "light.ambient"),   lambient, lambient, lambient);
	glUniform3f(glGetUniformLocation(sh->Program, "light.diffuse"),   ldiffuse, ldiffuse, ldiffuse);
	glUniform3f(glGetUniformLocation(sh->Program, "light.specular"),  lspecular, lspecular, lspecular);
	glUniform1f(glGetUniformLocation(sh->Program, "light.constant"),  1.0f);
	glUniform1f(glGetUniformLocation(sh->Program, "light.linear"),    0.09);
	glUniform1f(glGetUniformLocation(sh->Program, "light.quadratic"), 0.032);
}
