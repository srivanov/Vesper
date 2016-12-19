//
//  NPC.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 7/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#ifndef NPC_hpp
#define NPC_hpp

#include "estados.hpp"
class eventos;

struct DT_evento {
    DT_evento(Event_type tipo, vector3D posicion) : type(tipo){posEvent=posicion;}
    ~DT_evento();
    vector3D posEvent;
    Event_type type;
};

class NPC{
public:
    NPC(int ntipo, vector3D * posinicial,short rutina);
    ~NPC();
    datos getNPCinfo();
    void update(BlackBoard * worldINFO);
    vector3D * getPosition() const{return posActual;}
    void setPosition(vector3D * posicion);
    void setDestino(vector3D * posicion) {posDestino = posicion;}
    bool getFlags(int event);
    void setEventFlag(vector3D posicion,Event_type Etype);
    int getId() const {return id;}
private:
    int f = 0;
    
    vector<DT_evento*> EPropios;
    
    estados * DeciSys;
    
    int id;
    int life,sed,hambre,tipo;
    vector3D *posActual;
    std::vector<vector3D*> PosRutina;
    int rutinas,paso;
    vector3D * posDestino;
    float velocidad;
    float velcorriendo;
    int estados;
    
    
};

#endif /* NPC_hpp */
