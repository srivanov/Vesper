//
//  NodoSecuenciaPositiva.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef NodoSecuenciaPositiva_hpp
#define NodoSecuenciaPositiva_hpp

#include "Nodo.hpp"


class NodoSecuenciaPositiva : public Nodo{
public:
    NodoSecuenciaPositiva();
    ~NodoSecuenciaPositiva();
    short run(int &id);
    void anyadirHijo(Nodo * hijo);
    void reset();
private:
    vector<Nodo*> m_hijos;
    size_t hijo = -1;
};

#endif /* NodoSecuenciaPositiva_hpp */
