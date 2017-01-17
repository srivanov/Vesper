//
//  menu.cpp
//  integracion_sfml
//
//  Created by Catherine Castrillo González on 17/01/17.
//  Copyright © 2017 Catherine Castrillo González. All rights reserved.
//

#include "menu.hpp"

menu::menu() {
    num_menu = 1;
    textura.loadFromFile("../img_menu/cargarpartida.png");
//    rec.setSize(sf::Vector2f(800, 600));
    rec.setTexture(&textura);
}

void menu::set_menu(int num) {
    num_menu = num;
}

int menu::get_menu() {
    return num_menu;
}

void menu::update() {
    // Process events
    sf::Event event;
    while (window->pollEvent(event))
    {
        // Close window: exit
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        
        // Escape pressed: exit
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window->close();
        }
        
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            set_menu(1);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
            set_menu(2);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
            set_menu(3);
        }
        else {
            // No hago nada
        }
    }
    
    if(num_menu == 1) {
        textura.loadFromFile("../img_menu/menuprincipal.png");
    }
    else if(num_menu == 2) {
        textura.loadFromFile("../img_menu/cargarpartida.png");
    }
    else if(num_menu == 3) {
        textura.loadFromFile("../img_menu/menuajustes.png");
    }
    
    rec.setSize((sf::Vector2f)window->getSize());
}

void menu::render() {
    window->draw(rec);
}

menu::~menu() {
    
}
