//
//  SkyMalla.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 5/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "SkyMalla.hpp"

SkyMalla::SkyMalla(TNodo* padre, tipoMalla t){
	if(t) buildTransformStatic();
	else buildTransform();
	nodo = new TNodo();
	m_malla = new TMalla();
	
	nodo->setEntidad(m_malla);
	TransNodos[0]->addHijo(nodo);
	padre->addHijo(TransNodos[2]);
}

SkyMalla::~SkyMalla(){
	
}

void SkyMalla::setMalla(std::string fichero){
	m_malla->cargarMalla(fichero);
}

void SkyMalla::setTextura(std::string &fichero){
	m_malla->setTextura(fichero);
}
