//
//  Nodos.cpp
//  Sistema de Decision
//
//  Created by Gaspar Rodriguez Valero on 29/11/16.
//  Copyright © 2016 Gaspar Rodriguez Valero. All rights reserved.
//


#include "Nodos.hpp"

// NODO SECUENCIA
NodoSecuencia::NodoSecuencia(){}
void NodoSecuencia::anyadirHijo(Nodo * hijo){NodoSecuencia::m_hijos.push_back(hijo);}
bool NodoSecuencia::run(){
    for (int i=0; i<m_hijos.size(); i++) {
        if(!m_hijos[i]->run()){return false;}
    }
    return true;
}
// NODO RECORRER ZONA
NodoRecorreZonaCercana::NodoRecorreZonaCercana(){}
bool NodoRecorreZonaCercana::run(){return false;}
// NODO ABRIR PUERTA
NodoAbrirPuerta::NodoAbrirPuerta(){}
bool NodoAbrirPuerta::run(){return false;}
// NODO MOVER
NodoMover::NodoMover(){}
bool NodoMover::run(){return false;}
// NODO COMER
NodoComer::NodoComer(){}
bool NodoComer::run(){return false;}
// NODO BEBER
NodoBeber::NodoBeber(){}
bool NodoBeber::run(){return false;}
// NODO HUIR
NodoHuir::NodoHuir(){}
bool NodoHuir::run(){return false;}
// NODO AVISAR
NodoAvisar::NodoAvisar(){}
bool NodoAvisar::run(){return false;}
// NODO HABLAR
NodoHablar::NodoHablar(){}
bool NodoHablar::run(){return false;}
// NODO CURARSE
NodoCurarse::NodoCurarse(){}
bool NodoCurarse::run(){return false;}
// NODO VIGILAR
NodoVigilar::NodoVigilar(){}
bool NodoVigilar::run(){return false;}
// NODO CUBRISE
NodoCubrirse::NodoCubrirse(){}
bool NodoCubrirse::run(){return false;}
// NODO HAY RUIDO
NodoHayRuido::NodoHayRuido(){}
bool NodoHayRuido::run(){return false;}
// NODO PATRULLAR
NodoPatrullar::NodoPatrullar(){}
bool NodoPatrullar::run(){return false;}
// NODO ATAQUE CUERPO A CUERPO
NodoAtaqueCuerpo::NodoAtaqueCuerpo(){}
bool NodoAtaqueCuerpo::run(){return false;}
// NODO ATAQUE DISTANCIA
NodoAtaqueDistancia::NodoAtaqueDistancia(){}
bool NodoAtaqueDistancia::run(){return false;}

//NODOS PREGUNTA
// NODO TENGO SED ?
Nodo_TengoSed::Nodo_TengoSed(){}
bool Nodo_TengoSed::run(){return false;}
// NODO TENGO HAMBRE ?
Nodo_TengoHambre::Nodo_TengoHambre(){}
bool Nodo_TengoHambre::run(){return false;}
// NODO VIDA BAJA ?
Nodo_VidaBaja::Nodo_VidaBaja(){}
bool Nodo_VidaBaja::run(){return false;}
// NODO TIENE AGUA ?
Nodo_TieneAgua::Nodo_TieneAgua(){}
bool Nodo_TieneAgua::run(){return false;}
// NODO VER JUGADOR ?
Nodo_VerJugador::Nodo_VerJugador(){}
bool Nodo_VerJugador::run(){return false;}
// NODO ALARMA CERCA?
Nodo_AlarmaCerca::Nodo_AlarmaCerca(){}
bool Nodo_AlarmaCerca::run(){return false;}
// NODO HAY BOTIQUIN ?
Nodo_HayBotiquin::Nodo_HayBotiquin(){}
bool Nodo_HayBotiquin::run(){return false;}
// NODO SUENA ALARMA ?
Nodo_SuenaAlarma::Nodo_SuenaAlarma(){}
bool Nodo_SuenaAlarma::run(){return false;}
// NODO ESTAS ASUSTADO ?
Nodo_EstasAsustado::Nodo_EstasAsustado(){}
bool Nodo_EstasAsustado::run(){return false;}
// NODO HAY PARA HABLAR ?
Nodo_HayParaHablar::Nodo_HayParaHablar(){}
bool Nodo_HayParaHablar::run(){return false;}
// NODO PUERTA ABIERTA ?
Nodo_PuertaAbierta::Nodo_PuertaAbierta(){}
bool Nodo_PuertaAbierta::run(){return false;}
// NODO HAY ALGUIEN CERCA ?
Nodo_HayAlguienCerca::Nodo_HayAlguienCerca(){}
bool Nodo_HayAlguienCerca::run(){return false;}
// NODO HAY ALGUIEN RADIO ?
Nodo_HayAlguienRadio::Nodo_HayAlguienRadio(){}
bool Nodo_HayAlguienRadio::run(){return false;}
// NODO ESTAS CERCA JUGADOR ?
Nodo_EstasCercaJugador::Nodo_EstasCercaJugador(){}
bool Nodo_EstasCercaJugador::run(){return false;}
// NODO ESTAS LEJOS JUGADOR ?
Nodo_EstasLejosJugador::Nodo_EstasLejosJugador(){}
bool Nodo_EstasLejosJugador::run(){return false;}
// NODO TIEMPO INACTIVO ?
Nodo_TiempoInactivo::Nodo_TiempoInactivo(){}
bool Nodo_TiempoInactivo::run(){return false;}




