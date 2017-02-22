//
//  Nodo_TiempoInactivo.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_TiempoInactivo_hpp
#define Nodo_TiempoInactivo_hpp

#include "Nodo.hpp"

class Nodo_TiempoInactivo : public Nodo {
public:
    ~Nodo_TiempoInactivo();
    Nodo_TiempoInactivo();
    short run(int &id);
    void reset(){}
private:
};


#endif /* Nodo_TiempoInactivo_hpp */
