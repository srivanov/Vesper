//
//  transform3D.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 1/12/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "transform3D.hpp"

transform3D::transform3D(GameObject* p){
	padre = p;
}

transform3D::~transform3D(){
	delete padre;
}
