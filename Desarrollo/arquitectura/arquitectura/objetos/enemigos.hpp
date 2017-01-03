
#ifndef enemigos_hpp
#define enemigos_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include <time.h>
#include <stdlib.h>

class enemigos : public GameObject{
public:
    enemigos(int& ID);
    ~enemigos();
	void update();
private:
	int ID;
	unsigned int salud, sed, hambre;
};
#endif /* enemigos_hpp */
