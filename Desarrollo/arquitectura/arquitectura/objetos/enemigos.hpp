
#ifndef enemigos_hpp
#define enemigos_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "estados.hpp"
#include <time.h>
#include <stdlib.h>
#include "../Dvector.hpp"

class enemigos : public GameObject{
public:
    enemigos(int& ID);
    ~enemigos();
	void update();
private:
    int k ; // GUARRRADA!!!
    estados * STD;
	int ID;
	unsigned int salud, sed, hambre;
    unsigned int estado;
};
#endif /* enemigos_hpp */
