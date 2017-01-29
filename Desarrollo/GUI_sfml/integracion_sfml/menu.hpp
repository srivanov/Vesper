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
#include "Texto.hpp"
//#include "HUD.hpp"

class menu {
public:
    menu();
    virtual ~menu();
    void set_menu(int num);
    int get_menu();
    void update();
    void render();
    void set_window();
    sf::RenderWindow* window;
    
private:
    int num_menu;
//    HUD* hud_textos;
    
    sf::Texture textura;
    sf::RectangleShape rec;
    
    // Rectangulo para el menu principal y botones
    sf::RectangleShape principal_rec;
    sf::RectangleShape *principal_botones;
    Texto *principal_textos;
    
    // Rectangulos para niveles
    sf::RectangleShape *level_rec;
    sf::Texture *levels_tex;
    sf::RectangleShape *rec_img_levels;
    Texto level_nombre;
    
    // Rectangulo para ajustes y botones
    sf::RectangleShape ajustes_rec;
    sf::RectangleShape *ajustes_botones;
    Texto *ajustes_textos;
    Texto ajustes_nombre;
    
    // Flecha volver
    sf::ConvexShape boton;
    Texto boton_texto;
};

#endif /* menu_hpp */
