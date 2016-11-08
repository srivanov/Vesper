
#ifndef inputSFML_hpp
#define inputSFML_hpp

#include <stdio.h>
#include <SFML/Window.hpp>

class inputSFML{
    public:
        inputSFML();
        static inputSFML* Instance();
        virtual ~inputSFML();
        bool isKeyPressed(uint i);
    private:
        static inputSFML* pinstance;
};

#endif /* inputSFML_hpp */
