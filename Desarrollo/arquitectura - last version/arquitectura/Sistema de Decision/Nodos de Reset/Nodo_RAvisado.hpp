//
//  Nodo_RAvisado.hpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Nodo_RAvisado_hpp
#define Nodo_RAvisado_hpp

#include "../Nodo_base.hpp"

class Nodo_RAvisado : public Nodo_base{
public:
    short run(const int &);
    Nodo_RAvisado(){}
    ~Nodo_RAvisado(){}
};

#endif /* Nodo_RAvisado_hpp */
