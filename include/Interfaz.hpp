#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Interfaz : public Drawable{
    private:
        int fuego1 = 0, agua1 = 0, planta1 = 0;
        int fuego2 = 0, agua2 = 0, planta2 = 0;
        int ronda = 1;

        Font font;
        Text fuego1Text, agua1Text, planta1Text;
        Text fuego2Text, agua2Text, planta2Text;

        Text resultadoText, rondaText;

        RectangleShape pantallaNegra;
        bool mostrarPantallaNegra = false;

    public:
        Interfaz();
        void Update();
        void CambiarFuego1(int mod);
        void CambiarAgua1(int mod);
        void CambiarPlanta1(int mod);
        int ConsultarFuego1();
        int ConsultarAgua1();
        int ConsultarPlanta1();

        void CambiarFuego2(int mod);
        void CambiarAgua2(int mod);
        void CambiarPlanta2(int mod);
        int ConsultarFuego2();
        int ConsultarAgua2();
        int ConsultarPlanta2();

        void CambiarRonda(int crum);
        int ConsultarRonda();
        virtual void draw(RenderTarget &rt, RenderStates rs) const;
};