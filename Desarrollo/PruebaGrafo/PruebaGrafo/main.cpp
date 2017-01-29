//
//  main.cpp
//  PruebaGrafo
//
//  Created by Julia Martínez Valera on 27/1/17.
//  Copyright © 2017 Julia Martínez Valera. All rights reserved.
//

#include <unistd.h>
#include "Nodo.hpp"
#include "Grafo.hpp"


using namespace std;



void ClearScreen()
{
    for (int i=0; i<2; i++) {
        cout << endl;
    }
}


void Nodo_values(char& c, vector2d& posiciones){
    switch (c) {
        case '0':
            posiciones.x=0;
            posiciones.y=0;
            break;
        case '1':
            posiciones.x=3;
            posiciones.y=1;
            break;
        case '2':
            posiciones.x=4;
            posiciones.y=3;
            break;
        case '3':
            posiciones.x=1;
            posiciones.y=3;
            break;
        case '4':
            posiciones.x=6;
            posiciones.y=2;
            break;
        case '5':
            posiciones.x=2;
            posiciones.y=6;
            break;
        case '6':
            posiciones.x=3;
            posiciones.y=9;
            break;
        case '7':
            posiciones.x=5;
            posiciones.y=4;
            break;
        case '8':
            posiciones.x=5;
            posiciones.y=10;
            break;
        default:break;
    }
}

int main() {
    
    std::vector<Nodo*> nodos;
    int ids = 0;
    vector2d posiciones, posFinal;
    
    
    posiciones.x = 0; posiciones.y = 0;
    Nodo * A = new Nodo(posiciones,ids);
    ids++;
    posiciones.x = 3; posiciones.y = 1;
    Nodo * B = new Nodo(posiciones,ids);
    ids++;
    posiciones.x = 4; posiciones.y = 3;
    Nodo * C = new Nodo(posiciones,ids);
    ids++;
    posiciones.x = 1 ; posiciones.y = 3;
    Nodo * D = new Nodo(posiciones,ids);
    ids++;
    posiciones.x = 6 ; posiciones.y = 2;
    Nodo * E = new Nodo(posiciones,ids);
    ids++;
    posiciones.x = 2 ; posiciones.y = 6;
    Nodo * F = new Nodo(posiciones,ids);
    ids++;
    posiciones.x = 3 ; posiciones.y = 9;
    Nodo * G = new Nodo(posiciones,ids);
    ids++;
    posiciones.x = 5 ; posiciones.y = 4;
    Nodo * H = new Nodo(posiciones,ids);
    ids++;
    posiciones.x = 5 ; posiciones.y = 10;
    Nodo * I = new Nodo(posiciones,ids);
    
    
    A->conectar(B);
    A->conectar(D);
    B->conectar(C);
    C->conectar(E);
    C->conectar(H);
    D->conectar(F);
    E->conectar(H);
    F->conectar(G);
    F->conectar(H);
    G->conectar(I);
    I->conectar(H);
    I->conectar(G);
    
    
    
    nodos.push_back(A);
    nodos.push_back(B);
    nodos.push_back(C);
    nodos.push_back(D);
    nodos.push_back(E);
    nodos.push_back(F);
    nodos.push_back(G);
    nodos.push_back(H);
    nodos.push_back(I);
    
    
    A = nullptr; delete A;
    B = nullptr; delete B;
    C = nullptr; delete C;
    D = nullptr; delete D;
    E = nullptr; delete E;
    F = nullptr; delete F;
    G = nullptr; delete G;
    H = nullptr; delete H;
    I = nullptr; delete I;
    
    grafo * prueba = new grafo(nodos);
    
    // FIN DE LA CONSTRUCCION DEL GRAFO
    
    
    
     bool fin = true;
    string mensajes = "PATHPLANNING PRIMERA ITERACION \nPRUEBA DE ITERACION - BUSQUEDA DE CAMINOS\nGRAFO DE PRUEBA\n";
    string salida = "Para terminar la ejecucción -> X";
    string peticion = "Introduce el NUMERO del Nodo Inicial :  ";
    string peticion2 = "Introduce el NUMERO del Nodo Final :  ";
    
    char value;

    char GRAFO [10][22] = {
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ','4','-','-', 92,' ',' ',' ',' ',' ',' ','0','(','0',',','0',')'},
        {' ',' ',' ',' ',' ','|',' ',' ','|',' ',' ',' ',' ',' ',' ','1','(','3',',','1',')'},
        {' ',' ',' ',' ',' ','|',' ','-','7','-','-','-','-','8',' ','2','(','4',',','3',')'},
        {' ','1','-','-','-','2','/',' ','|',' ',' ',' ',' ','|',' ','3','(','1',',','3',')'},
        {' ','|',' ',' ',' ',' ',' ',' ',92 ,' ',' ',' ',' ','|',' ','4','(','6',',','2',')'},
        {' ','|',' ',' ',' ',' ',' ',' ',' ',92 ,' ',' ',' ','|',' ','5','(','2',',','6',')'},
        {' ','|',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ','|',' ','6','(','3',',','9',')'},
        {' ','0','-','-','-','3','-','-','-','5','-','-','-','6',' ','7','(','5',',','4',')'},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','8','(','5',',','1','0',')'}
    };
    
    while (fin) {
        cout << mensajes ;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 22; j++) {
                cout << GRAFO[i][j];
            }
            cout << endl;
        }
        cout << salida << endl;
        cout << endl << peticion; cin >> value;
        if(value=='x' || value == 'X') {fin=false;continue;}
        Nodo_values(value,posiciones);
        cout << endl << peticion2; cin >> value;
        if(value=='x' || value == 'X') {fin=false;continue;}
        Nodo_values(value,posFinal); cout << "RESULTADOS: " << endl;
        prueba->calcularCamino(posiciones, posFinal);
        prueba->reset();
        usleep(4000000);
        ClearScreen();
        //fin = false;
    }
    
    //posiciones.x= 5; posiciones.y = 12;
    //posFinal.x =3; posFinal.y = 1;
    
   // prueba->calcularCamino(posiciones, posFinal);
    
    delete prueba;
    
    
    return 0;
}
