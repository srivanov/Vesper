//
//  Nodo_NecesitoAyuda.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_NecesitoAyuda_hpp
#define Nodo_NecesitoAyuda_hpp

#include "Nodo.hpp"

class Nodo_NecesitoAyuda : public Nodo {
public:
    Nodo_NecesitoAyuda();
    ~Nodo_NecesitoAyuda();
    short run(int &id);
    void reset(){}
private:
    
};


#endif /* Nodo_NecesitoAyuda_hpp */
