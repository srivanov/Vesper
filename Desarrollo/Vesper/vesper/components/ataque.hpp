
#ifndef ataque_hpp
#define ataque_hpp

#include <stdio.h>
#include "component.hpp"
#include <vector>
#include "../tiempo.h"
class Bala;

class ataque : public component {
    tiempo t;
    Bala * attack;
public:
    void atacarDistancia();
    ataque();
    ~ataque();
	void update() override;
	
};
#endif /* ataque_hpp */
