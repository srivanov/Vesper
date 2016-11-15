//
//  DecisionSystem.hpp
//  Sistema de Decision
//
//  Created by Gaspar Rodriguez Valero on 8/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef DecisionSystem_hpp
#define DecisionSystem_hpp

#include <stdio.h>
#include <iostream>
#include "Vstate.hpp"

#define VIDA 0
#define COMIDA 2
#define AGUA 1

using namespace std;

class DecisionSystem{
public:
    DecisionSystem();
    void updateDecision();
    // FUNCIONES PARA LAS PRUEBAS
    int getLife() const {return Vestado->getLife();}
    int getThirst() const{return Vestado->getThirst();}
    int getHungry() const{return Vestado->getHungry();}
    int getCalculo() const{return Vestado->calculate();}
    void necesidad(int need){
        switch (need) {
            case VIDA:Vestado->heal();cout << "Me curo" <<endl;break;
            case COMIDA:Vestado->eat();cout << "He comido" <<endl;break;
            case AGUA:Vestado->drink();cout << "He bebido" <<endl;break;
            default:break;
        }
    }
private:
    void standar();
    void suspect();
    void alert();
    void inCombat();
    void frightened();
    int state,lastState;
    Vstate* Vestado;
    int sensor; // VARIABLE PROVISIONAL HASTA CREAR EL SENSOR REAL
    int* tiempo; // VARIABLE PROVISIONAL HASTA CREAR VARIABLE TIEMPO REAL
};

#endif /* DecisionSystem_hpp */
