//
//  Nodo_AHuir.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_AHuir_hpp
#define Nodo_AHuir_hpp

#include "Nodo_base.hpp"

class Nodo_AHuir : public Nodo_base{
public:
    short run(const int&);
    Nodo_AHuir(){}
    ~Nodo_AHuir(){}
};

#endif /* Nodo_AHuir_hpp */
