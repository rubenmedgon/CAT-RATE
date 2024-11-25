#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>
#include "../include/Ficha.hpp"

using namespace std;
using namespace sf;

int main(){
    //Ventana
    RenderWindow window(VideoMode(2000,900),"Jodo");
    //Fondo
    Texture texture;
    if(!texture.loadFromFile("./assets/Salon.png")){
        return -1;
    }
    Sprite sprite(texture);
    //Fichas
    vector<Texture> textures(2);
    for(int i=1; i<=2; i++){
        if(!textures[i-1].loadFromFile(to_string(i)+".png")){
        return -1;
        }
    }
    vector<vector<Ficha>> ficha(1,vector<Ficha>(4,Ficha(0,0,0)));
    vector<int> cantApariciones(6,0);
    int tipoRandom;

    srand(time(NULL));
    for(int j=0; j<4; j++){
        do{
            tipoRandom=1+rand()%6;
        }while(cantApariciones[tipoRandom-1]==2);
        cantApariciones[tipoRandom-1]++;
    }
    
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed) window.close();
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}