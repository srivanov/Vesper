
#ifndef IACamara_hpp
#define IACamara_hpp

#include <stdio.h>
#include "component.hpp"

class IACamara : public component {
public:
    IACamara();
    ~IACamara();
	void update();
};
#endif /* IACamara_hpp */
