//
//  gestor_eventos.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 28/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef gestor_eventos_hpp
#define gestor_eventos_hpp

#include "NpcLibrary.hpp"
#include "Types.h"

class Rehen;

struct eventos_values {
    Prioridades m_tipo;
    float radio;
    float caducidad;
};

struct eventos {
    eventos();
    ~eventos();
    int m_ID;
    int m_ID_CREADOR;
    Prioridades m_tipo;
    dvector3D m_posicion;
    float m_caducidad, radio;
    tiempo m_t;
    bool revisado;
};

class gestor_eventos {
    void limpiar();
    void comprobar();
    gestor_eventos();
    int id_counts;
    std::vector<eventos*> World_events;
    std::vector<NpcBook*> Suscritos;
    Rehen * rehen;
    size_t it,end;
public:
    ~gestor_eventos();
    void eliminarme(int ID);
    bool existeEvento(const Prioridades,const int);
    bool revisadoEvento(const Prioridades,const int);
    static gestor_eventos * instance();
    void addEvento(int id,const Prioridades t,dvector3D pos);
    void subscribirse(NpcBook * libro);
    void subscribirse(Rehen*);
    void update();
};

#endif /* gestor_eventos_hpp */
