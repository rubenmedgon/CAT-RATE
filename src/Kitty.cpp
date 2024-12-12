#include "Kitty.hpp"


    sf::RenderWindow window(sf::VideoMode(800, 600), "DinoChrome");

    Kitty Izquierdo(sf::Vector2f(400, 300));

        // Actualizar animacion gatico
        Izquierdo.updateK();
        Izquierdo.draw(window);
    }

