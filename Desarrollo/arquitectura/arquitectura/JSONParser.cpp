//
//  JSONParser.cpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 19/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "JSONParser.hpp"

void JSONParser::guardar(std::map<char*, char*> valores) {
    json j;
    
    //    j["sonido"] = check_sonido->isSelected() ? "true":"false";
    //
    //    char buf[3];
    //    sprintf(buf,"%d", (int)slider_volumen->getCurrentValue());
    //    j["volumen"] = buf;
    //    j["resolucion"] = "1280x720";
    for (std::map<char*, char*>::iterator i = valores.begin(); i != valores.end(); ++i) {
        j[i->first] = i->second;
    }
    std::ofstream o("controles.json");
    o << j << std::endl;
}

std::map<std::string, std::string> JSONParser::leer() {
    std::ifstream i("controles.json");
    json j;
    i >> j;
    
    std::map<std::string, std::string> valores;
    
    for (json::iterator k = j.begin(); k != j.end(); ++k) {
//        char* prueba = (k.value())->;
//        valores.insert(std::pair<char*, char*>(*k.key().c_str(), *k.value()));
//         std::cout << k.key() << " : " << k.value() << "\n";
    }
    
    return valores;
}
