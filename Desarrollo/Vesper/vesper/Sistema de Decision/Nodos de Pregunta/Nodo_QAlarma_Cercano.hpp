//
//  Nodo_QAlarma_Cercano.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_QAlarma_Cercano_hpp
#define Nodo_QAlarma_Cercano_hpp

#include "../Nodo de Secuencia/Nodo_Condicional_Secuencial.hpp"

class Nodo_QAlarma_Cercano : public Nodo_Condicional_Secuencial{
public:
    short run(const int&);
    Nodo_QAlarma_Cercano(){hijo=0;}
    ~Nodo_QAlarma_Cercano(){}
};

#endif /* Nodo_QAlarma_Cercano_hpp */
