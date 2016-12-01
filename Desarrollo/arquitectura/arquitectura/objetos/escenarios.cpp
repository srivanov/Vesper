//
//  escenarios.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "escenarios.hpp"

escenarios::escenarios(){
    this->insertComponent((char*)"physics", *new Physics());
    this->insertComponent((char*)"render", *new render());
}

escenarios::~escenarios(){
    
}
