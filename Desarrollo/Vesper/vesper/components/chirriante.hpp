
#ifndef chirriante_hpp
#define chirriante_hpp

#include <stdio.h>
#include "component.hpp"
#include "puertaInterface.hpp"

class chirriante : public puertaInterface{
public:
	chirriante();
	~chirriante();
	void update();
	bool abre();
};

#endif /* chirriante_hpp */
