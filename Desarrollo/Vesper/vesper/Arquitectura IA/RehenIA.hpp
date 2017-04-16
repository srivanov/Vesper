//
//  RehenIA.hpp
//  vesper
//
//  Created by Gaspar Rodriguez Valero on 14/4/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef RehenIA_hpp
#define RehenIA_hpp

#include "../Dvector.hpp"
#include "../Tools/EasyMath.hpp"
#include "../PathFinding/PathPlanning.hpp"
#include <vector>

enum R_states {
        HIBERNANDO = 0
    ,   SIGUIENDO
    ,   ASUSTADO
};

class RehenIA {
    bool change;
    std::vector<dvector3D> camino;
    dvector3D * player;
    dvector3D * posActual;
    dvector3D movimiento;
    dvector3D posInicial;
    R_states actual;
    void calcularSiguiente();
    void calcularCamino();
    void resetMov();
    void evaluar();
public:
    bool inicializado();
    RehenIA(dvector3D * pos);
    ~RehenIA();
    void changeState(R_states);
    void inicializar(dvector3D *);
    void update();
    dvector3D Vmover(){return movimiento;}
};

#endif /* RehenIA_hpp */
