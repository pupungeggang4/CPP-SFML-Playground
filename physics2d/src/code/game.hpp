#pragma once
#include "general.hpp"
#include "fdef.hpp"

#include "field.hpp"
#include "scenemain.hpp"

class Game {
    public:
        sf::RenderWindow window; sf::View UIView; sf::Clock clock = sf::Clock();
        unsigned int width, height;
        float frameCurrent = 0, framePrevious = 0, delta = 0;

        std::string scene = "main";
        shared_ptr<Field> field;

        Game();
        void run(shared_ptr<Game>);
        void loop(shared_ptr<Game>);
        void handleInput(shared_ptr<Game>);
        void handleScene(shared_ptr<Game>);
};
