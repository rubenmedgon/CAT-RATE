#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h> 
#include <thread>
#include <chrono>
#include "Ficha.hpp"
#include "Interfaz.hpp"
#include "Ventana.hpp"
#include "Arma.hpp"
#include "Onomatopeya.hpp"
#include "Animacion.hpp"

using namespace std;
using namespace sf;

void cargarTexturas(vector<Texture> &textures) {
    for (int i = 1; i <= 3; i++) {
        if (!textures[i - 1].loadFromFile("./assets/" + to_string(i) + ".png")) {
            cerr << "Error al cargar la textura " << i << endl;
        }
    }
}

//CargarArmas
Arma cargarArma(int tipoArchivo, int x, int y){
    Texture texture;
    if(!texture.loadFromFile("./assets/" + to_string(tipoArchivo) + ".png")) {
        cout << "Error al cargar el arma" << endl;
    }
    Arma objeto(4, x, y);
    objeto.DarTextura(texture);
    objeto.DesbloquearSprite();
    return objeto;
}

//CargarOnomaptopeyas
Onomatopeya CargarOnomaptopeya(int tipoArchivo, int x, int y){
    Texture texture;
    if(!texture.loadFromFile("./assets/" + to_string(tipoArchivo) + ".png")) {
        cout << "Error al cargar el arma" << endl;
    }
    Onomatopeya palabra(7, x, y);
    palabra.DarTextura(texture);
    palabra.DesbloquearSprite();
    return palabra;
}

double velocidad = 0.1;

