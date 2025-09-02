#pragma once
#include "general.hpp"
#include "fdef.hpp"

class Game {
    public:
        sf::RenderWindow window;
        std::unordered_map<std::string, sf::Texture> tex;
        sf::Texture emptyTex;
        sf::Sprite s = sf::Sprite(emptyTex);
        Game();
        void run();
};