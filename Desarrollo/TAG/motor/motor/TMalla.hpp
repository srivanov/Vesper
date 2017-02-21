//
//  TMalla.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 14/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TMalla_hpp
#define TMalla_hpp

#include <stdio.h>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Pila.h"
#include "TEntidad.hpp"
#include "TRecursoMalla.hpp"
#include "Shader.h"
#include "TGestorRecursos.hpp"

class TMalla : public TEntidad{
public:
	TMalla();
	~TMalla();
	void cargarMalla(std::string fichero);
	
	void beginDraw();
	void endDraw();
	//sucia
	Shader* sh;
private:
	TRecursoMalla* malla;
	Pila* pila;
	TGestorRecursos* gestor;
};

#endif /* TMalla_hpp */
