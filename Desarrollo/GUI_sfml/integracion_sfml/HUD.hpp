//
//  HUD.hpp
//  integracion_sfml
//
//  Created by Catherine Castrillo González on 17/01/17.
//  Copyright © 2017 Catherine Castrillo González. All rights reserved.
//

#ifndef HUD_hpp
#define HUD_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class HUD {
public:
    HUD();
    virtual ~HUD();
    void set_HUD(std::string string, float x, float y, sf::Color color);
    void set_size(int size);
    void set_string(std::string string);
    void set_font();
    
private:
    sf::Font *fuente;
    sf::Text *texto;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif /* HUD_hpp */
