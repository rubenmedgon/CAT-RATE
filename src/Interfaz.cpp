#include "Interfaz.hpp"

Interfaz::Interfaz(){
    if(!font.loadFromFile("Blabla.tff")) cout<<"Error al cargar fuente"<<endl;
    puntosText.setFont(font);
    descubiertasText.setFont(font);
    resultadoText.setFont(font);
}