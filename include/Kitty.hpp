#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Kitty : public Drawable {
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
    Kitty(Vector2f position);
    void move(float offsetX, float offsetY);
    void draw(RenderWindow &window);
    void updateK();

    //virtual void draw(RenderTarget& rt, RenderStates rs) const;

};
