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
    textura.loadFromFile("../img_menu/menu_principal_03.png");
    rec.setTexture(&textura);
    
    // Rectangulo para el menu principal
    principal_botones = new sf::RectangleShape [5];
    
    // Rectangulos para los niveles
    level_rec = new sf::RectangleShape [3];
    levels_tex = new sf::Texture [3];
    
    rec_img_levels = new sf::RectangleShape [3];
    
    // Rectangulos para ajuster
    ajustes_botones = new sf::RectangleShape [3];
    
    // Boton volver
    boton.setPointCount(7);
    
    // Textos
    principal_textos = new Texto [5];
    ajustes_textos = new Texto [3];
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
        
        sf::Vector2f size_rec(375, 350);
        sf::Vector2f size_botones(325, 40);
        
        principal_rec.setSize(size_rec);
        principal_rec.setPosition(centerOfWindow);
        principal_rec.setOrigin(principal_rec.getSize().x * 0.5, principal_rec.getSize().y * 0.25);
        principal_rec.setFillColor(sf::Color(248, 180, 134, 128));
        principal_rec.setOutlineColor(sf::Color(86, 143, 107, 128));
        principal_rec.setOutlineThickness(10);
        
        for(int i = 0; i < 5; i++) {
            principal_botones[i].setSize(size_botones);
            principal_botones[i].setPosition(principal_rec.getPosition());
            principal_botones[i].setOrigin(principal_rec.getOrigin().x - 25, principal_rec.getOrigin().y - 30);
            principal_botones[i].setFillColor(sf::Color(252, 204, 147));
            principal_botones[i].setOutlineColor(sf::Color(201, 170, 129));
            principal_botones[i].setOutlineThickness(2);
            
            if(i == 0) {
                principal_textos[i].set_texto("NUEVA PARTIDA", principal_botones[i].getPosition().x, principal_botones[i].getPosition().y, sf::Color::Black);
                principal_textos[i].set_origin(principal_botones[i].getOrigin().x - principal_textos[i].get_size().x * 0.2, principal_botones[i].getOrigin().y);
            }
            
            if(i == 1) {
                principal_botones[i].setOrigin(principal_rec.getOrigin().x - 25, principal_rec.getOrigin().y - 90);
                
                principal_textos[i].set_texto("CARGAR PARTIDA", principal_botones[i].getPosition().x, principal_botones[i].getPosition().y, sf::Color::Black);
                principal_textos[i].set_origin(principal_botones[i].getOrigin().x - principal_textos[i].get_size().x * 0.15, principal_botones[i].getOrigin().y);
            }
            
            if(i == 2) {
                principal_botones[i].setOrigin(principal_rec.getOrigin().x - 25, principal_rec.getOrigin().y - 150);
                
                principal_textos[i].set_texto("OPCIONES", principal_botones[i].getPosition().x, principal_botones[i].getPosition().y, sf::Color::Black);
                principal_textos[i].set_origin(principal_botones[i].getOrigin().x - principal_textos[i].get_size().x * 0.60, principal_botones[i].getOrigin().y);
            }
            
            if(i == 3) {
                principal_botones[i].setOrigin(principal_rec.getOrigin().x - 25, principal_rec.getOrigin().y - 210);
                
                principal_textos[i].set_texto("CREDITOS", principal_botones[i].getPosition().x, principal_botones[i].getPosition().y, sf::Color::Black);
                principal_textos[i].set_origin(principal_botones[i].getOrigin().x - principal_textos[i].get_size().x * 0.65, principal_botones[i].getOrigin().y);
            }

            if(i == 4) {
                principal_botones[i].setOrigin(principal_rec.getOrigin().x - 25, principal_rec.getOrigin().y - 270);
                
                principal_textos[i].set_texto("SALIR", principal_botones[i].getPosition().x, principal_botones[i].getPosition().y, sf::Color::Black);
                principal_textos[i].set_origin(principal_botones[i].getOrigin().x - 120, principal_botones[i].getOrigin().y);
            }
        }
        
        
    } else if(num_menu == 2) {
        level_nombre.set_texto("SELECCIONAR", centerOfWindow.x - level_nombre.get_size().x * 0.5, level_nombre.get_size().y, sf::Color::Black);
        level_nombre.set_size(50);
        
        textura.loadFromFile("../img_menu/cargarpartida.png");
        
        // Creo los rectangulos para los niveles que aparecen en esta pantalla
        sf::Vector2f size(230, 230);
        
        for(int i = 0; i < 3; i++) {
            level_rec[i].setSize(size);
            level_rec[i].setPosition(centerOfWindow);
            level_rec[i].setOrigin(level_rec[i].getSize().x * 0.5, level_rec[i].getSize().y * 0.5);
            level_rec[i].setFillColor(sf::Color(248, 180, 134, 128));
            level_rec[i].setOutlineColor(sf::Color(86, 143, 107, 128));
            level_rec[i].setOutlineThickness(10);
            
            // Inicializo los rectangulos que necesito para poder aplicarles la textura del livel correspondiente
            rec_img_levels[i].setSize(level_rec[i].getSize());
            rec_img_levels[i].setPosition(level_rec[i].getPosition());
            rec_img_levels[i].setOrigin(level_rec[i].getOrigin());
            
            if(i == 0) {
                level_rec[i].setPosition(level_rec[i].getPosition() - sf::Vector2f(level_rec[i].getSize().x + 40, 0));
                
                // Imagen nivel
                rec_img_levels[i].setPosition(level_rec[i].getPosition());
                levels_tex[i].loadFromFile("../img_menu/img1.png");
                rec_img_levels[i].setTexture(&levels_tex[i]);
            } else if(i ==1) {
                levels_tex[i].loadFromFile("../img_menu/img2.png");
                rec_img_levels[i].setTexture(&levels_tex[i]);
            } else if(i == 2) {
                level_rec[i].setPosition(level_rec[i].getPosition() + sf::Vector2f(level_rec[i].getSize().x + 40, 0));
                
                // Imagen
                rec_img_levels[i].setPosition(level_rec[i].getPosition());
                levels_tex[i].loadFromFile("../img_menu/img3.png");
                rec_img_levels[i].setTexture(&levels_tex[i]);
            }
            else {
                // Nada
            }
        }
    } else if(num_menu == 3) {
        ajustes_nombre.set_texto("AJUSTES", centerOfWindow.x - ajustes_nombre.get_size().x * 0.5, level_nombre.get_size().y, sf::Color::Black);
        ajustes_nombre.set_size(50);
        
        textura.loadFromFile("../img_menu/menuajustes.png");
        
        sf::Vector2f size_rec(375, 350);
        sf::Vector2f size_botones(325, 75);
        
        ajustes_rec.setSize(size_rec);
        ajustes_rec.setPosition(centerOfWindow);
        ajustes_rec.setOrigin(ajustes_rec.getSize().x * 0.02, ajustes_rec.getSize().y * 0.25);
        ajustes_rec.setFillColor(sf::Color(248, 180, 134, 128));
        ajustes_rec.setOutlineColor(sf::Color(86, 143, 107, 128));
        ajustes_rec.setOutlineThickness(10);
        
        for(int i = 0; i < 3; i++) {
            ajustes_botones[i].setSize(size_botones);
            ajustes_botones[i].setPosition(ajustes_rec.getPosition());
            ajustes_botones[i].setFillColor(sf::Color(252, 204, 147));
            ajustes_botones[i].setOutlineColor(sf::Color(201, 170, 129));
            ajustes_botones[i].setOutlineThickness(2);
            
            
            if(i == 0) {
                ajustes_botones[i].setOrigin(ajustes_rec.getOrigin().x - 25, ajustes_rec.getOrigin().y - 33);
                
                ajustes_textos[i].set_texto("CONTROLES", ajustes_botones[i].getPosition().x, ajustes_botones[i].getPosition().y, sf::Color::Black);
                
                ajustes_textos[i].set_origin(ajustes_botones[i].getOrigin().x  - principal_textos[i].get_size().x * 0.35, ajustes_botones[i].getOrigin().y  - principal_textos[i].get_size().y);
            } else if(i == 1) {
                ajustes_botones[i].setOrigin(ajustes_rec.getOrigin().x - 25, ajustes_rec.getOrigin().y - 133);
                
                ajustes_textos[i].set_texto("SONIDO", ajustes_botones[i].getPosition().x, ajustes_botones[i].getPosition().y, sf::Color::Black);
                
                ajustes_textos[i].set_origin(ajustes_botones[i].getOrigin().x - principal_textos[i].get_size().x * 0.45, ajustes_botones[i].getOrigin().y  - principal_textos[i].get_size().y);
            } else if(i == 2) {
                ajustes_botones[i].setOrigin(ajustes_rec.getOrigin().x - 25, ajustes_rec.getOrigin().y - 233);
                
                ajustes_textos[i].set_texto("PANTALLA", ajustes_botones[i].getPosition().x, ajustes_botones[i].getPosition().y, sf::Color::Black);

                
                ajustes_textos[i].set_origin(ajustes_botones[i].getOrigin().x - principal_textos[i].get_size().x * 0.60, ajustes_botones[i].getOrigin().y - principal_textos[i].get_size().y);
            } else {
                // Nada
            }
        }
    } else {
        // Nada
    }
    
    rec.setSize((sf::Vector2f)window->getSize());
    
    
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
    
    boton_texto.set_texto("VOLVER", boton.getPoint(0).x + boton_texto.get_size().x * 0.45, boton.getPoint(0).y - boton_texto.get_size().y, sf::Color::Black);
    boton_texto.set_origin(-50, 75);
}

void menu::render() {
    window->draw(rec);
    
    switch (num_menu) {
        case 1:
            window->draw(principal_rec);
            
            for(int i = 0; i < 5; i++) {
                window->draw(principal_botones[i]);
                
                principal_textos[i].draw(*window);
            }
            break;
            
        case 2:
            for(int i = 0; i < 3; i++) {
                window->draw(level_rec[i]);
                
                // Imagenes
                window->draw(rec_img_levels[i]);
            }
            
            level_nombre.draw(*window);
            window->draw(boton);
            boton_texto.draw(*window);
            break;
            
        case 3:
            window->draw(ajustes_rec);
            
            for(int i = 0; i < 3; i++) {
                window->draw(ajustes_botones[i]);
                
                ajustes_textos[i].draw(*window);
            }
            
            ajustes_nombre.draw(*window);
            window->draw(boton);
            boton_texto.draw(*window);
            break;
            
        default:
            break;
    }
}

menu::~menu() {
//    delete principal_textos;
//    delete principal_botones;
//    delete level_rec;
//    delete levels_tex;
//    delete rec_img_levels;
//    delete ajustes_botones;
//    delete ajustes_textos;
}
