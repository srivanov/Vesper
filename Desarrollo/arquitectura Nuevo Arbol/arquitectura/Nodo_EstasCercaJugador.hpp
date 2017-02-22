//
//  Nodo_EstasCercaJugador.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_EstasCercaJugador_hpp
#define Nodo_EstasCercaJugador_hpp

#include "Nodo.hpp"

class Nodo_EstasCercaJugador : public Nodo {
public:
    ~Nodo_EstasCercaJugador();
    Nodo_EstasCercaJugador();
    short run(int &id);
    void reset(){}
private:
};
#endif /* Nodo_EstasCercaJugador_hpp */
