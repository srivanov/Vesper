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
    
//    loadScheme("AlfiskoSkin.scheme");
//    loadScheme("OgreTray.scheme");
////    loadScheme("menu.scheme");
//    loadLayout("prueba.layout");
//    
//    label_prueba = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(69));
//    
//    label_prueba->setText("HOLA CATHERINE");
    
    loadScheme("Generic.scheme");
    loadScheme("OgreTray.scheme");
    loadLayout("MenuPrincipal.layout");
    
    label_titulo = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(8));
    label_titulo->setText("VESPER");
//    label_titulo->setFont("GreatVibes-22.font");
    
    button_nueva = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(3));
    button_nueva->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&menuPrueba::onClickStartGame, this));
}

void menuPrueba::update(){
    
}

void menuPrueba::onClickStartGame(const CEGUI::EventArgs &e) {
    printf("Empieza una nueva partida");
}
