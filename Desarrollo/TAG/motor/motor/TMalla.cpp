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
	sh = ShaderManager::Instance();
	malla = NULL;
	textura = nullptr;
	
}

TMalla::~TMalla(){
	sh = nullptr;
	pila = nullptr;
	malla = nullptr;
	gestor = nullptr;
}

void TMalla::cargarMalla(char* fichero){
	malla = static_cast<TRecursoMalla*>(gestor->getRecurso(fichero, tRMalla));
}

void TMalla::setTextura(char* fichero){
	textura = static_cast<TRecursoTextura*>(gestor->getRecurso(fichero, tRTextura));
}

void TMalla::beginDraw(){
	Shader* s = sh->getActivo();
	pila->calculaMVP();
	pila->calculoFrustum();
	bool control = pila->AABB_Frustum_Test(malla->getminBB(), malla->getmaxBB());
	
//	if(control == false)
//		printf("ESTOY FUERA %d\n", rand());
	
	glUniformMatrix4fv(glGetUniformLocation(s->Program, "model"), 1, GL_FALSE, glm::value_ptr(pila->actual));
	glUniformMatrix4fv(glGetUniformLocation(s->Program, "MVP"), 1, GL_FALSE, glm::value_ptr(pila->MVP));
	
	if(control){
		if(textura)
			malla->Draw(s, textura->getTexture());
		else
			malla->Draw(s, nullptr);
	}
}

void TMalla::endDraw(){
//	printf("END DRAW Malla\n");
}


