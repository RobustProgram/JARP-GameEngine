// JARP Game Engine.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main()
{
    try 
    {
        Game game;
        game.run();
    }
    catch (std::exception &e)
    {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
    return 0;
}