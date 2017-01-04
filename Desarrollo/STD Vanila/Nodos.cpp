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

// NODOS COMIDA CERCANA
// NODOS FUENTE CERCANA




//NODOS ESPECIALES / GENERALES
/*float Nodo::CalcularDistancia(vector3D a, vector3D b){
    float x = fabs(a.x-b.x);
    float y = fabs(a.y-b.y);
    return x+y;
}*/


// NODO SECUENCIA
NodoSecuencia::NodoSecuencia(){}
void NodoSecuencia::anyadirHijo(Nodo * hijo){NodoSecuencia::m_hijos.push_back(hijo);}
short NodoSecuencia::run(int &id){
    //cout << "NODO SECUENCIA" << endl;
    int i = hijo;
    for (i; i<m_hijos.size(); i++) {
        short answer = m_hijos[i]->run(id);
        if (answer==FAILURE) {hijo=0;return FAILURE;}
        else if(answer==RUNNING){hijo = i ;return RUNNING;}
    }
    hijo=0;
    return SUCCESS;
}

// NODO SECUENCIA POSITIVA
NodoSecuenciaPositiva::NodoSecuenciaPositiva(){}
short NodoSecuenciaPositiva::run(int &id){
    //cout << "NODO SECUENCIA POSITIVA" <<endl;
    int i = hijo;
    for(i;i<m_hijos.size();i++){
        short answer = m_hijos[i]->run(id);
        if(answer==SUCCESS){hijo=0;return SUCCESS;}
        else if (answer==RUNNING){hijo=i;return RUNNING;}
    }
    hijo=0;
    return FAILURE;
}

void NodoSecuenciaPositiva::anyadirHijo(Nodo * hijo){m_hijos.push_back(hijo);}


// NODOS DE ACCION
// NODO RECORRER ZONA
NodoRecorreZonaCercana::NodoRecorreZonaCercana(){}
short NodoRecorreZonaCercana::run(int &id){return false;}

// NODO MOVER
NodoMover::NodoMover(){}
short NodoMover::run(int &id){
    //cout << "NODO MOVER" << endl;
    
    /*
    if(aux==-1) {
        aux = CalcularDistancia(*NPCinfo->getPosActual(), *NPCinfo->getPosAviso());
        yABS = NPCinfo->getPosAviso()->y-NPCinfo->getPosActual()->y;
        xABS = NPCinfo->getPosAviso()->x-NPCinfo->getPosActual()->x;
    }else if (aux<0.5 && aux>0) {
        aux=-1;
        return true;
    }else{
        if(fabsf(xABS)>fabsf(yABS)){
            float x = 0.05;
            if (xABS<0) x=-0.05;
            NPCinfo->newPosition(new vector3D{NPCinfo->getPosActual()->x+x,NPCinfo->getPosActual()->y,NPCinfo->getPosActual()->z});
        }else{
            float y = 0.05;
            if (yABS<0) y=-0.05;
            NPCinfo->newPosition(new vector3D{NPCinfo->getPosActual()->x,NPCinfo->getPosActual()->y+y,NPCinfo->getPosActual()->z});
        }
        //cout << "JUGADOR :" << NPCinfo->getPosActual()->x << "|" << NPCinfo->getPosActual()->y << endl;
        //cout << NPCinfo->getPosAviso()->x << "|" << NPCinfo->getPosAviso()->y << endl;
        aux = -1;
        
    }*/
    return RUNNING;
}

