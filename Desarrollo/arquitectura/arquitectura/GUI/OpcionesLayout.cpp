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
    loadScheme("AlfiskoSkin.scheme");
    loadLayout("Opciones.layout");
    setMouseCursor("OgreTrayImages/MouseArrow");
    
    label_ajustes = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(7));
    
    button_controles = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(3));
    button_controles->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&OpcionesLayout::onClickControles, this));
    
    button_sonido = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(4));
    button_sonido->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&OpcionesLayout::onClickSonido, this));
    
    button_pantalla = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(5));
    button_pantalla->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&OpcionesLayout::onClickPantalla, this));
    
    button_volver = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(6));
    button_volver->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&OpcionesLayout::onClickVolver, this));
    
    button_resol1 = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(8)->getChild(9));
    button_resol1->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&OpcionesLayout::onClickResol1, this));
    
    button_resol2 = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(8)->getChild(10));
    button_resol2->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&OpcionesLayout::onClickResol2, this));
    
    button_resol3 = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(8)->getChild(16));
    button_resol3->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&OpcionesLayout::onClickResol3, this));
    
    contenedor_pantalla = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(8));
    contenedor_pantalla->hide();
    
    contenedor_sonido = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(11));
    contenedor_sonido->hide();
    
    contenedor_controles = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(15));
    contenedor_controles->hide();

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
    contenedor_pantalla->hide();
    contenedor_sonido->hide();
    contenedor_controles->show();
}

void OpcionesLayout::onClickSonido(const CEGUI::EventArgs &e) {
    printf("Pulsado boton sonido");
    contenedor_pantalla->hide();
    contenedor_sonido->show();
    contenedor_controles->hide();
}

void OpcionesLayout::onClickPantalla(const CEGUI::EventArgs &e) {
    printf("Pulsado boton pantalla");
    contenedor_pantalla->show();
    contenedor_sonido->hide();
    contenedor_controles->hide();
}

void OpcionesLayout::onClickVolver(const CEGUI::EventArgs &e) {
    padre->setActiveLayout(tMenuPrincipalLayout);
}

void OpcionesLayout::onClickResol1(const CEGUI::EventArgs &e){
    printf("pulsado resol1");
}

void OpcionesLayout::onClickResol2(const CEGUI::EventArgs &e){
    printf("pulsado resol2");
}

void OpcionesLayout::onClickResol3(const CEGUI::EventArgs &e){
    printf("pulsado resol3");
}

