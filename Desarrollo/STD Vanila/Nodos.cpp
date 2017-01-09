//
//  Nodos.cpp
//  Sistema de Decision
//
//  Created by Gaspar Rodriguez Valero on 29/11/16.
//  Copyright © 2016 Gaspar Rodriguez Valero. All rights reserved.
//
#include "Nodos.hpp"
#include "BlackBoards.hpp"

#define FAILURE 0
#define SUCCESS 1
#define RUNNING 2

#define UMBRAL_HAMBRE 60
#define UMBRAL_SED 70
#define UMBRAL_VIDA 30

#define ESTANDAR 0
#define ALERTA 1
#define COMBATE 2
#define ASUSTADO 3

#define BOTIQUIN_CURA 40
#define COMIDA_ALIMENTA 25
#define AGUA_HIDATRA 50

#define DISTANCIA_COMUNICACION_PERSONAL 30
#define DISTANCIA_POR_RADIO 35

#define ACTIVO true
#define INACTIVO false


//NODOS ESPECIALES / GENERALES

//Nodo::~Nodo(){}
// NODO SECUENCIA
NodoSecuencia::NodoSecuencia(){hijo=0;}
void NodoSecuencia::anyadirHijo(Nodo * hijo){NodoSecuencia::m_hijos.push_back(hijo);}
short NodoSecuencia::run(int &id){
    cout << "NODO SECUENCIA" << endl;
    for (hijo; hijo<m_hijos.size(); hijo++) {
        short answer = m_hijos[hijo]->run(id);
        if (answer==FAILURE) {hijo=0;return FAILURE;}
        else if(answer==RUNNING){return RUNNING;}
    }
    hijo=0;
    return SUCCESS;
}
NodoSecuencia::~NodoSecuencia(){
    for (int i=0; i<m_hijos.size(); i++) {
        delete m_hijos[i];
    }
    m_hijos.clear();
}
// NODO SECUENCIA POSITIVA
NodoSecuenciaPositiva::NodoSecuenciaPositiva(){hijo=0;}
short NodoSecuenciaPositiva::run(int &id){
    cout << "NODO SECUENCIA POSITIVA" <<endl;
    for(hijo;hijo<m_hijos.size();hijo++){
        short answer = m_hijos[hijo]->run(id);
        if(answer==SUCCESS){hijo=0;return SUCCESS;}
        else if (answer==RUNNING){return RUNNING;}
    }
    hijo=0;
    return FAILURE;
}
void NodoSecuenciaPositiva::anyadirHijo(Nodo * hijo){m_hijos.push_back(hijo);}
NodoSecuenciaPositiva::~NodoSecuenciaPositiva(){
    for (int i=0; i<m_hijos.size(); i++) {
        delete m_hijos[i];
    }
    m_hijos.clear();
}

// NODOS DE ACCION
// NODO RECORRER ZONA
NodoRecorreZonaCercana::NodoRecorreZonaCercana(){}
NodoRecorreZonaCercana::~NodoRecorreZonaCercana(){}
short NodoRecorreZonaCercana::run(int &id){return false;}

