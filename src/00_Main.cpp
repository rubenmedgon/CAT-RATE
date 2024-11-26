#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h> 
#include "../include/Ficha.hpp"

using namespace std;
using namespace sf;

int main(){
    //Ventana
    RenderWindow window(VideoMode(1080,900),"Jodo");
    //Fondo
    Texture texture;
    if(!texture.loadFromFile("./assets/Salon.png")){
        return -1;
    }
    Sprite sprite(texture);
    //Fichas
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
            ficha[i][j]=Ficha(tipoRandom,200*j+(j+1)*10,200*i+(i+1)*10);
            ficha[i][j].AsignarTextura(textures[tipoRandom-1]);
            ficha[i][j].BloquearSprite();
        }
    }

    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed) window.close();
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