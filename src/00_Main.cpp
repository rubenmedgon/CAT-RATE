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

    //Textura Fichas
    vector<Texture> textures(2);
    for(int i=1; i<=2; i++){
        if(!textures[i-1].loadFromFile("./assets/"+to_string(i)+".png")) cout<<"Error al cargar la textura "<<i<<endl;
    }
    vector<vector<Ficha>> ficha(1,vector<Ficha>(3,Ficha(0,0,0)));
    vector<int> cantApariciones(2,0);
    int tipoRandom;

    srand(time(NULL));
    for(int i=0; i<1; i++){
        for(int j=0; j<3; j++){
            do{
            tipoRandom=1+(rand()%2);
            }while(cantApariciones[tipoRandom-1]==2);
            cantApariciones[tipoRandom-1]++;
            ficha[i][j]=Ficha(tipoRandom,150*j+(j+1)*10,900-160);
            ficha[i][j].AsignarTextura(textures[tipoRandom-1]);
            ficha[i][j].BloquearSprite();
        }
    }

    //Click(Auxiliar)
    int cantDesbloqueada=0;
    int iAnt, jAnt;
    //Espera
    Clock clock;
    Time time;
    
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed) window.close();
            if(event.type==Event::MouseButtonPressed && event.mouseButton.button==Mouse::Left && cantDesbloqueada<3){
                for(int i=0; i<1; i++){
                    for(int j=0; j<3; j++){
                        IntRect rect(150*j+(j+1)*10,900-160,150,150);
                        if(rect.contains(event.mouseButton.x,event.mouseButton.y)){
                            ficha[i][j].DesbloquearSprite();
                            if(cantDesbloqueada==0) iAnt=i,jAnt=j,cantDesbloqueada++;
                            else if(ficha[i][j].ConsultarTipo()==ficha[iAnt][jAnt].ConsultarTipo()){
                                ficha[i][j].Descubrir();
                                ficha[iAnt][jAnt].Descubrir();
                                cantDesbloqueada=0;
                            }else{
                                cantDesbloqueada++;
                                clock.restart();
                            }
                        }
                    }
                }
            }
        }

        //Bloquear Fichas Desbloquadas
        if(cantDesbloqueada==2 && (time=clock.getElapsedTime())>=seconds(5)){
            for(int i=0; i<1; i++){
                for(int j=0; j<3; j++){
                    if(!ficha[i][j].ConsultarEstado()) ficha[i][j].BloquearSprite();
                }
            }
            cantDesbloqueada=0;
        }

        window.clear();
        window.draw(sprite);
        for(int i=0; i<1; i++){
            for(int j=0; j<3; j++){
                window.draw(ficha[i][j]);
            }
        }
        window.display();
    }
    return 0;
}