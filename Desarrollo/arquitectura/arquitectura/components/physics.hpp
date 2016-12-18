
#ifndef physics_hpp
#define physics_hpp

#include <stdio.h>
#include "component.hpp"
#include <Box2D/Box2D.h>
#include "../mundoBox2D.hpp"

class physics : public component {
public:
    physics();
    ~physics();
    void crearBodyDinamico(float* dimension, float* posicion);
	void crearBodyEstatico(float* dimension, float* posicion, float rotacion);
//    void update(float* anguloFinal, float* angulo, float* mousePosition);
	void update();
	
	void setPosition(float* pos);
	
	void setVelocity(float* vel);
	float rotarConRaton(float* posRaton);
	void rotar(float anguloRotacion);
private:
    b2Body *body;
    float rotacion, velocidad[2], angulo_disparo[2];
	
};
#endif /* physics_hpp */
