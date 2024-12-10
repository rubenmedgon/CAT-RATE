#include "Ventana.hpp"

Ventana::Ventana(const string& title, int width, int height, const string& route)
    : window(VideoMode(width, height), title){
        if(!texturaFondo.loadFromFile(route)) cout<<"Error al cargar textura";
        fondo.setTexture(texturaFondo);
}

RenderWindow& Ventana::obtenerVentana(){
    return window;
}

void Ventana::dibujar(Drawable& elemento){
    window.draw(elemento);
}

void Ventana::limpiar(){
    window.clear();
    window.draw(fondo);
}

void Ventana::mostrar(){
    window.display();
}
