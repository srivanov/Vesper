//
//  Final_layout.cpp
//  vesper
//
//  Created by Nerea Castellanos Rodríguez on 23/5/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "Final_layout.hpp"
#include "../components/ventana.hpp"


Final_layout::Final_layout() {
    
}

void Final_layout::init(CEGUI::RenderTarget* target){
    GUI::init(target);
    loadScheme("Generic.scheme");
    loadScheme("OgreTray.scheme");
    loadScheme("Menu.scheme");
    loadLayout("final_layout.layout");
    setMouseCursor("OgreTrayImages/MouseArrow");
    
    button_salir = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(4));
    button_salir->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&PausaLayout::onClickSalir, this));
    
    button_salir2 = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(1)->getChild(6));
    button_salir2->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&PausaLayout::onClickSalir, this));
    
    button_continuar = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(1)->getChild(5));
    button_continuar->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&PausaLayout::onClickContinuar, this));
    
    button_reintentar = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(3));
    button_reintentar->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&PausaLayout::onClickReintentar, this));
    
}

Final_layout::~Final_layout() {
    
}


void Final_layout::onClickReintentar(const CEGUI::EventArgs &e) {
    printf("Pulsado boton reintentar\n");
}

void Final_layout::onClickContinuar(const CEGUI::EventArgs &e) {
    printf("Pulsado boton continuar\n");
    // TO DO: Hacer una funcion en Game para poder continuar el juego o tener un bool que cambie en función de si esta pausado o no y modificar el bool aqui tambien
    //Game::Instance()->setPausa(false);
    actualState->nextState = PLAYING;
}

void Final_layout::onClickSalir(const CEGUI::EventArgs &e) {
    printf("Pulsado boton salir\n");
    //    Game::Instance()->stop();
    actualState->menu = tmMENUPRINCIPAL;
    actualState->guardarPartida();
    actualState->destruir = true;
}
