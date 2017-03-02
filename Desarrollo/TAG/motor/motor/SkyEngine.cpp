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

TNodo* SkyEngine::crearRama(TNodo* padre, TEntidad* ent){
	TNodo *nR = new TNodo(), *nS = new TNodo(), *nT = new TNodo(), *nResult = new TNodo();
	TTransform *tR = new TTransform(), *tS = new TTransform(), *tT = new TTransform();
	
	padre->addHijo(nR);
	nR->addHijo(nS);
	nS->addHijo(nT);
	nT->addHijo(nResult);
	
	
	nR->setEntidad(tR);
	nS->setEntidad(tS);
	nT->setEntidad(tT);
	nResult->setEntidad(ent);
	
	return nResult;
}

TNodo* SkyEngine::crearMalla(TNodo* padre){
	return crearRama(padre ? padre : root, new TMalla());
}

TNodo* SkyEngine::crearCamara(TNodo* padre){
	return crearRama(padre ? padre : root, new TCamara());
}

TNodo* SkyEngine::crearLuz(TNodo* padre){
	return crearRama(padre ? padre : root, new TLuz());
}

void SkyEngine::Draw(){
	
}

void SkyNodo::builTransform(){
	
	for (int i=0; i<3; i++) {
		TransNodos[i] = new TNodo;
		Trans[i] = new TTransform;
		TransNodos[i]->setEntidad(Trans[i]);
		if(i==0) continue;
		TransNodos[i]->addHijo(TransNodos[i-1]);
	}
}


