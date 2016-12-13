
#ifndef bala_hpp
#define bala_hpp

#include <stdio.h>
#include "GameObject.hpp"

class bala : public GameObject{
public:
    bala(float* pos, float* dir);
    ~bala();
	float* getDireccion();
private:
	float* direccion;
};
#endif /* bala_hpp */
