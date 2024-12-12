#include <iostream>
#include <SFML/Graphics.hpp>

class Fire : public Drawable{
    private:
        Texture texture,textureBlock;
        Sprite sprite;
        bool descubierta=false;
        int tipo;
    public:
        void AsignarTextura(Texture tex);
        void BloquearSprite();
        void DesbloquearSprite();
        int ConsultarTipo();
        bool ConsultarEstado();
        void Descubrir();
        virtual void draw(RenderTarget& rt,RenderStates rs) const;