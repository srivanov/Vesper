//
//  enemigos.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "enemigos.hpp"

enemigos::enemigos(){
    this->insertComponent((char*)"transform3D", *new transform3D(this));
    this->insertComponent((char*)"salud", *new salud());
    this->insertComponent((char*)"IAEnemigos", *new IAEnemigos());
    this->insertComponent((char*)"sed", *new sed());
    this->insertComponent((char*)"hambre", *new hambre());
    this->insertComponent((char*)"ataque", *new ataque());
}

enemigos::~enemigos(){
    
}