// NODO MOVER
NodoMover::NodoMover(){_movement=NULL;aux=-1;}
NodoMover::~NodoMover(){delete _movement;}
short NodoMover::run(int &id){
    cout << "NODO MOVER" << endl;
    if(_movement==NULL) _movement = new dvector3D;
    if(aux==-1){
        aux = CalcularDistancia(*NPC_library::instance()->getMyBook(&id)->getPosition(), *NPC_library::instance()->getMyBook(&id)->getPosObjetivo());
        _movement->x = 0;
        _movement->y = 0;
        _movement->z = 0;
    }else if(aux>0 && aux<0.5){
        return true;
    }else{
        if(fabsf(xABS)>fabsf(yABS)){
            float x = 0.05;
            if (xABS<0) x=-0.05;
            _movement->x = x;
            _movement->y = 0;
            _movement->z = 0;
            
        }else{
            float y = 0.05;
            if (yABS<0) y=-0.05;
            _movement->x = 0;
            _movement->y = y;
            _movement->z = 0;
        }
        NPC_library::instance()->getMyBook(&id)->setVMovement(_movement);
        aux = -1;
    }
    
    
    /*
    else{
        if(fabsf(xABS)>fabsf(yABS)){
            float x = 0.05;
            if (xABS<0) x=-0.05;
            NPCinfo->newPosition(new vector3D{NPCinfo->getPosActual()->x+x,NPCinfo->getPosActual()->y,NPCinfo->getPosActual()->z});
        }else{
            float y = 0.05;
            if (yABS<0) y=-0.05;
            NPCinfo->newPosition(new vector3D{NPCinfo->getPosActual()->x,NPCinfo->getPosActual()->y+y,NPCinfo->getPosActual()->z});
        }
        cout << "JUGADOR :" << NPCinfo->getPosActual()->x << "|" << NPCinfo->getPosActual()->y << endl;
        cout << NPCinfo->getPosAviso()->x << "|" << NPCinfo->getPosAviso()->y << endl;
        aux = -1;
        
    }*/
    return RUNNING;
}
float NodoMover::CalcularDistancia(dvector3D a, dvector3D b){
    float x = fabs(a.x-b.x);
    float y = fabs(a.y-b.y);
    return x+y;
}
// NODO COMER
NodoComer::NodoComer(){}
short NodoComer::run(int &id){
    cout << " NODO COMER" <<endl;
    NPC_library::instance()->getMyBook(&id)->setHungry(COMIDA_ALIMENTA);
    //NPCinfo->Alimentarse(COMIDA_ALIMENTA);
    
    return true;
}
NodoComer::~NodoComer(){}
// NODO BEBER
NodoBeber::NodoBeber(){}
NodoBeber::~NodoBeber(){}
short NodoBeber::run(int &id){
    cout << " NODO BEBER" <<endl;
    NPC_library::instance()->getMyBook(&id)->setThirst(AGUA_HIDATRA);
    return true;
}
// NODO HUIR
NodoHuir::NodoHuir(){}
NodoHuir::~NodoHuir(){}
short NodoHuir::run(int &id){
    cout << " NODO HUIR" << endl;
    return false;
}
// NODO AVISAR
NodoAvisar::NodoAvisar(){}
NodoAvisar::~NodoAvisar(){}
short NodoAvisar::run(int &id){
    cout << " NODO AVISAR" << endl;
    //NPCinfo->Avisado(true);
    return false;
}
// NODO HABLAR
NodoHablar::NodoHablar(){}
NodoHablar::~NodoHablar(){}
short NodoHablar::run(int &id){
    cout << " NODO HABLAR" << endl;
    return false;
}
// NODO CURARSE
NodoCurarse::NodoCurarse(){}
NodoCurarse::~NodoCurarse(){}
short NodoCurarse::run(int &id){
    cout << " NODO CURARSE" << endl;
    NPC_library::instance()->getMyBook(&id)->setLife(BOTIQUIN_CURA);
    return true;
}
// NODO VIGILAR
NodoVigilar::NodoVigilar(){}
NodoVigilar::~NodoVigilar(){}
short NodoVigilar::run(int &id){
    cout << " NODO VIGILAR" << endl;
    /*if(NPCinfo->getRutina()!=0){
        float aux = CalcularDistancia(*NPCinfo->getPosActual(), *NPCinfo->getPosRutina()[NPCinfo->getPaso()]);
        if(aux<0.5) {return true;}
        float xABS = fabs(NPCinfo->getPosRutina()[NPCinfo->getPaso()]->x-NPCinfo->getPosActual()->x);
        float x=0,y=0;
        if(NPCinfo->getPosRutina()[NPCinfo->getPaso()]->x-NPCinfo->getPosActual()->x<0){x-=0.05;}
        else{x+=0.05;}
        if(NPCinfo->getPosRutina()[NPCinfo->getPaso()]->y-NPCinfo->getPosActual()->y<0){y-=0.05;}
        else{y+=0.05;}
        float yABS = fabs(NPCinfo->getPosRutina()[NPCinfo->getPaso()]->y-NPCinfo->getPosActual()->y);
        cout << x << "|" << y << endl;
        if(xABS>yABS){
            
            NPCinfo->newPosition(new vector3D{NPCinfo->getPosActual()->x+x,NPCinfo->getPosActual()->y,NPCinfo->getPosActual()->z});
        }else if(xABS<yABS){
            NPCinfo->newPosition(new vector3D{NPCinfo->getPosActual()->x,NPCinfo->getPosActual()->y+y,NPCinfo->getPosActual()->z});
        }else if(xABS==yABS){
            NPCinfo->newPosition(new vector3D{NPCinfo->getPosActual()->x+x,NPCinfo->getPosActual()->y+y,NPCinfo->getPosActual()->z});
        }
        return true;
    }
        */
    return false;
}
// NODO CUBRISE
NodoCubrirse::NodoCubrirse(){}
NodoCubrirse::~NodoCubrirse(){}
short NodoCubrirse::run(int &id){
    cout << " NODO CUBRIRSE" << endl;
    return false;
}

