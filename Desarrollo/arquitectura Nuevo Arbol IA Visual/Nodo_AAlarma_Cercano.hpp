//
//  Nodo_AAlarma_Cercano.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_AAlarma_Cercano_hpp
#define Nodo_AAlarma_Cercano_hpp

#include "Nodo_base.hpp"

class Nodo_AAlarma_Cercano : public Nodo_base{
public:
    short run(const int&);
    Nodo_AAlarma_Cercano(){}
    ~Nodo_AAlarma_Cercano(){}
};

#endif /* Nodo_AAlarma_Cercano_hpp */
