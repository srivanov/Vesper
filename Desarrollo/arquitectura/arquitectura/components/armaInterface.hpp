//
//  armaInterface.hpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 16/12/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef armaInterface_hpp
#define armaInterface_hpp

#include <stdio.h>

class armaInterface{
public:
//	virtual void destructor()=0;
	virtual void atacar() = 0;
	virtual unsigned int getMunicion() = 0;
	virtual void setMunicion(unsigned int n) = 0;
	
};

#endif /* armaInterface_hpp */
