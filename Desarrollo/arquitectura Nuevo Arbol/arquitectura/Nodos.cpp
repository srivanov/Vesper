//
//  Nodos.cpp
//  Sistema de Decision
//
//  Created by Gaspar Rodriguez Valero on 29/11/16.
//  Copyright © 2016 Gaspar Rodriguez Valero. All rights reserved.
//
#include "Nodos.hpp"
#include "trigger_system.hpp"

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
#define COMIDA_ALIMENTA 45
#define AGUA_HIDATRA 70

#define DISTANCIA_COMUNICACION_PERSONAL 30
#define DISTANCIA_POR_RADIO 70

#define ACTIVO true
#define INACTIVO false



#define TIEMPO_VIGILIA 10
#define TIEMPO_ESTADO_ALTERADO 10


//NODOS ESPECIALES / GENERALES


// NODO SECUENCIA
//NodoSecuencia::NodoSecuencia(){hijo=0;}
//void NodoSecuencia::anyadirHijo(Nodo * hijo){NodoSecuencia::m_hijos.push_back(hijo);}
//short NodoSecuencia::run(int &id){
//    cout << "NODO SECUENCIA" << endl;
//    for (;hijo<m_hijos.size(); hijo++) {
//        short answer = m_hijos[hijo]->run(id);
//        if (answer==FAILURE) {hijo=0;return FAILURE;}
//        else if(answer==RUNNING){return RUNNING;}
//    }
//    hijo=0;
//    return SUCCESS;
//}
//void NodoSecuencia::reset(){
//    for (int i=0; i<m_hijos.size(); i++) {
//        m_hijos[i]->reset();
//    }
//    hijo = 0;
////}
//void NodoSecuenciaPositiva::reset(){
//    for (int i=0; i<m_hijos.size(); i++) {
//        m_hijos[i]->reset();
//    }
//    hijo = 0;
//}
//NodoSecuencia::~NodoSecuencia(){
//    for (int i=0; i<m_hijos.size(); i++) {
//        if(m_hijos[i]!=NULL){
//            delete m_hijos[i];
//            m_hijos[i] = NULL;
//        }
//    }
//    m_hijos.clear();
//}
// NODO SECUENCIA POSITIVA
//NodoSecuenciaPositiva::NodoSecuenciaPositiva(){hijo=0;}
//short NodoSecuenciaPositiva::run(int &id){
//    cout << "NODO SECUENCIA POSITIVA" <<endl;
//    for(;hijo<m_hijos.size();hijo++){
//        short answer = m_hijos[hijo]->run(id);
//        if(answer==SUCCESS){hijo=0;return SUCCESS;}
//        else if (answer==RUNNING){return RUNNING;}
//    }
//    hijo=0;
//    return FAILURE;
//}
//void NodoSecuenciaPositiva::anyadirHijo(Nodo * hijo){m_hijos.push_back(hijo);}
//NodoSecuenciaPositiva::~NodoSecuenciaPositiva(){
//    for (int i=0; i<m_hijos.size(); i++) {
//        if(m_hijos[i]!=NULL){
//            delete m_hijos[i];
//            m_hijos[i]=NULL;
//        }
//    }
//    m_hijos.clear();
//}

// NODOS DE ACCION
// NODO RECORRER ZONA
//NodoRecorreZonaCercana::NodoRecorreZonaCercana(){}
//NodoRecorreZonaCercana::~NodoRecorreZonaCercana(){}
//short NodoRecorreZonaCercana::run(int &id){return false;}

