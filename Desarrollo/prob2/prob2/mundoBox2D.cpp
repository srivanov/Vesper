
#include "mundoBox2D.hpp"

mundoBox2D* mundoBox2D::pinstance = 0;

//para crear y devolver la instancia del Juego
mundoBox2D* mundoBox2D::Instance(){
    
    if(pinstance == 0){ //si no se ha creado nunca, entra y la crea
        pinstance = new mundoBox2D();
        
    }
    return pinstance; //la devuelve
}

mundoBox2D::mundoBox2D()
{
	world = new b2World(b2Vec2(0.0f, 0.0f)); //mundo sin gravedad
	world->SetAllowSleeping(true);
}

b2World* mundoBox2D::getWorld(){
    return world;
}

mundoBox2D:: ~mundoBox2D(){ //borra todos los cuerpos y joints. No usar sus punteros despues
    delete world;
}
