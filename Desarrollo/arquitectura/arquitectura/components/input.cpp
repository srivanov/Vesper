
#include "input.hpp"
#include "../objetos/GameObject.hpp"
#include "../objetos/bala.hpp"
#include "../Game.hpp"

input::input(){
	r = MyEventReceiver::Instance();
    intervalo = clock();
    cadenciaDisparo = 5.0;
}

input::~input(){
	
}

void input::update(){
    dvector3D velocidad;
    
    if(MyEventReceiver::Instance()->IsKeyDown('W')){
        velocidad.y =  1;
    }
    if(MyEventReceiver::Instance()->IsKeyDown('S')){
        velocidad.y = -1;
    }
    if(MyEventReceiver::Instance()->IsKeyDown('A')){
        velocidad.x = -1;
    }
    if(MyEventReceiver::Instance()->IsKeyDown('D')){
        velocidad.x =  1;
    }
	
	if(MyEventReceiver::Instance()->IsKeyDown('s')){
		velocidad.x*=2; velocidad.y*=2;
		//TO DO: aumentar velocidad de la camara
	}
	
	if(MyEventReceiver::Instance()->IsKeyDown('E')){
		Game::Instance()->getPlayer()->activarHab();
		//TO DO: aumentar velocidad de la camara
	}
	
    Game::Instance()->getPlayer()->mover(velocidad);
	
    if(MyEventReceiver::Instance()->getLeftClick()){
		Game::Instance()->atacarJugador();
    }
	
	Game::Instance()->rotarConRaton(ventana::Instance()->posicionRaton(*Game::Instance()->getPlayer()->getPosicion()));
	
	if(MyEventReceiver::Instance()->IsKeyDown('t')){
		if(2000.0 * (clock()-intervalo) / CLOCKS_PER_SEC >= 500.0){
			Game::Instance()->cambiarArmaJugador();
			intervalo = clock();
		}
	}
	
    if(MyEventReceiver::Instance()->IsKeyDown('Q')){
        Game::Instance()->stop();
    }
	
    if(MyEventReceiver::Instance()->IsKeyDown('O')){
        Game::Instance()->zoom(false);
    }
    
    if(MyEventReceiver::Instance()->IsKeyDown('P')){
        Game::Instance()->zoom(true);
    }
}
