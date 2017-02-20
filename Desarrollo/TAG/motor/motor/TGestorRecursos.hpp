//
//  TGestorRecursos.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 15/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TGestorRecursos_hpp
#define TGestorRecursos_hpp

#include <vector>
#include "TRecurso.hpp"
#include "TRecursoMalla.hpp"

class TGestorRecursos{
public:
	TGestorRecursos();
	~TGestorRecursos();
	TRecurso* getRecurso(char* name);
	
private:
	std::vector<TRecurso*> recursos;
	TRecurso* buscarRecurso(char* name);
};

#endif /* TGestorRecursos_hpp */
