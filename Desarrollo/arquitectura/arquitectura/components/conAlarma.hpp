
#ifndef conAlarma_hpp
#define conAlarma_hpp

#include <stdio.h>
#include "component.hpp"

class conAlarma : public component{
public:
	conAlarma();
//	~conAlarma() override;
	~conAlarma();
	void update() override;
	
};

#endif /* conAlarma_hpp */
