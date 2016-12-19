//
//  world.cpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 8/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#include "world.hpp"
world::world(){
    infoWorld = new BlackBoard;
}

void world::anyadirBotiquin(botiquin *hijo){botiquin_mundo.push_back(hijo);}
void world::anyadirFuente(fuente *hijo){fuente_mundo.push_back(hijo);}
void world::anyadirComida(comida *hijo){comida_mundo.push_back(hijo);}
void world::anyadirAlarma(alarma *hijo){alarma_mundo.push_back(hijo);}
void world::anyadirNPC(NPC *hijo){enemigos.push_back(hijo);}
void world::update(){
    
    infoWorld->vaciarVectores();
    ConstruirBlackBoard();
    for (int i=0; i<enemigos.size(); i++) {
        
        infoWorld->cleanBool();
        
        // UPDATE DEL NPC
        enemigos[i]->update(infoWorld);
        // SE ACTUALIZAN LOS OBJECTOS DESTRUCTIBLES
        //ComprobacionFuentesAlarmas();
        //AVISO DE UN NPC A SUS COMPAÑEROS
        //NPCsAvisados(enemigos[i]);
    }
}


/*void world::ComprobacionFuentesAlarmas(){
    if(infoWorld->comprobadaAlarma && !infoWorld->estadoAlarma){
        for (int y=0; y<alarma_mundo.size(); y++) {
            if(alarma_mundo[y]->getPosition()==infoWorld->ObjetosCercanos[ALARMA-1])
                alarma_mundo[y]->Comprobacion();
        }
    }
    if(infoWorld->comprobadaFuente && !infoWorld->estadoFuente){
        for (int y=0; y<fuente_mundo.size(); y++) {
            if(fuente_mundo[y]->getPosition()==infoWorld->ObjetosCercanos[FUENTE-1])
                fuente_mundo[y]->Comprobacion();
        }
    }
}*/
float world::CalcularDistancia(vector3D a, vector3D b){
    float x = fabs(pow(a.x-b.x,2));
    float y = fabs(pow(a.y-b.y,2));
    return sqrt(x+y);
}
void world::ConstruirBlackBoard(){
    for (int i=0; i<enemigos.size(); i++) {
        infoWorld->posicionesNPC.push_back(enemigos[i]->getPosition());
    }
    for (int i=0; i<botiquin_mundo.size(); i++) {
        if(!botiquin_mundo[i]->getGastado())
            infoWorld->Botiquines.push_back(botiquin_mundo[i]->getPosition());
    }
    for (int i=0; i<fuente_mundo.size(); i++) {
        if(!fuente_mundo[i]->getNPCrota())
            infoWorld->Fuente.push_back(fuente_mundo[i]->getPosition());
    }
    for (int i=0; i<comida_mundo.size(); i++) {
        if (comida_mundo[i]->getComestible())
            infoWorld->Comida.push_back(comida_mundo[i]->getPosition());
    }
    for (int i=0; i<alarma_mundo.size(); i++) {
        if(!alarma_mundo[i]->getNPCrota())
            infoWorld->Alarma.push_back(alarma_mundo[i]->getPosition());
    }
}
/*
void world::NPCsCercanos(vector3D NPCactual){
    vector<int> respuesta;
    float aux=-1;int auxID = -1;
    bool completo = false;
    float distancias[3]={-1,-1,-1};
    for (int i=0; i<enemigos.size(); i++) {
        if (NPCactual == *enemigos[i]->getPosition()) {
            cout << "ERES TU IDIOTA!"<< endl;
        }else{
            
            float distancia = CalcularDistancia(*enemigos[i]->getPosition(), NPCactual);
            bool guardado = false;
            
            //###################################################
            // CONTROLAR EN EL FUTURO CON RADIO MAXIMO DE ACCION
            //###################################################
            
            if(!completo){
                for (int x = 0; x<3;x++) {
                    if (distancias[x]==-1 && !guardado) {
                        respuesta.push_back(i);
                        distancias[x]=distancia;
                        guardado=true;
                    }
                }
                if(distancias[2]!=-1) {
                    completo=true;
                    for (int x = 0; x<3;x++) {
                        if (x+1<3 && distancias[x]>distancias[x+1]) {
                            auxID = respuesta[x];
                            aux = distancias[x];
                            distancias[x]=distancias[x+1];
                            respuesta[x]=respuesta[x+1];
                            respuesta[x+1]=auxID;
                            distancias[x+1]=aux;
                        }
                    }
                }
            }
            else{
                for (int x = 0; x<3;x++) {
                    if (distancias[x]>distancia) {
                        if(!guardado){
                            aux = distancias[x];
                            auxID = respuesta[x];
                            distancias[x]=distancia;
                            respuesta[x]=i;
                        }else if (aux<distancias[x]) {
                            int aux3 = respuesta[x];
                            float aux2 = distancias[x];
                            distancias[x]=aux;
                            respuesta[x]= auxID;
                            aux = aux2;
                            auxID = aux3;
                        }
                       
                    }
                }
            }
            
        }
    }
    for (int l=0; l<respuesta.size(); l++) {
        infoWorld->posicionesNPC.push_back(enemigos[respuesta[l]]->getPosition());
    }
    
}

#define BOTIQUIN 1
#define FUENTE 2
#define COMIDA 3
#define ALARMA 4
 */
