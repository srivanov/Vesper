
#include "TEscena.hpp"
#include "InputManager.h"

TEscena::TEscena(){
//	root = new TNodo();
//	uno = new TNodo();
//	dos = new TNodo();
//	tres = new TNodo();
//	cuarto = new TNodo();
//	quinto = new TNodo();
//	sexto = new TNodo();
//	septimo = new TNodo();
//	
//	root->addHijo(uno);
//	root->addHijo(dos);
//	root->addHijo(sexto);
//
//	sexto->addHijo(quinto);
//	sexto->addHijo(septimo);
//	
//	uno->addHijo(tres);
//	
//	dos->addHijo(cuarto);
//
//	
//	t.cargarMalla("../Models/cube.obj");
//	
//	t2.cargarMalla("../Models/cube.obj");
//	
//	cam.w = WIDTH;
//	cam.h = HEIGHT;
//	
//	root->setEntidad(&troot);
//	uno->setEntidad(&tr);
//	dos->setEntidad(&tr2);
//	tres->setEntidad(&t);
//	cuarto->setEntidad(&t2);
//	quinto->setEntidad(&cam);
//	sexto->setEntidad(&trCam);
//	septimo->setEntidad(&luz);
//	
//	tr.trasladar(glm::vec3(-0.8f, 0.0f, 0.0f));
//	tr2.trasladar(glm::vec3(3.0f, 2.0f, 0.0f));
//	
//	trCam.trasladar(glm::vec3(0.0f, 0.0f, 5.0f));
	motor = SkyEngine::Instance();
	motor->init();
	cam = motor->crearCamara(NULL);
	motor->setActiveCam(0);
	cubo = motor->crearMalla(NULL, tMallaDinamica);
	luz = motor->crearLuz(NULL);
	plano = motor->crearMalla(NULL, tMallaEstatica);
	dvector3D n(0,2,2), s(0.1, 0.1, 0.1);
	cam->setPosicion(n);
	cam->setFarValue(100);
//	cam->rotar(dvector3D(-40,0,0));
	cubo->setMalla("../Models/zombi.fbx");
	plano->setMalla("../Models/plano2.obj");
	cubo->escalar(s);
	
//	cubo->setTextura("../Models/tex.png");
//	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
//	mallas.back()->setMalla("../Models/microwave.obj");
//
//	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
//	mallas.back()->setMalla("../Models/microwave.obj");
//	mallas.back()->setTextura("../Models/zil.png");
//	n = dvector3D(3,0,-2);
//	mallas.back()->setPosicion(n);
	
//	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
//	mallas.back()->setMalla("../Models/microwave.obj");
//	
//	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
//	mallas.back()->setMalla("../Models/microwave.obj");

	n = dvector3D(0,0.2,-2);
	cubo->transladar(n);
	n = dvector3D(0.1,0.1,0.1);
	cubo->escalar(n);
	n = dvector3D(0,0,0.1);
	plano->transladar(n);
	n = dvector3D(2,10,10);
	luz->setPosicion(n);
	
	n = cubo->getPosicion();
//	cam->setCamTarget(n);
	
//	delete cubo2;
}

TEscena::~TEscena(){
//	delete root;
//	delete uno;
//	delete dos;
//	delete tres;
//	delete cuarto;
}

void TEscena::Draw(){
	motor->Draw();
}

void TEscena::update(){
	dvector3D mov;
	
	if(InputManager::Instance()->isPressed(SKY_KEY_UP)){
		//cubo->rotar(dvector3D(0,-.1,0));
        float amb = luz->_getAmbient();
        amb+=0.01;
        luz->_setAmbient(amb);
        
	}
	if(InputManager::Instance()->isPressed(SKY_KEY_DOWN)){
        float amb = luz->_getAmbient();
        amb-=0.01;
        luz->_setAmbient(amb);
	}
	if(InputManager::Instance()->isPressed(SKY_KEY_LEFT)){
		//cubo->transladar(dvector3D(-.1,0,0));
        float dif = luz->_getDiffuse();
        dif-=0.1;
        luz->_setDiffuse(dif);
	}
	if(InputManager::Instance()->isPressed(SKY_KEY_RIGHT)){
		//cubo->transladar(dvector3D(.1,0,0));
        float dif = luz->_getDiffuse();
        dif+=0.1;
        luz->_setDiffuse(dif);
	}
    if(InputManager::Instance()->isPressed(SKY_KEY_M)){
        float spec = luz->_getSpecular();
        spec+=0.1;
        luz->_setSpecular(spec);
    }
    if(InputManager::Instance()->isPressed(SKY_KEY_N)){
        float spec = luz->_getSpecular();
        spec-=0.1;
        luz->_setSpecular(spec);
//		motor->debugON(true);
    }
	dvector3D m(0,0,-.1);
	if(InputManager::Instance()->isPressed(SKY_KEY_W)){
		cam->transladar(m);
	}
	m = dvector3D(0,0,.1);
	if(InputManager::Instance()->isPressed(SKY_KEY_S)){
		cam->transladar(m);
	}
	m = dvector3D(-.1,0,0);
	if(InputManager::Instance()->isPressed(SKY_KEY_A)){
		cam->transladar(m);
	}
	m = dvector3D(.1,0,0);
	if(InputManager::Instance()->isPressed(SKY_KEY_D)){
		cam->transladar(m);
	}
	m = cubo->getPosicion();
	if(InputManager::Instance()->isPressed(SKY_KEY_0)){
		cam->setCamTarget(m);
	}
//	mov = dvector3D(InputManager::Instance()->mousePos.x-400, 300-InputManager::Instance()->mousePos.y, 0);
//	cam->setCamTarget(mov);
	
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

