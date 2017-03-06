//
//  SkyLuz.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 5/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "SkyLuz.hpp"

SkyLuz::SkyLuz(TNodo* padre, int ID){
	builTransform();
	nodo = new TNodo();
	m_luz = new TLuz();
	m_luz->setID(ID);
	
	nodo->setEntidad(m_luz);
	TransNodos[0]->addHijo(nodo);
	TransNodos[2]->setPadre(padre);
}

SkyLuz::~SkyLuz(){
	
}

