//
//  CargarPartidaLayout.cpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 08/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "CargarPartidaLayout.hpp"
#include "../components/ventana.hpp"
#include "Game.hpp"

CargarPartidaLayout::CargarPartidaLayout() {
    
}

void CargarPartidaLayout::init(CEGUI::RenderTarget* target){
    GUI::init(target);
    loadScheme("Generic.scheme");
    loadScheme("OgreTray.scheme");
    loadScheme("Menu.scheme");
    loadLayout("CargarPartida.layout");
    setMouseCursor("OgreTrayImages/MouseArrow");
    
    
    label_cargar = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(7));
    
    button_partida1 = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(3)->getChild(8));
    button_partida1->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&CargarPartidaLayout::onClickPartida1, this));
    
    button_partida2 = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(4)->getChild(9));
    button_partida2->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&CargarPartidaLayout::onClickPartida2, this));
    
    button_partida3 = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(5)->getChild(10));
    button_partida3->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&CargarPartidaLayout::onClickPartida3, this));
    
    button_volver = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(6));
    button_volver->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&CargarPartidaLayout::onClickVolver, this));
}

CargarPartidaLayout::~CargarPartidaLayout(){
    
}

//void CargarPartidaLayout::update() {
//    
//}

void CargarPartidaLayout::onClickPartida1(const CEGUI::EventArgs &e) {
    printf("Pulsado boton partida 1");
}

void CargarPartidaLayout::onClickPartida2(const CEGUI::EventArgs &e) {
    printf("Pulsado boton partida 2");
}

void CargarPartidaLayout::onClickPartida3(const CEGUI::EventArgs &e) {
    printf("Pulsado boton partida 3");
}

void CargarPartidaLayout::onClickVolver(const CEGUI::EventArgs &e) {
//    padre->setActiveLayout(tMenuPrincipalLayout);
    actualState->menu = tmMENUPRINCIPAL;
}


