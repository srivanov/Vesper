//
//  Nodos.cpp
//  Sistema de Decision
//
//  Created by Gaspar Rodriguez Valero on 29/11/16.
//  Copyright © 2016 Gaspar Rodriguez Valero. All rights reserved.
//
#include "Nodos.hpp"

#define FAILURE 0
#define SUCCESS 1
#define RUNNING 2

#define ACTIVO true
#define INACTIVO false


//NODOS ESPECIALES / GENERALES
// NODO SECUENCIA
NodoSecuencia::NodoSecuencia(){}
void NodoSecuencia::anyadirHijo(Nodo * hijo){NodoSecuencia::m_hijos.push_back(hijo);}
short NodoSecuencia::run(datos NPCinfo){
    if(getRunning()){
        for (int i=0; i<m_hijos.size(); i++) {
            if(m_hijos[i]->getRunning()){
                m_hijos[i]->run(NPCinfo);
                return RUNNING;
            }
            else running=INACTIVO;
        }
    }
    for (int i=0; i<m_hijos.size(); i++) {
        short answer = m_hijos[i]->run(NPCinfo);
        if (answer==FAILURE) {
            return FAILURE;
        }else if(answer==RUNNING){
            running=ACTIVO;
            return RUNNING;
        }
        
    }
    running=INACTIVO;
    return SUCCESS;
}
// NODO SECUENCIA POSITIVA
NodoSecuenciaPositiva::NodoSecuenciaPositiva(){}
short NodoSecuenciaPositiva::run(datos NPCinfo){
    if(getRunning()){
        for (int i=0; i<m_hijos.size(); i++) {
            if(m_hijos[i]->getRunning()){
                m_hijos[i]->run(NPCinfo);
                return RUNNING;
            }
            else running=INACTIVO;
        }
    }
    for(int i=0;i<m_hijos.size();i++){
        short answer = m_hijos[i]->run(NPCinfo);
        if(answer==SUCCESS){
            running=INACTIVO;
            return SUCCESS;
        }
        else if (answer==RUNNING){
            running=ACTIVO;
            return RUNNING;
        }
    }
    return FAILURE;
}
void NodoSecuenciaPositiva::anyadirHijo(Nodo * hijo){m_hijos.push_back(hijo);}


// NODOS DE ACCION
// NODO RECORRER ZONA
NodoRecorreZonaCercana::NodoRecorreZonaCercana(){}
short NodoRecorreZonaCercana::run(datos NPCinfo){return false;}
// NODO ABRIR PUERTA
NodoAbrirPuerta::NodoAbrirPuerta(){}
short NodoAbrirPuerta::run(datos NPCinfo){
    return false;
}
// NODO MOVER
NodoMover::NodoMover(){}
short NodoMover::run(datos NPCinfo){return false;}
// NODO COMER
NodoComer::NodoComer(){}
short NodoComer::run(datos NPCinfo){
    return false;
}
// NODO BEBER
NodoBeber::NodoBeber(){}
short NodoBeber::run(datos NPCinfo){
    return false;
}
// NODO HUIR
NodoHuir::NodoHuir(){}
short NodoHuir::run(datos NPCinfo){
    return false;
}
// NODO AVISAR
NodoAvisar::NodoAvisar(){}
short NodoAvisar::run(datos NPCinfo){
    return false;
}
// NODO HABLAR
NodoHablar::NodoHablar(){}
short NodoHablar::run(datos NPCinfo){
    return false;
}
// NODO CURARSE
NodoCurarse::NodoCurarse(){}
short NodoCurarse::run(datos NPCinfo){
    return false;
}
// NODO VIGILAR
NodoVigilar::NodoVigilar(){}
short NodoVigilar::run(datos NPCinfo){
    return false;
}
// NODO CUBRISE
NodoCubrirse::NodoCubrirse(){}
short NodoCubrirse::run(datos NPCinfo){
    return false;
}
// NODO HAY RUIDO
NodoHayRuido::NodoHayRuido(){}
short NodoHayRuido::run(datos NPCinfo){
    return false;
}
// NODO PATRULLAR
NodoPatrullar::NodoPatrullar(){}
short NodoPatrullar::run(datos NPCinfo){
    return false;
}
// NODO ATAQUE CUERPO A CUERPO
NodoAtaqueCuerpo::NodoAtaqueCuerpo(){}
short NodoAtaqueCuerpo::run(datos NPCinfo){
    return false;
}
// NODO ATAQUE DISTANCIA
NodoAtaqueDistancia::NodoAtaqueDistancia(){}
short NodoAtaqueDistancia::run(datos NPCinfo){
    return false;
}
//#############################
//#    NODOS DE CONDICION     #
//#############################

