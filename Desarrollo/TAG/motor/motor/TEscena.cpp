
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
	luz = motor->crearLuz(NULL);
	plano = motor->crearMalla(NULL, tMallaEstatica);
	dvector3D n(0,1,0);
	cam->setPosicion(n);
	cam->setFarValue(100);
//	cam->rotar(dvector3D(-40,0,0));
	plano->setMalla("../Models/plano.obj");
	cubo->setMalla("../Models/cubo.3ds");
	cubo->setTextura("../Models/tex.png");
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");

	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	
	mallas.push_back(motor->crearMalla(NULL, tMallaEstatica));
	mallas.back()->setMalla("../Models/microwave.obj");
	n = dvector3D(3,0,-2);
	cubo->transladar(n);
	n = dvector3D(0,-2,0);
	plano->transladar(n);
	n = dvector3D(2,2,2);
	luz->setPosicion(n);
	
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
        amb++;
        luz->_setAmbient(amb);
        
	}
	if(InputManager::Instance()->isPressed(SKY_KEY_DOWN)){
		dvector3D n(0,.1,0);
		cubo->rotar(n);
        float amb = luz->_getAmbient();
        amb--;
        luz->_setAmbient(amb);
	}
	if(InputManager::Instance()->isPressed(SKY_KEY_LEFT)){
		//cubo->transladar(dvector3D(-.1,0,0));
        float dif = luz->_getDiffuse();
        dif--;
        luz->_setDiffuse(dif);
	}
	if(InputManager::Instance()->isPressed(SKY_KEY_RIGHT)){
		//cubo->transladar(dvector3D(.1,0,0));
        float dif = luz->_getDiffuse();
        dif++;
        luz->_setDiffuse(dif);
	}
    if(InputManager::Instance()->isPressed(SKY_KEY_M)){
        float spec = luz->_getSpecular();
        spec++;
        luz->_setSpecular(spec);
    }
    if(InputManager::Instance()->isPressed(SKY_KEY_N)){
        float spec = luz->_getSpecular();
        spec--;
        luz->_setSpecular(spec);
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
	if(InputManager::Instance()->isPressed(SKY_KEY_0)){
//		cam->setCamTarget(cubo->getPosicion());
	}
	
//	cam->setCamTarget(cubo->getPosicion());
	
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

