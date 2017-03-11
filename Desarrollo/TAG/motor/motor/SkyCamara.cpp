//
//  SkyCamara.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 5/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "SkyCamara.hpp"

SkyCamara::SkyCamara(TNodo* padre, int ID){
	builTransform();
	nodo = new TNodo();
	m_camara = new TCamara();
	m_camara->setID(ID);
	
	nodo->setEntidad(m_camara);
	TransNodos[0]->addHijo(nodo);
	padre->addHijo(TransNodos[2]);
}

SkyCamara::~SkyCamara(){
	
}

//void SkyCamara::rotar(dvector3D vector){
//	
//	int i=0;
//	TNodo* aux = nodo;
//	while(aux->getPadre() && i<2){
//		aux = aux->getPadre();
//		++i;
//	}
//	static_cast<TTransform*>(aux->getEntidad())->rotar(glmConverter(vector));
//}
