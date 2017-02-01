//
//  Nodo_TieneAgua.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_TieneAgua_hpp
#define Nodo_TieneAgua_hpp

#include "Nodo.hpp"

class Nodo_TieneAgua : public Nodo {
public:
    ~Nodo_TieneAgua();
    Nodo_TieneAgua();
    short run(int &id);
    void reset(){}
private:
};

#endif /* Nodo_TieneAgua_hpp */
