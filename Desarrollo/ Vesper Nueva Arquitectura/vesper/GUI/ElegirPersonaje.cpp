//
//  ElegirPersonaje.cpp
//  vesper
//
//  Created by Nerea Castellanos Rodríguez on 2/4/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "ElegirPersonaje.hpp"

ElegirPersonaje::ElegirPersonaje(){
	
}

void ElegirPersonaje::init(CEGUI::RenderTarget* target){
	GUI::init(target);
    loadScheme("Generic.scheme");
    loadScheme("OgreTray.scheme");
    loadScheme("Menu.scheme");
    loadLayout("ElegirPersonaje.layout");
    setMouseCursor("OgreTrayImages/MouseArrow");
    
    button_volver = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(3));
    button_volver->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ElegirPersonaje::onClickVolver, this));
    
    button_jugar = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(4));
    button_jugar->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ElegirPersonaje::onClickJugar, this));
}

void ElegirPersonaje::onClickVolver(const CEGUI::EventArgs &e){
    actualState->menu = tmMENUPRINCIPAL;
}

void ElegirPersonaje::onClickJugar(const CEGUI::EventArgs &e){
	actualState->nextState = PLAYING;
}
