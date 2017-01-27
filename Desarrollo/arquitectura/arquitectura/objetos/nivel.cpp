
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
	
    contador_npc = 0;
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
    
    
    enemigos* npc = new enemigos(contador_npc);
    npc->addNodo("");
    npc->setTexture("3d/enemy.jpg");
    dvector3D nodepos(10,15,0);
    npc->setPosicion(nodepos);
    
    contador_npc++;
    npcs.insert(npcs.end(), npc);
    npc = NULL;
    delete npc;
    
    alarma * alarmita = new alarma(contador_npc);
    alarmita->addNodo("3d/alarmita.3ds");
    alarmita->setTexture("3d/alarmita.jpg");
    dvector3D posal(5,3,0);
    alarmita->setPosicion(posal);
    
    contador_npc++;
    alarmas.insert(alarmas.end(), alarmita);
    alarmita = NULL;
    delete alarmita;
    
    fuente * fuentezita = new fuente(contador_npc);
    fuentezita->addNodo("");
    fuentezita->setTexture("3d/fuenten.jpg");
    dvector3D posf(0,10,0);
    fuentezita->setPosicion(posf);
    
    contador_npc++;
    fuentes.insert(fuentes.end(), fuentezita);
    fuentezita = NULL;
    delete fuentezita;
    
    comida * comidita = new comida(contador_npc);
    comidita->addNodo("");
    comidita->setTexture("3d/pizza.jpg");
    dvector3D poscom(0,0,0);
    comidita->setPosicion(poscom);
    
    contador_npc++;
    comidas.insert(comidas.end(), comidita);
    comidita = NULL;
    delete comidita;
    
    botiquin * botiqueen = new botiquin(contador_npc);
    botiqueen->addNodo("");
    botiqueen->setTexture("3d/botiquin.jpg");
    dvector3D posbot(10,0,0);
    botiqueen->setPosicion(posbot);
    
    contador_npc++;
    botiquines.insert(botiquines.end(), botiqueen);
    botiqueen = NULL;
    delete botiqueen;
    
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
    
    std::vector<enemigos*>::iterator it = npcs.begin();
    while (it != npcs.end() && npcs.size() > 0) {
        if(*(*it)->getmuero()){
            delete (*it);
            npcs.erase(it);
            it = npcs.begin();
        }else{
            (*it)->update();
            ++it;
        }
        
    }
    std::vector<comida*>::iterator it2 = comidas.begin();
    while (it2 != comidas.end() && comidas.size() > 0) {
        if(*(*it2)->getmuero()){
            delete (*it2);
            comidas.erase(it2);
            it2 = comidas.begin();
        }else{
            (*it2)->update();
            ++it2;
        }
    }
    std::vector<alarma*>::iterator it3 = alarmas.begin();
    while (it3 != alarmas.end() && alarmas.size() > 0) {
        if(*(*it3)->getmuero()){
            delete (*it3);
            alarmas.erase(it3);
            it3 = alarmas.begin();
        }else{
            (*it3)->update();
            ++it3;
        }
    }
    std::vector<fuente*>::iterator it4 = fuentes.begin();
    while (it4 != fuentes.end() && fuentes.size() > 0) {
        if(*(*it4)->getmuero()){
            delete (*it4);
            fuentes.erase(it4);
            it4 = fuentes.begin();
        }else{
            (*it4)->update();
            ++it4;
        }
    }
    std::vector<botiquin*>::iterator it5 = botiquines.begin();
    while (it5 != botiquines.end() && botiquines.size() > 0) {
        if(*(*it5)->getmuero()){
            delete (*it5);
            botiquines.erase(it5);
            it5 = botiquines.begin();
        }else{
            (*it5)->update();
            ++it5;
        }
    }
}

void nivel::contacto(GameObject *g){
    if(*g->getType() == tPLAYER){
//        muero = true;
    }
}

bool const* nivel::getmuero(){
    return &muero;
}

void nivel::contactoEnd(GameObject *g){
    
}

void nivel::render(){
//    std::vector<enemigos*>::iterator it = npcs.begin();
//    while (it != npcs.end()) {
//        (*it)->render();
//        it++;
//    }
}
