#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h> 
#include "../include/Ficha.hpp"
#include "../include/Interfaz.hpp"

using namespace std;
using namespace sf;

int main(){
    //Ventana
    RenderWindow window(VideoMode(1080,900),"CAT-RATE");

    //Fondo
    Texture texture;
    if(!texture.loadFromFile("./assets/Salon.png")){
        return -1;
    }
    Sprite sprite(texture);

    //Cargar Fichas
    vector<Texture> textures(3);
    for(int i=1; i<=3; i++){
        if(!textures[i-1].loadFromFile("./assets/"+to_string(i)+".png")) cout<<"Error al cargar la textura "<<i<<endl;
    }

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

    //Ciclo Principal
    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed){
                window.close();
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
                        }
                        if(tipoCarta1 == 1 && tipoCarta2 == 3){
                            interfaz.CambiarPlanta2(+1);
                        }
                        if(tipoCarta1 == 2 && tipoCarta2 == 1){
                            interfaz.CambiarAgua2(+1);
                        }
                        if(tipoCarta1 == 3 && tipoCarta2 == 1){
                            interfaz.CambiarPlanta1(+1);
                        }
                        if(tipoCarta1 == 2 && tipoCarta2 == 3){
                            interfaz.CambiarFuego1(+1);
                        }
                        if(tipoCarta1 == 3 && tipoCarta2 == 2){
                            interfaz.CambiarFuego2(+1);
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

        window.clear();
        window.draw(sprite);
        for (int j = 0; j < 3; j++) {
            window.draw(fichas_jugador1[0][j]);
            window.draw(fichas_jugador2[0][j]);
        }
        
        //Actualizar interfaz
        interfaz.Update();

        window.draw(interfaz);
        window.display();
    }
    return 0;
}
