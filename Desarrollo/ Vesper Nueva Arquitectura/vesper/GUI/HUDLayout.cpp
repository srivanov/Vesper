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
    moneda0->hide();
    
    moneda1 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(3));
    moneda1->show();
    
    moneda2 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(4));
    moneda2->hide();
    
    moneda3 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(5));
    moneda3->hide();
    
    vida1 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(6));
//    vida1->hide();
    
    vida2 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(7));
//    vida2->show();
    
    vida3 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(8));
//    vida3->hide();
    
    vida4 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(9));
//    vida4->hide();
    
    vida5 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(10));
//    vida5->hide();
    
    pistola1 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(11));
    pistola1->show();
    
    pistola2 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(12));
    pistola2->hide();
    
    pistola3 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(13));
    pistola3->hide();
    
}

int HUDLayout::getVida(int v){
    if(v > 80){
        vida1->show();
        vida2->hide();
        vida3->hide();
        vida4->hide();
        vida5->hide();
    }else if(v > 50 && v < 80){
        vida1->hide();
        vida2->show();
        vida3->hide();
        vida4->hide();
        vida5->hide();
    }else if(v < 50 && v > 30){
        vida1->hide();
        vida2->hide();
        vida3->show();
        vida4->hide();
        vida5->hide();
    }else if(v < 30 && v > 10){
        vida1->hide();
        vida2->hide();
        vida3->hide();
        vida4->show();
        vida5->hide();
    }else{
        vida1->hide();
        vida2->hide();
        vida3->hide();
        vida4->hide();
        vida5->show();
    }
    
    return v;
}

int HUDLayout::getMonedas(int v){
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
return v;
}

HUDLayout::~HUDLayout(){

}
