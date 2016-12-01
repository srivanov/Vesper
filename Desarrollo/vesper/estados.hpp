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
    void run();
private:
    int * estado_act;
    void estandar();
    void alerta();
    void combate();
    void asustado();
    NodoSecuencia* _estandar;
    NodoSecuencia* _alerta;
    NodoSecuencia* _combate;
    NodoSecuencia* _asustado;
};

#endif /* estados_hpp */
