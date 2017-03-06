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
	TransNodos[2]->setPadre(padre);
}

SkyCamara::~SkyCamara(){
	
}

