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
        void update();
        void cambiarFuego1(int mod);
        void cambiarAgua1(int mod);
        void cambiarPlanta1(int mod);
        int consultarFuego1();
        int consultarAgua1();
        int consultarPlanta1();

        void cambiarFuego2(int mod);
        void cambiarAgua2(int mod);
        void cambiarPlanta2(int mod);
        int consultarFuego2();
        int consultarAgua2();
        int consultarPlanta2();

        void cambiarRonda(int crum);
        int consultarRonda();
        virtual void draw(RenderTarget &rt, RenderStates rs) const;
};