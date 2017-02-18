//
//  TGestorRecursos.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 15/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "TGestorRecursos.hpp"

TGestorRecursos::TGestorRecursos(){
	
}

TGestorRecursos::~TGestorRecursos(){
	
}

TRecurso* TGestorRecursos::getRecurso(char* name){
	TRecurso* rec = buscarRecurso(name);
	if(rec == NULL){
		rec = new TRecurso();
		rec->cargarFichero(name);
		recursos.push_back(rec);
	}
	return rec;
}

TRecurso* TGestorRecursos::buscarRecurso(char* name){
	if(recursos.size() > 0){
		for (std::vector<TRecurso*>::iterator it = recursos.begin();it!=recursos.end();++it){
			if( strcmp((*it)->GetNombre(), name) == 0)
				return (*it);
		}
	}
	return NULL;
}
