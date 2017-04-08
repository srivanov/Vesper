//
//  Nodo_QAvisado.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_QAvisado_hpp
#define Nodo_QAvisado_hpp

#include "../Nodo de Secuencia/Nodo_Condicional_Secuencial.hpp"

class Nodo_QAvisado : public Nodo_Condicional_Secuencial{
public:
    short run(const int &);
    Nodo_QAvisado(){};
    ~Nodo_QAvisado(){}
};

#endif /* Nodo_QAvisado_hpp */
