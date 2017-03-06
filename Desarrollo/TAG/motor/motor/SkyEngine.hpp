//
//  SkyEngine.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 2/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef SkyEngine_hpp
#define SkyEngine_hpp

#include "TNodo.hpp"
#include "SkyNodo.hpp"
#include "SkyMalla.hpp"
#include "SkyCamara.hpp"
#include "SkyLuz.hpp"
#include <map>

class SkyEngine {
public:
	SkyEngine() : num_c(0), num_l(0){ root = new TNodo(); }
	~SkyEngine();
	SkyMalla* crearMalla(TNodo* padre);
	SkyCamara* crearCamara(TNodo* padre);
	SkyLuz* crearLuz(TNodo* padre);
	void Draw();
	bool setActiveCam(int i);
	int getActiveCam() { return active_cam; }
	
private:
	TNodo* root;
	std::map<int, SkyCamara*> camaras;
	std::map<int, SkyLuz*> luces;
	int num_c, num_l, active_cam;
};


#endif /* SkyEngine_hpp */

