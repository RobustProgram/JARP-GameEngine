#pragma once

#include <SFML/Graphics.hpp>
#include "World.h"

class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    sf::Time TIME_PER_FRAME = sf::seconds(1.0f / 60.0f);
    sf::RenderWindow gWindow;
    World gWorld;

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
};

