//
//  JSONParser.cpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 19/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#include "JSONParser.hpp"

void JSONParser::guardar(const char* filename, std::map<char*, char*> valores) {
    json j;
	
    for (std::map<char*, char*>::iterator i = valores.begin(); i != valores.end(); ++i) {
        j[i->first] = i->second;
    }
    std::ofstream o(filename);
    o << j << std::endl;
}

std::map<std::string, std::string> JSONParser::leer(const char* filename) {
    std::ifstream i(filename);
    json j;
	std::map<std::string, std::string> valores;
	if(i.is_open()){
		i >> j;
		
		for (json::iterator k = j.begin(); k != j.end(); ++k) {
			valores.insert(std::pair<std::string, std::string>(k.key(), k.value().get<std::string>()));
		}
	}
    return valores;
}

bool JSONParser::toBool(std::string s) {
	return s.compare("true") == 0;
}

int JSONParser::toInt(std::string s) {
	int r = 0;
	try{
		r = std::stoi(s);
	}
	//recogemos las excepciones que lanca el 'stoi'
	//si lo que pasamos no es una cadena de numeros
	catch(const std::invalid_argument& ia){
		printf("Conversion inválida: ");
	}
	//si el numero es demasiado grande
	catch(const std::out_of_range& oor){
		printf("Conversion inválida: ");
	}
	return r;
}

