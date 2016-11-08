
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

inputSFML::~inputSFML(){
    delete pinstance;
}
