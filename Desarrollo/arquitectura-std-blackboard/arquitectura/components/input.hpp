
#ifndef input_hpp
#define input_hpp

#include <stdio.h>
#include "component.hpp"
#include "../MyEventReceiver.hpp"
#include <time.h>


class input : public component {
public:
	input();
	~input();
	void update();
	
private:
	MyEventReceiver *r;
    time_t intervalo;
    float cadenciaDisparo;
};

#endif /* input_hpp */
