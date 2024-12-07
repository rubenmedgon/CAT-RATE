#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Interfaz : public Drawable{
    private:
        int puntos=0;
        int descubiertas=0;
        Font font;
        Text puntosText;
        Text descubiertasText;
        Text resultadoText;
    public:
        Interfaz();
        void Update();
        void CambiarPuntaje(int mod);
        void CambiarDescubiertas(int mod);
        int ConsultarDescubiertas();
        virtual void draw(RenderTarget &rt, RenderStates rs) const;
}