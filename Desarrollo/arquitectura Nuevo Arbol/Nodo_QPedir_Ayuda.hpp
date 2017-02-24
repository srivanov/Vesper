//
//  Nodo_QPedir_Ayuda.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_QPedir_Ayuda_hpp
#define Nodo_QPedir_Ayuda_hpp

#include "Nodo_Condicional_Secuencial.hpp"

class Nodo_QPedir_Ayuda : public Nodo_Condicional_Secuencial{
public:
    short run(const int&);
    Nodo_QPedir_Ayuda(){}
    ~Nodo_QPedir_Ayuda(){}
};

#endif /* Nodo_QPedir_Ayuda_hpp */
