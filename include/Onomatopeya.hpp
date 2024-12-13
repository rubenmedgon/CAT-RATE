#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Onomatopeya : public Drawable {
    private:
        Texture texture;
        Sprite sprite3;
        int tipo;
    public:
        Onomatopeya(int tip, int x, int y);
        void darTextura(Texture tex);
        void desbloquearSprite();
        virtual void draw(RenderTarget& rt, RenderStates rs) const;
};