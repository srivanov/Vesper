
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
    void contacto(GameObject* g);
    bool const* getmuero();
private:
    int k ; // GUARRRADA!!!
    estados * STD;
	int ID;
	unsigned int salud, sed, hambre;
    unsigned int estado;
    bool muero;
};
#endif /* enemigos_hpp */
