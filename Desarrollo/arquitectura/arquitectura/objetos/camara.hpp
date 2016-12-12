
#ifndef camara_hpp
#define camara_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "Fps.hpp"

class camara : public GameObject {
public:
    camara();
    ~camara();
	void addCamara(float* p, float* l);
	void movimientoInteligente(float* posPlayer);
private:
	class render* renderiza;
	float incrX, incrY, incrZ, offsetX, offsetY, offsetZ, camSpeed;
};
#endif /* camara_hpp */
