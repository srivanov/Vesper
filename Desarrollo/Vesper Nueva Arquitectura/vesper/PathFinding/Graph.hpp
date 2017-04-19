//
//  Graph.hpp
//  PathPlanning
//
//  Created by Gaspar Rodriguez Valero on 1/2/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <map>
#include "EasyMath.hpp"
#include "GraphNode.hpp"

class Graph{
    std::map<int,GraphNode*> Grafo;
    std::map<int,GraphNode*>::iterator it;
public:
    Graph();
    Graph(const Graph*);
    Graph(std::vector<GraphNode*>&);
    Graph(std::map<int,GraphNode*>&);
    ~Graph();
    bool add_node(int,GraphNode*);
    GraphNode * getInitialNode(dvector3D * initialPosition);
    GraphNode * getFinalNode(dvector3D * finalPosition);
    std::vector<conexos*> NextNodes();
    GraphNode * getNode(int ID);
};

#endif /* Graph_hpp */
