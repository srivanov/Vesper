
#include "input.hpp"
#include "GameObject.hpp"
#include "bala.hpp"
#include "Game.hpp"

input::input(){
	r = MyEventReceiver::Instance();
    tiempoDisparo = time(NULL);
    cadenciaDisparo = 1.0;
}

input::~input(){
	
}

void input::update(){
//	transform3D *com = (class transform3D*)padre->findComponent("transform3D");
//	if(com != NULL){
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
        
        if(MyEventReceiver::Instance()->IsKeyDown('L')){
            if(difftime(time(NULL), tiempoDisparo) >= cadenciaDisparo){
//                bala* disparo = new bala(padre->getPosicion());
//                disparo->addNodo("../../../arquitectura/3d/bala.3ds");
                Game::Instance()->insertBala();
                
                tiempoDisparo = time(NULL);
            
            }
            
        }
        
		if(MyEventReceiver::Instance()->IsKeyDown('Q')){
//			class render *com = (class render*)padre->findComponent("render");
//			if(com != NULL){
//				com->closeWindow();
//			}
            
            Game::Instance()->stop();
		}
//	}
}
