
#ifndef armasDisparo_hpp
#define armasDisparo_hpp

#include <stdio.h>
#include "component.hpp"

class armasDisparo : public component {
public:
    armasDisparo();
    ~armasDisparo();
	
private:
	unsigned int arma;
};

#endif /* armasDisparo_hpp */
