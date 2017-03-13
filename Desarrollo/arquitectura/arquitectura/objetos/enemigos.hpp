
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
    enemigos();
    ~enemigos();
	void update();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const* getmuero();
	int * getID(){return &ID;}
	void notify(dvector3D& position, int type);
	bool EventUsed(int type);
private:
    int k ; // GUARRRADA!!!
    estados * STD;
	//TO DO: estaria bien cambiar salud a INT para un mejor ajuste en el combate jaja, que PRO suena. Soy Stoycho por si el que lo leo se caga en mi jajaja SALUDOS
	unsigned int salud, sed, hambre;
    unsigned int estado;
    bool muero;
	
	Personal_BlackBoard * book;
};
#endif /* enemigos_hpp */
