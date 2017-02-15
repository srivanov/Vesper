
#include "TEscena.hpp"

TEscena::TEscena(Shader &shader){
	root = new TNodo();
	uno = new TNodo();
	dos = new TNodo();
	
	root->addHijo(uno);
	uno->setPadre(root);
	uno->addHijo(dos);
	dos->setPadre(uno);
	
	t.sh = &shader;
	t.cargarMalla("../Models/cube.obj");
	dos->setEntidad(&t);
}

TEscena::~TEscena(){
	
}

void TEscena::Draw(){
	root->Draw();
}
