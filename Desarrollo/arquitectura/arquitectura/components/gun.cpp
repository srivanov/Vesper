
#include "gun.hpp"
#include "../Game.hpp"

gun::gun(unsigned int pMunicion, float pAlcance, float pTiempo_recarga, unsigned int caden, unsigned int carga, typeArma t){
	cadencia = caden;
	alcance = pAlcance;
	municion = pMunicion;
	tiempo_vida = alcance/3.0f;
	tiempo_recarga = pTiempo_recarga;
	temp.start();
	cargador = carga;
    tipo = t;
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
        if(*bala_aux->getmuero()){
            delete bala_aux;
            bala_aux = NULL;
            iter = balas.erase(iter);
        }else
            iter++;
    }
}

void gun::render(float &interpolation){
    iter = balas.begin();
    while (iter != balas.end())
	{
        bala_aux = *iter;
        bala_aux->render(interpolation);
        iter++;
    }
}

void gun::atacar(dvector3D &pos, dvector3D &dir){
	if(municion > 0)
	{
		if(temp.tTranscurrido(1.0f/cadencia))
		{
			temp.reset();
            insertBala(pos, dir, 3.0f);
			if(tipo != tMARTILLO && tipo != tPALAc) { municion--; cargador--; }
		}
		else
		{
			if(temp.tTranscurrido(tiempo_recarga))
				cargador = 6;
		}
	}
}

unsigned int gun::getMunicion(){
	return 1;
}

void gun::setMunicion(unsigned int n){
	municion = n;
}

typeArma const* gun::getType(){
    return &tipo;
}

void gun::insertBala(dvector3D &pos, dvector3D &dir, float vel){
    //TO DO: Hacer la gestion de las balas en la clase bala
    bala_aux = new bala(pos, dir, vel);
    bala_aux->addNodo("3d/bala.3ds");
    balas.insert(balas.begin(), bala_aux);
   
}
