
#include "nivel.hpp"

nivel::nivel(){
	component* aux = new class render();
	this->insertComponent((char*)"render", aux);
	aux = new physics();
    this->insertComponent((char*)"physics", aux);
	
	std::map<char*,component*>::iterator iter = this->getIteradorBegin();
	while(iter != this->getIteradorEnd()){
		iter->second->setFather(this);
		iter++;
	}
	
    muero = false;
	mapa_nivel = NULL;
	cargador = new cargarMapa();
	aux = NULL;
	setType(tNIVEL);
}

nivel::~nivel(){
	delete cargador;
}

bool nivel::cargarNivel(char* numero){
	char ruta[30] = "";
	
	strcat(ruta, "tiled/mapa");
	strcat(ruta, numero);
	strcat(ruta, ".tmx");
	printf("\n%s\n", ruta);
	if(!cargador->leerMapa(ruta))
		printf("Ha habido un problema al leer el mapa del fichero. Comprueba la ruta y el acceso.\n");
	ancho = cargador->getWidth();
	alto = cargador->getHeight();
	
	dvector3D pos1(5,17,0);
    GameObject* aux = new palaObj();
	aux->addNodo("");
	aux->setTexture("3d/pala.jpg");
	aux->setPosicion(pos1);
    
    powerups.push_back(aux);
	
    dvector3D pos2(3,20,0);
    aux = new piedraObj();
    aux->addNodo("");
    aux->setTexture("3d/piedra.jpg");
    aux->setPosicion(pos2);
    
    powerups.push_back(aux);
    
    dvector3D pos3(8,20,0);
    aux = new monedas();
    aux->addNodo("");
    aux->setTexture("3d/moneda.jpg");
    aux->setPosicion(pos3);
    
    powerups.push_back(aux);
	
    dvector3D pos5(8,22,0);
    aux = new monedas();
    aux->addNodo("");
    aux->setTexture("3d/moneda.jpg");
    aux->setPosicion(pos5);
    
    powerups.push_back(aux);
    dvector3D pos6(8,24,0);
    aux = new monedas();
    aux->addNodo("");
    aux->setTexture("3d/moneda.jpg");
    aux->setPosicion(pos6);
    
    powerups.push_back(aux);
    
    dvector3D pos4(4,11,0);
    aux = new llaveObj();
    aux->addNodo("");
    aux->setTexture("3d/llave.jpg");
    aux->setPosicion(pos4);
    
    powerups.push_back(aux);
    
    aux = NULL;

	if(ancho == 0 || alto == 0)
		return false;
	else{
		mapa_nivel = cargador->getMatriz();
		return true;
	}
    
    //AQUI CODIGO MUERTO
}

int nivel::getAncho(){
	return ancho;
}

int nivel::getAlto(){
	return alto;
}

std::vector<int>* nivel::getMapa(){
	return mapa_nivel;
}

void nivel::dibujarMapa(){
	static_cast<class render*>(findComponent("render"))->dibujarMapa();
}

void nivel::update(){
    std::vector<GameObject*>::iterator iter = powerups.begin();
    while (iter!=powerups.end() && powerups.size() > 0) {
        if(*(*iter)->getmuero()){
            delete (*iter);
            powerups.erase(iter);
			iter = powerups.begin();
        }else{
            (*iter)->update();
			++iter;
        }
    }
}

void nivel::contacto(GameObject *g){
    if(*g->getType() == tPLAYER){
        muero = true;
    }
}

bool const* nivel::getmuero(){
    return &muero;
}

void nivel::contactoEnd(GameObject *g){
    
}