/*void world::ObjetosCercanos(vector3D NPCactual){
    infoWorld->ObjetosCercanos.assign(4,{1000,1000,1000});
    for (int i=0; i<botiquin_mundo.size(); i++) {
        bool descartar = false;
        float distancia = CalcularDistancia(botiquin_mundo[i]->getPosition(), NPCactual);
        float aux = CalcularDistancia(infoWorld->ObjetosCercanos[botiquin_mundo[i]->TipoObjeto()-1], NPCactual);
        if(botiquin_mundo[i]->getGastado()) descartar=true;
        if(aux>distancia && !descartar){
            infoWorld->ObjetosCercanos[botiquin_mundo[i]->TipoObjeto()-1]=botiquin_mundo[i]->getPosition();
        }
    }
    for (int i=0; i<fuente_mundo.size(); i++) {
        bool descartar = false;
        float distancia = CalcularDistancia(fuente_mundo[i]->getPosition(), NPCactual);
        float aux = CalcularDistancia(infoWorld->ObjetosCercanos[fuente_mundo[i]->TipoObjeto()-1], NPCactual);
        if(fuente_mundo[i]->getNPCrota()) descartar=true;
        if(aux>distancia && !descartar){
            infoWorld->ObjetosCercanos[fuente_mundo[i]->TipoObjeto()-1]=fuente_mundo[i]->getPosition();
            infoWorld->estadoFuente = fuente_mundo[i]->getEstado();
        }
    }
    for (int i=0; i<comida_mundo.size(); i++) {
        bool descartar = false;
        float distancia = CalcularDistancia(comida_mundo[i]->getPosition(), NPCactual);
        float aux = CalcularDistancia(infoWorld->ObjetosCercanos[comida_mundo[i]->TipoObjeto()-1], NPCactual);
        if(!comida_mundo[i]->getComestible()) descartar=true;
        if(aux>distancia && !descartar){
            infoWorld->ObjetosCercanos[comida_mundo[i]->TipoObjeto()-1]=comida_mundo[i]->getPosition();
        }
    }
    for (int i=0; i<alarma_mundo.size(); i++) {
        bool descartar = false;
        float distancia = CalcularDistancia(alarma_mundo[i]->getPosition(), NPCactual);
        float aux = CalcularDistancia(infoWorld->ObjetosCercanos[alarma_mundo[i]->TipoObjeto()-1], NPCactual);
        if(alarma_mundo[i]->getNPCrota()) descartar=true;
        if(aux>distancia && !descartar){
            infoWorld->ObjetosCercanos[alarma_mundo[i]->TipoObjeto()-1]=alarma_mundo[i]->getPosition();
            infoWorld->estadoAlarma = alarma_mundo[i]->getRota();
        }
    }
}
*/
