#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Arma : public Drawable {
    private:
        Texture texture;
        Sprite sprite2;
        bool descubierta = false;
        int tipo;
    public:
        Arma(int tip, int x, int y);
        void DarTextura(Texture tex);
        void BloquearSprite();
        void DesbloquearSprite();
        int ConsultarTipo();
        bool ConsultarEstado();
        void Descubrir();
        virtual void draw(RenderTarget& rt, RenderStates rs) const;
};