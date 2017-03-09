
#ifndef transform3D_hpp
#define transform3D_hpp

#include <stdio.h>
#include "component.hpp"
#include "../Dvector.hpp"


class transform3D : public component{
public:
	transform3D();
    ~transform3D();
	void update();
	void setPosition(dvector3D &pos);
	void mover(dvector3D &velocidad);
	float rotarConRaton(dvector3D &rotacion);
	void rotar(float anguloRotacion);

};
#endif /* transform3D_hpp */
