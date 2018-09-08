#pragma once

#include <math.h>
#include "Entity.h"

class LightSource : public Entity
{
public:
    LightSource(sf::Vector2f position, int radius, sf::Color colour);
    ~LightSource();

private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    int resolution = 64;
    int radius = 0;
    sf::Color colour;
    sf::VertexArray lightSource;
    sf::Vector2f position;
};

