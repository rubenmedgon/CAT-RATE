#include "Ficha.hpp"

Ficha::Ficha(int tip, int x, int y){
   tipo=tip;
   sprite.setPosition(x,y);
   if(!textureBlock.loadFromFile("./assets/Candado.png")) cout<<"Error al cargar textura Block";
}

void Ficha::asignarTextura(Texture tex){
    texture=tex;
}

void Ficha::bloquearSprite(){
    sprite.setTexture(textureBlock);
}

void Ficha::desbloquearSprite(){
    sprite.setTexture(texture);
}

int Ficha::consultarTipo(){
    return tipo;
}

bool Ficha::consultarEstado(){
    return descubierta;
}

void Ficha::descubrir(){
    descubierta=true;
}

void Ficha::draw(RenderTarget& rt,RenderStates rs) const{
    rt.draw(sprite,rs);
}