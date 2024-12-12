#include "Onomatopeya.hpp"

Onomatopeya::Onomatopeya(int tip, int x, int y){
   tipo = tip;
   sprite3.setPosition(x, y);
   //if(!textureBlock.loadFromFile("./assets/Candado.png")) cout << "Error al cargar textura Block";
}

void Onomatopeya::DarTextura(Texture tex){
    texture = tex;
}
/*
void Onomatopeya::BloquearSprite(){
    sprite3.setTexture(textureBlock);
}
*/

void Onomatopeya::DesbloquearSprite(){
    sprite3.setTexture(texture);
}

int Onomatopeya::ConsultarTipo(){
    return tipo;
}

bool Onomatopeya::ConsultarEstado(){
    return descubierta;
}

void Onomatopeya::Descubrir(){
    descubierta = true;
}

void Onomatopeya::draw(RenderTarget& rt, RenderStates rs) const{
    rt.draw(sprite3, rs);
}