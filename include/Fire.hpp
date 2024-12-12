#include <iostream>
#include <SFML/Graphics.hpp>

class Fire : public Drawable{
    private:
        Texture texture,textureBlock;
        Sprite sprite;
        bool descubierta=false;
        int tipo;
    public:
        Fire(int a, int b)
        void AsignarTextura(Texture tex);
        void AparecerFire();
        void DesaparecerFire();
        void AparecerFOOM();
        void DesaparecerFOOM();
        virtual void draw(RenderTarget& rt,RenderStates rs) const;