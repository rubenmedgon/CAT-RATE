#include <iostream>
#include <SFML/Graphics.hpp>

class Fire : public Drawable{
    private:
        Texture texture,textureBlock;
        Sprite sprite;
        bool descubierta=false;
        int tipo;
    public:
        