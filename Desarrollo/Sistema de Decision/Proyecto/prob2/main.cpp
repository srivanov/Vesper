#include <irrlicht.h>
#include <Box2D/Box2D.h>
#include <stdio.h>
#include "Vstate.hpp"
#include "DecisionSystem.hpp"
//PRUEBAS

#include <time.h>
#include <iostream>
#include <cstdio>
#include <stdint.h>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace irr;
using namespace core;
using namespace video;
using namespace std;

#if defined(_MSC_VER)
#pragma comment(lib, "Irrlicht.lib")
#endif

char mapa[10][10]={
//Y   0   1   2   3   4   5   6   7   8   9     X
    {'#','#','#','#','#','#','#','#','#','#'},//0
    {'#',' ',' ','F',' ',' ',' ',' ',' ','#'},//1
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},//2
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},//3
    {'#',' ','W',' ',' ',' ',' ',' ',' ','#'},//4
    {'#',' ',' ',' ',' ',' ',' ','B',' ','#'},//5
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},//6
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},//7
    {'#','C',' ',' ',' ',' ',' ',' ',' ','#'},//8
    {'#','#','#','#','#','#','#','#','#','#'}//9
};
int posX = 8,posY = 1;
int IniX = 8 , IniY = 1;
int FoodX = 1, FoodY=3;
int WaterX = 4, WaterY = 2;
int BotiqX = 5, BotiqY = 7;
int pathfinding(int need);

int main(){
    DecisionSystem * decisiones = new DecisionSystem();
    
    bool running = true;
    while(running){
        int y=0;
        cout << endl;
        for (int i=0; i<10; i++) {
            cout << i;
        }
        cout << endl;
        for (int i=0; i<10; i++) {
            cout << "-";
        }
        cout << endl;
        for (int x=0; x<10;x++) {
            for (int y=0; y<10; y++) {
                if(posX==x && posY==y) cout << '@';
                else cout << mapa[x][y];
            }
            cout<<'|'<< x ;
            switch (x) {
                case 0:cout << "  | PARAMETROS   IA |" <<endl;break;
                case 1:cout << "  |-----------------|" <<endl;break;
                case 2: cout << "  | nIA |VID|HAM|SED|" << endl;break;
                case 3: cout << "  |  1  |";
                    printf("%.3d", decisiones->getLife());
                    cout <<"|";
                    printf("%.3d", decisiones->getHungry());
                    cout <<"|";
                    printf("%.3d", decisiones->getThirst());
                    cout <<"|"<< endl;
                    break;
                case 4:cout << "  |-----------------|" <<endl;break;
                case 6:
                    if(decisiones->getLife()<=0){cout << endl;running=false;}
                    else{cout << "  |CALCULO : " << decisiones->getCalculo() << endl;}
                    break;
                case 5:cout << "  |";decisiones->updateDecision();break;
                default:cout << endl;break;
            }
            
        }
        int prioridad =5;
        if (decisiones->getLife()<50) {
            prioridad = 0 ;
            cout << "Me curare" <<endl;
        }// IR A BOTIQUÍN | PATHFINDING BOTIQUIN
        else if(decisiones->getThirst()>60){
            prioridad = 1 ;
            cout << "Voy a beber" <<endl;
        }// BEBER | PATHFINDING SED
        else if(decisiones->getHungry()>70){
            prioridad = 2 ;
            cout << "Voy a Comer" <<endl;
        }// COMER | PATHFINDING COMER
        else{
            prioridad = 3 ;
        }
        if (pathfinding(prioridad)==1) {
                decisiones->necesidad(prioridad);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        
    }
    return 0;
}

int pathfinding(int need){
    int FinX, FinY,x,y;
    switch (need) {
        case 0: FinX = (uint)BotiqX-posX;FinY = (uint)BotiqY-posY;
            x = BotiqX;y = BotiqY;
            break;
        case 2: FinX = (uint)FoodX-posX;FinY = (uint)FoodY-posY;
            x = FoodX;y = FoodY;
            break;
        case 1: FinX = (uint)WaterX-posX;FinY = (uint)WaterY-posY;
            x = WaterX;y = WaterY;
            break;
        case 3:FinX = (uint)IniX-posX;FinY = (uint)IniY-posY;
            x = IniX;y = IniY;
            break;
    }
    if(FinX==0 && FinY==0){
        return 1;
    }
    else if (FinX!=0) {
        if (x<posX) {posX--;}
        else if (x>posX) {posX++;}
    }
    else if(FinY!=0){
        if (y<posY) {posY--;}
        else if(y>posY){posY++;}
    }
    return 0;
    cout << FinX << "|" << FinY << endl;
}
