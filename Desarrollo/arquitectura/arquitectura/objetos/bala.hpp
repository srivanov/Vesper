
#ifndef bala_hpp
#define bala_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "../Dvector.hpp"

class bala : public GameObject{
public:
    bala(dvector3D &pos, dvector3D &dir, float vel);
    ~bala();
	dvector3D* getDireccion();
	void update();
	bool muero();
private:
	dvector3D direccion;
	time_t intervalo;
	float tiempo_vida, velocidad;
	bool muerto;
    int ID;
};
#endif /* bala_hpp */
