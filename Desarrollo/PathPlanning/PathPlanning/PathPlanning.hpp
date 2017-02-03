//
//  PathPlanning.hpp
//  PathPlanning
//
//  Created by Gaspar Rodriguez Valero on 2/2/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef PathPlanning_hpp
#define PathPlanning_hpp

#include "Graph.hpp"
#include <iostream>
using namespace std;

class NodeOpenBag{
    std::vector<GraphNode*> camino;
public:
    std::vector<dvector3D> getCamino();
    void add_node(GraphNode*);
    GraphNode * lastNode();
    bool HasNode(int& ID);
    NodeOpenBag(GraphNode *);
    ~NodeOpenBag();
};


class PathPlanning{
    Graph * grafo;
    NodeOpenBag * BolsaNodos;
    bool Pathbuilding();
    GraphNode* final_camino;
    void Revalorar();
public:
    std::vector<dvector3D> obtenerCamino(dvector2D,dvector2D);
    PathPlanning(Graph* grafo);
    PathPlanning(Graph* grafo,dvector2D,dvector2D);
    PathPlanning(Graph* grafo,dvector3D,dvector3D);
    ~PathPlanning();
};


#endif /* PathPlanning_hpp */
