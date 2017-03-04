
#ifndef player_hpp
#define player_hpp

#include <iostream>
#include "GameObject.hpp"
#include "../components/armas.hpp"
#include "../components/gun.hpp"
#include "../Dvector.hpp"

class player : public GameObject{
public:
    player();
    ~player();
    void update();
    void render(float &interpolation);
	void atacar();
	void cambiarArma();
	void contacto(GameObject* g);
    void contactoEnd(GameObject* g);
    bool const* getmuero();
	void mover(dvector3D &vel);
	void setVelocidad(unsigned int vel);
	void activarHab();
	bool habActiva();
    void accionar();
    void cuerpoacuerpo();
    unsigned int* getVel();
	
private:
	armas* arma;
    bool muero;
	unsigned int velocidad;
    GameObject* obj_colisionado;
};

#endif /* player_hpp */
