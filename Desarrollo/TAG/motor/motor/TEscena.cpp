
#include "TEscena.hpp"

TEscena::TEscena(Shader &shader){
	root = new TNodo();
	uno = new TNodo();
	dos = new TNodo();
	tres = new TNodo();
	cuarto = new TNodo();
	quinto = new TNodo();
	sexto = new TNodo();
	septimo = new TNodo();
	
	root->addHijo(uno);
	uno->addHijo(dos);
	uno->addHijo(sexto);
	dos->addHijo(tres);
	root->addHijo(cuarto);
	sexto->addHijo(quinto);
	sexto->addHijo(septimo);
	
	t.sh = &shader;
	t.cargarMalla("../Models/cube.obj");
	
	t2.sh = &shader;
	t2.cargarMalla("../Models/cube.obj");
	
	cam.sh = &shader;
	cam.w = WIDTH;
	cam.h = HEIGHT;
	
	luz.sh = &shader;
	
	uno->setEntidad(&tr);
	dos->setEntidad(&tr2);
	tres->setEntidad(&t);
	cuarto->setEntidad(&t2);
	quinto->setEntidad(&cam);
	sexto->setEntidad(&trCam);
	septimo->setEntidad(&luz);
	
	tr.trasladar(glm::vec3(-0.8f, 0.0f, 0.0f));
	tr2.trasladar(glm::vec3(3.0f, 0.0f, 0.0f));
	
	trCam.trasladar(glm::vec3(0.0f, 0.0f, -5.0f));
}

TEscena::~TEscena(){
	delete root;
	delete uno;
	delete dos;
	delete tres;
	delete cuarto;
}

void TEscena::Draw(){
	cam.Draw(quinto);
	luz.Draw(septimo);
	root->Draw();
}

void TEscena::cambiar(glm::vec3 mov){
	static_cast<TTransform*>(sexto->getEntidad())->trasladar(mov);
}

TNodo* TEscena::getActiveCamera(){
	return NULL;
}

