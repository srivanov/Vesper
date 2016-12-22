
#ifndef ataque_hpp
#define ataque_hpp

#include <stdio.h>
#include "component.hpp"

class ataque : public component {
public:
    ataque();
    ~ataque();
	void update();
	
};
#endif /* ataque_hpp */
