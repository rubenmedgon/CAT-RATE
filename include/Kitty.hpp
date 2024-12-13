#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Kitty : public sf::Drawable {
    public:
    Kitty(sf::Vector2f position);
    void move(float offsetX, float offsetY);
    void updateK();

    private:
        RectangleShape shape;
        Sprite sprite4;
        Texture texture;
        Clock clock;
        float frameTime = 0.1f; // Tiempo entre cada frame en segundos
        int currentFrame = 0;
        int numFrames = 4; 
        int frameWidth = 100;
        int frameHeight = 100;
    
    // Implement the pure virtual draw method from sf::Drawable
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};