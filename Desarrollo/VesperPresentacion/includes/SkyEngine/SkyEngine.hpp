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
#include "SkyMallaAnimada.hpp"
#include "SkyLuz.hpp"
#include <map>

class SkyWindow;

class SkyEngine {
public:
	static SkyEngine* Instance() { static SkyEngine p; return &p; }
	~SkyEngine();
	SkyMalla* crearMalla(SkyNodo* padre, tipoMalla t);
	SkyCamara* crearCamara(SkyNodo* padre);
	SkyLuz* crearLuz(SkyNodo* padre);
    SkyMallaAnimada * crearMallaAnimada(SkyNodo* padre);
	void Draw();
	bool setActiveCam(int i);
	int getActiveCam() { return active_cam; }
	SkyCamara* removeCam(SkyCamara* cam);
	SkyLuz* removeLight(SkyLuz* luz);
	void debugON(bool p) { debug = p; }
	void init();
    void setAntiAliasing(bool set);
private:
	SkyEngine();
	TNodo* root;
	std::map<int, SkyCamara*> camaras;
	std::map<int, SkyLuz*> luces;
	int num_c, num_l, active_cam;
	bool debug, AntiAliasing;
	ShaderManager* shMan;
	SkyWindow* window;
	void renderScene(bool pass);
	void renderCamaras();
	void limpiar();
	void renderZbuffer();
};


#endif /* SkyEngine_hpp */

