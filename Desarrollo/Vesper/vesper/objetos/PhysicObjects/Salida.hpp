//
//  Salida.hpp
//  vesper
//
//  Created by Stoycho Ivanov Atanasov on 8/4/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Salida_h
#define Salida_h

#include "PhysicObject.hpp"
#include "../../estados/estados.h"

class Salida : public PhysicObject{
	states* estado;
public:
	Salida(){ estado = states::Instance(); }
	~Salida(){}
	void contacto(PhysicObject* g){
		if(g){
			if(g->getObjectType()==REHEN){
				estado->nextState = MENU;
                estado->menu = tmELEGIR_PERSONAJE;
				estado->destruir = true;
				if(estado->nivel < 5)
					estado->nivel += 1;
                estado->guardarPartida();
			}
		}
	}
	void contactoEnd(PhysicObject* g){}
	
};

#endif /* Salida_h */
