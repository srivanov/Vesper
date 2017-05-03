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
    
    button_player01 = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(5));
    button_player01->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ElegirPersonaje::onClickSelectPlayer, this));
    
    button_player02 = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(6));
    button_player02->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ElegirPersonaje::onClickSelectPlayer, this));
    
    button_player03 = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(7));
    button_player03->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ElegirPersonaje::onClickSelectPlayer, this));
}

void ElegirPersonaje::onClickVolver(const CEGUI::EventArgs &e){
    actualState->menu = tmMENUPRINCIPAL;
}

void ElegirPersonaje::onClickJugar(const CEGUI::EventArgs &e){
	actualState->nextState = PLAYING;
}

void ElegirPersonaje::saveCharacter(int p) {
    actualState->character = p;
}

void ElegirPersonaje::onClickSelectPlayer(const CEGUI::EventArgs &e) {
    button_player01->setRiseOnClickEnabled(false);
    
    if(button_player01->isPushed()) {
        saveCharacter(1);
    } else if(button_player02->isPushed()) {
        saveCharacter(2);
    } else if(button_player03->isPushed()) {
        saveCharacter(3);
    } else { }
    
}
