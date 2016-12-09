//
//  bala.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 9/12/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "bala.hpp"

bala::bala(float* pos){
    component* aux = new class render();
    this->insertComponent((char*)"render", aux);
    aux = new physics();
    this->insertComponent((char*)"physics", aux);
    aux = new transform3D();
    this->insertComponent((char*)"transform3D", aux);
    
    std::map<char*,component*>::iterator iter = this->getIteradorBegin();
    while(iter != this->getIteradorEnd()){
        iter->second->setFather(this);
        iter++;
    }
    setRenderizable(true);
//    physics* fisica = (physics*)findComponent("physics");
//    fisica->crearBodyDinamico(new float[2]{0.1,0.1}, pos);
}

bala::~bala(){
    
}
