
#ifndef chirriante_hpp
#define chirriante_hpp

#include <stdio.h>
#include "component.hpp"

class chirriante : public component{
public:
	chirriante();
	~chirriante();
	void update() override;
	
};

#endif /* chirriante_hpp */
