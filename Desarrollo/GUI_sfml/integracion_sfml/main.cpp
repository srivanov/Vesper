
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "menu.hpp"

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    // Activo el antialiasing de forma global para que el boton de volver, p.e. no se vea mal
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Integracion SFML", sf::Style::Fullscreen, settings);
//    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Integracion SFML");
    
    menu menu;
    menu.window = &window;
    
    // Start the game loop
    while (window.isOpen())
    {
        menu.update();

        // Clear screen
        window.clear();
        menu.render();
        window.display();
    }

    return EXIT_SUCCESS;
}
