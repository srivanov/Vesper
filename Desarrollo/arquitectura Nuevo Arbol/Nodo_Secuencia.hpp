//
//  Nodo_Secuencia.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_Secuencia_hpp
#define Nodo_Secuencia_hpp

#include "Nodo_base.hpp"
#include <vector>


class Nodo_Secuencia : public Nodo_base{
protected:
    int hijo;
    std::vector<Nodo_base*> hijos;
public:
    virtual short run(const int &);
    void reset();
    void addHijo(Nodo_base*);
    Nodo_Secuencia(){hijo=0;}
    ~Nodo_Secuencia();
};

#endif /* Nodo_Secuencia_hpp */
