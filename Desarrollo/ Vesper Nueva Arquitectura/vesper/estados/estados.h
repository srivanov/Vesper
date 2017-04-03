//
//  estados.h
//  vesper
//
//  Created by Stoycho Ivanov Atanasov on 15/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef estados_h
#define estados_h

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
	tmPAUSE
};

struct states{
public:
	static states* Instance() { static states pinstance; return &pinstance; }
	void update() { estado = nextState; }
	const estados* getState() { return &estado; }
	estados nextState;
	tipoMenu menu;
	bool destruir;
	void* renderTarget, *renderer;
private:
	states() { estado = MENU; destruir = false; }
	estados estado;
};

#endif /* estados_h */
