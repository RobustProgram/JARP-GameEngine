#pragma once

#include "SceneNode.h"
#include "LightSource.h"

class LightMapNode : public SceneNode
{
public:
    LightMapNode(sf::RenderWindow& window);
    ~LightMapNode();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);

private:
    sf::RenderTexture lightMap;
    sf::Sprite lightMapSprite;
};

