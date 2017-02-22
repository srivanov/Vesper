//
//  Nodo_HayRuido.hpp
//  arquitectura
//
//  Created by Julia Martínez Valera on 1/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_HayRuido_hpp
#define Nodo_HayRuido_hpp

#include "Nodo.hpp"


class Nodo_HayRuido : public Nodo {
public:
    ~Nodo_HayRuido();
    Nodo_HayRuido();
    short run(int &id);
    void reset(){}
private:
};
#endif /* Nodo_HayRuido_hpp */
