//
//  gestor_eventos.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 17/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#ifndef gestor_eventos_hpp
#define gestor_eventos_hpp

#include "vectorD.hpp"
#include <vector>
#include <stdio.h>

class NPC;

enum Event_type{
    tE_None = 0,
    tE_Sound,
    tE_Aviso,
    tE_Enemy
};

struct eventos{
    eventos(int id,Event_type tipo, vector3D posicion, int * objeto_id);
    ~eventos();
    Event_type tE;
    int id_evento;
    vector3D pos_objeto;
    float radio;
    int * id_objeto;
    time_t timeStamp;
    time_t timeExpires;
};



class gestor{
public:
    static gestor * Instance();
    void addEvent(Event_type tipo, vector3D posicion,int * objeto_id);
    void update(std::vector<NPC*>& agentes);
    bool ExistEvent(Event_type tipo, int id);
private:
    static gestor * pInstancia;
    std::vector<eventos*> events;
    int contador;
    gestor();
    ~gestor();
};




#endif /* gestor_eventos_hpp */
