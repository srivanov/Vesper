//
//  MenuPrincipalLayout.cpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 08/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "MenuPrincipalLayout.hpp"


MenuPrincipalLayout::MenuPrincipalLayout() {
    // El codigo que habia aqui esta ahora en inicializar()
}

void MenuPrincipalLayout::init(CEGUI::RenderTarget* target) {
    GUI::init(target);
    loadScheme("Generic.scheme");
    loadScheme("OgreTray.scheme");
    loadScheme("Menu.scheme");
    loadLayout("MenuPrincipal.layout");
    setMouseCursor("OgreTrayImages/MouseArrow");
	
    button_nueva = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(3));
    button_nueva->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuPrincipalLayout::onClickStartGame, this));
    
    button_cargarpartida = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(4));
    button_cargarpartida->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuPrincipalLayout::onClickLoadScreen, this));
    
    button_opciones = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(5));
    button_opciones->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuPrincipalLayout::onClickOptions, this));
    
    button_creditos = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(6));
    button_creditos->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuPrincipalLayout::onClickCredits, this));
    
    button_salir = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(7));
    button_salir->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuPrincipalLayout::onClickStopGame, this));
    
    
    static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(1))->moveToBack();
}

void MenuPrincipalLayout::onClickStartGame(const CEGUI::EventArgs &e) {
    printf("Empieza una nueva partida");
	actualState->menu = tmELEGIR_PERSONAJE;
	actualState->empezar();
}

void MenuPrincipalLayout::onClickLoadScreen(const CEGUI::EventArgs &e){
    printf("Voy a la pantalla cargar partida");
    actualState->menu = tmELEGIR_PERSONAJE;
    actualState->cargarPartida();
}

void MenuPrincipalLayout::onClickOptions(const CEGUI::EventArgs &e){
    printf("Lleva al menú opciones");
    actualState->menu = tmOPCIONES;
}

void MenuPrincipalLayout::onClickCredits(const CEGUI::EventArgs &e){
    printf("Lleva a la pantalla de creditos");
    actualState->menu = tmCREDITOS;
}

void MenuPrincipalLayout::onClickStopGame(const CEGUI::EventArgs &e){
    printf("Salgo del juego");
    actualState->nextState = STOP;
}

