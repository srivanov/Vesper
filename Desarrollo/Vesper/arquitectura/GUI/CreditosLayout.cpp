//
//  CreditosLayout.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 9/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "CreditosLayout.hpp"
#include "../components/ventana.hpp"
#include "Game.hpp"

CreditosLayout::CreditosLayout(){
    init("3d/GUI", ventana::Instance()->getDevice());
    
    layout = tCreditosLayout;
    
    loadScheme("Generic.scheme");
    loadScheme("OgreTray.scheme");
    loadScheme("Menu.scheme");
    loadLayout("CreditosLayout.layout");
    setMouseCursor("OgreTrayImages/MouseArrow");
    
    
    label_creditos = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(2));
    
    button_volver = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(4));
    button_volver->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&CreditosLayout::onClickVolver, this));
}

CreditosLayout::~CreditosLayout(){
    
}

//void CargarPartidaLayout::update() {
//
//}

tLayout CreditosLayout::getLayout() {
    return layout;
}

void CreditosLayout::onClickVolver(const CEGUI::EventArgs &e) {
    padre->setActiveLayout(tMenuPrincipalLayout);
}


