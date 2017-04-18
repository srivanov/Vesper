
#include "ataque.hpp"
#include "../objetos/PhysicObjects/Bala.hpp"
#include "../objetos/PhysicObjects/Actores/Enemy.hpp"

ataque::ataque() : attack(nullptr){t.start();}

ataque::~ataque(){
    if(attack) delete attack;
}

void ataque::update(){
    if(attack->Eliminable()){
        delete attack;
        attack = nullptr;
    }
    if(attack)
        attack->update();
}

void ataque::atacarDistancia(){
    if(t.tTranscurrido(2.0f) && !attack){
        Enemy * E = static_cast<Enemy*>(getFather());
        attack = new Bala(*E->getPosition(),*E->getDirDisparo(),1.f,4.f);
        t.reset();
        printf("ATACO");
    }
}
