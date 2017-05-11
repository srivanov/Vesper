//
//  Nodo_AVigilar.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_AVigilar_hpp
#define Nodo_AVigilar_hpp

#include "../Nodo_base.hpp"
#include <time.h>

class Nodo_AVigilar : public Nodo_base {
    tiempo t;
public:
    Nodo_AVigilar(){t.start();}
    ~Nodo_AVigilar(){}
    short run(const int&);
    void reset(){t.reset();}
};

#endif /* Nodo_AVigilar_hpp */
