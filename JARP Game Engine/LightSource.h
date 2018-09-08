#pragma once

#include <iostream>
#include <math.h>
#include "Entity.h"

#define PI 3.14159265

class LightSource : public Entity
{
public:
    LightSource(sf::Vector2f position, int radius, sf::Color colour);
    ~LightSource();

private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);
    
    void drawLight(sf::Vector2f position);

private:
    int resolution = 64;
    int radius = 0;
    sf::Color colour;
    sf::VertexArray lightSource;
    sf::Vector2f position;
};

