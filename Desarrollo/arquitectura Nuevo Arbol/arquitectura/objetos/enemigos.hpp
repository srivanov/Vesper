
#ifndef enemigos_hpp
#define enemigos_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "estados.hpp"
#include <stdlib.h>
#include "NpcLibrary.hpp"

class Personal_BlackBoard;

class enemigos : public GameObject{
public:
    enemigos(int& ID);
    ~enemigos();
	void update();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const* getmuero();
	int&  getID(){return m_ID;}
private:
    int k ; // GUARRRADA!!!
    estados * STD;
	int m_ID;
    bool muero;
	
	NpcBook * book;
};
#endif /* enemigos_hpp */
