
#include "TEscena.hpp"

TEscena::TEscena(Shader &shader){
	root = new TNodo();
	uno = new TNodo();
	dos = new TNodo();
	tres = new TNodo();
	
	root->addHijo(uno);
	uno->setPadre(root);
	
	uno->addHijo(dos);
	dos->setPadre(uno);
	
	dos->addHijo(tres);
	tres->setPadre(dos);
	
	t.sh = &shader;
	t.cargarMalla("../Models/cube.obj");
	
	uno->setEntidad(&tr);
	dos->setEntidad(&tr2);
	tres->setEntidad(&t);
	
	tr.escalar(glm::vec3(0.5f, 0.5f, 0.5f));
	tr2.trasladar(glm::vec3(1.0f, 0.0f, 0.0f));
}

TEscena::~TEscena(){
	
}

void TEscena::Draw(){
	root->Draw();
}
