#pragma once
#include "general.hpp"

class Field;

class Game {
    public:
        sf::RenderWindow window; sf::View UIView; sf::Clock clock = sf::Clock();
        unsigned int width, height;
        float frameCurrent = 0, framePrevious = 0, delta = 0;

        std::string scene = "main";
        std::unordered_map<std::string, bool> keyPressed = {
            {"left", false}, {"right", false}, {"up", false}, {"down", false}
        };
        shared_ptr<Field> field;

        Game();
        void run(shared_ptr<Game>);
        void loop(shared_ptr<Game>);
        void handleInput(shared_ptr<Game>);
        void handleScene(shared_ptr<Game>);
};
