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
}

TMalla::~TMalla(){
	
}

void TMalla::cargarMalla(std::string fichero){
	malla = static_cast<TRecursoMalla*>(gestor->getRecurso(fichero, tRMalla));
}

void TMalla::beginDraw(){
	glUniformMatrix4fv(glGetUniformLocation(sh->Program, "model"), 1, GL_FALSE, glm::value_ptr(pila->actual));
	malla->Draw(*sh);
//	printf("BEGIN DRAW Malla\n");
}

void TMalla::endDraw(){
//	printf("END DRAW Malla\n");
}