// NODO COMER
NodoComer::NodoComer(){}
short NodoComer::run(int &id){
    cout << " NODO COMER" <<endl;
    NPC_library::instance()->getMyBook(&id)->setHungry(COMIDA_ALIMENTA);
    //NPCinfo->Alimentarse(COMIDA_ALIMENTA);
    
    return true;
}
// NODO BEBER
NodoBeber::NodoBeber(){}
short NodoBeber::run(int &id){
    cout << " NODO BEBER" <<endl;
    NPC_library::instance()->getMyBook(&id)->setThirst(AGUA_HIDATRA);
    //NPCinfo->Beber(AGUA_HIDATRA);
    
    return true;
}
// NODO HUIR
NodoHuir::NodoHuir(){}
short NodoHuir::run(int &id){
    //cout << " NODO HUIR" << endl;
    return false;
}
// NODO AVISAR
NodoAvisar::NodoAvisar(){}
short NodoAvisar::run(int &id){
    //cout << " NODO AVISAR" << endl;
    //NPCinfo->Avisado(true);
    return false;
}
// NODO HABLAR
NodoHablar::NodoHablar(){}
short NodoHablar::run(int &id){
    //cout << " NODO HABLAR" << endl;
    return false;
}
// NODO CURARSE
NodoCurarse::NodoCurarse(){}
short NodoCurarse::run(int &id){
    cout << " NODO CURARSE" << endl;
    NPC_library::instance()->getMyBook(&id)->setLife(BOTIQUIN_CURA);
    //cout << "  VIDA ANTES :" << NPCinfo->getLife() << endl;
    //NPCinfo->Curarse(BOTIQUIN_CURA);
    //cout << "  VIDA DESPS :" << NPCinfo->getLife() << endl;
    return true;
}
// NODO VIGILAR
NodoVigilar::NodoVigilar(){}
short NodoVigilar::run(int &id){
    //cout << " NODO VIGILAR" << endl;
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
        //cout << x << "|" << y << endl;
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
short NodoCubrirse::run(int &id){
    //cout << " NODO CUBRIRSE" << endl;
    return false;
}

// NODO PATRULLAR
NodoPatrullar::NodoPatrullar(){}
short NodoPatrullar::run(int &id){
    //cout << " NODO PATRULLAR" << endl;
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
short NodoAtaqueCuerpo::run(int &id){
    //cout << " NODO ATAQUE A CUEPO" << endl;
    return false;
}
// NODO ATAQUE DISTANCIA
NodoAtaqueDistancia::NodoAtaqueDistancia(){}
short NodoAtaqueDistancia::run(int &id){
    //cout << " NODO ATACO DISTANCIA" << endl;
    return false;
}
//#############################
//#    NODOS DE CONDICION     #
//#############################

// NODO HAY RUIDO

Nodo_HayRuido::Nodo_HayRuido(){}
short Nodo_HayRuido::run(int &id){
    //cout << " NODO HAY RUIDO ?" << endl;
    return false;
}

// PUEDO ATACAR DISTANCIA ?

Nodo_PuedoAtacarDistancia::Nodo_PuedoAtacarDistancia(){}
short Nodo_PuedoAtacarDistancia::run(int &id){
    //cout << " NODO PUEDO ATACAR DISTANCIA ?" << endl;
    return false;
}

// NODO NECESITO AYUDA?

Nodo_NecesitoAyuda::Nodo_NecesitoAyuda(){}
short Nodo_NecesitoAyuda::run(int &id){
    //cout << " NODO NECESITO AYUDA ?" << endl;
    return false;
}

// NODO ALARMA ROTA?

Nodo_AlarmaRota::Nodo_AlarmaRota(){}
short Nodo_AlarmaRota::run(int &id){
    //cout << " NODO ALARMA ROTA ?" << endl;
   // WorldInfo->comprobadaAlarma = true;
    //if(WorldInfo->estadoAlarma) return false;    
    return true;
}

// NODO HE SIDO AVISADO ?
Nodo_Avisado::Nodo_Avisado(){};
short Nodo_Avisado::run(int &id){
    //cout << " NODO AVISADO ?" << endl;
    //if(NPCinfo->getLLamada()) return true;
    return false;
}

// NODO TENGO SED ?
Nodo_TengoSed::Nodo_TengoSed(){}
short Nodo_TengoSed::run(int &id){
    
    /*if(NPCinfo->getSed()>UMBRAL_SED && WorldInfo->Botiquines.size()>0) {
        cout << " NODO TENGO SED?" << endl;
        NPCinfo->setPosicionFinal(MasCercano(WorldInfo->Fuente,NPCinfo));
        return true;
    }*/
    return false;
}
/*vector3D * Nodo_TengoSed::MasCercano(){
    int x = 0;
    
    float distancia;
    float aux = CalcularDistancia(*objetos[0],*NPCinfo->getPosActual());
    
    for (int i=0; i<objetos.size(); i++) {
        distancia = CalcularDistancia(*objetos[i],*NPCinfo->getPosActual());
        if(aux>distancia){
            x = i;
            aux = distancia;
        }
    }
    return objetos[x];
}*/
// NODO TENGO HAMBRE ?
Nodo_TengoHambre::Nodo_TengoHambre(){}
short Nodo_TengoHambre::run(int &id){
   
    /*if (NPCinfo->getHambre()>UMBRAL_HAMBRE && WorldInfo->Comida.size()>0) {
         cout << " NODO TEMGO HAMBRE?" << endl;
        NPCinfo->setPosicionFinal(MasCercano(WorldInfo->Comida, NPCinfo));
        return true;
    }*/
    return false;
}
/*vector3D * Nodo_TengoHambre::MasCercano(){
    int x = 0;
    
    float distancia;
    float aux = CalcularDistancia(*objetos[0],*NPCinfo->getPosActual());
    
    for (int i=0; i<objetos.size(); i++) {
        distancia = CalcularDistancia(*objetos[i],*NPCinfo->getPosActual());
        if(aux>distancia){
            x = i;
            aux = distancia;
        }
    }
    return objetos[x];
}*/
// NODO VIDA BAJA ?
Nodo_VidaBaja::Nodo_VidaBaja(){}
short Nodo_VidaBaja::run(int &id){
    //cout << " NODO VIDA BAJA?" << endl;
    //if(NPCinfo->getLife()<=UMBRAL_VIDA) {
        //cout << "  VIDA BAJA!" << endl;
        //return true;
    //}
    return false;
}
// NODO TIENE AGUA ?
Nodo_TieneAgua::Nodo_TieneAgua(){}
short Nodo_TieneAgua::run(int &id){
    //cout << " NODO FUENTE TIENE AGUA?" << endl;
    //WorldInfo->comprobadaFuente = true;
    //if(WorldInfo->estadofuente) return false;
    //NPCinfo->setPosicionFinal(WorldInfo->ObjetosCercanos[FUENTE-1]);
    return true;
}
// NODO VER JUGADOR ?
Nodo_VerJugador::Nodo_VerJugador(){}
short Nodo_VerJugador::run(int &id){
    //cout << " NODO VES AL JUGADOR?" << endl;
    return false;
}
// NODO ALARMA CERCA?
Nodo_AlarmaCerca::Nodo_AlarmaCerca(){}
short Nodo_AlarmaCerca::run(int &id){
    
    //cout << " NODO ALARMA CERCA?" << endl;
    /*if(MasCercano(WorldInfo->Alarma, NPCinfo)!=NULL)
        WorldInfo->posicion = MasCercano(WorldInfo->Alarma, NPCinfo);
        return true;*/
    return false;
}
/*vector3D * Nodo_AlarmaCerca::MasCercano(){
    if (objetos.size()>0) {
        int x = 0;
        float distancia;
        float aux = CalcularDistancia(*objetos[0],*NPCinfo->getPosActual());
        for (int i=0; i<objetos.size(); i++) {
            distancia = CalcularDistancia(*objetos[i],*NPCinfo->getPosActual());
            if(aux>distancia){
                x = i;
            }
        }
        return objetos[x];
    }
    return NULL;
}*/
// NODO HAY BOTIQUIN ?
Nodo_HayBotiquin::Nodo_HayBotiquin(){}
short Nodo_HayBotiquin::run(int &id){
    if(World_BlackBoard::instance()->existRecord(R_BOTIQUIN, &id)){
        if(World_BlackBoard::instance()->hasAnswer(R_BOTIQUIN, &id)){
            return true;
        }
        return false;
    }
    World_BlackBoard::instance()->addRecord(R_BOTIQUIN, &id, NPC_library::instance()->getMyBook(&id)->getPosition());
    //cout << " NODO HAY BOTIQUIN" << endl;
    /*if(WorldInfo->Botiquines.size()>0){
        NPCinfo->setPosicionFinal(MasCercano(WorldInfo->Botiquines,NPCinfo));
        //cout << "  HAY BOTQUIN" << endl;
        return true;
    }*/
    return false;
}
/*vector3D * Nodo_HayBotiquin::MasCercano(vector<vector3D*>& objetos,datos * NPCinfo){
    int x = 0;
    
    float distancia;
    float aux = CalcularDistancia(*objetos[0],*NPCinfo->getPosActual());
    //cout << aux << endl;
    for (int i=0; i<objetos.size(); i++) {
        distancia = CalcularDistancia(*objetos[i],*NPCinfo->getPosActual());
        if(aux>distancia){
            x = i;
            aux = distancia;
        }
    }
    //cout << "POS BOTI   " << objetos[x]->x << endl;
    return objetos[x];
}*/
// NODO SUENA ALARMA ?
Nodo_SuenaAlarma::Nodo_SuenaAlarma(){}
short Nodo_SuenaAlarma::run(int &id){
    //cout << " NODO SUENA ALARMA?" << endl;
    //if(WorldInfo->alarmaActivada) return true;
    return false;
}
// NODO ESTAS ASUSTADO ?
Nodo_EstasAsustado::Nodo_EstasAsustado(){}
short Nodo_EstasAsustado::run(int &id){
    //cout << " NODO ASUSTADO?" << endl;
    /*if (NPCinfo->getSed()>=UMBRAL_SED && NPCinfo->getLife()<UMBRAL_VIDA && NPCinfo->getHambre()>=UMBRAL_HAMBRE) {
        NPCinfo->setEstados(ASUSTADO);
        return true;
    }*/
    return false;
}
// NODO HAY PARA HABLAR ?
Nodo_HayParaHablar::Nodo_HayParaHablar(){}
short Nodo_HayParaHablar::run(int &id){
    //cout << " NODO ALGUIEN HABLAR?" << endl;
    return false;
}

// NODO HAY ALGUIEN CERCA ?
Nodo_HayAlguienCerca::Nodo_HayAlguienCerca(){}
/*float Nodo_HayAlguienCerca::CalcularDistancia(vector3D a, vector3D b){
    float x = fabs(pow(a.x-b.x,2));
    float y = fabs(pow(a.y-b.y,2));
    return sqrt(x+y);
}*/
short Nodo_HayAlguienCerca::run(int &id){
    /*for (int i = 0; i<WorldInfo->posicionesNPC.size(); i++) {
        if(2>-1 && CalcularDistancia(*WorldInfo->posicionesNPC[i], *NPCinfo->getPosActual())<=DISTANCIA_COMUNICACION_PERSONAL){
            NPCinfo->setPosicionFinal(WorldInfo->posicionesNPC[i]);
            return true;
        }
    }*/
    return false;
}
// NODO HAY ALGUIEN RADIO ?
Nodo_HayAlguienRadio::Nodo_HayAlguienRadio(){}
short Nodo_HayAlguienRadio::run(int &id){
    //cout << " NODO HAY NPCS POR RADIO?" << endl;
    //if (WorldInfo->posicionesNPC.size()>0) return true;
    return false;
}
// NODO ESTAS CERCA JUGADOR ?
Nodo_EstasCercaJugador::Nodo_EstasCercaJugador(){}
short Nodo_EstasCercaJugador::run(int &id){
    //cout << " NODO ESTAS CERCA DEL PLAYER?" << endl;
    return false;
}
// NODO ESTAS LEJOS JUGADOR ?
Nodo_EstasLejosJugador::Nodo_EstasLejosJugador(){}
short Nodo_EstasLejosJugador::run(int &id){
    //cout << " NODO ESTAS LEJOS DEL PLAYER?" << endl;
    return false;
}
// NODO TIEMPO INACTIVO ?
Nodo_TiempoInactivo::Nodo_TiempoInactivo(){}
short Nodo_TiempoInactivo::run(int &id){
    //cout << " NODO TIEMPO INACTIVO?" << endl;
    return false;
}



