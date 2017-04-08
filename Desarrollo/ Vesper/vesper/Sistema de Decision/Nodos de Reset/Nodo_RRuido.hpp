//
//  Nodo_RRuido.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_RRuido_hpp
#define Nodo_RRuido_hpp

#include "../Nodo_base.hpp"

class Nodo_RRuido : public Nodo_base{
public:
    short run(const int&);
    Nodo_RRuido(){}
    ~Nodo_RRuido(){}
};

#endif /* Nodo_RRuido_hpp */
