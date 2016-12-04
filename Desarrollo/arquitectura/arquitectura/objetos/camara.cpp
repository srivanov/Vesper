//
//  camara.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "camara.hpp"

camara::camara(){
    this->insertComponent((char*)"transform3D", *new transform3D(this));
    this->insertComponent((char*)"physics", *new Physics());
    this->insertComponent((char*)"IACamara", *new IACamara());
}

camara::~camara(){
    
}
