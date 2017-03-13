
#ifndef enemigos_hpp
#define enemigos_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "../PathFinding/PathPlanning.hpp"
#include <stdlib.h>
#include "../Arquitectura IA/NpcLibrary.hpp"
#include "../Sistema de Decision/Behaviour_tree2.hpp"

class Personal_BlackBoard;

class enemigos : public GameObject{
public:
    enemigos();
    ~enemigos();
	void update();
    void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const* getmuero();
	int&  getID(){return ID;}
private:
    int k ; // GUARRRADA!!!
    
    Nodo_base * tree;
    bool muero;
	
	NpcBook * book;
};
#endif /* enemigos_hpp */
