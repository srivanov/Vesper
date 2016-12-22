
#include "inputSFML.hpp"


inputSFML* inputSFML::pinstance = 0;

inputSFML* inputSFML::Instance(){
    
    if(pinstance == 0){ //si no se ha creado nunca, entra y la crea
        pinstance = new inputSFML();
        
    }
    return pinstance; //la devuelve
}

inputSFML::inputSFML(){
    
}

bool inputSFML::isKeyPressed(uint i){
    if(sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i)){
        return true;
    }
    return false;
}
bool inputSFML::mandoON(){
	for (int i= 0; i<sf::Joystick::Count; i++) {
		if(sf::Joystick::isConnected(i))
			return true;
		}
	return false;
}

int* inputSFML::posicionRaton(){
    int pos[2];
    pos[0] = sf::Mouse::getPosition().x;
    pos[1] = sf::Mouse::getPosition().y;
    return pos;
}

inputSFML::~inputSFML(){
    delete pinstance;
}
