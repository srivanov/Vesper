//
//  SkyMalla.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 5/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef SkyMalla_hpp
#define SkyMalla_hpp

#include "SkyNodo.hpp"
#include "TMalla.hpp"

enum tipoMalla{
	tMallaDinamica = 0,
	tMallaEstatica
};

class SkyMalla : public SkyNodo{
public:
	SkyMalla(TNodo* padre, tipoMalla t);
	~SkyMalla();
	
	void setMalla(char* fichero);
	void setTextura(char* fichero);
	
private:
	TMalla* m_malla;
};

#endif /* SkyMalla_hpp */
