//
//  Nodo_HayAlguienCerca.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_HayAlguienCerca_hpp
#define Nodo_HayAlguienCerca_hpp

#include "Nodo.hpp"

class Nodo_HayAlguienCerca : public Nodo {
public:
    ~Nodo_HayAlguienCerca();
    Nodo_HayAlguienCerca();
    short run(int &id);
    void reset(){}
private:
};

#endif /* Nodo_HayAlguienCerca_hpp */
