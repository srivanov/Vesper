//
//  NodoAtaqueDistancia.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef NodoAtaqueDistancia_hpp
#define NodoAtaqueDistancia_hpp

#include "Nodo.hpp"

class NodoAtaqueDistancia : public Nodo {
public:
    ~NodoAtaqueDistancia();
    NodoAtaqueDistancia();
    short run(int &id);
    void reset(){}
private:
};
#endif /* NodoAtaqueDistancia_hpp */
