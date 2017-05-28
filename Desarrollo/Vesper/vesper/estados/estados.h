//
//  estados.h
//  vesper
//
//  Created by Stoycho Ivanov Atanasov on 15/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef estados_h
#define estados_h

#include "../JSONParser.hpp"
#include "../components/typeArma.hpp"

struct datosPlayer {
    datosPlayer() { vida=monedas=llaves=0; municion=carga=0; update=true;}
    int vida, monedas, llaves;
    unsigned int municion, carga;
    typeArma arma;
    bool update;
};

enum estados{
	MENU = 0,
	PLAYING,
	STOP
};

enum tipoMenu {
	tmMENUPRINCIPAL = 0,
	tmELEGIR_PERSONAJE,
	tmOPCIONES,
	tmCREDITOS,
	tmPAUSE,
    tmHUD
};

struct states{
public:
	static states* Instance() { static states pinstance; return &pinstance; }
	void update() { estado = nextState; }
	const estados* getState() { return &estado; }
    
    /*
     ###################################################################
                        <CAMBIAR NIVEL INICIAL>
     ###################################################################
     */
    
	void empezar(){ nivel=1; }
    
    /*
     ###################################################################
                        </CAMBIAR NIVEL INICIAL>
     ###################################################################
     */
    
    void guardarPartida() {
        std::map<char *, char *> valores;
        
        char buf_nivel[2];
        sprintf(buf_nivel,"%d", nivel);
        
        valores.insert(std::pair<char *, char *>((char*)"nivel", buf_nivel));
        
        JSONParser::guardar(filename, valores);
    }
    
    void cargarPartida() {
        std::map<std::string, std::string> valores = JSONParser::leer(filename);
        
        nivel = JSONParser::toInt(valores.at("nivel"));
    }
	
	estados nextState;
	tipoMenu menu;
	bool destruir;
	int character, nivel;
    datosPlayer datos;
	void* renderTarget, *renderer;
private:
	states() {
		estado = MENU;
		destruir = false;
        //nextState = MENU;
		nextState = PLAYING;
        character = -1;
		nivel = 1;
	}
	estados estado;
    
    const char *filename = "datos_partida.json";
};

#endif /* estados_h */
