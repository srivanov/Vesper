//
//  TMalla.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 14/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "TMalla.hpp"

TMalla::TMalla(){
	pila = Pila::Instance();
	gestor = TGestorRecursos::Instance();
	malla = NULL;
	sh = ShaderManager::Instance()->getActivo();
}

TMalla::~TMalla(){
	sh = nullptr;
	pila = nullptr;
	malla = nullptr;
	gestor = nullptr;
}

void TMalla::cargarMalla(std::string fichero){
	malla = static_cast<TRecursoMalla*>(gestor->getRecurso(fichero, tRMalla));
}

void TMalla::setTextura(std::string &fichero){
	malla->setTexture(fichero);
}

void TMalla::beginDraw(){
	glUniformMatrix4fv(glGetUniformLocation(sh->Program, "model"), 1, GL_FALSE, glm::value_ptr(pila->actual));
	malla->Draw(sh);
//	printf("BEGIN DRAW Malla\n");

//	for (int i=0; i<pila->actual.length(); i++) {
//		printf("%.1f %.1f %.1f %.1f \n",pila->actual[i].x,pila->actual[i].y,pila->actual[i].z,pila->actual[i].w);
//	}
//	std::cout << std::endl;
}

void TMalla::endDraw(){
//	printf("END DRAW Malla\n");
}
