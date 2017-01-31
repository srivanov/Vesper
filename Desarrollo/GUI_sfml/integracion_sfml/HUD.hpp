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
private:
    HUD();
    virtual ~HUD();
    void set_hud();
    
public:
    sf::RectangleShape contenedor_nivel_vida;
    sf::RectangleShape nivel_vida;
    sf::RectangleShape contenedor_modedas;
    sf::RectangleShape monedas;
    sf::RectangleShape llaves;
    
};

#endif /* HUD_hpp */
