#include "LightMapNode.h"



LightMapNode::LightMapNode(sf::RenderWindow& window) : lightMap()
{
    sf::Vector2u windowSize = window.getSize();
    this->lightMap.create(windowSize.x, windowSize.y);
    this->lightMap.clear(sf::Color::Black);
  
}


LightMapNode::~LightMapNode()
{
}


void LightMapNode::drawLights()
{
    this->lightMap.clear(sf::Color::Black);
}


void LightMapNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
}
