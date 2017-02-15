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

#include "TEntidad.hpp"
#include "TModelo.hpp"
#include "Shader.h"

class TMalla : public TEntidad{
public:
	TMalla();
	~TMalla();
	void cargarMalla(std::string fichero);
	
	void beginDraw();
	void endDraw();
	Shader* sh;
private:
	TModelo malla;
};

#endif /* TMalla_hpp */
