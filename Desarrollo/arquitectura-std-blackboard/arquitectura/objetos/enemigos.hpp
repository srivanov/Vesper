
#ifndef enemigos_hpp
#define enemigos_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "estados.hpp"
#include <time.h>
#include <stdlib.h>

class enemigos : public GameObject{
public:
    enemigos(int& ID);
    ~enemigos();
	void update();
    void updateValues();
private:
    int k ; // GUARRRADA!!!
    estados * STD;
    dvector3D * posi;
	int ID;
	unsigned int salud, sed, hambre;
    unsigned int estado;
};
#endif /* enemigos_hpp */
