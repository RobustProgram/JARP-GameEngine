#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include "SceneNode.h"
#include "LightSource.h"

class World : private sf::NonCopyable
{
public:
    World(sf::RenderWindow& window);
    ~World();

    void draw();

private:
    void buildScene();

private:
    enum Layer
    {
        Background,
        Shadow,
        Solids,
        Lights,
        LayerCount
    };

    sf::RenderWindow&                       mWindow;
    SceneNode                           mSceneGraph;
    std::array<SceneNode*, LayerCount> mSceneLayers;
};

