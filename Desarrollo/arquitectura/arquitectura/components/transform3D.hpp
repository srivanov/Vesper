
#ifndef transform3D_hpp
#define transform3D_hpp

#include <stdio.h>
#include "component.hpp"


class transform3D : public component{
public:
	transform3D();
    ~transform3D();
	void update();
	void setPosition(float* pos);
	void mover(float* velocidad);
	float rotarConRaton(float* rotacion);
	void rotar(float anguloRotacion);

};
#endif /* transform3D_hpp */
