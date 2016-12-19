//
//  BlackBoard.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 1/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#ifndef BlackBoard_hpp
#define BlackBoard_hpp

#include "datos.hpp"
#include <vector>

class NPC;
class fuente;
class comida;
class alarma;
class botiquin;

enum ENUM_DTRECORD_TYPE{
    DT_Invalid = -1,
    DT_NPC,
    DT_BOTIQUIN,
    DT_COMIDA,
    DT_FUENTE,
    DT_ALARMA
};

struct DTRECORD {
    ENUM_DTRECORD_TYPE eType;
    int ID_Subject;
    ENUM_DTRECORD_TYPE TargetType; // optional
    int ID_Target; // optional
    vector3D * V3DData; // optional
};
typedef std::vector<DTRECORD*> DTRECORD_LIST;

class blackboard{
public:
    static blackboard * Instance();
    //queries
    vector3D * getDTRECORD_DATA(ENUM_DTRECORD_TYPE type);
    vector3D * getDTRECORD_DATA(ENUM_DTRECORD_TYPE type , int id_Target);
    void AddRecord(ENUM_DTRECORD_TYPE type, int id_object,vector3D * pos_object, ENUM_DTRECORD_TYPE type_target);
    void AddRecord(ENUM_DTRECORD_TYPE type, int id_object,vector3D * pos_object, ENUM_DTRECORD_TYPE type_target, int id_target);
    int countDTRECORD(ENUM_DTRECORD_TYPE type);
    int countDTRECORD(ENUM_DTRECORD_TYPE type,int id_Target);
    void update(DTRECORD * updated);
private:
    static blackboard * _instance;
    DTRECORD_LIST m_lstDTRECORD;
};
class arbitro{
    
};
class BlackBoard{
public:
    BlackBoard();
    ~BlackBoard();
    std::vector<vector3D*> posicionesNPC;
    std::vector<vector3D*> Botiquines;
    std::vector<vector3D*> Alarma;
    std::vector<vector3D*> Comida;
    std::vector<vector3D*> Fuente;
    std::vector<vector3D*> RuidosCercanos;
    
    vector3D * posicion;
    bool comprobadaFuente = false;
    bool estadofuente = false;
    bool estadoAlarma = false;
    bool comprobadaAlarma = false;
    bool alarmaActivada = false;
    void cleanBool();
    void vaciarVectores();
private:
};

#endif /* BlackBoard_hpp */
