//
//  Nodo_APatrullar.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_APatrullar_hpp
#define Nodo_APatrullar_hpp

#include "../Nodo_base.hpp"

class Nodo_APatrullar : public Nodo_base{
public:
    short run(const int&);
    Nodo_APatrullar(){}
    ~Nodo_APatrullar(){}
};

#endif /* Nodo_APatrullar_hpp */
