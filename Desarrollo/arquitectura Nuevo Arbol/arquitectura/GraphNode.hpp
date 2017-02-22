//
//  GraphNode.hpp
//  PathPlanning
//
//  Created by Gaspar Rodriguez Valero on 1/2/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef GraphNode_hpp
#define GraphNode_hpp

#include "Dvector.hpp"
#include <vector>
#include "EasyMath.hpp"


struct conexos {
    conexos(int ID, float peso , dvector2D posicion);
    ~conexos();
    int ID;
    float peso;
    float F;
    dvector2D posicion;
};

class GraphNode{
    dvector2D posicion;
    int ID;
    std::vector<conexos*> conecta_con;
public:
    int getID() const {return ID;}
    std::vector<conexos*> getConexos() const{return conecta_con;}
    dvector2D getPosition() const {return posicion;}
    bool conectar(GraphNode*);
    GraphNode(int,dvector2D&);
    ~GraphNode();
};

#endif /* GraphNode_hpp */
