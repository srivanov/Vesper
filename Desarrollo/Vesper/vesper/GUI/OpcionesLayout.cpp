//
//  OpcionesLayout.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 8/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "OpcionesLayout.hpp"
#include "../components/ventana.hpp"
#include "../Game.hpp"
#include "../JSONParser.hpp"
#include <map>

OpcionesLayout::OpcionesLayout() {
    
}

void OpcionesLayout::init(CEGUI::RenderTarget* target){
    GUI::init(target);
    loadScheme("Generic.scheme");
    loadScheme("OgreTray.scheme");
    loadScheme("Menu.scheme");
    loadScheme("AlfiskoSkin.scheme");
    loadLayout("Opciones.layout");
    setMouseCursor("OgreTrayImages/MouseArrow");
    
//    label_ajustes = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(7));
    
    button_controles = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(3));
    button_controles->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&OpcionesLayout::onClickControles, this));
    
    button_sonido = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(2)->getChild(4));
    button_sonido->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&OpcionesLayout::onClickSonido, this));
    
    
    
    button_volver = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(6));
    button_volver->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&OpcionesLayout::onClickVolver, this));
    
    contenedor_sonido = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(11));
    contenedor_sonido->hide();
    
    contenedor_controles = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(15));
    contenedor_controles->hide();
    
    check_sonido = static_cast<CEGUI::ToggleButton*>(contenedor_sonido->getChild(18));
    
    slider_volumen = static_cast<CEGUI::Slider*>(contenedor_sonido->getChild(14));
    
    button_guardar = static_cast<CEGUI::PushButton*>(getContext()->getRootWindow()->getChild(0)->getChild(17));
    button_guardar->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&OpcionesLayout::onClickGuardar, this));
    
    button_guardar->hide();
    
    // TO DO: Hacer un metodo que ponga los controles segun los datos que ponga en el archivo JSON
    setControles();
}

void OpcionesLayout::onClickControles(const CEGUI::EventArgs &e) {
    printf("Pulsado boton controles");
    contenedor_sonido->hide();
    contenedor_controles->show();
	button_guardar->hide();
}

void OpcionesLayout::onClickSonido(const CEGUI::EventArgs &e) {
    printf("Pulsado boton sonido");
    contenedor_sonido->show();
    contenedor_controles->hide();
    button_guardar->show();
}


void OpcionesLayout::onClickVolver(const CEGUI::EventArgs &e) {
    actualState->menu = tmMENUPRINCIPAL;
}



void OpcionesLayout::onClickGuardar(const CEGUI::EventArgs &e) {
    std::map<char*, char*> valores;
    char* sonido = (char*)(check_sonido->isSelected()  ? "true":"false");
    char buf[3];
    sprintf(buf,"%d", (int)slider_volumen->getCurrentValue());
    
    valores.insert(std::pair<char*, char*>("sonido", sonido));
    valores.insert(std::pair<char*, char*>("volumen", buf));
    valores.insert(std::pair<char*, char*>("resolucion", "1280x720"));
    
    JSONParser::guardar(controlesFile, valores);
}

void OpcionesLayout::setControles() {
	
	std::map<std::string, std::string> valores = JSONParser::leer(controlesFile);
	
	bool sonido_pred = true;
	int volumen_pred = 100;
	
	if(valores.size() > 0){
		sonido_pred = JSONParser::toBool(valores.at("sonido"));
		volumen_pred = JSONParser::toInt(valores.at("volumen"));
	}
	check_sonido->setSelected(sonido_pred);
	slider_volumen->setCurrentValue(volumen_pred);
}
