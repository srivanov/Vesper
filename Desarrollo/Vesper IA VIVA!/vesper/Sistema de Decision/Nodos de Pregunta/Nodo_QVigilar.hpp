//
//  Nodo_QVigilar.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_QVigilar_hpp
#define Nodo_QVigilar_hpp

#include "../Nodo de Secuencia/Nodo_Condicional_Secuencial.hpp"

class Nodo_QVigilar : public Nodo_Condicional_Secuencial{
    int hijo;
public:
    short run(const int&);
    Nodo_QVigilar(){hijo=0;}
    ~Nodo_QVigilar(){}
};

#endif /* Nodo_QVigilar_hpp */
