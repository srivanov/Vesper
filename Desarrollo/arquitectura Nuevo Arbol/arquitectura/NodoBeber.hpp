//
//  NodoBeber.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef NodoBeber_hpp
#define NodoBeber_hpp

#include "Nodo.hpp"

class NodoBeber : public Nodo {
public:
    ~NodoBeber();
    NodoBeber();
    short run(int &id);
    void reset(){}
private:
};

#endif /* NodoBeber_hpp */
