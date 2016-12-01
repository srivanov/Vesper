//
//  puerta.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "puerta.hpp"

puerta::puerta(){
    this->insertComponent((char*)"transform3D", *new transform3D());
    this->insertComponent((char*)"render", *new render());
    this->insertComponent((char*)"conPuzzle", *new conPuzzle());
    this->insertComponent((char*)"bloqueada", *new bloqueada());
    this->insertComponent((char*)"blindada", *new blindada());
    this->insertComponent((char*)"conLlave", *new conLlave());
    this->insertComponent((char*)"destructiva", *new destructiva());
    this->insertComponent((char*)"conAlarma", *new conAlarma());
    this->insertComponent((char*)"chirriante", *new chirriante());
}

puerta::~puerta(){
    
}
