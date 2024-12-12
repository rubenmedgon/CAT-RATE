#include "Kitty.hpp"

double velocidad = 0.1;

Kitty::kitty(Vector2f position)
{
    // Cargar la imagen desde un archivo
    if (!texture.loadFromFile("assets/.png"))
    {
        // Podrías agregar manejo de error aquí
    }
    this->sprite =Sprite(texture);
    this->sprite.setPosition(position); // Posición inicial sprite
}

void Kitty::move(float offsetX, float offsetY)
{
    sprite4.move(offsetX, offsetY);
}
/**
void Kitty::draw(sf::RenderWindow &window)
{ 
    window.draw(this->sprite4);
}
*/
void Kitty::updateK()
{
    // Actualizar el frame de la animación
    if (clock.getElapsedTime().asSeconds() >= frameTime)
    {
        currentFrame = (currentFrame + 1) % numFrames;
        sprite.setTextureRect(sf::IntRect((currentFrame * 64)+17, 133, 64, 36));
        clock.restart();
    }
}


void Kitty::draw(RenderTarget& rt, RenderStates rs) const{
    rt.draw(sprite4, rs);
}
