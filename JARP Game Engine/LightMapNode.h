#pragma once
#include "SceneNode.h"
class LightMapNode : public SceneNode
{
public:
    LightMapNode(sf::RenderWindow& window);
    ~LightMapNode();

private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    void drawLights();
    sf::RenderTexture lightMap;
};

