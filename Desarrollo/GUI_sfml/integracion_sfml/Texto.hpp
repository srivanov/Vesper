//
//  Texto.hpp
//  integracion_sfml
//
//  Created by Catherine Castrillo González on 29/01/17.
//  Copyright © 2017 Catherine Castrillo González. All rights reserved.
//

#ifndef Texto_hpp
#define Texto_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Texto {
public:
    Texto();
    ~Texto();
    void set_texto(std::string string, float x, float y, sf::Color color);
    void set_size(int size);
    void set_string(std::string string);
    void set_font(std::string name);
    sf::Vector2f get_size();
    void set_origin(float x, float y);
    void draw(sf::RenderTarget& target);
    
private:
    sf::Font fuente;
    sf::Text texto;
};

#endif /* Texto_hpp */
