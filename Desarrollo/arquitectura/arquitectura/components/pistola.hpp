//
//  pistola.hpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 16/12/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef pistola_hpp
#define pistola_hpp

#include <stdio.h>
#include "armaInterface.hpp"
#include <time.h>

class pistola : public armaInterface{
public:
	pistola(unsigned int muni);
	~pistola();
	void atacar();
	unsigned int getMunicion();
	void setMunicion(unsigned int n);
private:
	unsigned int cadencia, alcance, municion, cargador;
	float tiempo_recarga, tiempo_vida;
	time_t tiempo;
};

#endif /* pistola_hpp */
