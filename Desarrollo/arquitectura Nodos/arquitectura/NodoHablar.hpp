//
//  NodoHablar.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef NodoHablar_hpp
#define NodoHablar_hpp

#include "Nodo.hpp"

class NodoHablar : public Nodo {
public:
    ~NodoHablar();
    NodoHablar();
    short run(int &id);
    void reset(){}
private:
};


#endif /* NodoHablar_hpp */
