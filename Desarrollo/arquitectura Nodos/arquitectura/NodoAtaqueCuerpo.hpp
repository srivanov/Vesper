//
//  NodoAtaqueCuerpo.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef NodoAtaqueCuerpo_hpp
#define NodoAtaqueCuerpo_hpp

#include "Nodo.hpp"

class NodoAtaqueCuerpo : public Nodo {
public:
    ~NodoAtaqueCuerpo();
    NodoAtaqueCuerpo();
    short run(int &id);
    void reset(){}
private:
};
#endif /* NodoAtaqueCuerpo_hpp */
