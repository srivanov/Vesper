//
//  HUD.cpp
//  integracion_sfml
//
//  Created by Catherine Castrillo González on 17/01/17.
//  Copyright © 2017 Catherine Castrillo González. All rights reserved.
//

#include "HUD.hpp"

HUD::HUD() {
    fuente = new sf::Font;
    texto = new sf::Text;
}

void HUD::set_size(int size) {
    texto->setCharacterSize(size);
}

void HUD::set_string(std::string string) {
    texto->setString(string);
}

void HUD::set_HUD(std::string string, float x, float y, sf::Color color) {
    texto->setPosition(x, y);
    texto->setString(string);
    texto->setColor(color);
}

void HUD::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*texto, states);
}

void HUD::set_font() {
    fuente->loadFromFile("Resources/sansation.ttf");
    texto->setFont(*fuente);
}

HUD::~HUD() {
    delete fuente;
    delete texto;
}
