//
//  Nodo_ACurarse.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 23/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_ACurarse_hpp
#define Nodo_ACurarse_hpp

#include "Nodo_base.hpp"

class Nodo_ACurarse : public Nodo_base {
public:
    Nodo_ACurarse(){}
    ~Nodo_ACurarse(){}
    short run(const int&);
};

#endif /* Nodo_ACurarse_hpp */
