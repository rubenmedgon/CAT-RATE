#include "Onomatopeya.hpp"

Onomatopeya::Onomatopeya(int tip, int x, int y){
   tipo = tip;
   sprite3.setPosition(x, y);
}

void Onomatopeya::DarTextura(Texture tex){
    texture = tex;
}

void Onomatopeya::DesbloquearSprite(){
    sprite3.setTexture(texture);
}

void Onomatopeya::draw(RenderTarget& rt, RenderStates rs) const{
    rt.draw(sprite3, rs);
}