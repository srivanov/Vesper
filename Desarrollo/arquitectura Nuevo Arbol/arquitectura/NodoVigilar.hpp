//
//  NodoVigilar.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef NodoVigilar_hpp
#define NodoVigilar_hpp

#include "Nodo.hpp"


class NodoVigilar : public Nodo {
public:
    ~NodoVigilar();
    NodoVigilar();
    short run(int &id);
private:
    void reset(){}
    time_t _time;
};

#endif /* NodoVigilar_hpp */
