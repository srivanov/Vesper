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
    rec.setTexture(&textura);
    
    // Rectangulo para el menu principal
//    principal_rec = new sf::RectangleShape [1];
    
    // Rectangulos para los niveles
    level_rec = new sf::RectangleShape [3];
    
    // Boton volver
    boton.setPointCount(7);
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
    
    sf::Vector2f centerOfWindow = window->getView().getCenter();
    
    if(num_menu == 1) {
        textura.loadFromFile("../img_menu/menu_principal_03.png");
        
        sf::Vector2f size(375, 350);
//        sf::Vector2f centerOfWindow = window->getView().getCenter();
        
        principal_rec.setSize(size);
        principal_rec.setPosition(centerOfWindow);
        principal_rec.setOrigin(principal_rec.getSize().x * 0.5, principal_rec.getSize().y * 0.25);
        principal_rec.setFillColor(sf::Color(248, 180, 134, 128));
        principal_rec.setOutlineColor(sf::Color(86, 143, 107, 128));
        principal_rec.setOutlineThickness(10);
    } else if(num_menu == 2) {
        textura.loadFromFile("../img_menu/cargarpartida.png");
        
        // Creo los rectangulos para los niveles que aparecen en esta pantalla
        sf::Vector2f size(230, 230);
//        sf::Vector2f centerOfWindow = window->getView().getCenter();

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
            else {
                // Nada
            }
        }
    } else if(num_menu == 3) {
        textura.loadFromFile("../img_menu/menuajustes.png");
        
        sf::Vector2f size(375, 350);
//        sf::Vector2f centerOfWindow = window->getView().getCenter();
        
        ajustes_rec.setSize(size);
        ajustes_rec.setPosition(centerOfWindow);
        ajustes_rec.setOrigin(ajustes_rec.getSize().x * 0.02, ajustes_rec.getSize().y * 0.25);
        ajustes_rec.setFillColor(sf::Color(248, 180, 134, 128));
        ajustes_rec.setOutlineColor(sf::Color(86, 143, 107, 128));
        ajustes_rec.setOutlineThickness(10);
    } else {
        // Nada
    }
    
    rec.setSize((sf::Vector2f)window->getSize());
    
    // Prueba para poder ver como queda el menu en una pantalla mas pequena
    smallest_screen.setSize(sf::Vector2f(800, 600));
    smallest_screen.setPosition(window->getView().getCenter());
    smallest_screen.setOrigin(smallest_screen.getSize().x * 0.5, smallest_screen.getSize().y * 0.5);
    smallest_screen.setFillColor(sf::Color(251, 251, 251, 64));
    
    
    // Boton volver
    sf::Vector2f topLeftOfWindow = window->getView().getCenter() - window->getView().getSize() / 2.f;
    sf::Vector2f downLeftOfWindow(0, window->getView().getSize().y);

    boton.setPoint(0, downLeftOfWindow);
    boton.setPoint(1, sf::Vector2f(downLeftOfWindow.x + 100, downLeftOfWindow.y - 50));
    boton.setPoint(2, sf::Vector2f(downLeftOfWindow.x + 100, downLeftOfWindow.y - 25));
    boton.setPoint(3, sf::Vector2f(downLeftOfWindow.x + 200, downLeftOfWindow.y - 25));
    boton.setPoint(4, sf::Vector2f(downLeftOfWindow.x + 200, downLeftOfWindow.y + 25));
    boton.setPoint(5, sf::Vector2f(downLeftOfWindow.x + 100, downLeftOfWindow.y + 25));
    boton.setPoint(6, sf::Vector2f(downLeftOfWindow.x + 100, downLeftOfWindow.y + 50));
    
    boton.setFillColor(sf::Color(248, 180, 134, 250));
    
    boton.setOrigin(-50, 75);
}

sf::RectangleShape * menu::getLevelRec() {
    return level_rec;
}

void menu::render() {
    window->draw(rec);
    
    if(num_menu == 1) {
        window->draw(principal_rec);
    } else if(num_menu == 2){
        for(int i = 0; i < 3; i++) {
            window->draw(level_rec[i]);
            
        }
        
        window->draw(boton);
    } else if(num_menu == 3) {
        window->draw(ajustes_rec);
        
        window->draw(boton);
    } else {
        // Nada
    }
    
    window->draw(smallest_screen);
}

menu::~menu() {
//    delete level_rec[i];
}
