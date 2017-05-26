//
//  Alarm.hpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef Alarm_hpp
#define Alarm_hpp

#include "../PhysicObject.hpp"
#include "../../../Arquitectura IA/LevelBlackBoard.hpp"
#include "../../../Arquitectura IA/gestor_eventos.hpp"

class Alarm : public PhysicObject {
    void gestorTiempo();
    bool activado;
    bool rota;
    bool NPCKnows;
    tiempo _time;
    void activar();
    bool estaActivado();
    
public:
    bool EstaRota(){return rota;}
    Alarm();
    ~Alarm();
    void update();
    virtual void contacto(PhysicObject*);
    virtual void contactoEnd(PhysicObject*){}
    void romper(){eliminar=true;}
};

#endif /* Alarm_hpp */
