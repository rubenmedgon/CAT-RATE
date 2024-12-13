#include "Animacion.hpp"

Animacion::Animacion(const std::string& texturePath, int numFrames, float frameTime, int frameWidth, int frameHeight)
    : currentFrame(0), numFrames(numFrames), frameTime(frameTime), frameWidth(frameWidth), frameHeight(frameHeight) {
    if (!texture.loadFromFile(texturePath)) {
        throw std::runtime_error("No se pudo cargar la textura: " + texturePath);
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
}

void Animacion::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void Animacion::update() {
    if (clock.getElapsedTime().asSeconds() >= frameTime) {
        currentFrame = (currentFrame + 1) % numFrames;
        int left = currentFrame * frameWidth;
        sprite.setTextureRect(sf::IntRect(left, 0, frameWidth, frameHeight));
        clock.restart();
    }
}

void Animacion::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}
