#pragma once
#include "general.hpp"
#include "fdef.hpp"

class Game {
    public:
        shared_ptr<sf::RenderWindow> window;

        Game();
        void run();
};