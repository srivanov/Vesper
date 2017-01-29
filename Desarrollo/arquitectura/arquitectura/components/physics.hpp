
#ifndef physics_hpp
#define physics_hpp

#include <stdio.h>
#include "component.hpp"
#include <Box2D/Box2D.h>
#include "../mundoBox2D.hpp"
#include "../Dvector.hpp"

class physics : public component {
public:
    physics();
    ~physics();
    void crearBodyDinamico(dvector3D &dimension, dvector3D &posicion);
	void crearBodyEstatico(dvector3D &dimension, dvector3D &posicion, float rotacion);
//    void update(float* anguloFinal, float* angulo, float* mousePosition);
	void update();
	
	void setPosition(dvector3D &pos);
	
	void setVelocity(dvector3D &veloc);
	float rotarConRaton(dvector3D &posRaton);
	void rotar(float anguloRotacion);
private:
    b2Body *body;
    float rotacion;
    b2Vec2 vel;
    dvector3D angulo_disparo;
	
};
#endif /* physics_hpp */
