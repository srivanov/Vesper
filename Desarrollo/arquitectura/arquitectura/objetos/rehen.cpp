//
//  rehen.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 22/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "rehen.hpp"

rehen::rehen(){
    
    component* aux = new class render();
    this->insertComponent((char*)"render", aux);
    aux = new transform3D();
    this->insertComponent((char*)"transform3D", aux);
    aux = new physics();
    this->insertComponent((char*)"physics", aux);
    
    std::map<char*,component*>::iterator iter = this->getIteradorBegin();
    while(iter != this->getIteradorEnd()){
        iter->second->setFather(this);
        iter++;
    }
    setRenderizable(true);
    
    physics* fisica = (physics*)findComponent("physics");
    
    dvector3D dim(1,1,1);
    dvector3D pos(0,0,0);
    
    muero = false;
    fisica->crearBodyDinamico(dim, pos);
    aux = NULL;
    setType(tREHEN);

}

rehen::~rehen(){
    
}

void rehen::update(){
    GameObject::update();
}

bool const* rehen::getmuero(){
    return &muero;
}

void rehen::contacto(GameObject *g){
//    if(*g->getType() == tPALA){
//        arma->insertarArma(9);
//    }
//    if(*g->getType() == tMONEDAS){
//        ((habilidadEspecial*)findComponent("habilidadEspecial"))->aumentarMoneda();
//    }
//    if(*g->getType() == tALARMA){
//        
//    }
//    if(*g->getType() == tESCOPETA){
//        arma->insertarArma(2);
//    }
//    if(*g->getType() == tLANZACARAMELOS){
//        arma->insertarArma(3);
//    }
//    if(*g->getType() == tGLOBOAGUA){
//        arma->insertarArma(5);
//    }
//    if(*g->getType() == tCHICLE){
//        arma->insertarArma(6);
//    }
//    if(*g->getType() == tBOMBAHUMO){
//        arma->insertarArma(7);
//    }
//    obj_colisionado = g;
}

void rehen::contactoEnd(GameObject *g){
    obj_colisionado = NULL;
}
