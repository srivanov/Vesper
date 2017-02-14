//
//  TMalla.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 13/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TMalla_hpp
#define TMalla_hpp

#include <stdio.h>
#include <string>

#include "TEntidad.hpp"


class TMalla : public TEntidad{
public:
	TMalla();
	~TMalla();
	void cargarMalla(std::string fichero);
	
	void beginDraw();
	void endDraw();
	
private:
	
};

#endif /* TMalla_hpp */
