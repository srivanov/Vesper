
#ifndef transform3D_hpp
#define transform3D_hpp

#include <stdio.h>
#include "component.hpp"


class transform3D : public component{
public:
	transform3D();
    ~transform3D();
	void mover(float* velocidad);

};
#endif /* transform3D_hpp */
