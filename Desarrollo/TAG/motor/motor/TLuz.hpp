//
//  TLuz.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 7/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TLuz_hpp
#define TLuz_hpp

#include <stdio.h>
#include "TEntidad.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class TLuz : public TEntidad{
public:
	TLuz();
	~TLuz();
	void setIntensidad(glm::vec4 c);
	glm::vec4 getIntensidad();
	
	void beginDraw();
	void endDraw();
private:
	glm::vec4 color;
};

#endif /* TLuz_hpp */
