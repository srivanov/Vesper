
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
	cam = motor.crearCamara(NULL);
	motor.setActiveCam(0);
	cubo = motor.crearMalla(NULL);
	SkyLuz* luz = motor.crearLuz(NULL);
	cubo2 = motor.crearMalla(NULL);
	
	cam->setPosicion(dvector3D(1,0,3));
	
	cubo2->setMalla("../Models/cube.obj");
	cubo->setMalla("../Models/cube.obj");
	
	cubo->transladar(dvector3D(-2,1,0));
	cubo2->transladar(dvector3D(-5,-1,0));
	luz->setPosicion(dvector3D(2,2,2));
	
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

void TEscena::mover(glm::vec3 mov){
	if(cam != NULL)
		cam->transladar(dvector3D(mov.x,mov.y,mov.z));
}

void TEscena::girar(glm::vec3 mov){
	if(cam != NULL)
		cam->rotar(dvector3D(mov.x,mov.y,mov.z));
}

//TNodo* TEscena::getActiveCamera(){
//	return NULL;
//}

