#include "LightMapNode.h"



LightMapNode::LightMapNode(sf::RenderWindow& window) : lightMap(), lightMapSprite()
{
    sf::Vector2u windowSize = window.getSize();
    this->lightMap.create(windowSize.x, windowSize.y);
    this->lightMap.clear(sf::Color::Black);

    this->lightMapSprite.setTexture(this->lightMap.getTexture());
}


LightMapNode::~LightMapNode()
{
}

void LightMapNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // Hijack this function to not draw the children
    this->drawCurrent(target, sf::BlendMultiply);
}

void LightMapNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->lightMapSprite, states);
}

void LightMapNode::updateCurrent(sf::Time dt)
{
    this->lightMap.clear(sf::Color::Black);

    // We are going to manually draw the children lights onto this
    for (auto itr = this->mChildren.begin(); itr != mChildren.end(); itr++)
    {
        LightSource* light = (LightSource*)(*itr).get();
        this->lightMap.draw(*light, sf::BlendAdd);
        light = nullptr;
    }

    this->lightMap.display();
}
