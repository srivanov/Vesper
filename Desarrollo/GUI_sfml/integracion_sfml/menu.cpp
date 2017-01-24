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
    
    // Rectangulos para los niveles
    level_rec = new sf::RectangleShape [3];
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
        textura.loadFromFile("../img_menu/menu_principal_03.png");
        
    }
    else if(num_menu == 2) {
        textura.loadFromFile("../img_menu/cargarpartida.png");
        
        // Creo los rectangulos para los niveles que aparecen en esta pantalla
        sf::Vector2f size(230, 230);
        
        sf::Vector2f topLeftOfWindow = window->getView().getCenter() - window->getView().getSize() / 2.f;
        
        sf::Vector2f centerOfWindow = window->getView().getCenter();

        for(int i = 0; i < 3; i++) {
            level_rec[i].setSize(size);
            level_rec[i].setPosition(centerOfWindow);
            level_rec[i].setOrigin(level_rec[i].getSize().x * 0.5, level_rec[i].getSize().y * 0.5);
            level_rec[i].setFillColor(sf::Color(248, 180, 134, 128));
            level_rec[i].setOutlineColor(sf::Color(86, 143, 107, 128));
            level_rec[i].setOutlineThickness(10);
            
            if(i == 0) {
                level_rec[i].setPosition(level_rec[i].getPosition() - sf::Vector2f(level_rec[i].getSize().x + 40, 0));
            } else if(i == 2) {
                level_rec[i].setPosition(level_rec[i].getPosition() + sf::Vector2f(level_rec[i].getSize().x + 40, 0));
            }
        }
    }
    else if(num_menu == 3) {
        textura.loadFromFile("../img_menu/menuajustes.png");
    }
    
    rec.setSize((sf::Vector2f)window->getSize());
}

sf::RectangleShape * menu::getLevelRec() {
    return level_rec;
}

void menu::render() {
    window->draw(rec);
    
    if(num_menu == 2){
        for(int i = 0; i < 3; i++) {
            window->draw(level_rec[i]);
        }
    }
}

menu::~menu() {
    //delete level_rec;
}
