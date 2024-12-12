#include "Fire.hpp"

Fire::Fire( int x, int y){
   sprite.setPosition(x,y);
   if(!textureBlock.loadFromFile("./assets/picante.png")) cout<<"Error al cargar textura Block";
}


void Fire::AsignarTextura(Texture tex){
    texture=tex;
}

void AparecerFire(int a, int b){
    int i, a=x, b=y;
    for (i=0; i<6; i++)
    {
        Fire( x, y + (i*50)); 
    }
    Fire.AparecerFOOM();
}
        
void AparecerFOOM(){
    if(!textureBlock.loadFromFile("./assets/FOOM.png")) cout<<"Error al cargar textura Block";
}

void Fire::BloquearSprite(){
    sprite.setTexture(textureBlock);
}

void Fire::DesbloquearSprite(){
    sprite.setTexture(texture);
}


void Fire::draw(RenderTarget& rt,RenderStates rs) const{
    rt.draw(sprite,rs);
}