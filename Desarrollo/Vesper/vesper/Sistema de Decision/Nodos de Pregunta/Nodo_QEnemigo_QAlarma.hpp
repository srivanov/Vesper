//
//  Nodo_QEnemigo_QAlarma.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_QEnemigo_QAlarma_hpp
#define Nodo_QEnemigo_QAlarma_hpp

#include "../Nodo de Secuencia/Nodo_Condicional_Secuencial.hpp"

class Nodo_QEnemigo_QAlarma : public Nodo_Condicional_Secuencial{
    Nodo_base * hijo;
public:
    Nodo_QEnemigo_QAlarma(){}
    ~Nodo_QEnemigo_QAlarma(){}
    short run(const int&);
};

#endif /* Nodo_QEnemigo_QAlarma_hpp */
