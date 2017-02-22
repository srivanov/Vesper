
#ifndef conLlave_hpp
#define conLlave_hpp

#include <stdio.h>
#include "component.hpp"

class conLlave : public component{
public:
	conLlave();
	~conLlave();
	void update() override;
	
};

#endif /* conLlave_hpp */
