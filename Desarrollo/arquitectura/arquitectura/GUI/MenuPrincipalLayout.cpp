//
//  MenuPrincipalLayout.cpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 08/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "MenuPrincipalLayout.hpp"
#include "../components/ventana.hpp"
#include "../Game.hpp"

MenuPrincipalLayout::MenuPrincipalLayout() {
    init("3d/GUI", ventana::Instance()->getDevice());
    
    layout = tMenuPrincipalLayout;
    
    loadScheme("Generic.scheme");
    loadScheme("OgreTray.scheme");
    loadScheme("Menu.scheme");
    loadLayout("MenuPrincipal.layout");
    setMouseCursor("OgreTrayImages/MouseArrow");
    
    label_titulo = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(8));
    label_titulo->setText("VESPER");
    
    button_nueva = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(3));
    button_nueva->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuPrincipalLayout::onClickStartGame, this));
    
    button_cargar = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(4));
    button_cargar->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuPrincipalLayout::onClickLoadScreen, this));
    
    button_opciones = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(5));
    button_opciones->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuPrincipalLayout::onClickOptions, this));
    
    button_creditos = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(6));
    button_creditos->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuPrincipalLayout::onClickCredits, this));
    
    button_salir = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(7));
    button_salir->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MenuPrincipalLayout::onClickStopGame, this));
}

tLayout MenuPrincipalLayout::getLayout() {
    return layout;
}

void MenuPrincipalLayout::onClickStartGame(const CEGUI::EventArgs &e) {
    // TO DO: que lleve a empezar nueva partida
    printf("Empieza una nueva partida");
    
}

void MenuPrincipalLayout::onClickLoadScreen(const CEGUI::EventArgs &e){
    //TO DO: que lleve a la pantalla de cargar partida
    layout = tCargarPartidaLayout; // Estado 1 = CargarPartida
    printf("Voy a la pantalla cargar partida");
}

void MenuPrincipalLayout::onClickOptions(const CEGUI::EventArgs &e){
    //TO DO: que lleve a la pantalla de opciones
    layout = tOpcionesLayout;
    printf("Lleva al menú opciones");
}

void MenuPrincipalLayout::onClickCredits(const CEGUI::EventArgs &e){
    //TO DO: pantalla de creditos
    layout = tCreditosLayout;
    printf("Lleva a la pantalla de creditos");
}

void MenuPrincipalLayout::onClickStopGame(const CEGUI::EventArgs &e){
    //TO DO: salir del juego
    printf("Salgo del juego");
    Game::Instance()->stop();
}
