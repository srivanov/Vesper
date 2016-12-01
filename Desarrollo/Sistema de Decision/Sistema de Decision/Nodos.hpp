//
//  Nodos.hpp
//  Sistema de Decision
//
//  Created by Gaspar Rodriguez Valero on 29/11/16.
//  Copyright © 2016 Gaspar Rodriguez Valero. All rights reserved.
//
/* */
#ifndef Nodos_hpp
#define Nodos_hpp

#include <vector>
#include <iostream>
#include "engineInterface.hpp"
using namespace std;

/*###################
    CLASES GENERALES
 ###################*/
class Nodo {
public:
    virtual bool run() = 0;
};

class NodoSecuencia : public Nodo {
public:
    NodoSecuencia();
    bool run();
    void anyadirHijo(Nodo * hijo);
private:
    vector<Nodo*> m_hijos;
};

class NodoMover : public Nodo {
public:
    NodoMover();
    bool run();
private:
    //Posicion Inicial X e Y;
    //Posicion Final X e Y;
};
class Nodo_PuertaAbierta : public Nodo {
public:
    Nodo_PuertaAbierta();
    bool run();
private:
    // Estado de la puerta
    // Tipo de puerta
};
class NodoAbrirPuerta : public Nodo {
public:
    NodoAbrirPuerta();
    bool run();
private:
    // Estado de la puerta
    // Tipo de puerta
    // Si tiene llave
};
class Nodo_VerJugador : public Nodo {
public:
    Nodo_VerJugador();
    bool run();
private:
    // Sensor
};
class Nodo_SuenaAlarma : public Nodo {
public:
    Nodo_SuenaAlarma();
    bool run();
private:
    // Alarma Activa
};
class NodoHayRuido : public Nodo {
public:
    NodoHayRuido();
    bool run();
private:
    // Ruido de objeto
};

class NodoVigilar : public Nodo {
public:
    NodoVigilar();
    bool run();
private:
    // Iniciar Tiempo
};
class NodoPatrullar : public Nodo {
public:
    NodoPatrullar();
    bool run();
private:
    // Patrulla
};
class Nodo_TiempoInactivo : public Nodo {
public:
    Nodo_TiempoInactivo();
    bool run();
private:
    // Tiempo
};

class NodoDarAlarma : public Nodo {
public:
    NodoDarAlarma();
    bool run();
private:
    // Estado de la Alarma (CAMBIA ESTADO)
};

/*###################
 CLASES ESTANDAR
 ###################*/

class Nodo_VidaBaja : public Nodo {
public:
    Nodo_VidaBaja();
    bool run();
private:
    // VIDA DEL NPC
};

class Nodo_HayBotiquin : public Nodo {
public:
    Nodo_HayBotiquin();
    bool run();
private:
    // BOTIQUINES (BLACKBOARD)
};

class NodoCurarse : public Nodo {
public:
    NodoCurarse();
    bool run();
private:
    // VIDA
    // CUANTO CURA
};
class Nodo_TengoHambre : public Nodo {
public:
    Nodo_TengoHambre();
    bool run();
private:
    // HAMBRE
};
class Nodo_TengoSed : public Nodo {
public:
    Nodo_TengoSed();
    bool run();
private:
    // SED
};
class NodoComer : public Nodo {
public:
    NodoComer();
    bool run();
private:
    // HAMBRE
};
class NodoBeber : public Nodo {
public:
    NodoBeber();
    bool run();
private:
    // SED
};
class Nodo_TieneAgua : public Nodo {
public:
    Nodo_TieneAgua();
    bool run();
private:
    // ESTADO FUENTE
};
class Nodo_HayParaHablar : public Nodo {
public:
    Nodo_HayParaHablar();
    bool run();
private:
    // NPC + CERCANO
    
};
class NodoHablar : public Nodo {
public:
    NodoHablar();
    bool run();
private:
    //  TEMAS RAMDOM
};
/*###################
 CLASES ALERTA
 ###################*/

class Nodo_AlarmaCerca : public Nodo {
public:
    Nodo_AlarmaCerca();
    bool run();
private:
    // POSICION ALARMA + CERCANA
};

class NodoRecorreZonaCercana : public Nodo {
public:
    NodoRecorreZonaCercana();
    bool run();
private:
    //
};

/*###################
 CLASES COMBATE
 ###################*/
class Nodo_EstasAsustado : public Nodo {
public:
    Nodo_EstasAsustado();
    bool run();
private:
    // VIDA , HAMBRE Y SED
};
class Nodo_HayAlguienCerca : public Nodo {
public:
    Nodo_HayAlguienCerca();
    bool run();
private:
    // COORDENADAS NPC + CERCANO
};
class Nodo_HayAlguienRadio : public Nodo {
public:
    Nodo_HayAlguienRadio();
    bool run();
private:
    // COORDENADAS DE NPC DENTRO DE RANGO DE RADIO ,
    // CUANTOS AVISA: COMBATE SOLO 1 , ASUSTADO 3 NPCS
};

class NodoAvisar : public Nodo {
public:
    NodoAvisar();
    bool run();
private:
    // COORDENADAS PROPIAS
};
class Nodo_EstasCercaJugador : public Nodo {
public:
    Nodo_EstasCercaJugador();
    bool run();
private:
    // COORDENADAS DEL JUGADOR
};
class Nodo_EstasLejosJugador : public Nodo {
public:
    Nodo_EstasLejosJugador();
    bool run();
private:
    // COORDENADAS DEL JUGADOR
};
class NodoAtaqueCuerpo : public Nodo {
public:
    NodoAtaqueCuerpo();
    bool run();
private:
};
class NodoAtaqueDistancia : public Nodo {
public:
    NodoAtaqueDistancia();
    bool run();
private:
};
class NodoCubrirse : public Nodo {
public:
    NodoCubrirse();
    bool run();
private:
    // OBJETOS DONDE CUBRISE, EL + CERCANO
};

/*###################
 CLASES ASUTADO
 ###################*/

class NodoHuir : public Nodo {
public:
    NodoHuir();
    bool run();
private:
    // COORDENADAS DEL JUGADOR
};


#endif /* Nodos_hpp */
