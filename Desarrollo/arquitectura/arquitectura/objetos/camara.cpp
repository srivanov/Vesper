
#include "camara.hpp"

camara::camara(){
	component* aux = new class render();
	renderiza = (class render*)aux;
	this->insertComponent((char*)"render", aux);
	aux = new transform3D();
    this->insertComponent((char*)"transform3D", aux);
	aux = new physics();
    this->insertComponent((char*)"physics", aux);
	aux = new IACamara();
    this->insertComponent((char*)"IACamara", aux);
	
	std::map<char*,component*>::iterator iter = this->getIteradorBegin();
	while(iter != this->getIteradorEnd()){
		iter->second->setFather(this);
		iter++;
	}
	//incremento en el movimiento
	incrX = 0;
	incrY = 0;
	incrZ = 0;
	//la distancia hasta el jugador
	offsetX = 0;
	offsetY = -5;
	offsetZ = -10;
	//velocidad de la camara
	camSpeed = 2.0;
}

camara::~camara(){
	renderiza->~render();
	if(renderiza == NULL)
		printf("bien");
	clearComponents();
}

void camara::addCamara(float* p, float* l){
	renderiza->addCamera(p, l);
}

void camara::movimientoInteligente(float* posPlayer){
	incrX = ((posPlayer[0] + 0) - renderiza->getCamPos()[0])/ (camSpeed*60.0);
	incrY = ((posPlayer[1] + -5) - renderiza->getCamPos()[1])/ (camSpeed*60.0);
	incrZ = ((posPlayer[2] + -10) - renderiza->getCamPos()[2])/ (camSpeed*60.0);

//	printf("%.2f %.2f %.2f\n", renderiza->getCamPos()[0], renderiza->getCamPos()[1], renderiza->getCamPos()[2]);
	
//	printf("%.2f %.2f %.2f\n", posPlayer[0], posPlayer[1], posPlayer[2]);
//	printf("%.5f %.5f %.5f\n", incrX, incrY, incrZ);

	renderiza->setCamPos(new float[3]{renderiza->getCamPos()[0]+incrX, renderiza->getCamPos()[1]+incrY, renderiza->getCamPos()[2]+incrZ});
	renderiza->setCamTarget(new float[3]{renderiza->getCamPos()[0] - offsetX, renderiza->getCamPos()[1] - offsetY, renderiza->getCamPos()[2] - offsetZ});

}

