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
    
    
//    aux = new CreditosLayout();
//    aux->ocultar();
//    vector.push_back(aux);
    
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
    //TO DO: hacer aqui el cambio de un layout a otro segun el tipo en activeLayout aka borrar el layout actual y cargar el nuevo. Si los ocultamos, se haria en este metodo tambien.
    
    // Recorrer el vector ocultando todos los layouts menos el que tenga el tipo activeLayout.
    
    // Ocultar el vector en plan, solo el vector, no hace falta recorrer
    
    // O sea, ocultamos el actual y recorremos el vector para mostrar unicamente el nuevo/activo
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

void LayoutGUI::posicionarRaton(float x, float y){
    seleccionado->injectMousePosition(x, y);
}

void LayoutGUI::inyectarClick(){
    seleccionado->injectLeftMouseButton();
}

void LayoutGUI::inyectarClickUP(){
    seleccionado->injectLeftMouseButtonUp();
}
