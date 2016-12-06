//
//  alarma.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "alarma.hpp"

alarma::alarma(){
    this->insertComponent((char*)"transform3D", *new transform3D());
    this->insertComponent((char*)"render", *new class render());
}

alarma::~alarma(){
    
}
