
#ifndef physics_hpp
#define physics_hpp

#include <stdio.h>
#include "component.hpp"

#include <Box2D/Box2D.h>
#include "../mundoBox2D.hpp"
#include "../Dvector.hpp"
#include <vector>

class physics : public component {
public:
    physics();
    ~physics();
    void crearBodyDinamico(dvector3D &dimension, dvector3D &posicion);
	void crearBodyEstatico(dvector3D &dimension, dvector3D &posicion, float rotacion);
	void crearBodyKinematico(dvector3D &dimension, dvector3D &posicion, float rotacion);
	void crearObjetosEstaticos(std::vector<dvector2D> &v, std::vector<dvector2D> &p, int ancho, int alto);
	void attachSensor(float radio);
	void update();
	void atarCuerda(b2Body* atado);
	
	void setPosition(dvector3D &pos);
	void setVelocity(dvector3D &veloc);
	float rotarAposicion(dvector3D &posRaton, bool d2 = true);
	void rotar(float anguloRotacion);
    bool RayCastControl(dvector3D posIni,dvector3D posFin);
private:
    b2Body *body, *ata;
    float rotacion;
    b2Vec2 vel;
    dvector3D angulo_disparo;
	bool atar;
	void atarP();
};
#endif /* physics_hpp */
