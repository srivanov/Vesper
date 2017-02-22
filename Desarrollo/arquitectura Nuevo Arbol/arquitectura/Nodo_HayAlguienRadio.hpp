//
//  Nodo_HayAlguienRadio.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_HayAlguienRadio_hpp
#define Nodo_HayAlguienRadio_hpp

#include "Nodo.hpp"

class Nodo_HayAlguienRadio : public Nodo {
public:
    ~Nodo_HayAlguienRadio();
    Nodo_HayAlguienRadio();
    short run(int &id);
    void reset(){}
private:
    time_t time;
};
#endif /* Nodo_HayAlguienRadio_hpp */
