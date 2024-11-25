#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main(){
    RenderWindow window(VideoMode(850,750),"Memotest");
    
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed) window.close();
        }
        window.clear();
        window.display();
    }
    return 0;
}