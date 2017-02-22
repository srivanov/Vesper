//
//  NodoPatrullar.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef NodoPatrullar_hpp
#define NodoPatrullar_hpp

#include "Nodo.hpp"


class NodoPatrullar : public Nodo {
public:
    ~NodoPatrullar();
    NodoPatrullar();
    short run(int &id);
    void reset(){}
private:
};
#endif /* NodoPatrullar_hpp */
