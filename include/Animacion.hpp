#ifndef ANIMACION_HPP
#define ANIMACION_HPP

#include <SFML/Graphics.hpp>

class Animacion : public sf::Drawable {
private:
    sf::Sprite sprite;       // Sprite de la animación
    sf::Texture texture;     // Textura de la animación
    sf::Clock clock;         // Reloj para manejar el tiempo de animación
    int currentFrame;        // Frame actual
    int numFrames;           // Número total de frames
    float frameTime;         // Duración de cada frame
    int frameWidth;          // Ancho de cada frame
    int frameHeight;         // Altura de cada frame

public:
    Animacion(const std::string& texturePath, int numFrames, float frameTime, int frameWidth, int frameHeight);

    void setPosition(float x, float y);
    void update();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif

