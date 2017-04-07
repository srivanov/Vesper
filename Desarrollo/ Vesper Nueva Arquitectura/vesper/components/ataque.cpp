
#include "ataque.hpp"
#include "../objetos/PhysicObjects/Bala.hpp"
#include "../objetos/PhysicObjects/Actores/Enemy.hpp"

ataque::ataque(){
    t.start();
}

ataque::~ataque(){
    
}

void ataque::update(){
	
}

void ataque::atacarDistancia(){
    /*
    if(t.tTranscurrido(2.0f)){
        Enemy * E = static_cast<Enemy*>(getFather());
        Bala * aux = new Bala(*E->getPosition(),*E->getDirDisparo(),1.f,4.f);
        t.reset();
    }
     */
    printf("ATACO");
}
