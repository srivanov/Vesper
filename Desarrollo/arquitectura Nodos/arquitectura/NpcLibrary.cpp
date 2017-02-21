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

NpcBook * NpcLibrary::add_book(int &ID, dvector3D *posicion){
    it=libros.find(ID);
    if (it!=libros.end()) return nullptr;
    
    NpcBook * book = new NpcBook(ID,posicion);
    libros.insert(std::pair<int, NpcBook*>(ID,book));
    
    return book;
}

bool NpcLibrary::remove_book(int &ID){
    it=libros.find(ID);
    if (it==libros.end()) return false;
    
    delete it->second;
    libros.erase(it);
    return true;
}

NpcBook * NpcLibrary::recover_book(int &ID){
    it=libros.find(ID);
    if (it==libros.end()) return nullptr;
    return it->second;
}
/*
 EVENTOS
 */

Eventos::Eventos(int& ID, const Prioridades& tipo, dvector3D * posicion){
    m_tipo = tipo;
    m_ID = ID;
    m_posiciones.push_back(posicion);
    m_time = time(NULL) + 3;
}
Eventos::Eventos(int& ID,const Prioridades& tipo, std::vector<dvector3D*> posiciones){
    m_ID = ID;
    m_tipo = tipo;
    m_posiciones = posiciones;
}
Eventos::~Eventos(){}

/*
 NPC_BOOK
 */

NpcBook::NpcBook(int& ID,dvector3D* posicion) : m_ID(&ID){
    salud = 100;
    estado = 0;
    srand(time(NULL));
    sed = rand()%20 + 1;
    hambre = rand()%20 + 1;
    PosicionPropia = posicion;
    VectorMovimiento = new dvector3D(0,0,0);
}

NpcBook::~NpcBook(){
    m_ID = nullptr;
}

void NpcBook::notify(int& ID,const Prioridades& tipo, dvector3D * posicion){add_Event(ID,tipo, posicion);}

void NpcBook::notify(int& ID,const Prioridades& tipo, std::vector<dvector3D*> posiciones){add_Event(ID,tipo, posiciones);}

void NpcBook::add_Event(int& ID,const Prioridades& tipo, dvector3D *posicion){
    if (pila.empty()) {
        pila.push_back(new Eventos(ID,tipo,posicion));
        return;
    }
    for (int i=0; i<pila.size(); i++) {
        if(tipo>=pila[i]->m_tipo) continue;
        
        pila.insert(pila.begin()+i, new Eventos(ID,tipo,posicion));
        return;
    }
}

void NpcBook::add_Event(int& ID, const Prioridades& tipo, std::vector<dvector3D*> posiciones){
    if (pila.empty()) {
        pila.push_back(new Eventos(ID,tipo,posiciones));
        return;
    }
    for (int i=0; i<pila.size(); i++) {
        if(tipo>=pila[i]->m_tipo) continue;
        
        pila.insert(pila.begin()+i, new Eventos(ID,tipo,posiciones));
        return;
    }
}

bool NpcBook::ExistEventByType(const Prioridades& tipo){
    for (int i=0; i<pila.size(); i++) {
        if(pila[i]->m_tipo!=tipo) continue;
        changeObjective(tipo,i);
        return true;
    }
    return false;
}

void NpcBook::changeObjective(const Prioridades& tipo,int& it){
    // TO DO: PATHPLANNING
    PosicionesDestino.clear();
    PosicionesDestino = pila[it]->m_posiciones;
    if(tipo==P_VIGILAR || tipo==P_PATRULLAR) return;
    remove_Events(it);
}

void NpcBook::remove_Events(int &it){
    if(pila[it]){
        delete pila[it];
        pila.erase(pila.begin()+it);
    }
}

bool NpcBook::updatePilaObjetivo(){
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
    time_t aux = time(NULL);
    for (int i=0; i<pila.size(); i++) {
        if (pila[i]->m_tipo==P_PATRULLAR || pila[i]->m_tipo==P_VIGILAR)
            continue;
        if(pila[i]->m_time<=aux){
            delete pila[i];
            pila.erase(pila.begin()+i);
        }
    }
}

bool NpcBook::ExistEventByID(int &ID){
    for (int i=0; i<pila.size(); i++) {
        if(pila[i]->m_ID == ID)
            return true;
    }
    return false;
}
