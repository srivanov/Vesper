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
	
	void setPosicion(dvector3D &pos);
	void setRotacion(dvector3D &rot);
	void trasladar(dvector3D &pos);
	void rotar(dvector3D &rot);
	void escalar(dvector3D &esc);
	
	glm::mat4 getMT() { return matriz; }
	void beginDraw(bool pass);
	void endDraw(bool pass);
private:
	void aplicarRotacion(const glm::mat4 &m, glm::vec3 &rot);
	glm::mat4 matriz;
	Pila* pila;
};

#endif /* TTransform_hpp */
