//
//  Nodo_TengoVigilar.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_TengoVigilar_hpp
#define Nodo_TengoVigilar_hpp

#include "Nodo.hpp"

class Nodo_TengoVigilar : public Nodo {
    time_t _time;
public:
    Nodo_TengoVigilar();
    ~Nodo_TengoVigilar();
    short run(int &id);
    void reset(){}
};

#endif /* Nodo_TengoVigilar_hpp */