// NODO TENGO SED ?
Nodo_TengoSed::Nodo_TengoSed(){}
short Nodo_TengoSed::run(datos NPCinfo){
    if(NPCinfo.getSed()>60)
        return true;
    return false;
}
// NODO TENGO HAMBRE ?
Nodo_TengoHambre::Nodo_TengoHambre(){}
short Nodo_TengoHambre::run(datos NPCinfo){
    if (NPCinfo.getHambre()>70)
        return true;
    return false;
}
// NODO VIDA BAJA ?
Nodo_VidaBaja::Nodo_VidaBaja(){}
short Nodo_VidaBaja::run(datos NPCinfo){
    if(NPCinfo.getLife()<30)
        return true;
    return false;
}
// NODO TIENE AGUA ?
Nodo_TieneAgua::Nodo_TieneAgua(){}
short Nodo_TieneAgua::run(datos NPCinfo){
    return false;
}
// NODO VER JUGADOR ?
Nodo_VerJugador::Nodo_VerJugador(){}
short Nodo_VerJugador::run(datos NPCinfo){
    return false;
}
// NODO ALARMA CERCA?
Nodo_AlarmaCerca::Nodo_AlarmaCerca(){}
short Nodo_AlarmaCerca::run(datos NPCinfo){
    return false;
}
// NODO HAY BOTIQUIN ?
Nodo_HayBotiquin::Nodo_HayBotiquin(){}
short Nodo_HayBotiquin::run(datos NPCinfo){
    return false;
}
// NODO SUENA ALARMA ?
Nodo_SuenaAlarma::Nodo_SuenaAlarma(){}
short Nodo_SuenaAlarma::run(datos NPCinfo){
    return false;
}
// NODO ESTAS ASUSTADO ?
Nodo_EstasAsustado::Nodo_EstasAsustado(){}
short Nodo_EstasAsustado::run(datos NPCinfo){
    return false;
}
// NODO HAY PARA HABLAR ?
Nodo_HayParaHablar::Nodo_HayParaHablar(){}
short Nodo_HayParaHablar::run(datos NPCinfo){
    return false;
}
// NODO PUERTA ABIERTA ?
Nodo_PuertaAbierta::Nodo_PuertaAbierta(){}
short Nodo_PuertaAbierta::run(datos NPCinfo){
    return false;
}
// NODO HAY ALGUIEN CERCA ?
Nodo_HayAlguienCerca::Nodo_HayAlguienCerca(){}
short Nodo_HayAlguienCerca::run(datos NPCinfo){
    return false;
}
// NODO HAY ALGUIEN RADIO ?
Nodo_HayAlguienRadio::Nodo_HayAlguienRadio(){}
short Nodo_HayAlguienRadio::run(datos NPCinfo){
    return false;
}
// NODO ESTAS CERCA JUGADOR ?
Nodo_EstasCercaJugador::Nodo_EstasCercaJugador(){}
short Nodo_EstasCercaJugador::run(datos NPCinfo){
    return false;
}
// NODO ESTAS LEJOS JUGADOR ?
Nodo_EstasLejosJugador::Nodo_EstasLejosJugador(){}
short Nodo_EstasLejosJugador::run(datos NPCinfo){
    return false;
}
// NODO TIEMPO INACTIVO ?
Nodo_TiempoInactivo::Nodo_TiempoInactivo(){}
short Nodo_TiempoInactivo::run(datos NPCinfo){
    return false;
}




