//
//  IA.cpp
//  Sistema de Decision
//
//  Created by Gaspar Rodriguez Valero on 15/11/16.
//  Copyright © 2016 ScyScrappers. All rights reserved.
//

#include "IA.hpp"


void IA::lectura_stats(){
    TiXmlDocument doc("ia-stats.xml");
    bool lectura = doc.LoadFile();
    if(lectura){
        printf("Ha leido el documento! \n");
    }else{
        printf("No ha leido el documento \n");
    }
}
