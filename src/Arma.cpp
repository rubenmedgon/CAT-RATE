#include "Arma.hpp"

Arma::Arma(int tip, int x, int y){
   tipo = tip;
   sprite2.setPosition(x, y);
   //if(!textureBlock.loadFromFile("./assets/Candado.png")) cout << "Error al cargar textura Block";
}

void Arma::DarTextura(Texture tex){
    texture = tex;
}
/*
void Arma::BloquearSprite(){
    sprite2.setTexture(textureBlock);
}
*/

void Arma::DesbloquearSprite(){
    sprite2.setTexture(texture);
}

int Arma::ConsultarTipo(){
    return tipo;
}

bool Arma::ConsultarEstado(){
    return descubierta;
}

void Arma::Descubrir(){
    descubierta = true;
}

void Arma::draw(RenderTarget& rt, RenderStates rs) const{
    rt.draw(sprite2, rs);
}