#include <iostream>
#include <SFML/Graphics.hpp>

class KItty : public Drawable {
public:  
    Personaje(sf::Vector2f position)
    {

        // Cargar la imagen desde un archivo
        if (!texture.loadFromFile("assets/sprites_izq.png"))
        {
        
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position); // Posición inicial sprite
    }

    void move(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
        shape.move(offsetX, offsetY);
    }

    void draw(sf::RenderWindow &window)
    {
        ventana.draw(this->shape);
        ventana.draw(this->sprite);
    }

    void updateK(){
        // Actualizar el frame de la animación
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * 64)+17, 133, 64, 36));
            clock.restart();
        }
    }

    private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 0.2f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 4; // Número total de frames en la animación
    int frameWidth = 320;
    int frameHeight = 320;
};

 