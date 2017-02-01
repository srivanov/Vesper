//
//  Nodo_VerJugador.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_VerJugador_hpp
#define Nodo_VerJugador_hpp

#include "Nodo.hpp"


class Nodo_VerJugador : public Nodo {
public:
    ~Nodo_VerJugador();
    Nodo_VerJugador();
    short run(int &id);
    void reset(){}
private:
};

#endif /* Nodo_VerJugador_hpp */
