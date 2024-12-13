#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Arma : public Drawable {
    private:
        Texture texture;
        Sprite sprite2;
        int tipo;
    public:
        Arma(int tip, int x, int y);
        void DarTextura(Texture tex);
        void DesbloquearSprite();
        virtual void draw(RenderTarget& rt, RenderStates rs) const;
};