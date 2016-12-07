//
//  BlackBoard.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 1/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#ifndef BlackBoard_hpp
#define BlackBoard_hpp
typedef struct{
    float x;
    float y;
    float z;
}vector3d;
/*
class BlackBoard {
private:
    //VARIABLES DE MUNDO
    bool puerta;
    int tipo_puerta;
    int curacion,* hidratacion,* alimentacion;
    bool Alarma_Activa;
    bool Ruido;
    vector3d pos_botiquin;
    bool estado_fuente;
    int SPRITES_HABLAR; // POR DEFINIR
    vector3d pos_alarma;
    vector3d pos_jugador;
    vector3d pos_NPCcercanos[3];
    vector3d pos_cobertura;
    vector3d pos_Amoverse;
    
    //VARIABLES DEL NPC
    int vida, sed, hambre;
    vector3d  pos_propia;
    bool  llave;
    int  tipo_llave;
    int SENSOR_VISTA;
    float tiempo_estado;
    bool patrulla;
    int estado;
    
public:
    BlackBoard();
    ~BlackBoard();
    void Calcula();
};*/
class NPCBlackBoard{
public:
private:
};
class WorldBlackBoard{
public:
private:
};
class PlayerBlackBoard{
public:
private:
};
class OwnBlackBoard{
public:
private:
    
};
#endif /* BlackBoard_hpp */