// NODO MOVER
//NodoMover::NodoMover(){_movement=new dvector3D(0,0,0);aux=-1;}
//NodoMover::~NodoMover(){delete _movement;}
//short NodoMover::run(int &id){
//    cout << "NODO MOVER" << endl;
//    if(_movement==NULL) _movement = new dvector3D;
//    if(aux==-1){
//        dvector3D posObjetivo,posPropia;
//        posPropia = *NPC_library::instance()->getMyBook(&id)->getPosition();
//        posObjetivo = *NPC_library::instance()->getMyBook(&id)->getPosObjetivo();
//        aux = CalcularDistancia(posPropia,posObjetivo);
//        xABS = posObjetivo.x-posPropia.x;
//        yABS = posObjetivo.y-posPropia.y;
//    }else if(aux>0 && aux<1.5f){
//        NPC_library::instance()->getMyBook(&id)->updateEvent();
//        aux=-1;
//        return true;
//    }else{
//        float y=0,x=0;
//        if(aux<2){
//            x = xABS;
//            y = yABS;
//        }else{
//            float por = (2*100/aux);
//            x = xABS*(por/100);
//            y = yABS*(por/100);
//        }
//        _movement->x = x;
//        _movement->y = y;
//        _movement->z = 0;
//        NPC_library::instance()->getMyBook(&id)->setVMovement(_movement);
//        aux = -1;
//    }
//    return RUNNING;
//}
//float NodoMover::CalcularDistancia(dvector3D a, dvector3D b){
//    float x = fabs(a.x-b.x);
//    float y = fabs(a.y-b.y);
//    return x+y;
//}

