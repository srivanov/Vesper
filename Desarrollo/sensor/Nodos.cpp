//
//  Nodos.cpp
//  Sistema de Decision
//
//  Created by Gaspar Rodriguez Valero on 29/11/16.
//  Copyright © 2016 Gaspar Rodriguez Valero. All rights reserved.
//
#include "Nodos.hpp"
#include "gestor_eventos.hpp"

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



// NODO SECUENCIA
NodoSecuencia::NodoSecuencia(){}
void NodoSecuencia::anyadirHijo(Nodo * hijo){NodoSecuencia::m_hijos.push_back(hijo);}
short NodoSecuencia::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << "NODO SECUENCIA" << endl;
    size_t i = hijo;
    for (i; i<m_hijos.size(); i++) {
        short answer = m_hijos[i]->run(NPCinfo, WorldInfo);
        if (answer==FAILURE) {hijo=0;return FAILURE;}
        else if(answer==RUNNING){hijo = i ;return RUNNING;}
    }
    hijo=0;
    return SUCCESS;
}

// NODO SECUENCIA POSITIVA
NodoSecuenciaPositiva::NodoSecuenciaPositiva(){}
short NodoSecuenciaPositiva::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << "NODO SECUENCIA POSITIVA" <<endl;
    size_t i = hijo;
    for(i;i<m_hijos.size();i++){
        short answer = m_hijos[i]->run(NPCinfo, WorldInfo);
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
short NodoRecorreZonaCercana::run(datos * NPCinfo, BlackBoard * WorldInfo){return false;}

// NODO MOVER
NodoMover::NodoMover(){}
short NodoMover::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << "NODO MOVER" << endl;
    
    
    if(aux==-1) {
        aux = vector3D::CalcularDistancia(*NPCinfo->getPosActual(), *NPCinfo->getPosAviso());
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
        
    }
    return RUNNING;
}

// NODO COMER
NodoComer::NodoComer(){}
short NodoComer::run(datos * NPCinfo, BlackBoard * WorldInfo){
    cout << " NODO COMER" <<endl;
    NPCinfo->Alimentarse(COMIDA_ALIMENTA);
    
    return true;
}
// NODO BEBER
NodoBeber::NodoBeber(){}
short NodoBeber::run(datos * NPCinfo, BlackBoard * WorldInfo){
    cout << " NODO BEBER" <<endl;
    NPCinfo->Beber(AGUA_HIDATRA);
    
    return true;
}
// NODO HUIR
NodoHuir::NodoHuir(){}
short NodoHuir::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO HUIR" << endl;
    return false;
}
// NODO AVISAR
NodoAvisar::NodoAvisar(){}
short NodoAvisar::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO AVISAR" << endl;
    //NPCinfo->Avisado(true);
    return false;
}
// NODO HABLAR
NodoHablar::NodoHablar(){}
short NodoHablar::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO HABLAR" << endl;
    return false;
}
// NODO CURARSE
NodoCurarse::NodoCurarse(){}
short NodoCurarse::run(datos * NPCinfo, BlackBoard * WorldInfo){
    cout << " NODO CURARSE" << endl;
    //cout << "  VIDA ANTES :" << NPCinfo->getLife() << endl;
    NPCinfo->Curarse(BOTIQUIN_CURA);
    //cout << "  VIDA DESPS :" << NPCinfo->getLife() << endl;
    return true;
}
// NODO VIGILAR
NodoVigilar::NodoVigilar(){}
short NodoVigilar::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO VIGILAR" << endl;
    if(NPCinfo->getRutina()!=0){
        float aux = vector3D::CalcularDistancia(*NPCinfo->getPosActual(), *NPCinfo->getPosRutina()[NPCinfo->getPaso()]);
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
        
    return false;
}
// NODO CUBRISE
NodoCubrirse::NodoCubrirse(){}
short NodoCubrirse::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO CUBRIRSE" << endl;
    return false;
}

// NODO PATRULLAR
NodoPatrullar::NodoPatrullar(){}
short NodoPatrullar::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO PATRULLAR" << endl;
    if (NPCinfo->getRutina()!=0) {
        return false;
    }
    float aux = vector3D::CalcularDistancia(*NPCinfo->getPosActual(), *NPCinfo->getPosRutina()[NPCinfo->getPaso()]);
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
    
    return true;
}
// NODO ATAQUE CUERPO A CUERPO
NodoAtaqueCuerpo::NodoAtaqueCuerpo(){}
short NodoAtaqueCuerpo::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO ATAQUE A CUEPO" << endl;
    return false;
}
// NODO ATAQUE DISTANCIA
NodoAtaqueDistancia::NodoAtaqueDistancia(){}
short NodoAtaqueDistancia::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO ATACO DISTANCIA" << endl;
    return false;
}
//#############################
//#    NODOS DE CONDICION     #
//#############################

// NODO HAY RUIDO

