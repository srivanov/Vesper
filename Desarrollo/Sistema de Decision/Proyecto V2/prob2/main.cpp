#include <irrlicht.h>
#include <Box2D/Box2D.h>
#include <stdio.h>
#include <iostream>
#include "tinyxml.h"

using namespace irr;
using namespace core;
using namespace video;
using namespace std;

#if defined(_MSC_VER)
#pragma comment(lib, "Irrlicht.lib")
#endif


int main(){
    TiXmlDocument doc("/Resources/ia-stats.xml");
    bool lectura = doc.LoadFile();
    if(lectura){
        printf("Ha leido el documento! \n");
    }else{
        printf("No ha leido el documento \n");
    }
    
}
