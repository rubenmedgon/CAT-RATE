#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Ventana{
    private:
        RenderWindow window;
        Sprite fondo;
        Texture texturaFondo;
    public:
    Ventana(const string& title, int width, int height, const string& route);
    RenderWindow& obtenerVentana();
    void dibujar(Drawable& elemento);
    void limpiar();
    void mostrar();
};