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

class SkyMalla : public SkyNodo{
public:
	SkyMalla(TNodo* padre);
	~SkyMalla();
	
	void setMalla(std::string fichero);
	void setTextura(std::string &fichero);
	
private:
	TMalla* m_malla;
};

#endif /* SkyMalla_hpp */
