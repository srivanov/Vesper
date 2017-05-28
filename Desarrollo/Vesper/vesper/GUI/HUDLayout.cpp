//
//  HUDLayout.cpp
//  arquitectura
//
//  Created by Nerea Castellanos Rodríguez on 9/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "HUDLayout.hpp"
#include "../estados/estados.h"

HUDLayout::HUDLayout() {
    
}

void HUDLayout::init(){
	GUI::init((CEGUI::RenderTarget*)states::Instance()->renderTarget);
    loadScheme("Generic.scheme");
    loadScheme("OgreTray.scheme");
    loadScheme("Menu.scheme");
    loadLayout("HUD.layout");
    setMouseCursor("OgreTrayImages/MouseArrow");
    
    
    
    moneda1 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(3));
//    moneda1->show();
    
    moneda2 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(4));
//    moneda2->hide();
    
    moneda3 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(5));
//    moneda3->hide();
    
    llave1 = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(80));
    
    label = static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(22));
    
    armas.insert(std::pair<typeArma, CEGUI::DefaultWindow*>(tPISTOLA, static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(11))));
    
    armas.insert(std::pair<typeArma, CEGUI::DefaultWindow*>(tPALA, static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(50))));
    
    armas.insert(std::pair<typeArma, CEGUI::DefaultWindow*>(tESCOPETA, static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(12))));
    
    armas.insert(std::pair<typeArma, CEGUI::DefaultWindow*>(tLANZACARAMELOS, static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(13))));
    
    armas.insert(std::pair<typeArma, CEGUI::DefaultWindow*>(tBOMBAHUMO, static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(14))));
    
    armas.insert(std::pair<typeArma, CEGUI::DefaultWindow*>(tCHICLE, static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(15))));
    
    armas.insert(std::pair<typeArma, CEGUI::DefaultWindow*>(tGLOBOAGUA, static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(16))));
    
    armas.insert(std::pair<typeArma, CEGUI::DefaultWindow*>(tMARTILLO, static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(17))));
    
    armas.insert(std::pair<typeArma, CEGUI::DefaultWindow*>(tPIEDRA, static_cast<CEGUI::DefaultWindow*>(getContext()->getRootWindow()->getChild(0)->getChild(18))));
    
    ocultarArmas();
    actual = armas.begin()->second;
    actual->show();

    
    vida = static_cast<CEGUI::ProgressBar*>(getContext()->getRootWindow()->getChild(0)->getChild(19));
    vida->setProgress(0.5);
    estado = states::Instance();
}

void HUDLayout::update(){
    if(estado->datos.update){
        getVida(estado->datos.vida);
        getCarga(estado->datos.carga);
        getMunicion(estado->datos.municion);
        getllaves(estado->datos.llaves);
        getMonedas(estado->datos.monedas);
        mostrarArma(estado->datos.arma);
        estado->datos.update = false;
    }
}

void HUDLayout::getVida(int v){
    float normal_life = (float)v * 0.01; // Paso la vida a un numero entre 0 y 1 para la progress bar
    vida->setProgress(normal_life);
}

void HUDLayout::getMunicion(unsigned int municion) {
    //    label->setText("HOLA");
    //    printf("%d", municion);
    //    aux = carga_muni;
    carga_muni = aux + " / " + std::to_string(municion);
    label->setText(static_cast<CEGUI::String>(carga_muni));
}

void HUDLayout::getCarga(unsigned int carga){
    carga_muni = aux = std::to_string(carga);
    label->setText(static_cast<CEGUI::String>(carga_muni));
}

void HUDLayout::getMonedas(int v){
    printf("");
    if(v == 1){
        moneda1->show();
        moneda2->hide();
        moneda3->hide();
    }else if(v == 2){
        moneda1->show();
        moneda2->show();
        moneda3->hide();
    }else if(v>=3){
        moneda1->show();
        moneda2->show();
        moneda3->show();
    }else{
    	moneda1->hide();
    	moneda2->hide();
    	moneda3->hide();
    }
}

void HUDLayout::getllaves(int v){
    if(v == 1){
        llave1->show();
    }else{
        llave1->hide();
    }
}

void HUDLayout::ocultarArmas(){
    for(auto it = armas.begin(); it !=armas.end(); ++it){
        it->second->hide();
    }
}

void HUDLayout::mostrarArma(typeArma tipo){
    auto it = armas.find(tipo);
    
    if(it != armas.end()){
        actual->hide();
        actual = it->second;
        actual->show();
    }
}

HUDLayout::~HUDLayout(){

}
