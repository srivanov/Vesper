
#ifndef IAEnemigos_hpp
#define IAEnemigos_hpp

#include <stdio.h>
#include "component.hpp"

class IAEnemigos : public component {
public:
    IAEnemigos();
    ~IAEnemigos();
	void update();
};
#endif /* IAEnemigos_hpp */
