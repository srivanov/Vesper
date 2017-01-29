//
//  Nodo.hpp
//  PruebaGrafo
//
//  Created by Julia Martínez Valera on 27/1/17.
//  Copyright © 2017 Julia Martínez Valera. All rights reserved.
//

#ifndef Nodo_hpp
#define Nodo_hpp
#include <vector>
#include "Arista.hpp"



class Nodo{
public:
    Nodo(vector2d _pos, int ID);
    ~Nodo();
    void conectar(Nodo * a);
    vector2d getPosition() {return posicion;}
    int getID() const {return ID;}
    void pasado() {pase=true;}
    void reset() {pase=false;}
    bool getPass(){return pase;}
    std::vector<Nodo*> conexiones() const {return conecta_con;}
private:
    void anyadirArista(vector2d posA, vector2d posB);
    int ID;
    std::vector<Nodo*> conecta_con;
    //std::map<int,Nodo*>::iterator it;
    std::vector<arista*> aristas;
    vector2d posicion;
    bool pase;
};
#endif /* Nodo_hpp */