// NODO COMER
//NodoComer::NodoComer(){}
//short NodoComer::run(int &id){
//    cout << " NODO COMER" <<endl;
//    TypeRecords comida = R_COMIDA;
//    World_BlackBoard::instance()->addRecord(
//                                            comida,
//                                            *World_BlackBoard::instance()->getAnswer(comida,id)->_idResponse,
//                                            World_BlackBoard::instance()->getAnswer(comida, id)->_answerInfo
//                                            );
//    //World_BlackBoard::instance()->AnswerRecord(const TypeRecords &type, int *id, dvector3D *info)
//    World_BlackBoard::instance()->removeRecord(comida,id);
//    NPC_library::instance()->getMyBook(&id)->setHungry(COMIDA_ALIMENTA);
//    
//    return true;
//}
//NodoComer::~NodoComer(){}
// NODO BEBER
//NodoBeber::NodoBeber(){}
//NodoBeber::~NodoBeber(){}
//short NodoBeber::run(int &id){
//    cout << " NODO BEBER" <<endl;
//    TypeRecords fuente = R_FUENTE;
//    World_BlackBoard::instance()->addRecord(fuente,
//                                            *World_BlackBoard::instance()->getAnswer(fuente, id)->_idResponse,
//                                            World_BlackBoard::instance()->getAnswer(fuente, id)->_answerInfo);
//    //World_BlackBoard::instance()->AnswerRecord(const TypeRecords &type, int *id, dvector3D *info)
//    World_BlackBoard::instance()->removeRecord(fuente, id);
//    NPC_library::instance()->getMyBook(&id)->setThirst(AGUA_HIDATRA);
//    return true;
//}
// NODO HUIR
//NodoHuir::NodoHuir(){}
//NodoHuir::~NodoHuir(){}
//short NodoHuir::run(int &id){
//    cout << " NODO HUIR" << endl;
//    return false;
//}
// NODO AVISAR
//NodoAvisar::NodoAvisar(){}
//NodoAvisar::~NodoAvisar(){}
//short NodoAvisar::run(int &id){
//    cout << " NODO AVISAR" << endl;
//    return false;
//}
// NODO HABLAR
//NodoHablar::NodoHablar(){}
//NodoHablar::~NodoHablar(){}
//short NodoHablar::run(int &id){
//    cout << " NODO HABLAR" << endl;
//    return false;
//}
// NODO CURARSE
//NodoCurarse::NodoCurarse(){}
//NodoCurarse::~NodoCurarse(){}
//short NodoCurarse::run(int &id){
//    cout << " NODO CURARSE" << endl;
//    TypeRecords botiquin = R_BOTIQUIN;
//    World_BlackBoard::instance()->addRecord(botiquin,
//    *World_BlackBoard::instance()->getAnswer(botiquin, id)->_idResponse,
//    World_BlackBoard::instance()->getAnswer(botiquin, id)->_answerInfo);
//    //World_BlackBoard::instance()->AnswerRecord(const TypeRecords &type, int *id, dvector3D *info)
//    World_BlackBoard::instance()->removeRecord(botiquin,id);
//    NPC_library::instance()->getMyBook(&id)->setLife(BOTIQUIN_CURA);
//    return true;
//}
// NODO VIGILAR
//NodoVigilar::NodoVigilar(){_time = 0;}
//NodoVigilar::~NodoVigilar(){}
//
//short NodoVigilar::run(int &id){
//    cout << "VIGILANDO" << std::endl;
//    if(_time==0) _time = time(NULL);
//    int estado = NPC_library::instance()->getMyBook(&id)->getState();
//    if(estado!=ESTANDAR){
//        if(_time+TIEMPO_VIGILIA+TIEMPO_ESTADO_ALTERADO<time(NULL)){
//            _time = 0;
//            if (estado==COMBATE) {
//                NPC_library::instance()->getMyBook(&id)->setState(ALERTA);
//                return true;
//            }
//            NPC_library::instance()->getMyBook(&id)->setState(ESTANDAR);
//            return true;
//        }
//    }else{
//        if(_time+TIEMPO_VIGILIA<time(NULL)){
//            _time = 0;
//            return true;
//        }
//    }
//    return false;
//    /*
//    if(NPC_library::instance()->getMyBook(&id)->getPosObjetivo()!=vigilar)
//        NPC_library::instance()->getMyBook(&id)->setPosObjetivo(vigilar);
//    else{
//        // TO DO: RESUMIR LLAMADAS WITHOUT ID
//        if(aux==-1){
//            aux = CalcularDistancia(*NPC_library::instance()->getMyBook(&id)->getPosition(), *NPC_library::instance()->getMyBook(&id)->getPosObjetivo());
//            xABS = NPC_library::instance()->getMyBook(&id)->getPosObjetivo()->x-NPC_library::instance()->getMyBook(&id)->getPosition()->x;
//            yABS = NPC_library::instance()->getMyBook(&id)->getPosObjetivo()->y-NPC_library::instance()->getMyBook(&id)->getPosition()->y;
//        }else if(aux>0 && aux<0.1){
//            aux=-1;
//            return true;
//        }else{
//            float y,x;
//            if(aux<2){
//                x = xABS;
//                y = yABS;
//            }else{
//                float por = (100/aux);
//                x = xABS*(por/100);
//                y = yABS*(por/100);
//            }
//            _movement->x = x;
//            _movement->y = y;
//            _movement->z = 0;
//            NPC_library::instance()->getMyBook(&id)->setVMovement(_movement);
//            aux = -1;
//        }
//    }*/
//    return false;
//}
// NODO CUBRISE
//NodoCubrirse::NodoCubrirse(){}
//NodoCubrirse::~NodoCubrirse(){}
//short NodoCubrirse::run(int &id){
//    cout << " NODO CUBRIRSE" << endl;
//    return false;
//}

// NODO PATRULLAR
//NodoPatrullar::NodoPatrullar(){}
//NodoPatrullar::~NodoPatrullar(){}
//short NodoPatrullar::run(int &id){
//    return true;
//}
// NODO ATAQUE CUERPO A CUERPO
//NodoAtaqueCuerpo::NodoAtaqueCuerpo(){}
//NodoAtaqueCuerpo::~NodoAtaqueCuerpo(){}
//short NodoAtaqueCuerpo::run(int &id){
//    cout << " NODO ATAQUE A CUEPO" << endl;
//    return false;
//}
// NODO ATAQUE DISTANCIA
//NodoAtaqueDistancia::NodoAtaqueDistancia(){}
//NodoAtaqueDistancia::~NodoAtaqueDistancia(){}
//short NodoAtaqueDistancia::run(int &id){
//    cout << " NODO ATACO DISTANCIA" << endl;
//    return false;
//}
//#############################
//#    NODOS DE CONDICION     #
//#############################

