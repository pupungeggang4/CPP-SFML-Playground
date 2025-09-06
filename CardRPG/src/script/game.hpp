#pragma once
#include "general.hpp"
#include "fdef.hpp"
#include "scenetitle.hpp"

class Game : public std::enable_shared_from_this<Game> {
    public:
        sf::RenderWindow window;
        std::unordered_map<std::string, sf::Texture> tex;
        sf::Texture emptyTex;
        sf::Sprite s = sf::Sprite(emptyTex);

        Game();
        void run();
        void loop();
};