
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
	
private:
	armas* arma;
};

#endif /* player_hpp */
