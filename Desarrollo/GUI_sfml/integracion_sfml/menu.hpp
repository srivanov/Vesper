//
//  menu.hpp
//  integracion_sfml
//
//  Created by Catherine Castrillo González on 17/01/17.
//  Copyright © 2017 Catherine Castrillo González. All rights reserved.
//

#ifndef menu_hpp
#define menu_hpp

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "HUD.hpp"

class menu {
public:
    menu();
    virtual ~menu();
    void set_menu(int num);
    int get_menu();
    void update();
    void render();
    void set_window();
    sf::RectangleShape* getLevelRec();
    sf::RenderWindow* window;
    
private:
    int num_menu;
    HUD *hud;
    sf::Texture textura;
    sf::RectangleShape rec;
    
    // Rectangulo para el menu principal
    sf::RectangleShape principal_rec;
    // Rectangulos para niveles
    sf::RectangleShape *level_rec;
    // Rectangulo para ajustes
    sf::RectangleShape ajustes_rec;
    
    // Flecha volver
    sf::ConvexShape boton;
    
    // Prueba
    sf::RectangleShape smallest_screen;
};

#endif /* menu_hpp */
