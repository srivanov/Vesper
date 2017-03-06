//
//  TGestorRecursos.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 15/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "TGestorRecursos.hpp"

TGestorRecursos* TGestorRecursos::Instance(){
	static TGestorRecursos pinstance;
	return &pinstance;
}

TGestorRecursos::TGestorRecursos(){
	
}

TGestorRecursos::~TGestorRecursos(){
	for(std::vector<TRecurso*>::iterator it = recursos.begin();it!=recursos.end();++it){
		delete (*it);
		(*it) = 0;
	}
	recursos.clear();
}

TRecurso* TGestorRecursos::getRecurso(std::string &name, typeRecurso tipo){
	TRecurso* rec = buscarRecurso(name, tipo);
	if(rec == NULL){
		if(tipo == tRMalla)
			rec = new TRecursoMalla();
		else if(tipo == tRTextura)
			rec = new TRecursoTextura();
		
		rec->cargarFichero(name);
		rec->SetNombre(name);
		recursos.push_back(rec);
		printf("RECURSOS: %d\n", (int)recursos.size());
	}
	return rec;
}

TRecurso* TGestorRecursos::buscarRecurso(std::string &name, typeRecurso tipo){
	if(recursos.size() > 0){
		for (std::vector<TRecurso*>::iterator it = recursos.begin();it!=recursos.end();++it){
			if((*it)->GetNombre().compare(name) == 0)
				return (*it);
		}
	}
	return NULL;
}
