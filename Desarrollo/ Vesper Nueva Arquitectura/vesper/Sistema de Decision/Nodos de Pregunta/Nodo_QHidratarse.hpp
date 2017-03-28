//
//  Nodo_QHidratarse.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_QHidratarse_hpp
#define Nodo_QHidratarse_hpp

#include "../Nodo de Secuencia/Nodo_Condicional_Secuencial.hpp"

class Nodo_QHidratarse : public Nodo_Condicional_Secuencial{
public:
    short run(const int&);
    Nodo_QHidratarse(){}
    ~Nodo_QHidratarse(){}
};

#endif /* Nodo_QHidratarse_hpp */
