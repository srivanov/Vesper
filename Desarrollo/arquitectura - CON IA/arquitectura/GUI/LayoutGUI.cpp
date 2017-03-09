//
//  Layout.cpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 08/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "LayoutGUI.hpp"

LayoutGUI::LayoutGUI(){
    //TO DO: rellenar vector con layouts y poner todos ocultos menos el primero que se muestra
    Motor::GUI* aux;
    
    aux = new MenuPrincipalLayout();
    //aux->mostrar();
    aux->setPadre(this);
    seleccionado = aux;
    vector.push_back(aux);
    
    aux = new CargarPartidaLayout();
    aux->ocultar();
    aux->setPadre(this);
    vector.push_back(aux);
    
    aux = new OpcionesLayout();
    aux->ocultar();
    aux->setPadre(this);
    vector.push_back(aux);
    
    aux = new CreditosLayout();
    aux->ocultar();
    aux->setPadre(this);
    vector.push_back(aux);
    
    aux = new HUDLayout();
    aux->ocultar();
    aux->setPadre(this);
    vector.push_back(aux);
    
    aux = new PausaLayout();
    aux->ocultar();
    aux->setPadre(this);
    vector.push_back(aux);
    
    aux = new depuracionIA();
    aux->ocultar();
    aux->setPadre(this);
    vector.push_back(aux);
    
    iter = vector.begin();
}

LayoutGUI::~LayoutGUI(){
    iter = vector.begin();
    while(iter != vector.end()) {
        delete (*iter);
        
        iter++;
    }
    
    vector.clear();
}

void LayoutGUI::update(){
    
}

void LayoutGUI::setActiveLayout(tLayout nuevo){
    seleccionado->ocultar();
    activeLayout = nuevo;

    iter = vector.begin();
    while(iter != vector.end()) {
        if(activeLayout == (*iter)->getLayout()){
            (*iter)->mostrar();
            seleccionado = (*iter);
//            iter = vector.end();
            break;
        }
        iter++;
    }
}

void LayoutGUI::setActiveLayoutDebug(){
    iter = vector.begin();
    while(iter != vector.end()) {
        if(activeLayout == tdepuracionIA){
            (*iter)->mostrar();
            seleccionado = (*iter);
            break;
        }
        iter++;
    }
}
void LayoutGUI::showDebugMenu(){
    setActiveLayout(tdepuracionIA);
    iter = vector.end();
}

void LayoutGUI::posicionarRaton(float x, float y){
    seleccionado->injectMousePosition(x, y);
}

void LayoutGUI::inyectarClick(){
    seleccionado->injectLeftMouseButton();
}

void LayoutGUI::inyectarClickUP(){
    seleccionado->injectLeftMouseButtonUp();
}