int main(){
    //Ventana c/fondo
    Ventana ventana("CAT-RATE", 1080, 900, "./assets/Salon.png");

    Animacion animacion("./assets/G_SI.png", 4, 0.1f, 225, 220);
    animacion.setPosition(200, 470);

    Animacion animacion2("./assets/G_SD.png", 4, 0.1f, 225, 220);
    animacion2.setPosition(680, 470);

    //Cargar Fichas
    vector<Texture> textures(3);
    cargarTexturas(textures);

    //Fichas Jugadores
    vector<vector<Ficha>> fichas_jugador1(1,vector<Ficha>(3,Ficha(0,0,0)));
    vector<vector<Ficha>> fichas_jugador2(1,vector<Ficha>(3,Ficha(0,0,0)));

    for (int j = 0; j < 3; j++) {
        fichas_jugador1[0][j] = Ficha(j+1, 150*j+(j+3)*10, 740); // Tipos: 1, 2, 3
        fichas_jugador1[0][j].AsignarTextura(textures[j]);
        fichas_jugador1[0][j].DesbloquearSprite();

        fichas_jugador2[0][j] = Ficha(j+1, 1080-(150*(3-j))-(10*(3-j)), 740); 
        fichas_jugador2[0][j].AsignarTextura(textures[j]);
        fichas_jugador2[0][j].DesbloquearSprite();
    }
 
    //Click(Auxiliar)
    int cantBloqueada=0;
    int turno=1;
    int tipoCarta1 = -1; 
    int tipoCarta2 = -1;

    //Interfaz
    Interfaz interfaz;

    //Armas------------------------------------(acomodar píxeles de salida)
    // Globos
    Arma globo1 = cargarArma(4, 180, 100);
    Arma globo2 = cargarArma(4, 1080-480, 100);

    // Salsas
    Arma salsa1 = cargarArma(5, 80, 100);
    Arma salsa2 = cargarArma(5, 1080-480, 100);

    // Macetas
    Arma maceta1 = cargarArma(6, 180, 100);
    Arma maceta2 = cargarArma(6, 1080-480, 100);

    //Onomatopeyas------------------------------------(acomodar píxeles de salida)
    // Globos
    Onomatopeya splash1 = CargarOnomaptopeya(7, 180, 300);
    Onomatopeya splash2 = CargarOnomaptopeya(7, 1080-480, 300);    

    // Salsas
    Onomatopeya foom1 = CargarOnomaptopeya(8, 180, 300);
    Onomatopeya foom2 = CargarOnomaptopeya(8, 1080-480, 300);    

    // Macetas
    Onomatopeya crack1 = CargarOnomaptopeya(9, 180, 300);
    Onomatopeya crack2 = CargarOnomaptopeya(9, 1080-480, 300);  
    
    //Ciclo Principal------------------------------------------------
    while(ventana.obtenerVentana().isOpen()){
        Event event;
        while (ventana.obtenerVentana().pollEvent(event)){
            if (event.type == Event::Closed){
                ventana.obtenerVentana().close();
            }

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left){
                if (turno == 1){
                    for (int j = 0; j < 3; j++){
                        IntRect rect(150 * j + (j + 3) * 10, 740, 150, 150);
                        if (rect.contains(event.mouseButton.x, event.mouseButton.y)){
                            fichas_jugador1[0][j].BloquearSprite();
                            tipoCarta1 = fichas_jugador1[0][j].ConsultarTipo(); // Registra el tipo de carta
                            
                            
                            for (int k = 0; k < 3; k++) {
                                if (k != j) {
                                    fichas_jugador1[0][k].BloquearSprite();
                                }
                            }
                            turno = 2; // Cambiar al turno del jugador 2
                            break; // Salir del bucle después de seleccionar una carta
                        }
                    }
                } else if (turno == 2){
                    for (int j = 0; j < 3; j++){
                        IntRect rect(1080 - (150 * (3 - j)) - (10 * (3 - j)), 740, 150, 150);
                        if (rect.contains(event.mouseButton.x, event.mouseButton.y)){
                            tipoCarta2 = fichas_jugador2[0][j].ConsultarTipo(); // Registrar el tipo de carta

                        // Comparar las cartas seleccionadas 1=agua 2=fuego 3=planta
                        if(tipoCarta1 == 1 && tipoCarta2 == 2){
                            interfaz.CambiarAgua1(+1);
                            ventana.dibujar(interfaz);
                            ventana.dibujar(globo2);
                            ventana.mostrar();
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                            ventana.dibujar(interfaz);
                            ventana.dibujar(splash2);
                            ventana.mostrar();
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                        }
                        if(tipoCarta1 == 1 && tipoCarta2 == 3){
                            interfaz.CambiarPlanta2(+1);
                            ventana.dibujar(interfaz);
                            ventana.dibujar(maceta1);
                            ventana.mostrar();
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                            ventana.dibujar(interfaz);
                            ventana.dibujar(crack1);
                            ventana.mostrar();
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                        }
                        if(tipoCarta1 == 2 && tipoCarta2 == 1){
                            interfaz.CambiarAgua2(+1);
                            ventana.dibujar(interfaz);
                            ventana.dibujar(globo1);
                            ventana.mostrar();
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                            ventana.dibujar(interfaz);
                            ventana.dibujar(splash1);
                            ventana.mostrar();
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                        }
                        if(tipoCarta1 == 3 && tipoCarta2 == 1){
                            interfaz.CambiarPlanta1(+1);
                            ventana.dibujar(interfaz);
                            ventana.dibujar(maceta2);
                            ventana.mostrar();
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                            ventana.dibujar(interfaz);
                            ventana.dibujar(crack2);
                            ventana.mostrar();
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                        }
                        if(tipoCarta1 == 2 && tipoCarta2 == 3){
                            interfaz.CambiarFuego1(+1);
                            ventana.dibujar(interfaz);
                            ventana.dibujar(salsa2);
                            ventana.mostrar();
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                            ventana.dibujar(interfaz);
                            ventana.dibujar(foom2);
                            ventana.mostrar();
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                        }
                        if(tipoCarta1 == 3 && tipoCarta2 == 2){
                            interfaz.CambiarFuego2(+1);
                            ventana.dibujar(interfaz);
                            ventana.dibujar(salsa1);
                            ventana.mostrar();
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                            ventana.dibujar(interfaz);
                            ventana.dibujar(foom1);
                            ventana.mostrar();
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                        }

                        for (int i = 0; i < 3; i++){
                            fichas_jugador1[0][i].DesbloquearSprite();
                        }

                        // Finalizar ronda
                        turno = 1; // Reiniciar al turno del jugador 1
                        interfaz.CambiarRonda(1);
                        break; // Salir del bucle
                        }
                    }
                }
            }
        }

        animacion.update();
        animacion2.update();

        ventana.limpiar();
        for (int j = 0; j < 3; j++) {
            ventana.dibujar(fichas_jugador1[0][j]);
            ventana.dibujar(fichas_jugador2[0][j]);
        }

        //Actualizar interfaz
        interfaz.Update();

        ventana.dibujar(animacion);
        ventana.dibujar(animacion2);
        ventana.dibujar(interfaz);

        ventana.mostrar();
    }
    return 0;
}