Nodo_HayRuido::Nodo_HayRuido(){}
short Nodo_HayRuido::run(datos * NPCinfo, BlackBoard *WorldInfo){
    //cout << " NODO HAY RUIDO ?" << endl;
    return false;
}

// PUEDO ATACAR DISTANCIA ?

Nodo_PuedoAtacarDistancia::Nodo_PuedoAtacarDistancia(){}
short Nodo_PuedoAtacarDistancia::run(datos * NPCinfo, BlackBoard *WorldInfo){
    //cout << " NODO PUEDO ATACAR DISTANCIA ?" << endl;
    return false;
}

// NODO NECESITO AYUDA?

Nodo_NecesitoAyuda::Nodo_NecesitoAyuda(){}
short Nodo_NecesitoAyuda::run(datos * NPCinfo, BlackBoard *WorldInfo){
    //cout << " NODO NECESITO AYUDA ?" << endl;
    return false;
}

// NODO ALARMA ROTA?

Nodo_AlarmaRota::Nodo_AlarmaRota(){}
short Nodo_AlarmaRota::run(datos * NPCinfo, BlackBoard *WorldInfo){
    //cout << " NODO ALARMA ROTA ?" << endl;
    WorldInfo->comprobadaAlarma = true;
    if(WorldInfo->estadoAlarma) return false;    
    return true;
}

// NODO HE SIDO AVISADO ?
Nodo_Avisado::Nodo_Avisado(){};
short Nodo_Avisado::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO AVISADO ?" << endl;
    //if(NPCinfo->getLLamada()) return true;
    return false;
}

// NODO TENGO SED ?
Nodo_TengoSed::Nodo_TengoSed(){}
short Nodo_TengoSed::run(datos * NPCinfo, BlackBoard * WorldInfo){
    
    if(NPCinfo->getSed()>UMBRAL_SED && WorldInfo->Botiquines.size()>0) {
        cout << " NODO TENGO SED?" << endl;
        NPCinfo->setPosicionFinal(MasCercano(WorldInfo->Fuente,NPCinfo));
        return true;
    }
    return false;
}
vector3D * Nodo_TengoSed::MasCercano(vector<vector3D*>& objetos,datos * NPCinfo){
    int x = 0;
    
    float distancia;
    float aux = vector3D::CalcularDistancia(*objetos[0],*NPCinfo->getPosActual());
    
    for (int i=0; i<objetos.size(); i++) {
        distancia = vector3D::CalcularDistancia(*objetos[i],*NPCinfo->getPosActual());
        if(aux>distancia){
            x = i;
            aux = distancia;
        }
    }
    return objetos[x];
}
// NODO TENGO HAMBRE ?
Nodo_TengoHambre::Nodo_TengoHambre(){}
short Nodo_TengoHambre::run(datos * NPCinfo, BlackBoard * WorldInfo){
   
    if (NPCinfo->getHambre()>UMBRAL_HAMBRE && WorldInfo->Comida.size()>0) {
         cout << " NODO TEMGO HAMBRE?" << endl;
        NPCinfo->setPosicionFinal(MasCercano(WorldInfo->Comida, NPCinfo));
        return true;
    }
    return false;
}
vector3D * Nodo_TengoHambre::MasCercano(vector<vector3D*>& objetos,datos * NPCinfo){
    int x = 0;
    
    float distancia;
    float aux = vector3D::CalcularDistancia(*objetos[0],*NPCinfo->getPosActual());
    
    for (int i=0; i<objetos.size(); i++) {
        distancia = vector3D::CalcularDistancia(*objetos[i],*NPCinfo->getPosActual());
        if(aux>distancia){
            x = i;
            aux = distancia;
        }
    }
    return objetos[x];
}
// NODO VIDA BAJA ?
Nodo_VidaBaja::Nodo_VidaBaja(){}
short Nodo_VidaBaja::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO VIDA BAJA?" << endl;
    if(NPCinfo->getLife()<=UMBRAL_VIDA) {
        //cout << "  VIDA BAJA!" << endl;
        return true;
    }
    return false;
}
// NODO TIENE AGUA ?
Nodo_TieneAgua::Nodo_TieneAgua(){}
short Nodo_TieneAgua::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO FUENTE TIENE AGUA?" << endl;
    WorldInfo->comprobadaFuente = true;
    if(WorldInfo->estadofuente) return false;
    //NPCinfo->setPosicionFinal(WorldInfo->ObjetosCercanos[FUENTE-1]);
    return true;
}
// NODO VER JUGADOR ?
Nodo_VerJugador::Nodo_VerJugador(){}
short Nodo_VerJugador::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO VES AL JUGADOR?" << endl;
    for (int i=0; i<NPCinfo->getEvents().size(); i++) {
        if (NPCinfo->getEvents()[i]->type == tE_Enemy) {
            NPCinfo->setEstados(COMBATE);
            return true;
        }
    }
    //if(){}
    return false;
}
// NODO ALARMA CERCA?
Nodo_AlarmaCerca::Nodo_AlarmaCerca(){}
short Nodo_AlarmaCerca::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO ALARMA CERCA?" << endl;
    if(MasCercano(WorldInfo->Alarma, NPCinfo)!=NULL)
        WorldInfo->posicion = MasCercano(WorldInfo->Alarma, NPCinfo);
        return true;
    return false;
}
vector3D * Nodo_AlarmaCerca::MasCercano(vector<vector3D*>& objetos,datos * NPCinfo){
    if (objetos.size()>0) {
        int x = 0;
        float distancia;
        float aux = vector3D::CalcularDistancia(*objetos[0],*NPCinfo->getPosActual());
        for (int i=0; i<objetos.size(); i++) {
            distancia = vector3D::CalcularDistancia(*objetos[i],*NPCinfo->getPosActual());
            if(aux>distancia){
                x = i;
            }
        }
        return objetos[x];
    }
    return NULL;
}
// NODO HAY BOTIQUIN ?
Nodo_HayBotiquin::Nodo_HayBotiquin(){}
short Nodo_HayBotiquin::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO HAY BOTIQUIN" << endl;
    if(WorldInfo->Botiquines.size()>0){
        NPCinfo->setPosicionFinal(MasCercano(WorldInfo->Botiquines,NPCinfo));
        //cout << "  HAY BOTQUIN" << endl;
        return true;
    }
    return false;
}
vector3D * Nodo_HayBotiquin::MasCercano(vector<vector3D*>& objetos,datos * NPCinfo){
    int x = 0;
    
    float distancia;
    float aux = vector3D::CalcularDistancia(*objetos[0],*NPCinfo->getPosActual());
    //cout << aux << endl;
    for (int i=0; i<objetos.size(); i++) {
        distancia = vector3D::CalcularDistancia(*objetos[i],*NPCinfo->getPosActual());
        if(aux>distancia){
            x = i;
            aux = distancia;
        }
    }
    //cout << "POS BOTI   " << objetos[x]->x << endl;
    return objetos[x];
}
// NODO SUENA ALARMA ?
Nodo_SuenaAlarma::Nodo_SuenaAlarma(){}
short Nodo_SuenaAlarma::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO SUENA ALARMA?" << endl;
    if(WorldInfo->alarmaActivada) return true;
    return false;
}
// NODO ESTAS ASUSTADO ?
Nodo_EstasAsustado::Nodo_EstasAsustado(){}
short Nodo_EstasAsustado::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO ASUSTADO?" << endl;
    if (NPCinfo->getSed()>=UMBRAL_SED && NPCinfo->getLife()<UMBRAL_VIDA && NPCinfo->getHambre()>=UMBRAL_HAMBRE) {
        NPCinfo->setEstados(ASUSTADO);
        return true;
    }
    return false;
}
// NODO HAY PARA HABLAR ?
Nodo_HayParaHablar::Nodo_HayParaHablar(){}
short Nodo_HayParaHablar::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO ALGUIEN HABLAR?" << endl;
    return false;
}

