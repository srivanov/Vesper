//
//  NodoMover.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef NodoMover_hpp
#define NodoMover_hpp

#include "Nodo.hpp"
#include "EasyMath.hpp"

class NodoMover : public Nodo {
public:
    ~NodoMover();
    NodoMover();
    short run(int &id);
    void reset(){aux=-1;}
private:
    short updatePosition(int &id);
    short updateVMovement(int &id);
    float aux = -1;
    float xABS, yABS;
};

#endif /* NodoMover_hpp */
