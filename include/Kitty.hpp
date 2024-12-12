#include <iostream>
#include <SFML/Graphics.hpp>

class Kitty
{
private:
    Sprite sprite4;
    Texture texture;
    Clock clock;
    float frameTime = 0.1f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 4; 
    int frameWidth = 100;
    int frameHeight = 100;


public:
    Kitty(sf::Vector2f position);

    void move(float offsetX, float offsetY);
    void draw(sf::RenderWindow &window);
    void updateK();

};
extern double velocidad;