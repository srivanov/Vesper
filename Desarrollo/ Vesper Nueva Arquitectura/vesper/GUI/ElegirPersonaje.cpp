//
//  ElegirPersonaje.cpp
//  vesper
//
//  Created by Nerea Castellanos Rodríguez on 2/4/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "ElegirPersonaje.hpp"
#include "../components/ventana.hpp"
#include "Game.hpp"

ElegirPersonaje::ElegirPersonaje(){
    init("3d/GUI", ventana::Instance()->getDevice());
    
    layout = tElegirPersonaje;
    
    loadScheme("Generic.scheme");
    loadScheme("OgreTray.scheme");
    loadScheme("Menu.scheme");
    loadLayout("ElegirPersonaje.layout");
    setMouseCursor("OgreTrayImages/MouseArrow");
    
    
    label_elegirpersonaje = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(2));
    
    button_volver = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(3));
    button_volver->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ElegirPersonaje::onClickVolver, this));
    
    button_jugar = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(4));
    button_jugar->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ElegirPersonaje::onClickJugar, this));
}

ElegirPersonaje::~ElegirPersonaje(){
    
}

tLayout ElegirPersonaje::getLayout(){
    return layout;
}

void ElegirPersonaje::onClickVolver(const CEGUI::EventArgs &e){
    padre->setActiveLayout(tMenuPrincipalLayout);
}

void ElegirPersonaje::onClickJugar(const CEGUI::EventArgs &e){
    Game::Instance()->setPausa(false);
    padre->setActiveLayout(tPausa);
}
