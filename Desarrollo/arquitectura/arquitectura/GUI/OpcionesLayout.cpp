//
//  OpcionesLayout.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 8/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "OpcionesLayout.hpp"
#include "../components/ventana.hpp"
#include "Game.hpp"

OpcionesLayout::OpcionesLayout(){
    init("3d/GUI", ventana::Instance()->getDevice());
    
    layout = tOpcionesLayout;
    
    loadScheme("Generic.scheme");
    loadScheme("OgreTray.scheme");
    loadScheme("Menu.scheme");
    loadLayout("Opciones.layout");
    setMouseCursor("OgreTrayImages/MouseArrow");
    
    
    label_ajustes = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(7));
    
    button_controles = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(3));
    button_controles->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&OpcionesLayout::onClickControles, this));
    
    button_sonido = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(4));
    button_sonido->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&OpcionesLayout::onClickControles, this));
    
    button_pantalla = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(5));
    button_pantalla->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&OpcionesLayout::onClickControles, this));
    
    button_volver = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(6));
    button_volver->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&OpcionesLayout::onClickVolver, this));
}

OpcionesLayout::~OpcionesLayout(){
    
}

//void OpcionesLayout::update() {
//
//}

tLayout OpcionesLayout::getLayout() {
    return layout;
}

void OpcionesLayout::onClickControles(const CEGUI::EventArgs &e) {
    printf("Pulsado boton controles");
}

void OpcionesLayout::onClickSonido(const CEGUI::EventArgs &e) {
    printf("Pulsado boton sonido");
}

void OpcionesLayout::onClickPantalla(const CEGUI::EventArgs &e) {
    printf("Pulsado boton pantalla");
}

void OpcionesLayout::onClickVolver(const CEGUI::EventArgs &e) {
    padre->setActiveLayout(tMenuPrincipalLayout);
}

