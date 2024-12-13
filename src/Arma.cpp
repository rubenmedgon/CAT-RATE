#include "Arma.hpp"

Arma::Arma(int tip, int x, int y){
   tipo = tip;
   sprite2.setPosition(x, y);
}

void Arma::DarTextura(Texture tex){
    texture = tex;
}

void Arma::DesbloquearSprite(){
    sprite2.setTexture(texture);
}

void Arma::draw(RenderTarget& rt, RenderStates rs) const{
    rt.draw(sprite2, rs);
}