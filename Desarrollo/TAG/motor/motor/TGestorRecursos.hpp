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
#include "TRecursoTextura.hpp"

class TGestorRecursos{
public:
	static TGestorRecursos* Instance();
	virtual ~TGestorRecursos();
	TRecurso* getRecurso(std::string name, typeRecurso tipo);
	
protected:
	TGestorRecursos();
	
private:
	std::vector<TRecurso*> recursos;
	TRecurso* buscarRecurso(std::string name);
};

#endif /* TGestorRecursos_hpp */
