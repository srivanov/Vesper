//
//  Nodo_EstasAsustado.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_EstasAsustado_hpp
#define Nodo_EstasAsustado_hpp

#include "Nodo.hpp"

class Nodo_EstasAsustado : public Nodo {
public:
    ~Nodo_EstasAsustado();
    Nodo_EstasAsustado();
    short run(int &id);
    void reset(){}
private:
};

#endif /* Nodo_EstasAsustado_hpp */
