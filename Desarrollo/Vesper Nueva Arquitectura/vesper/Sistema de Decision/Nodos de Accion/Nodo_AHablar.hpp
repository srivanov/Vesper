//
//  Nodo_AHablar.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_AHablar_hpp
#define Nodo_AHablar_hpp

#include "../Nodo_base.hpp"

class Nodo_AHablar : public Nodo_base {
public:
    short run(const int&);
    Nodo_AHablar(){}
    ~Nodo_AHablar(){}
};

#endif /* Nodo_AHablar_hpp */
