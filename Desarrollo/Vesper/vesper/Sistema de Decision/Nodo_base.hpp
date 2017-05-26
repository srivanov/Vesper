//
//  Nodo_base.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_base_hpp
#define Nodo_base_hpp

#define FALLO 0
#define FUNCIONO 1
#define RUNNING 2
// COMPARATIVAS CON LA MORAL
#define NEEDHELP 40
#define RUNAWAY 10
// UMBRAL PARA CONSIDERAR SUS STATS BAJAS
#define UMBRALVIDA 30
#define UMBRALSED 60
#define UMBRALHAMBRE 70
// CANTIDADES DE RECUPERACION
#define CURACION 60
#define HIDRATACION 50
#define ALIMENTACION 70

#include "../Arquitectura IA/NpcLibrary.hpp"
#include "../Arquitectura IA/LevelBlackBoard.hpp"
#include "../Tools/EasyMath.hpp"
#include "../Arquitectura IA/Types.h"

//TO DO : BORRAR (DEBUG)
#include <iostream>
using namespace std;

class Nodo_base{
public:
    Nodo_base(){}
    virtual short run(const int&) = 0;
    virtual ~Nodo_base(){}
    virtual void reset(){}
};

#endif /* Nodo_base_hpp */
