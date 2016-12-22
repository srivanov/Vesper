
#ifndef bala_hpp
#define bala_hpp

#include <stdio.h>
#include "GameObject.hpp"

class bala : public GameObject{
public:
    bala(float* pos, float* dir);
    ~bala();
	float* getDireccion();
	void update();
	bool muero();
private:
	float* direccion;
	time_t tiempo_vida;
	bool muerto;
};
#endif /* bala_hpp */