// NODO PATRULLAR
NodoPatrullar::NodoPatrullar(){}
NodoPatrullar::~NodoPatrullar(){}
short NodoPatrullar::run(int &id){
    cout << " NODO PATRULLAR" << endl;
   /* if (NPCinfo->getRutina()!=0) {
        return false;
    }
    float aux = CalcularDistancia(*NPCinfo->getPosActual(), *NPCinfo->getPosRutina()[NPCinfo->getPaso()]);
    if(aux<0.5) NPCinfo->setPaso();
    float xABS = fabs(NPCinfo->getPosRutina()[NPCinfo->getPaso()]->x-NPCinfo->getPosActual()->x);
    float x=0,y=0;
    if(NPCinfo->getPosRutina()[NPCinfo->getPaso()]->x-NPCinfo->getPosActual()->x<0){x-=0.05;}
    else{x+=0.05;}
    if(NPCinfo->getPosRutina()[NPCinfo->getPaso()]->y-NPCinfo->getPosActual()->y<0){y-=0.05;}
    else{y+=0.05;}
    float yABS = fabs(NPCinfo->getPosRutina()[NPCinfo->getPaso()]->y-NPCinfo->getPosActual()->y);
    if(xABS>yABS){
        
        NPCinfo->newPosition(new vector3D{NPCinfo->getPosActual()->x+x,NPCinfo->getPosActual()->y,NPCinfo->getPosActual()->z});
    }else if(xABS<yABS){
        NPCinfo->newPosition(new vector3D{NPCinfo->getPosActual()->x,NPCinfo->getPosActual()->y+y,NPCinfo->getPosActual()->z});
    }else if(xABS==yABS){
        NPCinfo->newPosition(new vector3D{NPCinfo->getPosActual()->x+x,NPCinfo->getPosActual()->y+y,NPCinfo->getPosActual()->z});
    }
    */
    return true;
}
// NODO ATAQUE CUERPO A CUERPO
NodoAtaqueCuerpo::NodoAtaqueCuerpo(){}
NodoAtaqueCuerpo::~NodoAtaqueCuerpo(){}
short NodoAtaqueCuerpo::run(int &id){
    cout << " NODO ATAQUE A CUEPO" << endl;
    return false;
}
// NODO ATAQUE DISTANCIA
NodoAtaqueDistancia::NodoAtaqueDistancia(){}
NodoAtaqueDistancia::~NodoAtaqueDistancia(){}
short NodoAtaqueDistancia::run(int &id){
    cout << " NODO ATACO DISTANCIA" << endl;
    return false;
}
//#############################
//#    NODOS DE CONDICION     #
//#############################

// NODO HAY RUIDO

Nodo_HayRuido::Nodo_HayRuido(){}
Nodo_HayRuido::~Nodo_HayRuido(){}
short Nodo_HayRuido::run(int &id){
    cout << " NODO HAY RUIDO ?" << endl;
    return false;
}

// PUEDO ATACAR DISTANCIA ?
Nodo_PuedoAtacarDistancia::~Nodo_PuedoAtacarDistancia(){}
Nodo_PuedoAtacarDistancia::Nodo_PuedoAtacarDistancia(){}
short Nodo_PuedoAtacarDistancia::run(int &id){
    cout << " NODO PUEDO ATACAR DISTANCIA ?" << endl;
    return false;
}

