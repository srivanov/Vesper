
#ifndef input_hpp
#define input_hpp

#include <stdio.h>
#include "component.hpp"

#include "../Dvector.hpp"


class input : public component {
public:
	input();
	~input();
	void update();
	
private:
//	MyEventReceiver *r;
    float cadenciaDisparo;
};

#endif /* input_hpp */
