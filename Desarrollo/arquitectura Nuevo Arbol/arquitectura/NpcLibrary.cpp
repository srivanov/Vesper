//
//  NpcLibrary.cpp
//  arquitectura
//
//  Created by Gaspar Rodriguez Valero on 10/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "NpcLibrary.hpp"

/*
 NPC_LIBRARY
 */

NpcLibrary * NpcLibrary::library = 0;

NpcLibrary * NpcLibrary::instancia(){
    if(library==0) library = new NpcLibrary;
    return library;
}

NpcLibrary::NpcLibrary(){}
NpcLibrary::~NpcLibrary(){
    it = libros.begin();
    while (it!=libros.end()) {
        if(it->second)
            delete it->second;
        it++;
    }
    libros.clear();
}

NpcBook * NpcLibrary::add_book(const int &ID, dvector3D *posicion){
    it=libros.find(ID);
    if (it!=libros.end()) return nullptr;
    
    NpcBook * book = new NpcBook(ID,posicion);
    libros.insert(std::pair<int, NpcBook*>(ID,book));
    
    return book;
}

bool NpcLibrary::remove_book(const int &ID){
    it=libros.find(ID);
    if (it==libros.end()) return false;
    
    delete it->second;
    libros.erase(it);
    return true;
}

NpcBook * NpcLibrary::recover_book(const int &ID){
    it=libros.find(ID);
    if (it==libros.end()) return nullptr;
    return it->second;
}
/*
 EVENTOS
 */

Eventos::Eventos(int& ID, const Prioridades& tipo, dvector3D * posicion){
    m_ID = ID;
    m_posiciones.push_back(posicion);
    m_time = time(NULL) + 3;
}
Eventos::Eventos(int& ID,const Prioridades& tipo, std::vector<dvector3D*> posiciones){
    m_ID = ID;
    m_posiciones = posiciones;
}
Eventos::~Eventos(){}

/*
 NPC_BOOK
 */

NpcBook::NpcBook(const int& ID,dvector3D* posicion){
    m_ID = ID;
    salud = 100;
    estado = 0;
    srand(time(NULL));
    sed = rand()%20 + 1;
    hambre = rand()%20 + 1;
    PosicionPropia = posicion;
    VectorMovimiento = new dvector3D(0,0,0);
    Enemigo = Aviso = Ruido = Alarma = Evento = Alerta = false;
    pila.clear();
}

NpcBook::~NpcBook(){}

void NpcBook::notify(int& ID,const Prioridades& tipo, dvector3D * posicion){
    Evento = true;
    it = pila.find(tipo);
    if(it!=pila.end()) remove_EventsByType(it->first);
    
    pila.insert(std::pair<Prioridades, Eventos*>(tipo,new Eventos(ID,tipo,posicion)));
    
    if(tipo<P_VIDA)
        valueObjective(tipo);
}

void NpcBook::notify(int& ID,const Prioridades& tipo, std::vector<dvector3D*> posiciones){
    Evento = true;
    it = pila.find(tipo);
    if(it!=pila.end()) remove_EventsByType(it->first);
    
    pila.insert(std::pair<Prioridades, Eventos*>(tipo,new Eventos(ID,tipo,posiciones)));
}



void NpcBook::valueObjective(const Prioridades &tipo){
    it = pila.find(tipo);
    if(it==pila.end()) return;
    switch (it->first) {
        case P_ENEMIGO:
            Enemigo = true;
            changeObjective();
            Ruido = false;
            remove_EventsByType(P_RUIDO);
            break;
        case P_ALERTA:
            Alerta = true;
            break;
        case P_ALARMA:
            if(Enemigo) return;
            Alarma = true;
            changeObjective();
        case P_AVISO:
            Aviso = true;
            if(Ruido) return;
            changeObjective();
            break;
        case P_RUIDO:
            if (Enemigo) return;
            Ruido = true;
            changeObjective();
            break;
        case P_VOID: break;
        default:changeObjective();break;
    }
}
void NpcBook::changeObjective(){
    PosicionesDestino.clear();
    PosicionesDestino = PathPlanning(it->second->m_posiciones);
}

int NpcBook::getMoral(){
    int calculo = (salud * 50)+(hambre * 30)+(sed * 20);
    return calculo/100;
}

std::vector<dvector3D*> NpcBook::PathPlanning(std::vector<dvector3D*> posiciones){
    return  posiciones;
}

bool NpcBook::ExistEventByType(const Prioridades& tipo){
    it = pila.find(tipo);
    if(it==pila.end()) return false;
    valueObjective(tipo);
    return true;
}

bool NpcBook::updateObjetivo(){
    if(PosicionesDestino.empty()) return false;
    PosicionesDestino.erase(PosicionesDestino.begin());
    return true;
}

dvector3D * NpcBook::lastPosition() const{
    if(PosicionesDestino.empty()) return nullptr;
    return PosicionesDestino[0];
}

void NpcBook::resetVectorMovimiento(){
    VectorMovimiento->x = 0;
    VectorMovimiento->y = 0;
    VectorMovimiento->z = 0;
}
void NpcBook::updateBook(){
    it = pila.begin();
    while(it!=pila.end()){
        if(it->second->m_time<=time(NULL)
           && it->first!=P_PATRULLAR
           && it->first!=P_VIGILAR){
            delete it->second;
            pila.erase(it);
            it = pila.begin();
            continue;
        }
        it++;
    }
}

void NpcBook::remove_EventsByType(const Prioridades &tipo){
    it = pila.find(tipo);
    if(it==pila.end()) return;
    
    delete it->second;
    pila.erase(it);
}
