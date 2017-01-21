
#ifndef camara_hpp
#define camara_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "../Fps.hpp"
#include "../Dvector.hpp"

class camara : public GameObject {
public:
    camara();
    ~camara();
	void addCamara(dvector3D &p, dvector3D &l);
	void movimientoInteligente(dvector3D &posPlayer);
    void setCamSpeed(float vel);
    void setZoom(bool z);
    bool getZoom();
private:
	class render* renderiza;
	float incrX, incrY, incrZ, offsetX, offsetY, offsetZ, camSpeed;
    bool cerca;
};
#endif /* camara_hpp */
