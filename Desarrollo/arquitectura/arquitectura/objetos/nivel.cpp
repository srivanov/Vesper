
#include "nivel.hpp"


GameObject* accion2(){
	return new alarma();
}

GameObject* accion3(){
	return new monedas();
}

GameObject* accion4(){
	return new player();
}

GameObject* accion5(){
	return new palaObj();
}

GameObject* accion6(){
	return new piedraObj();
}

GameObject* accion7(){
	return new enemigos();
}

GameObject* accion8(){
	return new llaveObj();
}

GameObject* accion9(){
	return new fuente();
}

GameObject* accion10(){
	return new botiquin();
}

GameObject* accion11(){
	return new puerta();
}

GameObject* accion12(){
	return new comida();
}

GameObject* accion14(){
	return NULL;
}

GameObject* accion15(){
    return new superSockerObj();
}

GameObject* accion16(){
    return new lanzaCaramelosObj();
}

GameObject* accion17(){
    return new globoAguaObj();
}

GameObject* accion18(){
    return new chicleObj();
}

GameObject* accion19(){
    return new bombaHumoObj();
}

GameObject* accion20(){
    return NULL;
}

GameObject* accion21(){
    return new rehen();
}

obj_mapping mapping[] = {

	{	1		,	""					,		0		},
	{	2		,	"3d/alarmita.jpg"	,	accion2		},
	{	3		,	"3d/moneda.jpg"		,	accion3		},
	{	4		,	"3d/texture.png"	,	accion4		},
	{	5		,	"3d/pala.jpg"		,	accion5		},
	{	6		,	"3d/piedra.jpg"		,	accion6		},
	{	7		,	"3d/naranja.jpg"	,	accion7		},
	{	8		,	"3d/llave.jpg"		,	accion8		},
	{	9		,	"3d/fuenten.jpg"	,	accion9		},
	{	10		,	"3d/botiquin.jpg"	,	accion10	},
	{	11		,	"3d/puerta.jpg"		,	accion11	},
	{	12		,	"3d/pizza.jpg"		,	accion12	},
	{	13		,	""					,		0		},
	{	14		,	"3d/rehen.jpg"		,	accion21	},
    {	15 		,	"3d/letraE.png"		,	accion15	},
    {	16 		,	"3d/letraL.png"		,	accion16	},
    {	17 		,	"3d/globoagua.png"	,	accion17	},
    {	18 		,	"3d/chicle.png"		,	accion18	},
    {	19 		,	"3d/bombahumo.png"	,	accion19	},
    {	20 		,	""		,	0	},
	{	0		,	""					,		0		}

};

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
	objs = mapping;
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
	

	if(ancho == 0 || alto == 0)
		return false;
	else{
		mapa_nivel = cargador->getMatriz();
		objetos_col = cargador->getParedes();
		std::vector<dvector3D>* posis = cargador->get_PosObjetos();

		std::vector<dvector3D>::iterator iter = posis->begin();
		while (iter!=posis->end()) {
			
			(*iter).z;
			objs = mapping;
			while(objs->key){
				if((*iter).z == objs->key && objs->pfunc != 0){
					GameObject* g = (*objs->pfunc)();
					
					if((*g->getType()) == tALARMA ||
					   (*g->getType()) == tENEMIGOS ||
					   (*g->getType()) == tFUENTE ||
					   (*g->getType()) == tBOTIQUIN ||
					   (*g->getType()) == tCOMIDA) {
						g->setID(contador_npc);
						contador_npc++;
					}
					
					if((*g->getType()) == tPLAYER) {
						g->addNodo("3d/sphere.3ds");
						jugador = static_cast<player*>(g);
					}else
						g->addNodo("");
					g->setTexture((char*)objs->tex.c_str());
					
					std::cout << (*iter).x << (*iter).y << std::endl;
					g->setPosicion(dvector3D((int)(*iter).y, (int)(*iter).x, 0));
					powerups.push_back(g);
				}
				++objs;
			}
			
			++iter;
		}
		
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
	static_cast<physics*>(findComponent("physics"))->crearObjetosEstaticos(*objetos_col, *cargador->get_posParedes(), cargador->getTileWidth(), cargador->getTileHeight());
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
