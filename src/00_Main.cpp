#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h> 
#include "../include/Ficha.hpp"

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

    int tipoRandom;

    srand(time(NULL));
    for(int j=0; j<3; j++){
        tipoRandom=1+(rand()%3);
        fichas_jugador1[0][j]=Ficha(tipoRandom,150*j+(j+3)*10,740);
        fichas_jugador1[0][j].AsignarTextura(textures[tipoRandom-1]);
        fichas_jugador1[0][j].BloquearSprite();

        tipoRandom=1+(rand()%3);
        fichas_jugador2[0][j]=Ficha(tipoRandom,1080-(150*(3-j))-(10*(3-j)),740);
        fichas_jugador2[0][j].AsignarTextura(textures[tipoRandom-1]);
        fichas_jugador2[0][j].BloquearSprite();
    }

    //Click(Auxiliar)
    int cantDesbloqueada=0;
    int iAnt, jAnt;

    //Turno & Espera
    int turno=1;
    Clock clock;
    Time time;
    
    //Ciclo Principal
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed) window.close();
            
            if(event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left && cantDesbloqueada<3){
                if (turno==1){
                    for(int j=0; j<3; j++){
                        IntRect rect(150*j+(j+3)*10,740,150,150);
                        if(rect.contains(event.mouseButton.x,event.mouseButton.y)){
                            fichas_jugador1[0][j].DesbloquearSprite();
                        }
                    }
                }else if(turno==2){
                    for(int j=0; j<3; j++){
                        IntRect rect(1080-(150*(3-j))-(10*(3-j)),740,150,150);
                        if(rect.contains(event.mouseButton.x,event.mouseButton.y)){
                            fichas_jugador2[0][j].DesbloquearSprite();
                        }
                    }
                }
                clock.restart();
            }
        }

        //Bloquear Fichas Desbloquadas
        if((time=clock.getElapsedTime())>=seconds(3)){
            if (turno==1){
                for(int j=0; j<3; j++){
                    fichas_jugador1[0][j].BloquearSprite();
                }
                turno=2;
                clock.restart();
            }else if(turno==2){
                for(int j=0; j<3; j++){
                    fichas_jugador2[0][j].BloquearSprite();
                }
                turno=1;
                clock.restart();
            }
        }
          
        window.clear();
        window.draw(sprite);
        for(int j=0; j<3; j++){
            window.draw(fichas_jugador1[0][j]);
            window.draw(fichas_jugador2[0][j]);
        }
        window.display();
    }
    return 0;
}