//
//  Nodo_QCurarse.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_QCurarse_hpp
#define Nodo_QCurarse_hpp

#include "Nodo_Condicional_Secuencial.hpp"

class Nodo_QCurarse : public Nodo_Condicional_Secuencial{
public:
    short run(const int&);
    Nodo_QCurarse(){}
    ~Nodo_QCurarse(){}
};

#endif /* Nodo_QCurarse_hpp */
