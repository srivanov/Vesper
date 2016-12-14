
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
    void update(float* velocidad, float * posicion, float* anguloFinal, float* angulo, float* mousePosition);
private:
    b2Body *body;
    float angulo[2];
};
#endif /* physics_hpp */
