//
//  TTransform.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 7/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef TTransform_hpp
#define TTransform_hpp

#include "TEntidad.hpp"

class TTransform : public TEntidad{
public:
	TTransform();
	~TTransform();
	void identidad();
	void cargar(glm::mat4 &m);
	void trasponer();
	
	void setPosicion(glm::vec3 pos);
	void trasladar(glm::vec3 pos);
	void rotar(glm::vec3 rot);
	void escalar(glm::vec3 esc);
	
	glm::mat4 getMT() { return matriz; }
	void beginDraw();
	void endDraw();
private:
	glm::mat4 matriz;
	Pila* pila;
};

#endif /* TTransform_hpp */
