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
	void cargarMalla(char* fichero);
	void setTextura(char* fichero);
	
	
	void beginDraw(bool pass);
	void endDraw(bool pass);
	void setVisible(){clip=false;}
	
private:
	TRecursoMalla* malla;
	TRecursoTextura* textura;
	Pila* pila;
	TGestorRecursos* gestor;
	bool clip;
};

#endif /* TMalla_hpp */
