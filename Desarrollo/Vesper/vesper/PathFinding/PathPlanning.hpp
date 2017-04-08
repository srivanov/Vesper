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


enum N_Errores{
    no_way = 0,
    fail
};


class NodeOpenBag{
    std::vector<GraphNode*> camino;
    std::vector<GraphNode*> descartes;
    void setDescartes(std::vector<GraphNode*> discards);
public:
    float peso;
    std::vector<dvector3D> getCamino();
    void add_node(GraphNode*);
    void disable_node(int ID);
    std::vector<GraphNode*> getNodes(){return camino;}
    GraphNode * lastNode();
    bool HasNode(int& ID);
    void clean();
    NodeOpenBag();
    ~NodeOpenBag();
};




class PathPlanning{
    Graph * m_grafo;
    NodeOpenBag * BolsaNodos;
    bool Pathbuilding();
    GraphNode* final_camino;
    bool Revalorar(NodeOpenBag *);
    void inicializarBolsaNodos();
    void vaciarBolsa();
    void construirbolsa();
    bool CalcularSiguienteNodo(NodeOpenBag* bolsa);
    bool EvaluarCamino();
    bool NeedCalculo(dvector3D *initialPosition,dvector3D * finalPosition);
public:
    void init(Graph *);
    static PathPlanning * instance();
    dvector3D * aux;
    std::vector<dvector3D> obtenerCamino(dvector3D *,dvector3D *);
    PathPlanning();
    ~PathPlanning();
};


#endif /* PathPlanning_hpp */
