//
//  Nodo_HayParaHablar.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_HayParaHablar_hpp
#define Nodo_HayParaHablar_hpp

#include "Nodo.hpp"

class Nodo_HayParaHablar : public Nodo {
public:
    ~Nodo_HayParaHablar();
    Nodo_HayParaHablar();
    short run(int &id);
    void reset(){}
private:
    
};
#endif /* Nodo_HayParaHablar_hpp */
