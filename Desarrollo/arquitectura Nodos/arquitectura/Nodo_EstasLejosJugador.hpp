//
//  Nodo_EstasLejosJugador.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_EstasLejosJugador_hpp
#define Nodo_EstasLejosJugador_hpp

#include "Nodo.hpp"

class Nodo_EstasLejosJugador : public Nodo {
public:
    ~Nodo_EstasLejosJugador();
    Nodo_EstasLejosJugador();
    short run(int &id);
    void reset(){}
private:
};
#endif /* Nodo_EstasLejosJugador_hpp */
