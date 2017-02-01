//
//  NodoHuir.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef NodoHuir_hpp
#define NodoHuir_hpp

#include "Nodo.hpp"

class NodoHuir : public Nodo {
public:
    NodoHuir();
    ~NodoHuir();
    short run(int &id);
    void reset(){}
private:
};

#endif /* NodoHuir_hpp */
