//
//  TTransform.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 7/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TTransform_hpp
#define TTransform_hpp

#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "TEntidad.hpp"

class TTransform : public TEntidad{
public:
	TTransform();
	~TTransform();
	void identidad();
	void cargar(glm::mat4 &m);
	void trasponer();
	
	void trasladar(glm::vec3 pos);
	void rotar(glm::vec3 rot);
	void escalar(glm::vec3 esc);
	
	void beginDraw(glm::mat4 &matriz);
	void endDraw();
private:
	glm::mat4 actual;
	std::stack<glm::mat4> pila;
};

#endif /* TTransform_hpp */
