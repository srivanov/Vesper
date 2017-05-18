
#include "gun.hpp"
#include "../Game.hpp"


cualidades valores[] = {
//      TIPO             MUNI     ALC   RECARGA CADE CARGA
    { tMARTILLO         , 10    , 0.2f , 4.0f , 2 , 6 },
    { tPISTOLA          , 8     , 2.0f , 2.0f , 1 , 6 },
    { tESCOPETA         , 8     , 1.0f , 4.0f , 1 , 2 },
    { tLANZACARAMELOS   , 30    , 3.0f , 4.0f , 5 , 6 },
    { tGLOBOAGUA        , 3     , 2.5f , 4.0f , 1 , 6 },
    { tCHICLE           , 3     , 2.5f , 4.0f , 1 , 6 },
    { tBOMBAHUMO        , 3     , 2.5f , 4.0f , 5 , 6 },
    { tPIEDRA           , 3     , 2.5f , 4.0f , 5 , 6 },
    { tPALA             , 10    , 0.2f , 4.0f , 1 , 6 },
    { tArmaNO_TYPE      , 0     , 0    , 0    , 0 , 0 }
};



gun::gun(const typeArma t){
    size_t it = 0;
    while(valores[it].tipo!=tArmaNO_TYPE){
        if(valores[it].tipo==t) {
            cualidad = valores[it];
            break;
        }
        it++;
    }
    
	tiempo_vida = cualidad.alcance/3.0f;
    carga_max = cualidad.cargador;
	temp.start();
}

gun::~gun(){
    balas.clear();
}

void gun::update(){
    iter = balas.begin();
    while (iter != balas.end()){
        bala_aux = *iter;
//        bala_aux->mover(*bala_aux->getDireccion());
        bala_aux->update();
        if(bala_aux->Eliminable()){
            delete bala_aux;
            bala_aux = NULL;
            iter = balas.erase(iter);
        }else
            iter++;
    }
}

void gun::render(){
    iter = balas.begin();
    while (iter != balas.end())
	{
        bala_aux = *iter;
        bala_aux->render();
        iter++;
    }
}

void gun::atacar(dvector3D &pos, dvector3D &dir){
	if(cualidad.municion > 0 || cualidad.cargador > 0)
	{
		if(cualidad.cargador>0
        && temp.tTranscurrido(1.0f/cualidad.cadencia)){
			temp.reset();
            insertBala(pos, dir, 3.0f);
			if(cualidad.tipo != tMARTILLO && cualidad.tipo != tPALA) {
//                cualidad.municion--;
                cualidad.cargador--;
            }
		}
        else if(temp.tTranscurrido(cualidad.recarga)){
            if(cualidad.municion >= carga_max){
                cualidad.cargador = carga_max;
                cualidad.municion -= carga_max;
            }else{
                cualidad.cargador = cualidad.municion;
                cualidad.municion = 0;
            }
        }
	}
}

unsigned int gun::getMunicion(){
	return cualidad.municion;
}

unsigned int gun::getCarga(){
    return cualidad.cargador;
}

void gun::setMunicion(unsigned int n){
	cualidad.municion = n;
}

void gun::insertBala(dvector3D &pos, dvector3D &dir, float vel){
    
    bala_aux = new Bala(pos, dir, vel,tiempo_vida);
    bala_aux->setObjectType(BALA);
    switch(cualidad.tipo){
            // TIPOS DE MALLA Y TEXTURA
        case tPISTOLA:
            bala_aux->addNodo("3d/bala_pistola_agua.obj");
            bala_aux->setTexture("3d/bala_pistola_diffuse.png");
            break;
        case tESCOPETA:
            bala_aux->addNodo("3d/bala_escopeta.obj");
            bala_aux->setTexture("3d/bala_escopeta_diffuse.png");
            break;
        case tLANZACARAMELOS:
            bala_aux->addNodo("3d/bala_lanza.obj");
            bala_aux->setTexture("3d/bala_lanza_diffuse.png");
            break;
        case tPIEDRA:
            bala_aux->addNodo("3d/piedra.obj");
            bala_aux->setTexture("3d/Piedra_Diffuse.png");
            break;
        case tMARTILLO:
            bala_aux->addNodo("3d/bala.3ds");
            break;
        case tPALA:
            bala_aux->addNodo("3d/bala.3ds");
            break;
        case tBOMBAHUMO:
            bala_aux->addNodo("3d/bala.3ds");
            break;
        case tGLOBOAGUA:
            bala_aux->addNodo("3d/bala.3ds");
            break;
        default:return;
    }
    dvector3D rotar = dvector3D(0,0,0);
    bala_aux->setRotation(rotar);
    
    balas.insert(balas.begin(), bala_aux);
   
}
