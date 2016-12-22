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
#include "datos.hpp"
#include "vectorD.hpp"
#include "BlackBoard.hpp"
#include "objects.hpp"


using namespace std;

/*###################
    CLASES GENERALES
 ###################*/
class Nodo {
public:
    virtual short run(datos * NPCinfo, BlackBoard * WorldInfo) = 0;
protected:
    
};

class NodoSecuencia : public Nodo {
public:
    NodoSecuencia();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
    void anyadirHijo(Nodo * hijo);
private:
    vector<Nodo*> m_hijos;
    size_t hijo = -1;
};
class NodoSecuenciaPositiva : public Nodo{
public:
    NodoSecuenciaPositiva();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
    void anyadirHijo(Nodo * hijo);
private:
    vector<Nodo*> m_hijos;
    size_t hijo = -1;
};
class NodoMover : public Nodo {
public:
    NodoMover();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    int f = 0;
    float aux = -1;
    float xABS, yABS;
};

class Nodo_VerJugador : public Nodo {
public:
    Nodo_VerJugador();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // Sensor
};
class Nodo_HayRuido : public Nodo {
public:
    Nodo_HayRuido();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // Sensor
};
class Nodo_SuenaAlarma : public Nodo {
public:
    Nodo_SuenaAlarma();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // Alarma Activa
};

class NodoVigilar : public Nodo {
public:
    NodoVigilar();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // Iniciar Tiempo
};
class NodoPatrullar : public Nodo {
public:
    NodoPatrullar();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    float aux = -1;
    float xABS, yABS;
};
class Nodo_TiempoInactivo : public Nodo {
public:
    Nodo_TiempoInactivo();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // Tiempo
};

class NodoDarAlarma : public Nodo {
public:
    NodoDarAlarma();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // Estado de la Alarma (CAMBIA ESTADO)
};
class Nodo_Avisado : public Nodo {
public:
    Nodo_Avisado();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // Estado de la Alarma (CAMBIA ESTADO)
};
/*###################
 CLASES ESTANDAR
 ###################*/

class Nodo_VidaBaja : public Nodo {
public:
    Nodo_VidaBaja();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // VIDA DEL NPC
};

class Nodo_NecesitoAyuda : public Nodo {
public:
    Nodo_NecesitoAyuda();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    
};

class Nodo_HayBotiquin : public Nodo {
public:
    Nodo_HayBotiquin();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    vector3D * MasCercano(vector<vector3D*>& objetos,datos * NPCinfo);
    // BOTIQUINES (BLACKBOARD)
};

class NodoCurarse : public Nodo {
public:
    NodoCurarse();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // VIDA
    // CUANTO CURA
};
class Nodo_TengoHambre : public Nodo {
public:
    Nodo_TengoHambre();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    vector3D * MasCercano(vector<vector3D*>& objetos,datos * NPCinfo);
    int hambre;
    // HAMBRE
};
class Nodo_TengoSed : public Nodo {
public:
    Nodo_TengoSed();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    vector3D * MasCercano(vector<vector3D*>& objetos,datos * NPCinfo);
    int sed;
    // SED
};
class NodoComer : public Nodo {
public:
    NodoComer();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // HAMBRE
    
};
class NodoBeber : public Nodo {
public:
    NodoBeber();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // SED
};
class Nodo_TieneAgua : public Nodo {
public:
    Nodo_TieneAgua();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // ESTADO FUENTE
};
class Nodo_HayParaHablar : public Nodo {
public:
    Nodo_HayParaHablar();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // NPC + CERCANO
    
};
class NodoHablar : public Nodo {
public:
    NodoHablar();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    //  TEMAS RAMDOM
};
/*###################
 CLASES ALERTA
 ###################*/

class Nodo_AlarmaCerca : public Nodo {
public:
    Nodo_AlarmaCerca();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    vector3D * posAlarma;
    vector3D * MasCercano(vector<vector3D*>& objetos,datos * NPCinfo);
    // POSICION ALARMA + CERCANA
};

class NodoRecorreZonaCercana : public Nodo {
public:
    NodoRecorreZonaCercana();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    //
};

/*###################
 CLASES COMBATE
 ###################*/

class Nodo_PuedoAtacarDistancia : public Nodo {
public:
    Nodo_PuedoAtacarDistancia();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    //  TEMAS RAMDOM
};

class Nodo_EstasAsustado : public Nodo {
public:
    Nodo_EstasAsustado();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // VIDA , HAMBRE Y SED
};
class Nodo_HayAlguienCerca : public Nodo {
public:
    Nodo_HayAlguienCerca();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
    float CalcularDistancia(vector3D a, vector3D b);
private:
    // COORDENADAS NPC + CERCANO
};
class Nodo_HayAlguienRadio : public Nodo {
public:
    Nodo_HayAlguienRadio();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // COORDENADAS DE NPC DENTRO DE RANGO DE RADIO ,
    // CUANTOS AVISA: COMBATE SOLO 1 , ASUSTADO 3 NPCS
};

class NodoAvisar : public Nodo {
public:
    NodoAvisar();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // COORDENADAS PROPIAS
};
class Nodo_EstasCercaJugador : public Nodo {
public:
    Nodo_EstasCercaJugador();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // COORDENADAS DEL JUGADOR
};
class Nodo_AlarmaRota : public Nodo {
public:
    Nodo_AlarmaRota();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // COORDENADAS DEL JUGADOR
};
class Nodo_EstasLejosJugador : public Nodo {
public:
    Nodo_EstasLejosJugador();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // COORDENADAS DEL JUGADOR
};
class NodoAtaqueCuerpo : public Nodo {
public:
    NodoAtaqueCuerpo();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
};
class NodoAtaqueDistancia : public Nodo {
public:
    NodoAtaqueDistancia();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
};
class NodoCubrirse : public Nodo {
public:
    NodoCubrirse();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // OBJETOS DONDE CUBRISE, EL + CERCANO
};

/*###################
 CLASES ASUTADO
 ###################*/

class NodoHuir : public Nodo {
public:
    NodoHuir();
    short run(datos * NPCinfo, BlackBoard * WorldInfo);
private:
    // COORDENADAS DEL JUGADOR
};


#endif /* Nodos_hpp */
