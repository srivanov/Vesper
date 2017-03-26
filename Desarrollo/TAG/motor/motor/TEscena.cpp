
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
	ShaderManager::Instance()->cargarShader("1", "../Shaders/texLight.vs", "../Shaders/texLight.frag");
	ShaderManager::Instance()->setActiveShader("1");
	cam = motor->crearCamara(NULL);
	motor->setActiveCam(0);
	cubo = motor->crearMalla(NULL, tMallaDinamica);
	SkyLuz* luz = motor->crearLuz(NULL);
	cubo2 = motor->crearMalla(NULL, tMallaEstatica);
	
	cam->setPosicion(dvector3D(0,2,5));
	cam->setFarValue(100);
//	cam->rotar(dvector3D(-40,0,0));
	cubo2->setMalla("../Models/plano.obj");
	cubo->setMalla("../Models/cube.obj");
	
	cubo->transladar(dvector3D(3,0,-2));
	cubo2->transladar(dvector3D(0,-3,0));
	luz->setPosicion(dvector3D(2,2,2));
	
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
		cubo->rotar(dvector3D(0,-.1,0));
	}
	if(InputManager::Instance()->isPressed(SKY_KEY_DOWN)){
		cubo->rotar(dvector3D(0,.1,0));
	}
	if(InputManager::Instance()->isPressed(SKY_KEY_LEFT)){
		cubo->transladar(dvector3D(-.1,0,0));
	}
	if(InputManager::Instance()->isPressed(SKY_KEY_RIGHT)){
		cubo->transladar(dvector3D(.1,0,0));
	}
	
	if(InputManager::Instance()->isPressed(SKY_KEY_W)){
		cam->rotar(dvector3D(0,-.1,0));
	}
	if(InputManager::Instance()->isPressed(SKY_KEY_S)){
		cam->rotar(dvector3D(0,.1,0));
	}
	if(InputManager::Instance()->isPressed(SKY_KEY_A)){
		cam->transladar(dvector3D(-.1,0,0));
	}
	if(InputManager::Instance()->isPressed(SKY_KEY_D)){
		cam->transladar(dvector3D(.1,0,0));
	}
	if(InputManager::Instance()->isPressed(SKY_KEY_0)){
		cam->setRotacion(dvector3D(-45,0,0));
	}
	
//	cam->setCamTarget(cubo->getPosicion());
	
//	cam->transladar(mov);
	
	//para ver la posicion del raton
//	std::cout << InputManager::Instance()->mousePos.x << " - " << InputManager::Instance()->mousePos.y << std::endl;
	
}

void TEscena::girar(glm::vec3 mov){
	if(cam != NULL)
		cam->rotar(dvector3D(mov.x,mov.y,mov.z));
}

void TEscena::imprime(){
	cubo->imprimePos();
}

//TNodo* TEscena::getActiveCamera(){
//	return NULL;
//}

