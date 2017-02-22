//
//  Nodo_TengoHambre.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_TengoHambre_hpp
#define Nodo_TengoHambre_hpp

#include "Nodo.hpp"

class Nodo_TengoHambre : public Nodo {
public:
    ~Nodo_TengoHambre();
    Nodo_TengoHambre();
    short run(int &id);
    void reset(){}
private:
};

#endif /* Nodo_TengoHambre_hpp */
