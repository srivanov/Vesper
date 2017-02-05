//
//  main.cpp
//  PathPlanning
//
//  Created by Gaspar Rodriguez Valero on 1/2/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include <iostream>
#include "PathPlanning.hpp"
#include "Graph.hpp"
#include "GraphNode.hpp"
using namespace std;

int main() {
    int ID = 0;
    vector<GraphNode*> nodos;
    
    dvector2D posIni(0,0);
    dvector2D posFin(9,0);
    
    dvector2D posA(0,0);
    GraphNode * A = new GraphNode(ID,posA);
    ID++;
    dvector2D posB(0,3);
    GraphNode * B = new GraphNode(ID,posB);
    ID++;
    dvector2D posC(0,6);
    GraphNode * C = new GraphNode(ID,posC);
    ID++;
    dvector2D posD(0,9);
    GraphNode * D = new GraphNode(ID,posD);
    ID++;
    dvector2D posE(3,0);
    GraphNode * E = new GraphNode(ID,posE);
    ID++;
    dvector2D posF(3,3);
    GraphNode * F = new GraphNode(ID,posF);
    ID++;
    dvector2D posG(3,6);
    GraphNode * G = new GraphNode(ID,posG);
    ID++;
    dvector2D posH(3,9);
    GraphNode * H = new GraphNode(ID,posH);
    ID++;
    dvector2D posI(6,0);
    GraphNode * I = new GraphNode(ID,posI);
    ID++;
    dvector2D posJ(6,3);
    GraphNode * J = new GraphNode(ID,posJ);
    ID++;
    dvector2D posK(6,6);
    GraphNode * K = new GraphNode(ID,posK);
    ID++;
    dvector2D posL(6,9);
    GraphNode * L = new GraphNode(ID,posL);
    ID++;
    dvector2D posM(9,0);
    GraphNode * M = new GraphNode(ID,posM);
    ID++;
    dvector2D posN(9,3);
    GraphNode * N= new GraphNode(ID,posN);
    ID++;
    dvector2D posNY(9,6);
    GraphNode * NY = new GraphNode(ID,posNY);
    ID++;
    dvector2D posO(9,9);
    GraphNode * O = new GraphNode(ID,posO);
    //GRAFO 1
    /*
    A->conectar(B);
    A->conectar(D);
    A->conectar(F);
    
    B->conectar(C);
    B->conectar(E);
    
    C->conectar(H);
    C->conectar(E);
    
    D->conectar(F);
    D->conectar(G);
    
    E->conectar(G);
    E->conectar(H);
    
    F->conectar(I);
    F->conectar(K);
    
    G->conectar(I);
    G->conectar(J);
    
    H->conectar(J);
    H->conectar(M);
    
    I->conectar(K);
    I->conectar(L);
    
    J->conectar(L);
    J->conectar(M);
    
    K->conectar(L);
    
    L->conectar(M);
    */
    //GRAFO 2
    
    A->conectar(B);
    A->conectar(E);
    A->conectar(F);
    
    B->conectar(F);
    B->conectar(C);
    
    C->conectar(G);
    C->conectar(D);
    
    D->conectar(G);
    D->conectar(H);
    
    E->conectar(F);
    E->conectar(I);
    E->conectar(J);
    
    F->conectar(J);
    F->conectar(G);
    F->conectar(K);
    
    G->conectar(H);
    G->conectar(K);
    
    H->conectar(L);
    H->conectar(K);
    
    //I->conectar(M);
    I->conectar(J);
    
    //J->conectar(N);
    J->conectar(K);
    //J->conectar(M);
    //J->conectar(NY);
    
    K->conectar(NY);
    K->conectar(L);
    
    L->conectar(O);
    
    M->conectar(N);
    N->conectar(NY);
    NY->conectar(O);
    
    nodos.push_back(A);
    nodos.push_back(B);
    nodos.push_back(C);
    nodos.push_back(D);
    nodos.push_back(E);
    nodos.push_back(F);
    nodos.push_back(G);
    nodos.push_back(H);
    nodos.push_back(I);
    nodos.push_back(J);
    nodos.push_back(K);
    nodos.push_back(L);
    nodos.push_back(M);
    nodos.push_back(N);
    nodos.push_back(NY);
    nodos.push_back(O);

    // FIN CONSTRUCCION GRAFO
    
    Graph * grafo = new Graph(nodos);
    
    PathPlanning prueba(grafo,posIni,posFin);
    
    return 0;
}
