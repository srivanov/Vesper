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
    void reset(){}
private:
   // float CalcularDistancia(dvector3D a, dvector3D b);
    float aux = -1;
    float xABS, yABS;
    dvector3D * _movement;
};

#endif /* NodoMover_hpp */
