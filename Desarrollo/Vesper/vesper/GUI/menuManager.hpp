//
//  menuManager.hpp
//  estados
//
//  Created by Stoycho Ivanov Atanasov on 15/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef menuManager_hpp
#define menuManager_hpp

#include <map>
#include <iostream>
#include "estados.h"
#include "state.hpp"
#include "GUI.h"
#include "listaMenus.h"

class menuManager : public state{
public:
	menuManager();
	~menuManager();
	void update(const long &timePerFrame);
	void render(float &interpolation);
    void renderHUD() { glDisable(GL_DEPTH_TEST); hud.beginRender(); hud.render(); hud.endRender(); glEnable(GL_DEPTH_TEST); }
    void updateHUD() { hud.update(); }
    void InitRenderer();
    void Init();
	
private:
	std::map<tipoMenu,GUI*> menus;
	GUI* seleccionado;
    CEGUI::OpenGL3Renderer *m_IrrlichtRenderer; //TO DO: CAMBIAR A OPENGL3RENDERER CUANDO CAMBIEMOS A NUESTRO MOTOR
    CEGUI::RenderTarget* m_target;
    HUDLayout hud;
};

#endif /* menuManager_hpp */
