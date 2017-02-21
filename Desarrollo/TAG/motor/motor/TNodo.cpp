//
//  TNodo.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 7/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "TNodo.hpp"

TNodo::TNodo(){
	entidad = NULL;
	padre = NULL;
}

TNodo::~TNodo(){
	hijos.clear();
}

int TNodo::addHijo(TNodo* n){
	hijos.push_back(n);
	n->setPadre(this);
	return 0;
}

int TNodo::remHijo(TNodo* n){
	std::vector<TNodo*>::iterator it = std::find(hijos.begin(), hijos.end(), n);
	if(it != hijos.end())
		hijos.erase(it);
	return 0;
}

bool TNodo::setEntidad(TEntidad* en){
	if(entidad != NULL)
		return false;
	entidad = en;
	return true;
}

void TNodo::setPadre(TNodo* p){
	padre = p;
}

void TNodo::Draw(){
	if(entidad != NULL)
		entidad->beginDraw();
	
	for (auto it = hijos.begin(); it != hijos.end(); ++it) {
		(*it)->Draw();
	}
	
	if(entidad != NULL)
		entidad->endDraw();
}


