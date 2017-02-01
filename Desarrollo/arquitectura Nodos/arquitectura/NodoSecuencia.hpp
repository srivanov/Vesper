//
//  NodoSecuencia.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef NodoSecuencia_hpp
#define NodoSecuencia_hpp

#include "Nodo.hpp"


class NodoSecuencia : public Nodo {
public:
    NodoSecuencia();
    ~NodoSecuencia();
    short run(int &id);
    void reset();
    void anyadirHijo(Nodo * hijo);
private:
    vector<Nodo*> m_hijos;
    size_t hijo;
};
#endif /* NodoSecuencia_hpp */
