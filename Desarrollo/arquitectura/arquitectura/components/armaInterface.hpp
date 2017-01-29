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

enum typeArma{
    tArmaNO_TYPE = -1,
    tPISTOLA,
    tESCOPETA,
    tLANZACARAMELOS,
    tPIEDRAc,
    tGLOBOAGUA,
    tCHICLE,
    tBOMBAHUMO,
    tMARTILLO,
    tPALAc
};

class armaInterface{
public:
	virtual void destructor()=0;
	virtual void atacar() = 0;
	virtual unsigned int getMunicion() = 0;
	virtual void setMunicion(unsigned int n) = 0;
    virtual typeArma const* getType() = 0;
protected:
    typeArma tipo;
};

#endif /* armaInterface_hpp */
