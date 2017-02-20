//
//  menuPrueba.cpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 01/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "menuPrueba.hpp"
#include "../components/ventana.hpp"
#include "Game.hpp"

void menuPrueba::inicializar(){
    init("3d/GUI", ventana::Instance()->getDevice());
    //layout = 0;
    
    loadScheme("Generic.scheme");
    loadScheme("OgreTray.scheme");
    loadScheme("Menu.scheme");
    loadLayout("MenuPrincipal.layout");
    estado = STATE_PRINCIPAL;
    setMouseCursor("OgreTrayImages/MouseArrow");
    
    //    loadLayout("CargarPartida.layout");
    //    label_cargar = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(7));
    
    label_titulo = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(8));
    label_titulo->setText("VESPER");
//    label_titulo->setFont("GreatVibes-22.font");
    
    button_nueva = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(3));
//    button_nueva->setText("Nueva partida");
    button_nueva->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&menuPrueba::onClickStartGame, this));
    
    button_cargar = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(4));
    button_cargar->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&menuPrueba::onClickLoadScreen, this));
    
    button_opciones = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(5));
    button_opciones->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&menuPrueba::onClickOptions, this));
    
    button_creditos = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(6));
    button_creditos->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&menuPrueba::onClickCredits, this));
    
    button_salir = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(7));
    button_salir->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&menuPrueba::onClickStopGame, this));
}

void menuPrueba::update(){
//    switch (estado) {
//        case STATE_PRINCIPAL:
//            loadLayout("MenuPrincipal.layout");
//    
//            break;
//        case STATE_CARGAR:            loadLayout("CargarPartida.layout");
//            
//            break;
//            
//        case STATE_OPCIONES:
//            loadLayout("Opciones.layout");
//            
//            break;
//            
//        case STATE_CREDITOS:
//            //loadLayout("Creditos.layout");
//            
//            break;
//            
//        default:
//            break;
//    }
}

void menuPrueba::onClickStartGame(const CEGUI::EventArgs &e) {
	// TO DO: que lleve a empezar nueva partida
    printf("Empieza una nueva partida");
    
}

void menuPrueba::onClickLoadScreen(const CEGUI::EventArgs &e){
    //TO DO: que lleve a la pantalla de cargar partida
    estado = STATE_CARGAR;
    printf("Voy a la pantalla cargar partida");
}

void menuPrueba::onClickOptions(const CEGUI::EventArgs &e){
    //TO DO: que lleve a la pantalla de opciones
    printf("Lleva al menú opciones");
}

void menuPrueba::onClickCredits(const CEGUI::EventArgs &e){
    //TO DO: pantalla de creditos
    printf("Lleva a la pantalla de creditos");
}

void menuPrueba::onClickStopGame(const CEGUI::EventArgs &e){
    //TO DO: salir del juego
    printf("Salgo del juego");
    Game::Instance()->stop();
}

//void menuPrueba::setLayout(int e){
//    layout = e;
//    
//    if(layout == 0){
//        loadLayout("MenuPrincipal.layout");
//    }else if(layout == 1){
//        loadLayout("CargarPartida.layout");
//    }else if(layout == 2){
//        loadLayout("Opciones.layout");
//    }else if(layout == 3){
//        loadLayout("Creditos.layout");
//    }
//}
