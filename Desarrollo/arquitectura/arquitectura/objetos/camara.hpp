
#ifndef camara_hpp
#define camara_hpp

#include <stdio.h>
#include "GameObject.hpp"

class camara : public GameObject {
public:
    camara();
    ~camara();
	void addCamara(float* p, float* l);
private:
	class render* renderizador;
};
#endif /* camara_hpp */
