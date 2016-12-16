
#ifndef salud_hpp
#define salud_hpp

#include <stdio.h>
#include "component.hpp"

class salud : public component{
public:
	salud();
	~salud();
	void update();
	
};

#endif /* salud_hpp */
