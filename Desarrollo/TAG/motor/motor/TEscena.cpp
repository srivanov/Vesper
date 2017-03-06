
#include "TEscena.hpp"

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
	ShaderManager::Instance()->cargarShader("1", "../Shaders/texLight.vs", "../Shaders/texLight.frag");
	ShaderManager::Instance()->setActiveShader("1");
	SkyCamara* cam = motor.crearCamara(NULL);
	SkyMalla* cubo = motor.crearMalla(NULL);
	SkyLuz* luz = motor.crearLuz(NULL);
	
	dvector3D p(1,1,5), j(0,0,5);
	cam->setPosicion(&p);
	cubo->setMalla("../Models/cube.obj");
	luz->setPosicion(&j);
	
}

TEscena::~TEscena(){
//	delete root;
//	delete uno;
//	delete dos;
//	delete tres;
//	delete cuarto;
}

void TEscena::Draw(){
//	cam.Draw(quinto);
//	luz.Draw(septimo);
//	root->Draw();
	motor.Draw();
}

void TEscena::cambiar(glm::vec3 mov){
	
}

//TNodo* TEscena::getActiveCamera(){
//	return NULL;
//}

