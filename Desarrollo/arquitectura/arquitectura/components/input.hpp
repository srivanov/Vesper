
#ifndef input_hpp
#define input_hpp

#include <stdio.h>
#include "component.hpp"
#include "MyEventReceiver.hpp"

class bala;

class input : public component {
public:
	input();
	~input();
	void update();
	
private:
	MyEventReceiver *r;
    int prueba;
};

#endif /* input_hpp */
