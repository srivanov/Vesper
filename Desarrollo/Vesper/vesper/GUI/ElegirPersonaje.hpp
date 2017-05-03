//
//  ElegirPersonaje.hpp
//  vesper
//
//  Created by Nerea Castellanos Rodríguez on 2/4/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef ElegirPersonaje_hpp
#define ElegirPersonaje_hpp

#include <stdio.h>
#include "GUI.h"
#include "../MyEventReceiver.hpp"

class ElegirPersonaje : public GUI{
public:
    ElegirPersonaje();
	~ElegirPersonaje(){}
	
	void init(CEGUI::RenderTarget* target);
    void onClickVolver(const CEGUI::EventArgs &e);
    void onClickJugar(const CEGUI::EventArgs &e);
    void onClickSelectPlayer(const CEGUI::EventArgs &e);
    void saveCharacter(int p);
    
private:
    CEGUI::DefaultWindow *label_elegirpersonaje;
    CEGUI::PushButton *button_volver;
    CEGUI::PushButton *button_jugar;
    CEGUI::PushButton *button_player01;
    CEGUI::PushButton *button_player02;
    CEGUI::PushButton *button_player03;
    
    const char *characterFile = "character.json";
};


#endif /* ElegirPersonaje_hpp */
