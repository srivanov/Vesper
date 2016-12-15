
#include "transform3D.hpp"
#include "../objetos/GameObject.hpp"

transform3D::transform3D(){
	
}

transform3D::~transform3D(){
	
}

void transform3D::mover(float* velocidad){
	getFather()->mover(velocidad);
}