// NODO NECESITO AYUDA?
Nodo_NecesitoAyuda::~Nodo_NecesitoAyuda(){}
Nodo_NecesitoAyuda::Nodo_NecesitoAyuda(){}
short Nodo_NecesitoAyuda::run(int &id){
    cout << " NODO NECESITO AYUDA ?" << endl;
    return false;
}

// NODO ALARMA ROTA?
Nodo_AlarmaRota::~Nodo_AlarmaRota(){}
Nodo_AlarmaRota::Nodo_AlarmaRota(){}
short Nodo_AlarmaRota::run(int &id){
    cout << " NODO ALARMA ROTA ?" << endl;
   // WorldInfo->comprobadaAlarma = true;
    //if(WorldInfo->estadoAlarma) return false;    
    return true;
}

// NODO HE SIDO AVISADO ?
Nodo_Avisado::Nodo_Avisado(){};
Nodo_Avisado::~Nodo_Avisado(){}
short Nodo_Avisado::run(int &id){
    cout << " NODO AVISADO ?" << endl;
    //if(NPCinfo->getLLamada()) return true;
    return false;
}

// NODO TENGO SED ?
Nodo_TengoSed::Nodo_TengoSed(){}
Nodo_TengoSed::~Nodo_TengoSed(){}
short Nodo_TengoSed::run(int &id){
    cout << "NODO TENGO SED" << endl;
    if(NPC_library::instance()->getMyBook(&id)->getThirst()>=UMBRAL_SED){
        if (World_BlackBoard::instance()->existRecord(R_FUENTE, &id)) {
            if (World_BlackBoard::instance()->hasAnswer(R_FUENTE, &id)) {
                NPC_library::instance()->getMyBook(&id)->setPosObjetivo(World_BlackBoard::instance()->getAnswer(R_FUENTE, &id)->_answerInfo);
                return true;
            }
        }
        World_BlackBoard::instance()->addRecord(R_FUENTE, &id, NPC_library::instance()->getMyBook(&id)->getPosition());
    }
    return false;
}
// NODO TENGO HAMBRE ?
Nodo_TengoHambre::Nodo_TengoHambre(){}
Nodo_TengoHambre::~Nodo_TengoHambre(){}
short Nodo_TengoHambre::run(int &id){
    cout << "NODO TENGO HAMBRE" << endl;
    if(NPC_library::instance()->getMyBook(&id)->getHungry()>=UMBRAL_HAMBRE){
        if (World_BlackBoard::instance()->existRecord(R_COMIDA, &id)) {
            if (World_BlackBoard::instance()->hasAnswer(R_COMIDA, &id)) {
                NPC_library::instance()->getMyBook(&id)->setPosObjetivo(World_BlackBoard::instance()->getAnswer(R_COMIDA, &id)->_answerInfo);
                return true;
            }
        }
        World_BlackBoard::instance()->addRecord(R_COMIDA, &id, NPC_library::instance()->getMyBook(&id)->getPosition());
    }
    return false;
}
// NODO VIDA BAJA ?
Nodo_VidaBaja::Nodo_VidaBaja(){}
Nodo_VidaBaja::~Nodo_VidaBaja(){}
short Nodo_VidaBaja::run(int &id){
    cout << " NODO VIDA BAJA?" << endl;
    if(NPC_library::instance()->getMyBook(&id)->getLife()<=UMBRAL_VIDA)
        return true;
    return false;
}
// NODO TIENE AGUA ?
Nodo_TieneAgua::Nodo_TieneAgua(){}
Nodo_TieneAgua::~Nodo_TieneAgua(){}
short Nodo_TieneAgua::run(int &id){
    cout << " NODO FUENTE TIENE AGUA?" << endl;
    
    return true;
}
// NODO VER JUGADOR ?
Nodo_VerJugador::Nodo_VerJugador(){}
Nodo_VerJugador::~Nodo_VerJugador(){}
short Nodo_VerJugador::run(int &id){
    cout << " NODO VES AL JUGADOR?" << endl;
    return false;
}
// NODO ALARMA CERCA?
Nodo_AlarmaCerca::Nodo_AlarmaCerca(){}
Nodo_AlarmaCerca::~Nodo_AlarmaCerca(){}
short Nodo_AlarmaCerca::run(int &id){
    
    cout << " NODO ALARMA CERCA?" << endl;
    /*######################################
     TRIGGER SYSTEM
     #####################################*/
    return false;
}
// NODO HAY BOTIQUIN ?
Nodo_HayBotiquin::Nodo_HayBotiquin(){}
Nodo_HayBotiquin::~Nodo_HayBotiquin(){}
short Nodo_HayBotiquin::run(int &id){
    cout << "NODO HAY BOTIQUIN" << endl;
    if (World_BlackBoard::instance()->existRecord(R_BOTIQUIN, &id)) {
        if (World_BlackBoard::instance()->hasAnswer(R_BOTIQUIN, &id)) {
            NPC_library::instance()->getMyBook(&id)->setPosObjetivo(World_BlackBoard::instance()->getAnswer(R_BOTIQUIN, &id)->_answerInfo);
            return true;
        }
    }
    World_BlackBoard::instance()->addRecord(R_BOTIQUIN, &id, NPC_library::instance()->getMyBook(&id)->getPosition());
    return false;
}
// NODO SUENA ALARMA ?
Nodo_SuenaAlarma::Nodo_SuenaAlarma(){}
Nodo_SuenaAlarma::~Nodo_SuenaAlarma(){}
short Nodo_SuenaAlarma::run(int &id){
    cout << " NODO SUENA ALARMA?" << endl;
    /*######################################
     TRIGGER SYSTEM
     #####################################*/
    return false;
}
// NODO ESTAS ASUSTADO ?
Nodo_EstasAsustado::Nodo_EstasAsustado(){}
Nodo_EstasAsustado::~Nodo_EstasAsustado(){}
short Nodo_EstasAsustado::run(int &id){
    cout << " NODO ASUSTADO?" << endl;
    return false;
}
// NODO HAY PARA HABLAR ?
Nodo_HayParaHablar::Nodo_HayParaHablar(){}
Nodo_HayParaHablar::~Nodo_HayParaHablar(){}
short Nodo_HayParaHablar::run(int &id){
    cout << " NODO ALGUIEN HABLAR?" << endl;
    /*######################################
     TRIGGER SYSTEM
     #####################################*/
    return false;
}

