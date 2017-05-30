//
//  Nodo_QPatrullar.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_QPatrullar_hpp
#define Nodo_QPatrullar_hpp

#include "../Nodo de Secuencia/Nodo_Condicional_Secuencial.hpp"

class Nodo_QPatrullar : public Nodo_Condicional_Secuencial{
public:
    short run(const int&);
    Nodo_QPatrullar(){}
    ~Nodo_QPatrullar(){}
};

#endif /* Nodo_QPatrullar_hpp */
