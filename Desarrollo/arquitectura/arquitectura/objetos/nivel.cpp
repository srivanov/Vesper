
#include "nivel.hpp"

nivel::nivel(){
    setType(tNIVEL);
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
    jugador = NULL;
}

nivel::~nivel(){
    //TO DO: falta por borrar todos los vectores
	delete cargador;
    delete jugador;
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
	
	dvector3D pos1(16,32,0);
    GameObject* aux = new palaObj();
	aux->addNodo("");
	aux->setTexture("3d/pala.jpg");
	aux->setPosicion(pos1);

    powerups.push_back(aux);
    
    dvector3D pos8(0,3,0);
    aux = new superSockerObj();
    aux->addNodo("");
    aux->setTexture("3d/letraE.png");
    aux->setPosicion(pos8);
	
    powerups.push_back(aux);
    
    dvector3D pos9(0,6,0);
    aux = new lanzaCaramelosObj();
    aux->addNodo("");
    aux->setTexture("3d/letraL.png");
    aux->setPosicion(pos9);
    
    powerups.push_back(aux);
    
    dvector3D pos10(0,9,0);
    aux = new globoAguaObj();
    aux->addNodo("");
    aux->setTexture("3d/globoagua.png");
    aux->setPosicion(pos10);
    
    powerups.push_back(aux);
    
    dvector3D pos11(0,12,0);
    aux = new chicleObj();
    aux->addNodo("");
    aux->setTexture("3d/chicle.png");
    aux->setPosicion(pos11);
    
    powerups.push_back(aux);
    
    dvector3D pos12(0,16,0);
    aux = new bombaHumoObj();
    aux->addNodo("");
    aux->setTexture("3d/bombahumo.png");
    aux->setPosicion(pos12);
    
    powerups.push_back(aux);
    
    dvector3D pos2(27,95,0);
    aux = new piedraObj();
    aux->addNodo("");
    aux->setTexture("3d/piedra.jpg");
    aux->setPosicion(pos2);
    
    powerups.push_back(aux);
    
    dvector3D pos6(40,25,0);
    aux = new piedraObj();
    aux->addNodo("");
    aux->setTexture("3d/piedra.jpg");
    aux->setPosicion(pos6);
    
    powerups.push_back(aux);
    
    dvector3D pos3(5,63,0);
    aux = new monedas();
    aux->addNodo("");
    aux->setTexture("3d/moneda.jpg");
    aux->setPosicion(pos3);
    
    powerups.push_back(aux);
	
    dvector3D pos5(24,33,0);
    aux = new monedas();
    aux->addNodo("");
    aux->setTexture("3d/moneda.jpg");
    aux->setPosicion(pos5);
    
    powerups.push_back(aux);
    
    dvector3D pos7(45,90,0);
    aux = new monedas();
    aux->addNodo("");
    aux->setTexture("3d/moneda.jpg");
    aux->setPosicion(pos7);
    
    powerups.push_back(aux);

    dvector3D pos4(45,50,0);
    aux = new llaveObj();
    aux->addNodo("");
    aux->setTexture("3d/llave.jpg");
    aux->setPosicion(pos4);
    
    powerups.push_back(aux);
//
//	
//    enemigos* npc = new enemigos(contador_npc);
//    npc->addNodo("");
//    npc->setTexture("3d/naranja.jpg");
//    dvector3D nodepos(10,15,0);
//    npc->setPosicion(nodepos);
//    
//    contador_npc++;
//    npcs.insert(npcs.end(), npc);
//    npc = NULL;
//    delete npc;
//
	puerta * puertita = new puerta();
	puertita->addNodo("");
	puertita->setTexture("3d/puerta.jpg");
	dvector3D pospu(8,23,0);
	puertita->setPosicion(pospu);
	puertita->setTipo(tCHIRRIANTE);

	contador_npc++;
	puertas.insert(puertas.end(), puertita);
	puertita = NULL;
	delete puertita;

    alarma * alarmita = new alarma(contador_npc);
    alarmita->addNodo("");
    alarmita->setTexture("3d/alarmita.jpg");
    dvector3D posal(20,65,0);
    alarmita->setPosicion(posal);
    
    contador_npc++;
    alarmas.insert(alarmas.end(), alarmita);
    alarmita = NULL;
    delete alarmita;
    
    alarma * alarmita2 = new alarma(contador_npc);
    alarmita2->addNodo("");
    alarmita2->setTexture("3d/alarmita.jpg");
    dvector3D posal2(29,2,0);
    alarmita2->setPosicion(posal2);
    
    contador_npc++;
    alarmas.insert(alarmas.end(), alarmita2);
    alarmita2 = NULL;
    delete alarmita2;
    
    fuente * fuentezita = new fuente(contador_npc);
    fuentezita->addNodo("");
    fuentezita->setTexture("3d/fuenten.jpg");
    dvector3D posf(5,55,0);
    fuentezita->setPosicion(posf);
    
    contador_npc++;
    fuentes.insert(fuentes.end(), fuentezita);
    fuentezita = NULL;
    delete fuentezita;
    
    fuente * fuentezita2 = new fuente(contador_npc);
    fuentezita2->addNodo("");
    fuentezita2->setTexture("3d/fuenten.jpg");
    dvector3D posf2(39,6,0);
    fuentezita2->setPosicion(posf2);
    
    contador_npc++;
    fuentes.insert(fuentes.end(), fuentezita2);
    fuentezita2 = NULL;
    delete fuentezita2;
    
    comida * comidita = new comida(contador_npc);
    comidita->addNodo("");
    comidita->setTexture("3d/pizza.jpg");
    dvector3D poscom(4,26,0);
    comidita->setPosicion(poscom);
    
    contador_npc++;
    comidas.insert(comidas.end(), comidita);
    comidita = NULL;
    delete comidita;
    
    comida * comidita2 = new comida(contador_npc);
    comidita2->addNodo("");
    comidita2->setTexture("3d/pizza.jpg");
    dvector3D poscom2(36,58,0);
    comidita2->setPosicion(poscom2);
    
    contador_npc++;
    comidas.insert(comidas.end(), comidita2);
    comidita2 = NULL;
    delete comidita2;
    
    botiquin * botiqueen = new botiquin(contador_npc);
    botiqueen->addNodo("");
    botiqueen->setTexture("3d/botiquin.jpg");
    dvector3D posbot(37,34,0);
    botiqueen->setPosicion(posbot);
    
    contador_npc++;
    botiquines.insert(botiquines.end(), botiqueen);
    botiqueen = NULL;
    delete botiqueen;
    
    jugador = new player();
    jugador->addNodo("3d/sphere.3ds");
    jugador->setTexture("3d/texture.png");
    dvector3D jpos(10,10,0);
    jugador->setPosicion(jpos);
    
    
    aux = NULL;

	if(ancho == 0 || alto == 0)
		return false;
	else{
		mapa_nivel = cargador->getMatriz();
		objetos_col = cargador->getObjetos();
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
	static_cast<physics*>(findComponent("physics"))->crearObjetosEstaticos(*objetos_col, *cargador->get_posObjetos(), cargador->getTileWidth(), cargador->getTileHeight());
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
	std::vector<puerta*>::iterator it6 = puertas.begin();
	while (it6 != puertas.end() && puertas.size() > 0) {
		if(*(*it6)->getmuero()){
			delete (*it6);
			puertas.erase(it6);
			it6 = puertas.begin();
		}else{
			(*it6)->update();
			++it6;
		}
	}
    
    jugador->update();
}

void nivel::contacto(GameObject *g){
    
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
    jugador->render();
}

void nivel::cambiarArmaJugador() {
    jugador->cambiarArma();
}

void nivel::atacarJugador() {
    jugador->atacar();
}

void nivel::rotarConRaton(dvector3D posRaton) {
    jugador->rotarConRaton(posRaton);
}

player* nivel::getPlayer() {
    return jugador;
}

//rehen* nivel::getRehen(){
//    return re;
//}
