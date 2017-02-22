//
//  Nodo_VidaBaja.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_VidaBaja_hpp
#define Nodo_VidaBaja_hpp

#include "Nodo.hpp"

class Nodo_VidaBaja : public Nodo {
public:
    ~Nodo_VidaBaja();
    Nodo_VidaBaja();
    short run(int &id);
    void reset(){}
private:
};

#endif /* Nodo_VidaBaja_hpp */