// NODO HAY RUIDO
//
//Nodo_HayRuido::Nodo_HayRuido(){}
//Nodo_HayRuido::~Nodo_HayRuido(){}
//short Nodo_HayRuido::run(int &id){
//    cout << " NODO HAY RUIDO ?" << endl;
//    if (NPC_library::instance()->getMyBook(&id)->EventUsed(EVENTO_RUIDO)) {
//        cout << "ESCUCHE" << endl;
//        NPC_library::instance()->getMyBook(&id)->EventPosObjetivo(EVENTO_RUIDO);
//        return true;
//    }
//    return false;
//}

// PUEDO ATACAR DISTANCIA ?
//Nodo_PuedoAtacarDistancia::~Nodo_PuedoAtacarDistancia(){}
//Nodo_PuedoAtacarDistancia::Nodo_PuedoAtacarDistancia(){}
//short Nodo_PuedoAtacarDistancia::run(int &id){
//    cout << " NODO PUEDO ATACAR DISTANCIA ?" << endl;
//    return false;
//}

// NODO TENGO QUE VIGILAR
//Nodo_TengoVigilar::Nodo_TengoVigilar(){}
//Nodo_TengoVigilar::~Nodo_TengoVigilar(){}
//short Nodo_TengoVigilar::run(int &id){
//    cout << "TENGO QUE VIGILAR" << endl;
//    if (NPC_library::instance()->getMyBook(&id)->EventUsed(EVENTO_VIGILAR)) {
//        NPC_library::instance()->getMyBook(&id)->EventPosObjetivo(EVENTO_VIGILAR);
//        return true;
//    }
//    return  false;
//}

// NODO NECESITO AYUDA?
//Nodo_NecesitoAyuda::~Nodo_NecesitoAyuda(){}
//Nodo_NecesitoAyuda::Nodo_NecesitoAyuda(){}
//short Nodo_NecesitoAyuda::run(int &id){
//    cout << " NODO NECESITO AYUDA ?" << endl;
//    return false;
//}

//// NODO ALARMA ROTA?
//Nodo_AlarmaRota::~Nodo_AlarmaRota(){}
//Nodo_AlarmaRota::Nodo_AlarmaRota(){}
//short Nodo_AlarmaRota::run(int &id){
//    cout << " NODO ALARMA ROTA ?" << endl;
//    // WorldInfo->comprobadaAlarma = true;
//    //if(WorldInfo->estadoAlarma) return false;
//    return true;
//}

// NODO HE SIDO AVISADO ?
//Nodo_Avisado::Nodo_Avisado(){};
//Nodo_Avisado::~Nodo_Avisado(){}
//short Nodo_Avisado::run(int &id){
//    cout << " NODO AVISADO ?" << endl;
//    //if(NPCinfo->getLLamada()) return true;
//    return false;
//}

