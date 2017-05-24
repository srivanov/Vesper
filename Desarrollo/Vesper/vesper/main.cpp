//
//  main.cpp
//  arquitectura
//
//  Created by Stoycho Ivanov Atanasov on 29/11/16.
//  Copyright © 2016 Stoycho Ivanov Atanasov. All rights reserved.
//

#include <iostream>
#include "Game.hpp"
#include "mundoBox2D.hpp"
#include "components/ventana.hpp"

int main(int argc, const char * argv[]) {
	//TO DO: Hacer los Singleton sin puntero y con const (ejemplo en Game)
	mundoBox2D::Instance();
	ventana::Instance();
	Game* game = Game::Instance();
	tiempo t;
	const long timePerFrame = 66;
	long timeSinceLastUpdate = 0;
	float interpolation;
	
	game->start(1280,720,32,true,false,true,true);
	t.start();
	
	while (game->isRunning()) {
		
		long elapsedTime = t.getTiempo();     //Actualizamos variables de tiempo
		t.reset();
		if(elapsedTime > 250)
			elapsedTime = 250;
		timeSinceLastUpdate += elapsedTime;
		
		//Llevamos control en las actualizaciones por frame
		while (timeSinceLastUpdate > timePerFrame) {	// 15 veces/segundo
			
			game->update(timePerFrame);
			
			timeSinceLastUpdate -= timePerFrame;
		}
		
		float aux = ((float)timeSinceLastUpdate / (float)timePerFrame);
		interpolation = aux<1.0f ? aux : 1.0f;
		
		//TO DO: interpolacion
		game->render(interpolation);
	}
    return 0;
}
