//
//  TEntidad.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 7/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TEntidad_hpp
#define TEntidad_hpp

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Pila.h"

class TEntidad{
public:
	TEntidad(){}
	virtual ~TEntidad(){}
	virtual void beginDraw()=0;
	virtual void endDraw()=0;
	virtual glm::mat4 getMT(){return glm::mat4();};
};

#endif /* TEntidad_hpp */
