//
//  Nodo_ARuido.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_ARuido_hpp
#define Nodo_ARuido_hpp

#include "Nodo_base.hpp"

class Nodo_ARudio : public Nodo_base{
public:
    short run(const int&);
    Nodo_ARudio(){}
    ~Nodo_ARudio(){}
};

#endif /* Nodo_ARuido_hpp */
