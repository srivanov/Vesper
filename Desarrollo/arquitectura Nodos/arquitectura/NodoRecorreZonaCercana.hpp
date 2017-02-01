//
//  NodoRecorreZonaCercana.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef NodoRecorreZonaCercana_hpp
#define NodoRecorreZonaCercana_hpp

#include "Nodo.hpp"

class NodoRecorreZonaCercana : public Nodo {
public:
    ~NodoRecorreZonaCercana();
    NodoRecorreZonaCercana();
    short run(int &id);
    void reset(){}
private:
};

#endif /* NodoRecorreZonaCercana_hpp */
