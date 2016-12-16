
#ifndef hambre_hpp
#define hambre_hpp

#include <stdio.h>
#include "component.hpp"

class hambre : public component {
public:
    hambre();
    ~hambre();
	void update();
	
};
#endif /* hambre_hpp */
