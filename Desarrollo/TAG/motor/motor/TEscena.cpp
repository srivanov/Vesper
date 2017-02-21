
#include "TEscena.hpp"

TEscena::TEscena(Shader &shader){
	root = new TNodo();
	uno = new TNodo();
	dos = new TNodo();
	tres = new TNodo();
	cuarto = new TNodo();
	
	root->addHijo(uno);
	
	uno->addHijo(dos);
	uno->addHijo(cuarto);
	
	dos->addHijo(tres);
	
	t.sh = &shader;
	t.cargarMalla("../Models/cube.obj");
	
	t2.sh = &shader;
	t2.cargarMalla("../Models/cube.obj");
	
	uno->setEntidad(&tr);
	dos->setEntidad(&tr2);
	
	tres->setEntidad(&t);
	cuarto->setEntidad(&t2);
	
	tr.escalar(glm::vec3(0.5f, 0.5f, 0.5f));
	tr2.trasladar(glm::vec3(2.0f, 0.0f, 0.0f));
}

TEscena::~TEscena(){
	
}

void TEscena::Draw(){
	root->Draw();
}

void TEscena::cambiar(glm::vec3 mov){
	tr.trasladar(mov);
}
