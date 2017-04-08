//
//  Nodo_QPedir_Ayuda.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_QPedir_Ayuda_hpp
#define Nodo_QPedir_Ayuda_hpp

#include "../Nodo de Secuencia/Nodo_Condicional_Secuencial.hpp"

class Nodo_QPedir_Ayuda : public Nodo_Condicional_Secuencial{
    bool CONGELADO;
public:
    short run(const int&);
    Nodo_QPedir_Ayuda(){CONGELADO=false;}
    ~Nodo_QPedir_Ayuda(){}
};

#endif /* Nodo_QPedir_Ayuda_hpp */
