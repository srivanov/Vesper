
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
	//delete r;
	r = NULL;
}

void input::update(){
    float* velocidad = new float[3]{0,0,0};
    if(MyEventReceiver::Instance()->IsKeyDown('W')){
        velocidad[1] =  1;
    }
    if(MyEventReceiver::Instance()->IsKeyDown('S')){
        velocidad[1] = -1;
    }
    if(MyEventReceiver::Instance()->IsKeyDown('A')){
        velocidad[0] = -1;
    }
    if(MyEventReceiver::Instance()->IsKeyDown('D')){
        velocidad[0] =  1;
    }

//        com->mover(velocidad);
    Game::Instance()->getPlayer()->mover(velocidad);
	
    if(MyEventReceiver::Instance()->getLeftClick()){
//        if(difftime(time(NULL), tiempoDisparo) >= cadenciaDisparo){
//		if(2000.0 * (clock()-tiempoDisparo) / CLOCKS_PER_SEC >= (1000.0 / cadenciaDisparo)){
//                bala* disparo = new bala(padre->getPosicion());
//                disparo->addNodo("../../../arquitectura/3d/bala.3ds");
//            Game::Instance()->insertBala();
			Game::Instance()->atacarJugador();
			
//            tiempoDisparo = clock();
//        }
    }
	
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
