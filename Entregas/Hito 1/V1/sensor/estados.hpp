//
//  estados.hpp
//  vesper
//
//  Created by Julia Martínez Valera on 1/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#ifndef estados_hpp
#define estados_hpp

#include "Nodos.hpp"

class estados {
public:
    estados();
    ~estados();
    void run(datos * NPCinfo,BlackBoard * worldInfo);
private:
    int estado_act;
    void estandar();
    void alerta();
    void combate();
    void asustado();
    datos * NPC;
    BlackBoard * WorldInfo;
    NodoSecuenciaPositiva* _estandar;
    NodoSecuenciaPositiva* _alerta;
    NodoSecuenciaPositiva* _combate;
    NodoSecuenciaPositiva* _asustado;
};

#endif /* estados_hpp */
