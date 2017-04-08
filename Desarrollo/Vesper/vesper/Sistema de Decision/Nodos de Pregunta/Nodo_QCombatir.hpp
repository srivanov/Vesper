//
//  Nodo_QCombatir.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_QCombatir_hpp
#define Nodo_QCombatir_hpp

#include "../Nodo de Secuencia/Nodo_Condicional_Secuencial.hpp"

class Nodo_QCombatir : public Nodo_Condicional_Secuencial{
public:
    short run(const int&);
    Nodo_QCombatir(){}
    ~Nodo_QCombatir(){}
};

#endif /* Nodo_QCombatir_hpp */
