#include "LightSource.h"



LightSource::LightSource(sf::Vector2f position, int radius, sf::Color colour)
    : colour(colour), lightSource(sf::TriangleFan, resolution + 1)
{
    this->radius = radius;
    this->position = position;

    this->drawLight(position);
}

LightSource::~LightSource()
{
}

void LightSource::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(lightSource, states);
}

void LightSource::drawLight(sf::Vector2f position)
{
    this->lightSource[0].position = position;
    this->lightSource[0].color = this->colour;

    float angleIncrement = 360.f / (resolution - 1);
    float angle = 0;
    float radian = 0;

    for (int i = 1; i < resolution + 1; i++)
    {
        radian = angle * (PI / 180);
        this->lightSource[i].position = sf::Vector2f(
            position.x + radius * cos(radian), 
            position.y + radius * sin(radian)
        );
        this->lightSource[i].color = sf::Color::Transparent;
        angle += angleIncrement;
    }
}

void LightSource::updateCurrent(sf::Time dt)
{
}