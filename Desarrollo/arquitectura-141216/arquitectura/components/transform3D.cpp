
#include "transform3D.hpp"
#include "GameObject.hpp"

transform3D::transform3D(){
	
}

transform3D::~transform3D(){
	
}

void transform3D::mover(float* velocidad){
	padre->mover(velocidad);
}
