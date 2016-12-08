
#include "input.hpp"
#include "GameObject.hpp"

input::input(){
	r = MyEventReceiver::Instance();
}

input::~input(){
	
}

void input::update(){
	transform3D *com = (class transform3D*)padre->findComponent("transform3D");
	if(com != NULL){
		float* velocidad = new float[3]{0,0,0};
		if(MyEventReceiver::Instance()->IsKeyDown('W')){
			velocidad[1] =  0.2;
		}
		if(MyEventReceiver::Instance()->IsKeyDown('S')){
			velocidad[1] = -0.2;
		}
		if(MyEventReceiver::Instance()->IsKeyDown('A')){
			velocidad[0] = -0.2;
		}
		if(MyEventReceiver::Instance()->IsKeyDown('D')){
			velocidad[0] =  0.2;
		}
		if(velocidad[0] != 0 || velocidad[1] != 0 || velocidad[2] != 0)
			com->mover(velocidad);
	}
}
