#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main(){
    //Ventana
    RenderWindow window(VideoMode(850,750),"Jodo");
    //Fondo
    Texture texture;
    if(!texture.loadFromFile("./assets/Carta_01.png")){
        return -1;
    }
    
    Sprite sprite(texture);

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