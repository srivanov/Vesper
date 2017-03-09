//
//  Nodo_AHidratarse.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_AHidratarse_hpp
#define Nodo_AHidratarse_hpp

#include "../Nodo_base.hpp"

class Nodo_AHidratarse : public Nodo_base {
public:
    Nodo_AHidratarse(){}
    ~Nodo_AHidratarse(){}
    short run(const int&);
};

#endif /* Nodo_AHidratarse_hpp */
