#pragma once
#include "general.hpp"
#include "fdef.hpp"
#include "scenemain.hpp"

class Game {
    public:
        sf::RenderWindow window;
        std::string scene = "main";
        unsigned int width, height;
        Game();
        void run(shared_ptr<Game>);
        void loop(shared_ptr<Game>);
        void handleInput(shared_ptr<Game>);
        void handleScene(shared_ptr<Game>);
};
