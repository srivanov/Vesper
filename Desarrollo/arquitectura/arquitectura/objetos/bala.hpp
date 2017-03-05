
#ifndef bala_hpp
#define bala_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "../Dvector.hpp"
#include "../tiempo.h"

class bala : public GameObject{
public:
    bala(dvector3D pos, dvector3D &dir, float vel);
    ~bala();
	dvector3D* getDireccion();
	void update();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const getmuero();
private:
	dvector3D direccion;
	tiempo temp;
	float tiempo_vida, velocidad;
    bool muero;
};
#endif /* bala_hpp */
