//
//  SkyEngine.cpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 2/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "SkyEngine.hpp"

SkyEngine::~SkyEngine(){
	delete root;
}

SkyMalla* SkyEngine::crearMalla(TNodo* padre){
	return new SkyMalla(padre ? padre : root);
}

SkyCamara* SkyEngine::crearCamara(TNodo* padre){
	SkyCamara* c = new SkyCamara(padre ? padre : root, num_c);
	camaras.insert(std::pair<int, SkyCamara*>(num_c, c));
	num_c++;
	return c;
}

SkyLuz* SkyEngine::crearLuz(TNodo* padre){
	SkyLuz* c = new SkyLuz(padre ? padre : root, num_l);
	luces.insert(std::pair<int, SkyLuz*>(num_l, c));
	num_l++;
	return c;
}

void SkyEngine::Draw(){
	std::map<int, SkyCamara*>::iterator iter = camaras.find(active_cam);
	if(iter != camaras.end())
		iter->second->Draw();
	else
		printf("SIN CAMARA\n");
	
	std::map<int, SkyLuz*>::iterator it = luces.begin();
	while(it != luces.end()){
		it->second->Draw();
		++it;
	}
	root->Draw();
}

bool SkyEngine::setActiveCam(int i){
	if(i<0 || i>num_c)
		return false;
	active_cam = i;
	return true;
}

//TO DO: apagar luz segun el ID
