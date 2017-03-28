//
//  Nodo_SecuenciaPlus.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_SecuenciaPlus_hpp
#define Nodo_SecuenciaPlus_hpp

#include "Nodo_Secuencia.hpp"

class Nodo_SecuenciaPlus : public Nodo_Secuencia{
public:
    short run(const int &);
    ~Nodo_SecuenciaPlus(){}
    Nodo_SecuenciaPlus(){hijo=0;}
};

#endif /* Nodo_SecuenciaPlus_hpp */
