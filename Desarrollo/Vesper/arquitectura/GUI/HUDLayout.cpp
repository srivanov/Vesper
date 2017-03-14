//
//  HUDLayout.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 9/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "HUDLayout.hpp"
#include "../components/ventana.hpp"
#include "Game.hpp"

HUDLayout::HUDLayout(){
    init("3d/GUI", ventana::Instance()->getDevice());
    
    layout = tHUD;
    
    loadScheme("Generic.scheme");
    loadScheme("OgreTray.scheme");
    loadScheme("Menu.scheme");
    loadLayout("HUD.layout");
    setMouseCursor("OgreTrayImages/MouseArrow");
    
    button_volver = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2));
    button_volver->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&HUDLayout::onClickVolver, this));
}

HUDLayout::~HUDLayout(){
    
}

//void CargarPartidaLayout::update() {
//
//}

tLayout HUDLayout::getLayout() {
    return layout;
}


void HUDLayout::onClickVolver(const CEGUI::EventArgs &e) {
    padre->setActiveLayout(tMenuPrincipalLayout);
}
