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
	static SkyEngine* Instance() { static SkyEngine p; return &p; }
	~SkyEngine();
	SkyMalla* crearMalla(TNodo* padre, tipoMalla t);
	SkyCamara* crearCamara(TNodo* padre);
	SkyLuz* crearLuz(TNodo* padre);
	void Draw();
	bool setActiveCam(int i);
	int getActiveCam() { return active_cam; }
	
private:
	SkyEngine() : num_c(0), num_l(0), active_cam(0) { root = new TNodo(); root->setEntidad(new TTransform()); }
	TNodo* root;
	std::map<int, SkyCamara*> camaras;
	std::map<int, SkyLuz*> luces;
	int num_c, num_l, active_cam;
};


#endif /* SkyEngine_hpp */

