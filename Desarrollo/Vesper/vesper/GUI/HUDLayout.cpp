//
//  HUDLayout.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 9/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "HUDLayout.hpp"

HUDLayout::HUDLayout() {
    
}

void HUDLayout::init(){
	GUI::init((CEGUI::RenderTarget*)states::Instance()->renderTarget);
    loadScheme("Generic.scheme");
    loadScheme("OgreTray.scheme");
    loadScheme("Menu.scheme");
    loadLayout("HUD.layout");
    setMouseCursor("OgreTrayImages/MouseArrow");
    

    moneda0 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(2));
//    moneda0->hide();
    
    moneda1 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(3));
//    moneda1->show();
    
    moneda2 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(4));
//    moneda2->hide();
    
    moneda3 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(5));
//    moneda3->hide();
    
    pistola = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(11));
    pistola->show();
    
    supersocker = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(12));
    supersocker->hide();
    
    lanzacaramelos = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(13));
    lanzacaramelos->hide();
    
    bombahumo = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(14));
    bombahumo->hide();
    
    chicle = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(15));
    chicle->hide();
    
    globo = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(16));
    globo->hide();
    
    martillo = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(17));
    martillo->hide();
    
    piedra = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(18));
    piedra->hide();
    
    vida = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(19));
    vida->setProgress(0.5);
}

void HUDLayout::getVida(int v){
    float normal_life = (float)v * 0.01; // Paso la vida a un numero entre 0 y 1 para la progress bar
    vida->setProgress(normal_life);
}

void HUDLayout::getMonedas(int v){
    if(v == 1){
        moneda0->hide();
        moneda1->show();
        moneda2->hide();
        moneda3->hide();
    }else if(v == 2){
        moneda0->hide();
        moneda1->hide();
        moneda2->show();
        moneda3->hide();
    }else if(v == 3){
        moneda0->hide();
        moneda1->hide();
        moneda2->hide();
        moneda3->show();
    }else{
        moneda0->hide();
    	moneda1->hide();
    	moneda2->hide();
    	moneda3->show();
    }
}

HUDLayout::~HUDLayout(){

}
