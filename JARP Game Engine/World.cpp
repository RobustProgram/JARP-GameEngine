#include "World.h"

World::World(sf::RenderWindow& window) :
    mWindow(window), mSceneGraph(), mSceneLayers()
{
    this->buildScene();
}


World::~World()
{
}


void World::draw()
{
    this->mWindow.draw(this->mSceneGraph);
}


void World::buildScene()
{
    for (int i = 0; i < this->LayerCount; i++)
    {
        SceneNode::SceneNodePtr layer(new SceneNode());
        this->mSceneLayers[i] = layer.get();
        this->mSceneGraph.attachChild(std::move(layer));
    }

    std::unique_ptr<LightSource> demoLight(new LightSource(sf::Vector2f(100, 100), 100, sf::Color::White));
    this->mSceneLayers[Lights]->attachChild(std::move(demoLight));

    std::unique_ptr<LightSource> demoLight2(new LightSource(sf::Vector2f(200, 100), 100, sf::Color::Green));
    this->mSceneLayers[Lights]->attachChild(std::move(demoLight2));
}