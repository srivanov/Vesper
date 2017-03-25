//
//  Enemy.cpp
//  Arquitectura
//
//  Created by Gaspar Rodriguez Valero on 16/3/17.
//  Copyright © 2017 Gaspar Rodriguez Valero. All rights reserved.
//

#include "Enemy.hpp"

Enemy::Enemy(){
    
     component * componente = new ataque();
     componentes.insert(
     std::pair<const ComponentType,component*>(ATAQUE,componente)
     );
     componente->setFather(this);
     
     Arbol = Behaviour_tree2::instancia()->ArbolPorDefecto();
    
    
}

Enemy::~Enemy(){

     delete Arbol;
     NpcLibrary::instancia()->remove_book(m_ID);
}

void Enemy::update(){
    
     if(book->salud <= 0)
         eliminar = true;
     
     if (book->Evento) {
     Arbol->reset();
     book->Evento = false;
     }
     book->updateBook();
     
     Arbol->run(m_ID);
     
     mover(*book->VectorMovimiento);
    dvector3D aux = *getPosition() + *book->VectorMovimiento;
     rotarConRaton(aux);
    
    
    GameObject::update();
}

void Enemy::inicializar(int& ID){
    m_ID = ID;
    
    book = NpcLibrary::instancia()->add_book(m_ID, getPosition());
     //TRIGGER SYSTEM
    trigger_system::instance()->subs(book);
     
    
    
}

void Enemy::contacto(PhysicObject *g){
    if(g && g->getObjectType()==BALA){
        
         //Bala * bullet = static_cast<Bala*>(g);
         book->salud-=20;
         
    }
}
