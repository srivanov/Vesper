
#ifndef sed_hpp
#define sed_hpp

#include <stdio.h>
#include "component.hpp"

class sed : public component {
public:
    sed();
    ~sed();
	void update();
};
#endif /* sed_hpp */