//// NODO TENGO SED ?
//Nodo_TengoSed::Nodo_TengoSed(){}
//Nodo_TengoSed::~Nodo_TengoSed(){}
//short Nodo_TengoSed::run(int &id){
//    cout << "NODO TENGO SED" << endl;
//    TypeRecords sed = R_FUENTE;
//    if(NPC_library::instance()->getMyBook(&id)->getThirst()>UMBRAL_SED){
//        if (World_BlackBoard::instance()->existRecord(sed, id)) {
//            if (World_BlackBoard::instance()->hasAnswer(sed, id)) {
//                NPC_library::instance()->getMyBook(&id)->setPosObjetivo(World_BlackBoard::instance()->getAnswer(sed, id)->_answerInfo);
//                return true;
//            }
//            return false;
//        }
//        World_BlackBoard::instance()->addRecord(sed, id, NPC_library::instance()->getMyBook(&id)->getPosition());
//    }
//    return false;
//}
// NODO TENGO HAMBRE ?
//Nodo_TengoHambre::Nodo_TengoHambre(){}
//Nodo_TengoHambre::~Nodo_TengoHambre(){}
//short Nodo_TengoHambre::run(int &id){
//    cout << "NODO TENGO HAMBRE" << endl;
//    TypeRecords comida = R_COMIDA;
//    if(NPC_library::instance()->getMyBook(&id)->getHungry()>=UMBRAL_HAMBRE){
//        if (World_BlackBoard::instance()->existRecord(comida, id)) {
//            if (World_BlackBoard::instance()->hasAnswer(comida, id)) {
//                NPC_library::instance()->getMyBook(&id)->setPosObjetivo(World_BlackBoard::instance()->getAnswer(comida, id)->_answerInfo);
//                return true;
//            }
//            return false;
//        }
//        World_BlackBoard::instance()->addRecord(comida, id, NPC_library::instance()->getMyBook(&id)->getPosition());
//    }
//    return false;
//}
// NODO VIDA BAJA ?
//Nodo_VidaBaja::Nodo_VidaBaja(){}
//Nodo_VidaBaja::~Nodo_VidaBaja(){}
//short Nodo_VidaBaja::run(int &id){
//    cout << " NODO VIDA BAJA?" << endl;
//    if(NPC_library::instance()->getMyBook(&id)->getLife()<=UMBRAL_VIDA)
//        return true;
//    return false;
//}
//// NODO TIENE AGUA ?
//Nodo_TieneAgua::Nodo_TieneAgua(){}
//Nodo_TieneAgua::~Nodo_TieneAgua(){}
//short Nodo_TieneAgua::run(int &id){
//    cout << " NODO FUENTE TIENE AGUA?" << endl;
//    
//    return true;
//}
// NODO VER JUGADOR ?
//Nodo_VerJugador::Nodo_VerJugador(){}
//Nodo_VerJugador::~Nodo_VerJugador(){}
//short Nodo_VerJugador::run(int &id){
//    cout << " NODO VES AL JUGADOR?" << endl;
//    return false;
//}
//// NODO ALARMA CERCA?
//Nodo_AlarmaCerca::Nodo_AlarmaCerca(){}
//Nodo_AlarmaCerca::~Nodo_AlarmaCerca(){}
//short Nodo_AlarmaCerca::run(int &id){
//    
//    if (NPC_library::instance()->getMyBook(&id)->EventUsed(EVENTO_ALARMA_CERCA)) {
//        NPC_library::instance()->getMyBook(&id)->EventPosObjetivo(EVENTO_ALARMA_CERCA);
//        return true;
//    }
//    cout << " NODO ALARMA CERCA?" << endl;
//    /*######################################
//     TRIGGER SYSTEM
//     #####################################*/
//    return false;
//}
//// NODO HAY BOTIQUIN ?
//Nodo_HayBotiquin::Nodo_HayBotiquin(){}
//Nodo_HayBotiquin::~Nodo_HayBotiquin(){}
//short Nodo_HayBotiquin::run(int &id){
//    cout << "NODO HAY BOTIQUIN" << endl;
//    TypeRecords botiquin = R_BOTIQUIN;
//    if (World_BlackBoard::instance()->existRecord(botiquin, id)) {
//        if (World_BlackBoard::instance()->hasAnswer(botiquin, id)) {
//            NPC_library::instance()->getMyBook(&id)->setPosObjetivo(World_BlackBoard::instance()->getAnswer(botiquin, id)->_answerInfo);
//            return true;
//        }
//    }
//    World_BlackBoard::instance()->addRecord(botiquin, id, NPC_library::instance()->getMyBook(&id)->getPosition());
//    return false;
//}
// NODO SUENA ALARMA ?
//Nodo_SuenaAlarma::Nodo_SuenaAlarma(){}
//Nodo_SuenaAlarma::~Nodo_SuenaAlarma(){}
//short Nodo_SuenaAlarma::run(int &id){
//    if (NPC_library::instance()->getMyBook(&id)->EventUsed(EVENTO_ALARMA)) {
//        NPC_library::instance()->getMyBook(&id)->setState(ALERTA);
//        return true;
//    }
//    cout << " NODO SUENA ALARMA?" << endl;
//    /*######################################
//     TRIGGER SYSTEM
//     #####################################*/
//    return false;
//}
//// NODO ESTAS ASUSTADO ?
//Nodo_EstasAsustado::Nodo_EstasAsustado(){}
//Nodo_EstasAsustado::~Nodo_EstasAsustado(){}
//short Nodo_EstasAsustado::run(int &id){
//    cout << " NODO ASUSTADO?" << endl;
//    return false;
//}
// NODO HAY PARA HABLAR ?
//Nodo_HayParaHablar::Nodo_HayParaHablar(){}
//Nodo_HayParaHablar::~Nodo_HayParaHablar(){}
//short Nodo_HayParaHablar::run(int &id){
//    if (NPC_library::instance()->getMyBook(&id)->EventUsed(EVENTO_HABLAR)) {
//        NPC_library::instance()->getMyBook(&id)->EventPosObjetivo(EVENTO_HABLAR);
//        return true;
//    }
//    cout << " NODO ALGUIEN HABLAR?" << endl;
//    /*######################################
//     TRIGGER SYSTEM
//     #####################################*/
//    return false;
//}

