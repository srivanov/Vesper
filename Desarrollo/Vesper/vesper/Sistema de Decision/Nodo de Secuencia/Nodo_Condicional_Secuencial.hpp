//
//  Nodo_Condicional_Secuencial.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_Condicional_Secuencial_hpp
#define Nodo_Condicional_Secuencial_hpp

#include "Nodo_Secuencia.hpp"

class Nodo_Condicional_Secuencial : public Nodo_Secuencia{
protected:
    
    short runHijos(const int&);
    bool activado;
public:
    void reset();
    virtual short run(const int&) = 0;
    Nodo_Condicional_Secuencial(){activado=false;}
    ~Nodo_Condicional_Secuencial(){}
};

#endif /* Nodo_Condicional_Padre_hpp */
