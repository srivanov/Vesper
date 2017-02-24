//
//  Nodo_QAlimentarse.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_QAlimentarse_hpp
#define Nodo_QAlimentarse_hpp

#include "Nodo_Condicional_Secuencial.hpp"

class Nodo_QAlimentarse : public Nodo_Condicional_Secuencial{
    int hijo;
public:
    short run(const int&);
    Nodo_QAlimentarse(){hijo=0;}
    ~Nodo_QAlimentarse(){}
};

#endif /* Nodo_QAlimentarse_hpp */