// NODO HAY ALGUIEN CERCA ?
Nodo_HayAlguienCerca::Nodo_HayAlguienCerca(){}
float Nodo_HayAlguienCerca::CalcularDistancia(vector3D a, vector3D b){
    float x = fabs(pow(a.x-b.x,2));
    float y = fabs(pow(a.y-b.y,2));
    return sqrt(x+y);
}
short Nodo_HayAlguienCerca::run(datos * NPCinfo, BlackBoard * WorldInfo){
    for (int i = 0; i<WorldInfo->posicionesNPC.size(); i++) {
        if(2>-1 && CalcularDistancia(*WorldInfo->posicionesNPC[i], *NPCinfo->getPosActual())<=DISTANCIA_COMUNICACION_PERSONAL){
            NPCinfo->setPosicionFinal(WorldInfo->posicionesNPC[i]);
            return true;
        }
    }
    return false;
}
// NODO HAY ALGUIEN RADIO ?
Nodo_HayAlguienRadio::Nodo_HayAlguienRadio(){}
short Nodo_HayAlguienRadio::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO HAY NPCS POR RADIO?" << endl;
    if (WorldInfo->posicionesNPC.size()>0) return true;
    return false;
}
// NODO ESTAS CERCA JUGADOR ?
Nodo_EstasCercaJugador::Nodo_EstasCercaJugador(){}
short Nodo_EstasCercaJugador::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO ESTAS CERCA DEL PLAYER?" << endl;
    return false;
}
// NODO ESTAS LEJOS JUGADOR ?
Nodo_EstasLejosJugador::Nodo_EstasLejosJugador(){}
short Nodo_EstasLejosJugador::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO ESTAS LEJOS DEL PLAYER?" << endl;
    return false;
}
// NODO TIEMPO INACTIVO ?
Nodo_TiempoInactivo::Nodo_TiempoInactivo(){}
short Nodo_TiempoInactivo::run(datos * NPCinfo, BlackBoard * WorldInfo){
    //cout << " NODO TIEMPO INACTIVO?" << endl;
    return false;
}



