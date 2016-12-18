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
