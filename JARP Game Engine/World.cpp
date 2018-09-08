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

void World::update(sf::Time dt)
{
    this->mSceneGraph.update(dt);

    sf::Vector2i mousePos = sf::Mouse::getPosition();
}

void World::buildScene()
{
    for (int i = 0; i < this->LayerCount; i++)
    {
        if (i == Lights)
        {
            std::unique_ptr<LightMapNode> lightLayer(new LightMapNode(mWindow));
            this->mSceneLayers[i] = lightLayer.get();
            this->mSceneGraph.attachChild(std::move(lightLayer));
        }
        else
        {
            SceneNode::SceneNodePtr layer(new SceneNode());
            this->mSceneLayers[i] = layer.get();
            this->mSceneGraph.attachChild(std::move(layer));
        }
    }

    std::unique_ptr<LightSource> demoLight(new LightSource(sf::Vector2f(100, 100), 200, sf::Color::White));
    this->mSceneLayers[Lights]->attachChild(std::move(demoLight));

    std::unique_ptr<LightSource> demoLight2(new LightSource(sf::Vector2f(300, 100), 200, sf::Color::Green));
    this->mSceneLayers[Lights]->attachChild(std::move(demoLight2));
}