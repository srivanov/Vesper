
#ifndef armas_hpp
#define armas_hpp

#include <stdio.h>
#include "component.hpp"
#include "armaInterface.hpp"
#include "pistola.hpp"

class armas : public component {
public:
    armas();
    ~armas();
	void atacar();
	
private:
	armaInterface* interface;
};

#endif /* armas_hpp */
