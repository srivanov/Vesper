//
//  pistola.cpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 16/12/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "pistola.hpp"

pistola::pistola(unsigned int muni){
	cadencia = 1;
	alcance = 10;
	municion = muni;
	tiempo_vida = 3.0f;
	tiempo_recarga = 3.0f;
	tiempo = clock();
	cargador = 6;
}

pistola::~pistola(){
	
}

void pistola::atacar(){
	if(municion > 0){
		if(cargador > 0 && 2000.0 * (clock()-tiempo) / CLOCKS_PER_SEC >= (1000.0 / cadencia)){
			printf("PISTOLA ");
			municion--;
			cargador--;
			tiempo = clock();
		}else{
			
			if(2000.0 * (clock()-tiempo) / CLOCKS_PER_SEC >= (1000.0 * tiempo_recarga)){
				cargador = 6;
			}
		}
	}
}

unsigned int pistola::getMunicion(){
	return 1;
}

void pistola::setMunicion(unsigned int n){
	municion = n;
}
