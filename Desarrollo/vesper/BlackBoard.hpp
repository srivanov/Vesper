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
    std::vector<vector3D> posicionesNPC;
    std::vector<vector3D> ObjetosCercanos;
    std::vector<vector3D> RuidosCercanos;
    vector3D JugadorPosicion;
    bool estadoFuente;
    bool comprobadaFuente = false;
    bool estadoAlarma;
    bool comprobadaAlarma = false;
    bool alarmaActivada = false;
    void clean();
private:
};

#endif /* BlackBoard_hpp */
