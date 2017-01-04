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
#include <math.h>

using namespace std;

/*###################
    CLASES GENERALES
 ###################*/
class Nodo {
public:
    virtual short run() = 0;
protected:
    //float CalcularDistancia(vector3D a, vector3D b);
};

class NodoSecuencia : public Nodo {
public:
    NodoSecuencia();
    short run();
    void anyadirHijo(Nodo * hijo);
private:
    vector<Nodo*> m_hijos;
    size_t hijo = -1;
};
class NodoSecuenciaPositiva : public Nodo{
public:
    NodoSecuenciaPositiva();
    short run();
    void anyadirHijo(Nodo * hijo);
private:
    vector<Nodo*> m_hijos;
    size_t hijo = -1;
};
class NodoMover : public Nodo {
public:
    NodoMover();
    short run();
private:
    int f = 0;
    float aux = -1;
    float xABS, yABS;
};

class Nodo_VerJugador : public Nodo {
public:
    Nodo_VerJugador();
    short run();
private:
    // Sensor
};
class Nodo_HayRuido : public Nodo {
public:
    Nodo_HayRuido();
    short run();
private:
    // Sensor
};
class Nodo_SuenaAlarma : public Nodo {
public:
    Nodo_SuenaAlarma();
    short run();
private:
    // Alarma Activa
};

class NodoVigilar : public Nodo {
public:
    NodoVigilar();
    short run();
private:
    // Iniciar Tiempo
};
class NodoPatrullar : public Nodo {
public:
    NodoPatrullar();
    short run();
private:
    //float aux = -1;
    //float xABS, yABS;
};
class Nodo_TiempoInactivo : public Nodo {
public:
    Nodo_TiempoInactivo();
    short run();
private:
    // Tiempo
};

class NodoDarAlarma : public Nodo {
public:
    NodoDarAlarma();
    short run();
private:
    // Estado de la Alarma (CAMBIA ESTADO)
};
class Nodo_Avisado : public Nodo {
public:
    Nodo_Avisado();
    short run();
private:
    // Estado de la Alarma (CAMBIA ESTADO)
};
/*###################
 CLASES ESTANDAR
 ###################*/

class Nodo_VidaBaja : public Nodo {
public:
    Nodo_VidaBaja();
    short run();
private:
    // VIDA DEL NPC
};

class Nodo_NecesitoAyuda : public Nodo {
public:
    Nodo_NecesitoAyuda();
    short run();
private:
    
};

class Nodo_HayBotiquin : public Nodo {
public:
    Nodo_HayBotiquin();
    short run();
private:
    //vector3D * MasCercano(vector<vector3D*>& objetos,datos * NPCinfo);
    // BOTIQUINES (BLACKBOARD)
};

class NodoCurarse : public Nodo {
public:
    NodoCurarse();
    short run();
private:
    // VIDA
    // CUANTO CURA
};
class Nodo_TengoHambre : public Nodo {
public:
    Nodo_TengoHambre();
    short run();
private:
    //vector3D * MasCercano(vector<vector3D*>& objetos,datos * NPCinfo);
    //int hambre;
    // HAMBRE
};
class Nodo_TengoSed : public Nodo {
public:
    Nodo_TengoSed();
    short run();
private:
    //vector3D * MasCercano(vector<vector3D*>& objetos,datos * NPCinfo);
    //int sed;
    // SED
};
class NodoComer : public Nodo {
public:
    NodoComer();
    short run();
private:
    // HAMBRE
    
};
class NodoBeber : public Nodo {
public:
    NodoBeber();
    short run();
private:
    // SED
};
class Nodo_TieneAgua : public Nodo {
public:
    Nodo_TieneAgua();
    short run();
private:
    // ESTADO FUENTE
};
class Nodo_HayParaHablar : public Nodo {
public:
    Nodo_HayParaHablar();
    short run();
private:
    // NPC + CERCANO
    
};
class NodoHablar : public Nodo {
public:
    NodoHablar();
    short run();
private:
    //  TEMAS RAMDOM
};
/*###################
 CLASES ALERTA
 ###################*/

class Nodo_AlarmaCerca : public Nodo {
public:
    Nodo_AlarmaCerca();
    short run();
private:
    //vector3D * posAlarma;
    //vector3D * MasCercano(vector<vector3D*>& objetos,datos * NPCinfo);
    // POSICION ALARMA + CERCANA
};

class NodoRecorreZonaCercana : public Nodo {
public:
    NodoRecorreZonaCercana();
    short run();
private:
    //
};

/*###################
 CLASES COMBATE
 ###################*/

class Nodo_PuedoAtacarDistancia : public Nodo {
public:
    Nodo_PuedoAtacarDistancia();
    short run();
private:
    //  TEMAS RAMDOM
};

class Nodo_EstasAsustado : public Nodo {
public:
    Nodo_EstasAsustado();
    short run();
private:
    // VIDA , HAMBRE Y SED
};
class Nodo_HayAlguienCerca : public Nodo {
public:
    Nodo_HayAlguienCerca();
    short run();
    //float CalcularDistancia(vector3D a, vector3D b);
private:
    // COORDENADAS NPC + CERCANO
};
class Nodo_HayAlguienRadio : public Nodo {
public:
    Nodo_HayAlguienRadio();
    short run();
private:
    // COORDENADAS DE NPC DENTRO DE RANGO DE RADIO ,
    // CUANTOS AVISA: COMBATE SOLO 1 , ASUSTADO 3 NPCS
};

class NodoAvisar : public Nodo {
public:
    NodoAvisar();
    short run();
private:
    // COORDENADAS PROPIAS
};
class Nodo_EstasCercaJugador : public Nodo {
public:
    Nodo_EstasCercaJugador();
    short run();
private:
    // COORDENADAS DEL JUGADOR
};
class Nodo_AlarmaRota : public Nodo {
public:
    Nodo_AlarmaRota();
    short run();
private:
    // COORDENADAS DEL JUGADOR
};
class Nodo_EstasLejosJugador : public Nodo {
public:
    Nodo_EstasLejosJugador();
    short run();
private:
    // COORDENADAS DEL JUGADOR
};
class NodoAtaqueCuerpo : public Nodo {
public:
    NodoAtaqueCuerpo();
    short run();
private:
};
class NodoAtaqueDistancia : public Nodo {
public:
    NodoAtaqueDistancia();
    short run();
private:
};
class NodoCubrirse : public Nodo {
public:
    NodoCubrirse();
    short run();
private:
    // OBJETOS DONDE CUBRISE, EL + CERCANO
};

/*###################
 CLASES ASUTADO
 ###################*/

class NodoHuir : public Nodo {
public:
    NodoHuir();
    short run();
private:
    // COORDENADAS DEL JUGADOR
};


#endif /* Nodos_hpp */
