//
//  objects.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 8/12/16.
//  Copyright © 2016 Skyscrapers. All rights reserved.
//

#ifndef objects_hpp
#define objects_hpp

#define BOTIQUIN 1
#define FUENTE 2
#define COMIDA 3
#include "datos.hpp"

class objetos {
public:
    vector3D getPosition(){return posicion;}
    int TipoObjeto(){return tipo;}
private:
    int tipo;
    vector3D posicion;
};
class botiquin : public objetos{
public:
    botiquin();
    ~botiquin();
    bool getGastado(){return gastado;}
    void usar();
    int getUsos(){return num_usos;}
private:
    int  num_usos = 3;
    int tipo = BOTIQUIN;
    bool gastado = false;
};
class fuente : public objetos{
public:
    fuente();
    ~fuente();
    void inicializar(bool indestructible){infinita=indestructible;}
    bool getInifinita(){return infinita;}
    bool getEstado(){return destruida;}
    void destruir(){destruida=true;}
private:
    int tipo = FUENTE;
    bool infinita;
    bool destruida;
    
};
class comida : public objetos{
public:
    comida();
    ~comida();
    void comer(){comestible=false;}
    bool getComestible(){return comestible;}
    void Aparecer(){comestible=true;}
private:
    bool comestible = true;
    int tipo = COMIDA;
    // FALTA EL TIEMPO
};

#endif /* objects_hpp */
