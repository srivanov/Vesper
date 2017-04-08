//
//  Nodo_AAtacar.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 7/4/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_AAtacar_hpp
#define Nodo_AAtacar_hpp

#include "../Nodo_base.hpp"

class Nodo_AAtacar : public Nodo_base {
    short updateVMovement(const int&);
    void updatePosition(const int&);
    float xABS, yABS , aux;
public:
    short run(const int &);
    Nodo_AAtacar(){}
    ~Nodo_AAtacar(){}
};

#endif /* Nodo_AAtacar_hpp */
