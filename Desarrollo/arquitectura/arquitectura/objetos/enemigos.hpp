
#ifndef enemigos_hpp
#define enemigos_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "estados.hpp"
#include <time.h>
#include <stdlib.h>
#include "../Dvector.hpp"

class Personal_BlackBoard;

class enemigos : public GameObject{
public:
    enemigos(int& ID);
    ~enemigos();
	void update();
    int * getID(){return &ID;}
    void notify(dvector3D& position, int type);
    bool EventUsed(int type);
private:
    int k ; // GUARRRADA!!!
    estados * STD;
	int ID;
	unsigned int salud, sed, hambre;
    unsigned int estado;
    
    Personal_BlackBoard * book;
};
#endif /* enemigos_hpp */
