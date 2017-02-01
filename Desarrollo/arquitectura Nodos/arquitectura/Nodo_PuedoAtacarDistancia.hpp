//
//  Nodo_PuedoAtacarDistancia.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_PuedoAtacarDistancia_hpp
#define Nodo_PuedoAtacarDistancia_hpp

#include "Nodo.hpp"

class Nodo_PuedoAtacarDistancia : public Nodo {
public:
    ~Nodo_PuedoAtacarDistancia();
    Nodo_PuedoAtacarDistancia();
    short run(int &id);
    void reset(){}
private:
};

#endif /* Nodo_PuedoAtacarDistancia_hpp */
