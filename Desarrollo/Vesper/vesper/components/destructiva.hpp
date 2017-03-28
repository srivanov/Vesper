
#ifndef destructiva_hpp
#define destructiva_hpp

#include <stdio.h>
#include "component.hpp"

class destructiva : public component{
public:
	destructiva();
	~destructiva();
	void update();
	
};

#endif /* destructiva_hpp */
