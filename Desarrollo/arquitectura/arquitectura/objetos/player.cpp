//
//  player.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "player.hpp"

player::player(){
    this->insertComponent((char*)"input", *new input());
    this->insertComponent((char*)"pala", *new pala());
    this->insertComponent((char*)"armasArrojadizas", *new armasArrojadizas());
    this->insertComponent((char*)"piedra", *new piedra());
    this->insertComponent((char*)"habilidadEspecial", *new habilidadEspecial());
    this->insertComponent((char*)"martilloDeJuguete", *new martilloDeJuguete());
    this->insertComponent((char*)"transform3D", *new transform3D());
    this->insertComponent((char*)"armasDisparo", *new armasDisparo());
    this->insertComponent((char*)"salud", *new salud());
    this->insertComponent((char*)"physics", *new Physics());
    this->insertComponent((char*)"render", *new class render());
	
	std::map<char*,component>::iterator iter = this->getIteradorBegin();

	while(iter != this->getIteradorEnd()){
		iter->second.setFather(this);
		iter++;
	}
}

player::~player(){
    
}
