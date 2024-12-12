#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Onomatopeya : public Drawable {
    private:
        Texture texture;
        Sprite sprite3;
        bool descubierta = false;
        int tipo;
    public:
        Onomatopeya(int tip, int x, int y);
        void DarTextura(Texture tex);
        void BloquearSprite();
        void DesbloquearSprite();
        int ConsultarTipo();
        bool ConsultarEstado();
        void Descubrir();
        virtual void draw(RenderTarget& rt, RenderStates rs) const;
};