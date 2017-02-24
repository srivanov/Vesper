//
//  Nodo_AAyudar.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_AAyudar_hpp
#define Nodo_AAyudar_hpp

#include "Nodo_base.hpp"

class Nodo_AAyudar : public Nodo_base{
public:
    short run(const int&);
    Nodo_AAyudar(){}
    ~Nodo_AAyudar(){}
};

#endif /* Nodo_AAyudar_hpp */
