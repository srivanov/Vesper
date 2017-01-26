
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
    rapido = false;
    muero = false;
	//incremento en el movimiento
	incrX = 0;
	incrY = 0;
	incrZ = 0;
	//la distancia hasta el jugador
	offsetX = 0;
	offsetY = -5;
	offsetZ = -10;
	//velocidad de la camara
	camSpeed = 1.5f;
    //variable para zoom zoom zoom
    cerca = false;
	aux = NULL;
	setType(tCAMARA);
}

camara::~camara(){
	
}

void camara::addCamara(dvector3D &p, dvector3D &l){
    posicion = p;
	renderiza->addCamera(posicion, l);
}

void camara::movimientoInteligente(dvector3D &posPlayer){
    
	incrX = ((posPlayer.x + offsetX) - renderiza->getCamPos()->x)/ (camSpeed*60.0);
	incrY = ((posPlayer.y + offsetY) - renderiza->getCamPos()->y)/ (camSpeed*60.0);
	incrZ = ((posPlayer.z + offsetZ) - renderiza->getCamPos()->z)/ (camSpeed*60.0);
    
    dvector3D aux1(renderiza->getCamPos()->x+incrX, renderiza->getCamPos()->y+incrY, renderiza->getCamPos()->z+incrZ);
    dvector3D aux2(renderiza->getCamPos()->x - offsetX, renderiza->getCamPos()->y - offsetY, renderiza->getCamPos()->z - offsetZ);
    
    renderiza->setCamPos(aux1);
    renderiza->setCamTarget(aux2);
//	printf("%.2f %.2f %.2f\n", renderiza->getCamPos()[0], renderiza->getCamPos()[1], renderiza->getCamPos()[2]);
}

void camara::setCamSpeed(float vel){
    camSpeed = vel;
}

void camara::setZoom(bool z){
    cerca = z;
    if(cerca){
        //distancia con zoom
        offsetX = 0; offsetY = -2.5; offsetZ = -5;
        setCamSpeed(0.5);
    }else{
        //distancia normal
        offsetX = 0; offsetY = -5; offsetZ = -10;
        setCamSpeed(1.5);
    }
}

bool camara::getZoom(){
    return cerca;
}

void camara::contacto(GameObject *g){
    if(*g->getType() == tPLAYER){
        muero = true;
    }
}

bool const* camara::getmuero(){
    return &muero;
}

float* camara::getCamSpeed(){
    return &camSpeed;
}

void camara::setRapido(bool r){
    rapido = r;
    if(r)
    	camSpeed*=0.5f;
    else
        camSpeed=1.5f;
}

bool camara::getRapido(){
    return rapido;
}
