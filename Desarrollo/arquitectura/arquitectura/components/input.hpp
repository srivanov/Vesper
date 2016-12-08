
#ifndef input_hpp
#define input_hpp

#include <stdio.h>
#include "component.hpp"
#include "MyEventReceiver.hpp"

class input : public component {
public:
	input();
	~input();
	void update();
	
private:
	MyEventReceiver *r;
	
};

#endif /* input_hpp */
