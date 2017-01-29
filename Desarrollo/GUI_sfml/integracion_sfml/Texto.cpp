//
//  Texto.cpp
//  integracion_sfml
//
//  Created by Catherine Castrillo González on 29/01/17.
//  Copyright © 2017 Catherine Castrillo González. All rights reserved.
//

#include "Texto.hpp"

Texto::Texto() {
    fuente.loadFromFile("../img_menu/sansation.ttf");
    texto.setFont(fuente);
}

void Texto::set_size(int size) {
    texto.setCharacterSize(size);
}

void Texto::set_string(std::string string) {
    texto.setString(string);
}

void Texto::set_texto(std::string string, float x, float y, sf::Color color) {
    texto.setString(string);
    texto.setPosition(x, y);
    texto.setColor(color);
}

void Texto::draw(sf::RenderTarget &target) {
    target.draw(texto);
}

void Texto::set_font(std::string name) {
    fuente.loadFromFile("../font/" + name);
    texto.setFont(fuente);
}

void Texto::set_origin(float x, float y) {
    texto.setOrigin(x, y);
}

sf::Vector2f Texto::get_size() {
    return sf::Vector2f(texto.getGlobalBounds().width, texto.getGlobalBounds().height);
}

Texto::~Texto() {
    
}
