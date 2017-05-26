
#include "TEscena.hpp"
#include "InputManager.h"
#include "SkyWindow.hpp"

TEscena::TEscena(){

	motor = SkyEngine::Instance();
	motor->init();
	cam = motor->crearCamara(NULL);
	motor->setActiveCam(0);
	cubo = motor->crearMalla(NULL, tMallaDinamica);
	luz = motor->crearLuz(cam);
	plano = motor->crearMalla(NULL, tMallaEstatica);
	dvector3D n(0,1,0), s(0.1, 0.1, 0.1);
	cam->setPosicion(n);
	cam->setFarValue(100);
//	cam->rotar(dvector3D(-40,0,0));
	cubo->setMalla("../Models/atacarZarpazo.obj");
	
	plano->setMalla("../Models/plano2.obj");
//	cubo->escalar(s);
	
//	cubo->setTextura("../Models/tex.png");
//	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
//	mallas.back()->setMalla("../Models/wall.obj");
//	n = dvector3D(2,1,2);
//	mallas.back()->setPosicion(n);
//	n = dvector3D(0.1,0.1,0.1);
//	mallas.back()->escalar(n);

//	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
//	mallas.back()->setMalla("../Models/microwave.obj");
////	mallas.back()->setTextura("../Models/zil.png");
//	n = dvector3D(-8,0,1);
//	mallas.back()->setPosicion(n);
	
	animacion = motor->crearMallaAnimada(NULL);
	animacion->AnyadirAnimacion("../Models/Reposo/", "p1_reposo.obj", 1.0f);
	animacion->setTextura("../Models/Player1_Diffuse.png");
//	animacion->AnyadirAnimacion("../Models/cil/", "cil.obj", 1.0f);
	n = dvector3D(6,-0.04,5);
	animacion->setPosicion(n);

    animacion = motor->crearMallaAnimada(NULL);
    animacion->AnyadirAnimacion("../Models/p2_andarArma/", "p2_andar.obj", 0.5f);
    animacion->setTextura("../Models/Player2_Diffuse.png");
    //	animacion->AnyadirAnimacion("../Models/cil/", "cil.obj", 1.0f);
    n = dvector3D(3,-0.04,5);
    animacion->setPosicion(n);
    
    animacion = motor->crearMallaAnimada(NULL);
    animacion->AnyadirAnimacion("../Models/m1_zarpazo/", "m1_zarpazo.obj", 1.f);
    animacion->setTextura("../Models/Monstruo1_Diffuse.png");
    //	animacion->AnyadirAnimacion("../Models/cil/", "cil.obj", 1.0f);
    n = dvector3D(0,-0.04,5);
    animacion->setPosicion(n);
    n = animacion->getPosicion();
    cam->setCamTarget(n);
//	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
//	mallas.back()->setMalla("../Models/microwave.obj");
//	
//	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
//	mallas.back()->setMalla("../Models/microwave.obj");
	
	n = dvector3D(0,0,-2);
	cubo->transladar(n);
	n = dvector3D(2.1,2.1,2.1);
	cubo->escalar(n);
	n = dvector3D(0.0,0.0,0.1);
	plano->transladar(n);
	n = dvector3D(-2,10,-10);
//	n = dvector3D(2,0,8);
	luz->setPosicion(n);
	luz->setLightDirection(dvector3D(10,-20,2));
	n = cubo->getPosicion();
//	cam->setCamTarget(n);
	
//	delete cubo2;
}

TEscena::~TEscena(){
	delete cubo;
	delete plano;
	delete luz;
	delete cam;
}

void TEscena::Draw(){
	motor->Draw();
}

void TEscena::update(){
	dvector3D mov;
	
	if(InputManager::Instance()->isPressed(SKY_KEY_UP)){
		//cubo->rotar(dvector3D(0,-.1,0));
        float amb = luz->getAmbient();
        amb+=0.01;
        luz->setAmbient(amb);
        
	}
	if(InputManager::Instance()->isPressed(SKY_KEY_DOWN)){
        float amb = luz->getAmbient();
        amb-=0.01;
        luz->setAmbient(amb);
	}
	if(InputManager::Instance()->isPressed(SKY_KEY_LEFT)){
		//cubo->transladar(dvector3D(-.1,0,0));
        float dif = luz->getDiffuse();
        dif-=0.1;
        luz->setDiffuse(dif);
	}
	if(InputManager::Instance()->isPressed(SKY_KEY_RIGHT)){
		//cubo->transladar(dvector3D(.1,0,0));
        float dif = luz->getDiffuse();
        dif+=0.1;
        luz->setDiffuse(dif);
	}
    if(InputManager::Instance()->isPressed(SKY_KEY_M)){
        float spec = luz->getSpecular();
        spec+=0.1;
        luz->setSpecular(spec);
    }
    if(InputManager::Instance()->isPressed(SKY_KEY_N)){
        float spec = luz->getSpecular();
        spec-=0.1;
        luz->setSpecular(spec);
//		motor->debugON(true);
    }
	dvector3D m(0,0,.1);
	if(InputManager::Instance()->isPressed(SKY_KEY_W)){
		cam->transladar(m);
		luz->transladar(m);
	}
	m = dvector3D(0,0,-.1);
	if(InputManager::Instance()->isPressed(SKY_KEY_S)){
		cam->transladar(m);
		luz->transladar(m);
	}
	m = dvector3D(.1,0,0);
	if(InputManager::Instance()->isPressed(SKY_KEY_A)){
		cam->transladar(m);
		luz->transladar(m);
	}
	m = dvector3D(-.1,0,0);
	if(InputManager::Instance()->isPressed(SKY_KEY_D)){
		cam->transladar(m);
		luz->transladar(m);
	}
	m = animacion->getPosicion();
	if(InputManager::Instance()->isPressed(SKY_KEY_0)){
		cam->setCamTarget(m);
	}
	if(InputManager::Instance()->isPressed(SKY_KEY_K))
		printf("%d\n",animacion->CambiarAnimacion("cil"));
	if(InputManager::Instance()->isPressed(SKY_KEY_8)){
		cam = motor->removeCam(cam);
		if(cam == nullptr)
			printf("");
		cam = motor->crearCamara(NULL);
		motor->setActiveCam(cam->getID());
		luz = motor->removeLight(luz);
		luz = motor->crearLuz(cam);
	}
	
//	mov = dvector3D(0, InputManager::Instance()->mousePos.y, 0);
//	cam->setCamTarget(mov);
//	cubo->setRotacion(mov);
	
//	cam->transladar(mov);
	
	//para ver la posicion del raton
//	std::cout << InputManager::Instance()->mousePos.x << " - " << InputManager::Instance()->mousePos.y << std::endl;
}

void TEscena::imprime(){
	cubo->imprimePos();
}

//TNodo* TEscena::getActiveCamera(){
//	return NULL;
//}

