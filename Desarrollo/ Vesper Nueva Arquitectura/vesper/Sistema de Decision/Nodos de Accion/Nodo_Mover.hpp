//
//  Nodo_Mover.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_Mover_hpp
#define Nodo_Mover_hpp

#include "../Nodo_base.hpp"


class Nodo_Mover : public Nodo_base {
public:
    ~Nodo_Mover();
    Nodo_Mover(){aux=-1;}
    short run(const int &id);
    void reset();
private:
    short updatePosition(const int &id);
    short updateVMovement(const int &id);
    float aux;
    float xABS, yABS;
};

#endif /* NodoMover_hpp */