// NODO HAY ALGUIEN CERCA ?
Nodo_HayAlguienCerca::Nodo_HayAlguienCerca(){}
Nodo_HayAlguienCerca::~Nodo_HayAlguienCerca(){}
short Nodo_HayAlguienCerca::run(int &id){
    cout << "NODO HAY ALGUIEN CERCA " << endl;
    /*######################################
     TRIGGER SYSTEM
     #####################################*/
    return false;
}
// NODO HAY ALGUIEN RADIO ?
Nodo_HayAlguienRadio::Nodo_HayAlguienRadio(){}
Nodo_HayAlguienRadio::~Nodo_HayAlguienRadio(){}
short Nodo_HayAlguienRadio::run(int &id){
    cout << " NODO HAY NPCS POR RADIO?" << endl;
    /*######################################
     TRIGGER SYSTEM
     #####################################*/
    return false;
}
// NODO ESTAS CERCA JUGADOR ?
Nodo_EstasCercaJugador::Nodo_EstasCercaJugador(){}
Nodo_EstasCercaJugador::~Nodo_EstasCercaJugador(){}
short Nodo_EstasCercaJugador::run(int &id){
    cout << " NODO ESTAS CERCA DEL PLAYER?" << endl;
    return false;
}
// NODO ESTAS LEJOS JUGADOR ?
Nodo_EstasLejosJugador::Nodo_EstasLejosJugador(){}
Nodo_EstasLejosJugador::~Nodo_EstasLejosJugador(){}
short Nodo_EstasLejosJugador::run(int &id){
    cout << " NODO ESTAS LEJOS DEL PLAYER?" << endl;
    return false;
}
// NODO TIEMPO INACTIVO ?
Nodo_TiempoInactivo::Nodo_TiempoInactivo(){}
Nodo_TiempoInactivo::~Nodo_TiempoInactivo(){}
short Nodo_TiempoInactivo::run(int &id){
    cout << " NODO TIEMPO INACTIVO?" << endl;
    return false;
}



