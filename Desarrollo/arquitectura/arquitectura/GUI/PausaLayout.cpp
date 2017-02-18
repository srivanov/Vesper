//
//  PausaLayout.cpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 18/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "PausaLayout.hpp"
#include "../components/ventana.hpp"
#include "Game.hpp"

PausaLayout::PausaLayout(){
    init("3d/GUI", ventana::Instance()->getDevice());
    
    layout = tPausa;
    
    loadScheme("Generic.scheme");
    loadScheme("OgreTray.scheme");
    loadScheme("Menu.scheme");
    loadScheme("AlfiskoSkin.scheme");
    loadLayout("Pause.layout");
    setMouseCursor("OgreTrayImages/MouseArrow");
    
    label_pausa = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(2));
    
    button_continuar = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(3));
    button_continuar->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&PausaLayout::onClickContinuar, this));
    
    button_guardar = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(4));
    button_guardar->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&PausaLayout::onClickGuardar, this));
    
    button_menuprincipal = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(5));
    button_menuprincipal->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&PausaLayout::onClickMenuPrincipal, this));
    
    button_salir = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(6));
    button_salir->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&PausaLayout::onClickSalir, this));
}

PausaLayout::~PausaLayout() {
    
}

tLayout PausaLayout::getLayout() {
    return layout;
}

void PausaLayout::onClickContinuar(const CEGUI::EventArgs &e) {
    printf("Pulsado boton continuar");
    // TO DO: Hacer una funcion en Game para poder continuar el juego o tener un bool que cambie en función de si esta pausado o no y modificar el bool aqui tambien
    
}

void PausaLayout::onClickGuardar(const CEGUI::EventArgs &e) {
    printf("Pulsado boton guardar");
    // TO DO: Guardar en un fichero XML el nivel actual en el que se guarda el juego para poder cargarlo cuando sea necesario
}

void PausaLayout::onClickMenuPrincipal(const CEGUI::EventArgs &e) {
    printf("Pulsado boton menu principal");
    padre->setActiveLayout(tMenuPrincipalLayout);
}

void PausaLayout::onClickSalir(const CEGUI::EventArgs &e) {
    printf("Pulsado boton salir");
    Game::Instance()->stop();
}
