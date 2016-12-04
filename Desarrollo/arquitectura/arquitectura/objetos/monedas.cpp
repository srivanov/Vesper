//
//  monedas.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "monedas.hpp"

monedas::monedas(){
    this->insertComponent((char*)"transform3D", *new transform3D(this));
}

monedas::~monedas(){
    
}