//// NODO HAY ALGUIEN CERCA ?
//Nodo_HayAlguienCerca::Nodo_HayAlguienCerca(){}
//Nodo_HayAlguienCerca::~Nodo_HayAlguienCerca(){}
//short Nodo_HayAlguienCerca::run(int &id){
//    TypeRecords radio = R_RADIO;
//    TypeRecords cercano = R_CERCA;
//    if(World_BlackBoard::instance()->existRecord(radio, id)) return false;
//    if(World_BlackBoard::instance()->existRecord(cercano, id)){
//        if(World_BlackBoard::instance()->hasAnswer(cercano, id)){
//            return true;
//        }
//        return false;
//    }
//    World_BlackBoard::instance()->addRecord(cercano, id, NPC_library::instance()->getMyBook(&id)->getPosition());
//    
//    cout << "NODO HAY ALGUIEN CERCA " << endl;
//    return false;
//}
//// NODO HAY ALGUIEN RADIO ?
//Nodo_HayAlguienRadio::Nodo_HayAlguienRadio(){}
//Nodo_HayAlguienRadio::~Nodo_HayAlguienRadio(){}
//short Nodo_HayAlguienRadio::run(int &id){
//    TypeRecords radio = R_RADIO;
//    TypeRecords cercano = R_CERCA;
//    if(World_BlackBoard::instance()->existRecord(cercano, id)) return false;
//    if(World_BlackBoard::instance()->existRecord(radio, id)){
//        if(World_BlackBoard::instance()->hasAnswer(radio, id)){
//            return true;
//        }
//        return false;
//    }
//    World_BlackBoard::instance()->addRecord(radio, id, NPC_library::instance()->getMyBook(&id)->getPosition());
//    
//    return false;
//    
//    cout << " NODO HAY NPCS POR RADIO?" << endl;
//    
//    return false;
//}
//// NODO ESTAS CERCA JUGADOR ?
//Nodo_EstasCercaJugador::Nodo_EstasCercaJugador(){}
//Nodo_EstasCercaJugador::~Nodo_EstasCercaJugador(){}
//short Nodo_EstasCercaJugador::run(int &id){
//    cout << " NODO ESTAS CERCA DEL PLAYER?" << endl;
//    return false;
//}
//// NODO ESTAS LEJOS JUGADOR ?
//Nodo_EstasLejosJugador::Nodo_EstasLejosJugador(){}
//Nodo_EstasLejosJugador::~Nodo_EstasLejosJugador(){}
//short Nodo_EstasLejosJugador::run(int &id){
//    cout << " NODO ESTAS LEJOS DEL PLAYER?" << endl;
//    return false;
//}
// NODO TIEMPO INACTIVO ?
//Nodo_TiempoInactivo::Nodo_TiempoInactivo(){}
//Nodo_TiempoInactivo::~Nodo_TiempoInactivo(){}
//short Nodo_TiempoInactivo::run(int &id){
//    cout << " NODO TIEMPO INACTIVO?" << endl;
//    return false;
//}



