//
//  NodoAvisar.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef NodoAvisar_hpp
#define NodoAvisar_hpp

#include "Nodo.hpp"

class NodoAvisar : public Nodo {
public:
    ~NodoAvisar();
    NodoAvisar();
    short run(int &id);
    void reset(){}
private:
};
#endif /* NodoAvisar_hpp */
