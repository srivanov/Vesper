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
	clip = true;
}

TMalla::~TMalla(){
	sh = nullptr;
	pila = nullptr;
	malla = nullptr;
	gestor = nullptr;
	textura = nullptr;
}

void TMalla::cargarMalla(char* fichero){
	malla = static_cast<TRecursoMalla*>(gestor->getRecurso(fichero, tRMalla));
}

void TMalla::setTextura(char* fichero){
	textura = static_cast<TRecursoTextura*>(gestor->getRecurso(fichero, tRTextura));
}

void TMalla::beginDraw(bool pass){
	Shader* s = sh->getActivo();
	pila->calculaMVP();
	bool control = true;
	if(clip){
		pila->calculoFrustum();
		glm::vec4 min, max;
		
		min = malla->getminBB() * pila->MVP;
		max = malla->getmaxBB() * pila->MVP;
		
		control = pila->AABB_Frustum_Test(min, max);
	}
	
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

void TMalla::endDraw(bool pass){
//	printf("END DRAW Malla\n");
}


