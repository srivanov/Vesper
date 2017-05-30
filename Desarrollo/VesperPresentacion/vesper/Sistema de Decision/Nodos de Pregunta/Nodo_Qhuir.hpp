//
//  Nodo_Qhuir.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_Qhuir_hpp
#define Nodo_Qhuir_hpp

#include "../Nodo de Secuencia/Nodo_Condicional_Secuencial.hpp"

class Nodo_Qhuir : public Nodo_Condicional_Secuencial{
public:
    short run(const int&);
    Nodo_Qhuir(){}
    ~Nodo_Qhuir(){}
};

#endif /* Nodo_Qhuir_hpp */
