//
//  Nodo_QAyudar.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_QAyudar_hpp
#define Nodo_QAyudar_hpp

#include "../Nodo de Secuencia/Nodo_Condicional_Secuencial.hpp"

class Nodo_QAyudar : public Nodo_Condicional_Secuencial{
public:
    short run(const int&);
    Nodo_QAyudar(){}
    ~Nodo_QAyudar(){}
};

#endif /* Nodo_QAyudar_hpp */
