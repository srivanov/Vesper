//
//  TCamara.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 7/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "TCamara.hpp"

TCamara::TCamara(){
	
}

TCamara::~TCamara(){
	
}

void TCamara::setPerspectiva(){
	
	esPerspectiva = true;
}

void TCamara::setParalela(){
	
	esPerspectiva = false;
}

void TCamara::setNearValue(float n){
	nearV = n;
}

void TCamara::setFarValue(float f){
	farV = f;
}

void TCamara::beginDraw(){
	
}

void TCamara::endDraw(){
	
}
