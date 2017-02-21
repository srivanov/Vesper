//
//  estados.hpp
//  vesper
//
//  Created by Julia Martínez Valera on 1/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#ifndef estados_hpp
#define estados_hpp

#include "behaviour_trees.hpp"

class estados {
public:
    estados();
    ~estados();
    void run(int &id);
private:
    vector<Nodo*> all_nodos;
    void estandar(int &id);
    void alerta(int &id);
    void combate(int &id);
    void asustado(int &id);
    NodoRaiz* _estandar;
    NodoSecuenciaPositiva* _alerta;
    NodoSecuenciaPositiva* _combate;
    NodoSecuenciaPositiva* _asustado;
    
};

#endif /* estados_hpp */
