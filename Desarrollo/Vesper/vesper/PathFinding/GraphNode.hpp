//
//  GraphNode.hpp
//  PathPlanning
//
//  Created by Gaspar Rodriguez Valero on 1/2/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef GraphNode_hpp
#define GraphNode_hpp

#include "../Dvector.hpp"
#include <vector>
#include "../Tools/EasyMath.hpp"


struct conexos {
    conexos(int ID, float peso , dvector3D * posicion);
    ~conexos();
    int ID;
    float peso;
    float F;
    dvector3D * posicion;
};

class GraphNode{
    dvector3D * posicion;
    int ID;
    std::vector<conexos*> conecta_con;
public:
    int getID() const {return ID;}
    std::vector<conexos*> getConexos() const{return conecta_con;}
    dvector3D * getPosition() const {return posicion;}
    bool conectar(GraphNode*);
    GraphNode(int,dvector3D *);
    ~GraphNode();
};

#endif /* GraphNode_hpp */
