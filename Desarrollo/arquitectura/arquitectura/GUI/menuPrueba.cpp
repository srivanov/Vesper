//
//  menuPrueba.cpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 01/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "menuPrueba.hpp"
#include "../components/ventana.hpp"

void menuPrueba::inicializar(){
    init("3d/GUI", ventana::Instance()->getDevice());
    
    loadScheme("Generic.scheme");
    loadScheme("OgreTray.scheme");
    loadScheme("Menu.scheme");
    loadLayout("MenuPrincipal.layout");
    
    setMouseCursor("OgreTrayImages/MouseArrow");
    
    label_titulo = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(8));
    label_titulo->setText("VESPER");
//    label_titulo->setFont("GreatVibes-22.font");
    
    button_nueva = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(3));
    button_nueva->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&menuPrueba::onClickStartGame, this));
    
//    loadLayout("Opciones.layout");
//    
//    label_ajustes = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(7));

//    loadLayout("CargarPartida.layout");
//    label_cargar = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(7));
}

void menuPrueba::update(){
    
}

bool menuPrueba::onClickStartGame(const CEGUI::EventArgs &e) {
//    injectMouseClick();
    printf("Empieza una nueva partida");
    
    return true;
}
