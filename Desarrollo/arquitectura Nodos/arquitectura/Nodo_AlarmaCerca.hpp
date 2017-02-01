//
//  Nodo_AlarmaCerca.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_AlarmaCerca_hpp
#define Nodo_AlarmaCerca_hpp

#include "Nodo.hpp"

class Nodo_AlarmaCerca : public Nodo {
public:
    ~Nodo_AlarmaCerca();
    Nodo_AlarmaCerca();
    short run(int &id);
    void reset(){}
private:
};
#endif /* Nodo_AlarmaCerca_hpp */
