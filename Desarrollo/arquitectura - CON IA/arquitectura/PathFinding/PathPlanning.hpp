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
    std::vector<GraphNode*> descartes;
public:
    float peso;
    std::vector<dvector3D> getCamino();
    void add_node(GraphNode*);
    void disable_node(int ID);
    std::vector<GraphNode*> getNodes() const{return camino;}
    void rebuild(NodeOpenBag*);
    void setDescartes(std::vector<GraphNode*> discards);
    std::vector<GraphNode*> getDescartes() const {return descartes;}
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
    bool Revalorar(NodeOpenBag *);
public:
    dvector2D aux;
    std::vector<dvector3D> obtenerCamino(dvector3D,dvector3D);
    std::vector<dvector3D> obtenerCamino(dvector2D,dvector2D);
    PathPlanning(Graph* grafo);
    PathPlanning(Graph* grafo,dvector2D,dvector2D);
    PathPlanning(Graph* grafo,dvector3D,dvector3D);
    ~PathPlanning();
};


#endif /* PathPlanning_hpp */
