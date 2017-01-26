
#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "../components/armas.hpp"
#include "../components/pistola.hpp"
#include "../Dvector.hpp"

class player : public GameObject{
public:
    player();
    ~player();
	void atacar();
	void cambiarArma();
	void contacto(GameObject* g);
    bool const* getmuero();
	void mover(dvector3D &vel);
	void setVelocidad(unsigned int vel);
	void activarHab();
	bool habActiva();
    unsigned int* getVel();
	
private:
	armas* arma;
    bool muero;
	unsigned int velocidad;
};

#endif /* player_hpp */
