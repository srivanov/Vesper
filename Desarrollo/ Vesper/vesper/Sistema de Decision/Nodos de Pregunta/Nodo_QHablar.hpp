//
//  Nodo_QHablar.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_QHablar_hpp
#define Nodo_QHablar_hpp

#include "../Nodo de Secuencia/Nodo_Condicional_Secuencial.hpp"

class Nodo_QHablar : public Nodo_Condicional_Secuencial{
public:
    short run(const int&);
    Nodo_QHablar(){}
    ~Nodo_QHablar(){}
};

#endif /* Nodo_QHablar_hpp */
