//
//  NodoComer.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef NodoComer_hpp
#define NodoComer_hpp

#include "Nodo.hpp"

class NodoComer : public Nodo {
public:
    ~NodoComer();
    NodoComer();
    short run(int &id);
    void reset(){}
private:
};

#endif /* NodoComer_hpp */
