
#ifndef bala_hpp
#define bala_hpp

#include <stdio.h>
#include "GameObject.hpp"

class bala : public GameObject{
public:
    bala(float* pos, float* dir, float vel);
    ~bala();
	float* getDireccion();
	void update();
	bool muero();
private:
	float direccion[2];
	time_t intervalo;
	float tiempo_vida, velocidad;
	bool muerto;
};
#endif /* bala_hpp */
