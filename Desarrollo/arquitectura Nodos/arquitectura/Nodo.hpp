//
//  Nodo.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_hpp
#define Nodo_hpp

#include <stdio.h>
#include <iostream>
#include "NpcLibrary.hpp"
#include "LevelBlackBoard.hpp"

#define RUNNING 2

#define ESTANDAR 0
#define ALERTA 1
#define COMBATE 2

using namespace std;


class Nodo {
public:
    Nodo(){}
    virtual short run(int &id) = 0;
    virtual ~Nodo(){}
    virtual void reset() = 0;
protected:
    bool borrable; // TO DO:
};

#endif /* Nodo_hpp */
