//
//  Nodo_AAlimentarse.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_AAlimentarse_hpp
#define Nodo_AAlimentarse_hpp

#include "../Nodo_base.hpp"

class Nodo_AAlimentarse : public Nodo_base {
public:
    Nodo_AAlimentarse(){}
    ~Nodo_AAlimentarse(){}
    short run(const int&);
};

#endif /* Nodo_AAlimentarse_hpp */
