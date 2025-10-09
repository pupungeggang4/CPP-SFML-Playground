#pragma once
#include "general.hpp"

class UI;

class Adventure;
class Player;
class Unit;
class Card;

class Render;
class Func;
class Game;

class UI {
    public:
        static std::unordered_map<std::string, std::vector<int>> title;
};

class Func {
    public:
        static bool pointInsideRectUI(sf::Vector2i pos, sf::IntRect rect);
};

class Game {
    public:
        sf::RenderWindow window;
        unsigned int width, height;
        Game();
        void run(shared_ptr<Game> game);
        void handleScene(shared_ptr<Game> game);
        void handleInput(shared_ptr<Game> game);
};