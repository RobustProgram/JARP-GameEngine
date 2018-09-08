#include "Game.h"

Game::Game()
: gWindow(sf::VideoMode(1024, 720), "Testing"), gWorld(gWindow)
{
    gWindow.setVerticalSyncEnabled(true);
}


Game::~Game()
{
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (gWindow.isOpen())
    {
        processEvents();

        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TIME_PER_FRAME)
        {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            processEvents();
            update(TIME_PER_FRAME);
        }
        
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (gWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            gWindow.close();
    }
}

void Game::render()
{
    gWindow.clear(sf::Color::White);
    gWorld.draw();
    gWindow.display();
}

void Game::update(sf::Time deltaTime)
{
    gWorld.update(deltaTime);
}