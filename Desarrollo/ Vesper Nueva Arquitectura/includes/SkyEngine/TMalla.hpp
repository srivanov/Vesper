//
//  TMalla.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 14/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TMalla_hpp
#define TMalla_hpp

#include <string>

#include "TEntidad.hpp"
#include "TRecursoMalla.hpp"
#include "ShaderManager.hpp"
#include "TGestorRecursos.hpp"

class TMalla : public TEntidad{
public:
	TMalla();
	~TMalla();
	void cargarMalla(std::string fichero);
	void setTextura(std::string &fichero);
	
	
	void beginDraw();
	void endDraw();
	
private:
	Shader* sh;
	TRecursoMalla* malla;
	Pila* pila;
	TGestorRecursos* gestor;
};

#endif /* TMalla_hpp */
