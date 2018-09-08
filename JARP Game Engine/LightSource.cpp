#include "LightSource.h"



LightSource::LightSource(sf::Vector2f position, int radius, sf::Color colour)
    : colour(colour), lightSource(sf::TriangleFan, resolution + 1)
{
    this->radius = radius;
    this->position = position;

    // This is the point where the light comes from
    this->lightSource[0].position = position;
    this->lightSource[0].color = this->colour;

    float angleIncrement = 360.f / resolution;
    float angle = 0;

    for (int i = 1; i < resolution + 1; i++)
    {
        this->lightSource[i].position = sf::Vector2f(position.x + radius * cos(angle), position.y + radius * sin(angle));
        this->lightSource[i].color = sf::Color::Transparent;
        angle += angleIncrement;
    }
}


LightSource::~LightSource()
{
}

void LightSource::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(lightSource, states);
}